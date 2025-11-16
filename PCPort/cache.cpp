#if 1
int loadFromCache(int index) {
    (void)index;
    return 0;
}
void storeToCache(int index) {
    (void)index;
}
#else 

// An AMS cache for downloaded images - this lets us load without
// going to the web and also play music during the load (since we expect that to take about 4 frames)
// This code is expected to be loaded in low RAM, and will page in at >A000. it should not expect other code to be available.

#include <vdp.h>
#include <f18a.h>
#include <string.h>
#include "cache.h"
#include "music.h"

// cache line structure - first page of AMS is the lookup table. Each line is 32 bytes and contains:
// 2 bytes of image index
// 30 bytes of F18A palette (skipping color 0)
// 4k divided by 32 bytes lets us store 127 images (cause 1 is reserved for the index).
// That would fill our 1MB max, but we have to also leave room for the 32k RAM:
//
// page 0 - cache here (overlaps ROM otherwise unused)
// page 1 - overlaps ROM, unused
// page 2 - >2000
// page 3 - >3000
// page 4 - overlaps DSR, unused
// page 5 - overlaps DSR, unused
// page 6 - overlaps cart, unused
// page 7 - overlaps cart, unused
// page 8 - overlaps I/O, unused
// page 9 - overlaps I/O, unused (24k unused here total)
// page10 - >a000
// page11 - >b000
// page12 - >c000
// page13 - >d000
// page14 - >e000
// page15 - >f000
// page16-255 - free to use - still need to work out sample data

#define CACHE_PAGE 0
#define FIRST_CACHE_PAGE 16
#define LAST_CACHE_PAGE 255
#define NUM_CACHE_PAGES (LAST_CACHE_PAGE-FIRST_CACHE_PAGE+1)
#define MAP_ADDRESS 0xa000
#define ADR_DEFAULT_PAGE 10

int CacheHead = 0, CacheTail = 0;
#define CACHE_MAX (NUM_CACHE_PAGES-1)

// SAMS code by Jedimatt42
void samsMapOn() {
  __asm__ volatile (
    "LI r12, >1E00\n\t"
    "SBO 1\n\t"
  );
}

void samsMapOff() {
  __asm__ volatile (
    "LI r12, >1E00\n\t"
    "SBZ 1\n\t"
  );
}

void samsMapPage(int page, int location) {
  __asm__ volatile (
      "LI r12, >1E00\n\t"
      "SRL %0, 12\n\t"      // isolate top nibble of location
      "SLA %0, 1\n\t"       // shift up for word address
      "SWPB %1\n\t"         // want little endian order for page
      "SBO 0\n\t"           // card on
      "MOV %1, @>4000(%0)\n\t"  // map page
      "SBZ 0\n\t"           // card off
      "SWPB %1\n\t"         // restore page register before returning
      :
      : "r"(location), "r"(page)
      : "r12");
}

// sz must be a multiple of 256!
void vdpmemcpywithmusic(unsigned int vdpAdr, unsigned char *cpuAdr, unsigned int sz) {
    // store 256 bytes at a time, checking for music
    // music player and data must ALSO be in low memory!!
    while (sz > 0) {
        vdpmemcpy(vdpAdr, cpuAdr, 0x100);
        vdpAdr += 0x100;
        cpuAdr += 0x100;
        sz -= 0x100;
        // check VDP CRU
        int flag = 0;
        __asm__ volatile ( "clr r12\n\ttb 2\n\tjeq vdp%=\n\tseto r12\nvdp%=:\n\tmov r12,%0" : "=r"(flag) : : "r12","cc" );
        if (flag) {
            VDP_CLEAR_VBLANK;
            update_music();
        }
    }
}

void vdpmemreadwithmusic(unsigned int vdpAdr, unsigned char *cpuAdr, unsigned int sz) {
    // read 256 bytes at a time, checking for music
    // music player and data must ALSO be in low memory!!
    while (sz > 0) {
        vdpmemread(vdpAdr, cpuAdr, 0x100);
        vdpAdr += 0x100;
        cpuAdr += 0x100;
        sz -= 0x100;
        // check VDP CRU
        int flag = 0;
        __asm__ volatile ( "clr r12\n\ttb 2\n\tjeq vdp%=\n\tseto r12\nvdp%=:\n\tmov r12,%0" : "=r"(flag) : : "r12","cc" );
        if (flag) {
            VDP_CLEAR_VBLANK;
            update_music();
        }
    }
}

// restore default sams map
void restoreSamsMap() {
    samsMapPage(ADR_DEFAULT_PAGE, MAP_ADDRESS);
    samsMapOff();
}

// if we find the item in cache, copy the cache line to buf and return the cache line offset, else return 0xffff (which is > 4k)
// warning: SAMS MAP is NOT restored on good return!
int findInCache(int idx, unsigned char *buf) {
    samsMapPage(0, MAP_ADDRESS);
    samsMapOn();
    for (int cnt = CacheHead; cnt != CacheTail; cnt = ((cnt+1)>CACHE_MAX ? 0 : cnt+1)) {
        // fetch the cache line
        memcpy(buf, (unsigned char*)MAP_ADDRESS + (cnt<<5), 32);
        if (*(unsigned int*)buf == idx) {
            // hey, this is it!
            return cnt;
        }
    }

    restoreSamsMap();
    return 0xffff;
}

// Load image from cache. Return non-zero if we found it
int loadFromCache(int idx) {
    unsigned char buf[32];

    if (ams == 0) {
        return 0;
    }

    int found = findInCache(idx, buf);
    if (found == 0xffff) {
        return 0;
    }

    // remember the SAMS MAP needs to be restored!

    // we found it. We have a copy of the cache line, so we can use that
    // found has the index of the cache line. The card page is (index*2)+FIRST_CACHE_PAGE
    // remember it takes two pages for every cached image
    found = (found<<1)+FIRST_CACHE_PAGE;
    samsMapPage(found, MAP_ADDRESS);
    samsMapOn();
    vdpmemcpywithmusic(gPattern, (unsigned char*)MAP_ADDRESS, 0x1000);
    if (f18a) {
        // warning: this might not work on little endian...
        loadpal_f18a((unsigned int*)&buf[2], 1, 15);
    }
    samsMapPage(found+1, MAP_ADDRESS);
    vdpmemcpywithmusic(gColor, (unsigned char*)MAP_ADDRESS, 0x1000);
    restoreSamsMap();

    return 1;
}

// Store image from VDP to cache. If it is already there, it's overwritten.
// The F18A palette bytes are copied whether we are in F18A mode or not
void storeToCache(int idx) {
    unsigned char buf[32];

    if (ams == 0) {
        return;
    }

    int found = findInCache(idx, buf);
    if (found == 0xffff) {
        // we need to find a new page
        ++CacheTail;
        if (CacheTail > CACHE_MAX) CacheTail = 0;
        int cnt = CacheTail - CacheHead;
        if (cnt < 0) cnt = CacheTail+CACHE_MAX+1 - CacheHead;
        if (cnt > CACHE_MAX) {
            ++CacheHead;
            if (CacheHead > CACHE_MAX) {
                CacheHead = 0;
            }
        }
    }
    
    // update cache line
    vdpmemread(0x1000, (unsigned char*)MAP_ADDRESS + (found<<5), 32);
    *(unsigned int*)MAP_ADDRESS = idx;
    
    // copy pattern table
    found = (found<<1)+FIRST_CACHE_PAGE;
    samsMapPage(found, MAP_ADDRESS);
    samsMapOn();
    vdpmemreadwithmusic(gPattern, (unsigned char*)MAP_ADDRESS, 0x1000);
    samsMapPage(found+1, MAP_ADDRESS);
    vdpmemreadwithmusic(gColor, (unsigned char*)MAP_ADDRESS, 0x1000);
    restoreSamsMap();
}

#endif
