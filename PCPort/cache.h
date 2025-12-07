// cache isn't working, and I really don't have the memory to spare
// it helps real hardware more than Classic99, and was just a curiousity
// can re-investigate it later. Haha, get it?

#ifndef CACHE_H
#define CACHE_H

// Warning: bug workaround asm code in cache.cpp hard-codes this MAP_ADDRESS value
#define MAP_ADDRESS 0xf000
#define ADR_DEFAULT_PAGE 15
#define MAP_ADDRESS2 0xe000
#define ADR_DEFAULT_PAGE2 14

// Some code to cache recent images in AMS
extern int ams;
extern int f18a;

// Load image from cache. Return non-zero if we found it
int loadFromCache(int idx);

// Store image from VDP to cache. If it is already there, it's overwritten.
// The F18A palette bytes are copied whether we are in F18A mode or not
void storeToCache(int idx);

// invalidate the cache for a particular image so it can be force-reloaded
void invalidateCache(int idx);

// SAMS code by Jedimatt42
extern void samsMapOn();
extern void samsMapOff();
extern void samsMapPage(int page, int location);

// this is hard coded to "the" paged map and exposed only for voice.cpp
void restoreSamsMap();

#endif
