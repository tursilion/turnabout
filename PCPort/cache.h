// cache isn't working, and I really don't have the memory to spare
// it helps real hardware more than Classic99, and was just a curiousity
// can re-investigate it later. Haha, get it?

#ifndef CACHE_H
#define CACHE_H

// TODO: we need to figure out how much AMS to reserve for samples. I guess for now we'll all cache

// Some code to cache recent images in AMS
extern int ams;
extern int f18a;

// Load image from cache. Return non-zero if we found it
int loadFromCache(int idx);

// Store image from VDP to cache. If it is already there, it's overwritten.
// The F18A palette bytes are copied whether we are in F18A mode or not
void storeToCache(int idx);

#endif
