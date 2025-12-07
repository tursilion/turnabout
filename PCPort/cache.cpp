// Make sure to link this file first after the crt0, that way it's guaranteed to be in the >a000 page
// An AMS cache for downloaded images - this lets us load without
// going to the web and also play music during the load (since we expect that to take about 4 frames)

#include <vdp.h>
#include <f18a.h>
#include <string.h>
#include "engine.h"
#include "cache.h"
#include "music.h"

// cache line structure - first page of AMS is the lookup table. Each line is 32 bytes and contains:
// 2 bytes of image index
// 30 bytes of F18A palette (skipping color 0)
// 4k divided by 32 bytes lets us store 127 images (cause 1 is reserved for the index).
// That would fill our 1MB max, but we have to also leave room for the 32k RAM:
//
// page 0 - cache here (overlaps ROM otherwise unused)
// page 1 - (overlaps ROM) SAMPLE: All Objection (ending)
// page 2 - >2000
// page 3 - >3000
// page 4 - (overlaps DSR) SAMPLE: Trixie Objection
// page 5 - (overlaps DSR) SAMPLE: Trixie Holdit
// page 6 - (overlaps cart) SAMPLE: Phoenix Holdit
// page 7 - (overlaps cart) SAMPLE: Phoenix Objection
// page 8 - (overlaps I/O) SAMPLE: Phoenix TakeThat / Judge Objection (final scene)
// page 9 - (overlaps I/O) SAMPLE: Fluttershy Objection / Twilight Objection
// page10 - >a000
// page11 - >b000
// page12 - >c000
// page13 - >d000
// page14 - >e000
// page15 - >f000
// page16 - music player at >E000
// page17-47  - cached music
// page48-255 - Cached images

// the AMS is also going to handle all music now as well, so that will reduce the pages
// available a bit more. Expecting 51 tunes right now, possibly there will be more.
// I think we'll lay out the cache data based on up to 4 per page, since a good number
// so far as under 1k (of course, some are over 2k). Anyway, see the music page for that.
// For now, we're assuming we'll need 32 pages (including one for the music PLAYER. Nice
// thing is since it's RAM, we can store its data in that page too!)

// Image - each image takes 2 pages (pattern and color) plus 32 bytes in the cache index page 0
// The 32 bytes contain 2 bytes of image, and 30 bytes of F18A image. (Random data if not F18A).
// As the total page is 4k in size, we can store 128 images total in cache.
// 128 images is 256 pages - but since 16 pages are used for the default memory space + cache + samples,
// We are now down to 208 pages - 104 images. That's still tons. Anything over say 64 is overkill.
// 32 is probably adequate... but 64 may help some roundabout sequences.

// TODO: LAST_CACHE_PAGE assumes 1MB or greater, we should use the value in the ams variable

#define CACHE_PAGE 0
#define FIRST_CACHE_PAGE 48
#define LAST_CACHE_PAGE 255
#define NUM_CACHE_PAGES (LAST_CACHE_PAGE-FIRST_CACHE_PAGE+1)
int CacheHead = 0, CacheTail = 0;
#define CACHE_MAX (NUM_CACHE_PAGES-1)

#ifdef CLASSIC99
// Can't test the hardware interaction, but can at least test the buffering theory!
// we could use the real AMS hardware if the emulation gave us a way to SBO/SBZ, but that's ok.
// later, if necessary.
#include <malloc.h>

#ifndef NULL
#define NULL (0)
#endif

unsigned char *pAmsRam = NULL;      // we'll allocate this on first run
unsigned char *pAmsMap[16] = {};    // 16 4k blocks pointing into AMS, initialized to sequence by CRT, here we'll do it when we allocate
bool amsMapOn = false;

// beware: In the classic99 build CPlayer.h types "uint16" to a 32-bit int, so keep the name distinct and don't assume
typedef unsigned short uint16_type;
extern "C" void debug_write(char *s, ...);

// here we'll just track a variable to ensure we are doing the on/off right
void samsMapOn() {
    amsMapOn = true;
}

void samsMapOff() {
    amsMapOn = false;
}

// must be the first function called! (otherwise what are you mapping?)
void samsMapPage(int page, int location) {
    if (pAmsRam == NULL) {
        // first call
        pAmsRam=(unsigned char*)malloc(ams*4096);   // yes, we'll leak this
        for (int i=0; i<16; ++i) {
            pAmsMap[i]=pAmsRam+4096*i;
        }
    }

    // now update the map
    pAmsMap[(location&0xf000)>>12] = pAmsRam+page*4096;
}

#else
typedef unsigned int uint16_type;
#define debug_write(...) ((void)0)

// SAMS code by Jedimatt42
void __attribute__ ((noinline)) samsMapOn() {
  __asm__ volatile (
    "LI r12, >1E00\n\t"
    "SBO 1\n\t"
    : : : "r12" );
}

void __attribute__ ((noinline)) samsMapOff() {
  __asm__ volatile (
    "LI r12, >1E00\n\t"
    "SBZ 1\n\t"
   : : : "r12" );
}

void __attribute__ ((noinline)) samsMapPage(int page, int location) {
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
#endif

// sz must be a multiple of 256!
void vdpmemcpywithmusic(unsigned int vdpAdr, unsigned char *cpuAdr, unsigned int sz, unsigned int page) {
    // store 256 bytes at a time, checking for music
    // music player and data must ALSO be in low memory!!
    samsMapPage(page, MAP_ADDRESS);
    samsMapOn();
#ifdef CLASSIC99
    if ((((int)cpuAdr&0xfff))+sz > 0x1000) debug_write("Warning: access past end of AMS page");
    if (!amsMapOn) debug_write("WARNING: memcpywithmusic but map is off!");
    cpuAdr = pAmsMap[(((int)cpuAdr)&0xf000)>>12]+(((int)cpuAdr)&0x0fff);
#endif
    while (sz > 0) {
        vdpmemcpy(vdpAdr, cpuAdr, 0x100);
        vdpAdr += 0x100;
        cpuAdr += 0x100;
        sz -= 0x100;
#ifndef CLASSIC99
        // check VDP CRU
        int flag = 0;
        __asm__ volatile ( "clr r12\n\ttb 2\n\tjeq vdp%=\n\tseto r12\nvdp%=:\n\tmov r12,%0" : "=r"(flag) : : "r12","cc" );
        if (flag) {
            VDP_CLEAR_VBLANK;
            update_music();
            // update_music reset the AMS page, so get it back
            samsMapPage(page, MAP_ADDRESS);
            samsMapOn();
        }
#endif
    }
}

void vdpmemreadwithmusic(unsigned int vdpAdr, unsigned char *cpuAdr, unsigned int sz, unsigned int page) {
    // read 256 bytes at a time, checking for music
    // music player and data must ALSO be in low memory!!
    samsMapPage(page, MAP_ADDRESS);
    samsMapOn();
#ifdef CLASSIC99
    if ((((int)cpuAdr&0xfff))+sz > 0x1000) debug_write("Warning: access past end of AMS page");
    if (!amsMapOn) debug_write("WARNING: memreadwithmusic but map is off!");
    cpuAdr = pAmsMap[(((int)cpuAdr)&0xf000)>>12]+(((int)cpuAdr)&0x0fff);
#endif
    while (sz > 0) {
        vdpmemread(vdpAdr, cpuAdr, 0x100);
        vdpAdr += 0x100;
        cpuAdr += 0x100;
        sz -= 0x100;
#ifndef CLASSIC99
        // check VDP CRU
        int flag = 0;
        __asm__ volatile ( "clr r12\n\ttb 2\n\tjeq vdp%=\n\tseto r12\nvdp%=:\n\tmov r12,%0" : "=r"(flag) : : "r12","cc" );
        if (flag) {
            VDP_CLEAR_VBLANK;
            update_music();
            // update_music reset the AMS page, so get it back
            samsMapPage(page, MAP_ADDRESS);
            samsMapOn();
        }
#endif
    }
}

// restore default sams map
// This file doesn't use the second page, but this lets other systems use this function
void restoreSamsMap() {
    samsMapPage(ADR_DEFAULT_PAGE, MAP_ADDRESS);
    samsMapPage(ADR_DEFAULT_PAGE2, MAP_ADDRESS2);
    samsMapOff();
}

// if we find the item in cache, copy the cache line to buf and return the cache line offset, else return 0xffff (which is > 4k)
// warning: SAMS MAP is NOT restored - left active on the cache page
int findInCache(int idx, unsigned char *buf) {
    // to avoid violating assumptions - always turn on AMS first
    samsMapPage(0, MAP_ADDRESS);
    samsMapOn();

    // ignore index 0, might just be uninitialized RAM. We only load it once ever.
    if (idx != 0) {
        for (int cnt = CacheHead; cnt != CacheTail; cnt = ((cnt+1)>CACHE_MAX ? 0 : cnt+1)) {
            // fetch the cache line
#ifdef CLASSIC99
            if (!amsMapOn) debug_write("WARNING: findinCache but map is off!");
            memcpy(buf, (unsigned char*)(pAmsMap[(MAP_ADDRESS&0xf000)>>12]) + (cnt<<5), 32);
#else
            memcpy(buf, (unsigned char*)MAP_ADDRESS + (cnt<<5), 32);
#endif
            if (*(uint16_type*)buf == idx) {
                // hey, this is it!
                return cnt;
            }
        }
    }

    return 0xffff;
}

// Load image from cache. Return non-zero if we found it
int loadFromCache(int idx) {
    unsigned char buf[32];

#ifdef CLASSIC99
    if (amsMapOn) debug_write("loadFromCache but last call left map on");
#endif

    if (ams == 0) {
        return 0;
    }

    int found = findInCache(idx, buf);
    if (found == 0xffff) {
        restoreSamsMap();
        return 0;
    }
    debug_write("Loading from page %d\n", found);

    // remember the SAMS MAP needs to be restored!

    // we found it. We have a copy of the cache line, so we can use that
    // found has the index of the cache line. The card page is (index*2)+FIRST_CACHE_PAGE
    // remember it takes two pages for every cached image
    int mapidx = (found<<1)+FIRST_CACHE_PAGE;
    vdpmemcpywithmusic(gPattern, (unsigned char*)MAP_ADDRESS, 0x1000, mapidx);
    if (f18a) {
        // we need to load the palette into the right VDP address too, and tell the F18A about it
        buf[0]=0;   // always black and need to clear out the image index
        buf[1]=0;
        vdpmemcpy(gPattern+0x1000, buf, 32);
        vdpchar(0x3900, 0x01);  // load palette command
    }
    ++mapidx;
    vdpmemcpywithmusic(gColor, (unsigned char*)MAP_ADDRESS, 0x1000, mapidx);
    restoreSamsMap();

    return 1;
}

// Store image from VDP to cache. If it is already there, we're done
// The F18A palette bytes are copied whether we are in F18A mode or not
void storeToCache(int idx) {
    unsigned char buf[32];

#ifdef CLASSIC99
    if (amsMapOn) debug_write("storeToCache but last call left map on");
#endif

    if (ams == 0) {
        return;
    }

    if (idx == 0) {
        // don't store 0, we can't load it
        restoreSamsMap();
        return;
    }

    int found = findInCache(idx, buf);
    if (found != 0xffff) {
        restoreSamsMap();
        return;
    }

    // Save it to the current tail, and increment
    // if we bump the head, nudge it up to lose the oldest one
    found = CacheTail;
    ++CacheTail;
    if (CacheTail > CACHE_MAX) CacheTail = 0;
    if (CacheTail == CacheHead) {
        ++CacheHead;
        if (CacheHead > CACHE_MAX) {
            CacheHead = 0;
        }
    }
    debug_write("Saving to new page %d\n", found);
    
    // update cache line - read in F18A palette (or junk if it's not on)
    unsigned char *baseAddress = (unsigned char*)MAP_ADDRESS;
#ifdef CLASSIC99
    if (!amsMapOn) debug_write("WARNING: storetocache but map is off!");
    baseAddress = pAmsMap[(((int)baseAddress)&0xf000)>>12]+(((int)baseAddress)&0x0fff);
#endif
    baseAddress += (found<<5);
    vdpmemread(0x1000, baseAddress, 32);
    *(uint16_type*)baseAddress = idx;
    
    // copy pattern table - use the TI addresses here as vdpmemreadwithmusic will fix for C99 build

    // THis compiler bug is not an issue here now(?), the bank was moved to vdpmemreadwithmusic...
    // compiler bug needs to be resolved here... we lose the MAP_ADDRESS constant (because we don't flag that the shift changes the value?)
    // We should take a look, but otherwise we can probably do the mapping inline more efficiently than it did...
    // I think my patches are out of date, so maybe we start with finding the latest and rebuilding?
    // What about my custom patches? Do I have any I need to keep?
#if 0
    samsMapPage((found<<1)+FIRST_CACHE_PAGE, MAP_ADDRESS);
    // TODO** COMPILER BUG
   A2B0  020E  li   R14,>f000              (20)     MAP_ADDRESS -> R14
         F000
   A2B4  C04F  mov  R15,R1                 (18)     found cache index
   A2B6  0221  ai   R1,>0010               (22)     plus first page (we already did the times 2)
         0010
   A2BA  020C  li   R12,>1e00              (20)     CRU for AMS
         1E00
>  A2BE  09CE  srl  R14,12                          MAP Address most significant nibble
   A2C0  0A1E  sla  R14,1                           times 2 for map register address
   A2C2  06C1  swpb R1                              'correct' byte order for write to register
   A2C4  1D00  sbo  >0000                           card regs on
   A2C6  CB81  mov  R1,@>4000(R14)                  write map value
         4000
   A2CA  1E00  sbz  >0000                           card regs off
   A2CC  06C1  swpb R1                              restore R1 order
   A2CE  0203  li   R3,>1000                        VDP copy size
         1000
   A2D2  C08E  mov  R14,R2                          ** still thinks R14 has the MAP_ADDRESS in it ** <---
   A2D4  C060  mov  @>e2bc[gPattern],R1             VDP address in R1
         E2BC
   A2D8  06A0  bl   @>a1aa[vdpmemreadwithmusic]     do vdpmemread
         A1AA
#endif

    int mapidx = (found<<1)+FIRST_CACHE_PAGE;
    vdpmemreadwithmusic(gPattern, (unsigned char*)MAP_ADDRESS, 0x1000, mapidx);

    ++mapidx;
    vdpmemreadwithmusic(gColor, (unsigned char*)MAP_ADDRESS, 0x1000, mapidx);

    restoreSamsMap();
}

// invalidate the cache for a particular image so it can be force-reloaded
void invalidateCache(int idx) {
    unsigned char buf[32];

#ifdef CLASSIC99
    if (amsMapOn) debug_write("invalidateCache but last call left map on");
#endif

    if (ams == 0) {
        return;
    }

    int found = findInCache(idx, buf);
    if (found != 0xffff) {
        unsigned char *baseAddress = (unsigned char*)MAP_ADDRESS;
    #ifdef CLASSIC99
        if (!amsMapOn) debug_write("WARNING: invalidateCache but map is off!");
        baseAddress = pAmsMap[(((int)baseAddress)&0xf000)>>12]+(((int)baseAddress)&0x0fff);
    #endif
        baseAddress += (found<<5);
        *(uint16_type*)baseAddress = 0xffff;
    }

    restoreSamsMap();
}
