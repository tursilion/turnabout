#ifndef ENGINE_H
#define ENGINE_H

#include <files.h>
#include "structures.h"
#include "mylib.h"

#ifdef CLASSIC99
extern Evidence_t evidence[EV_MAX_STORED_EV];
extern Evidence_t people[PP_MAX];
#else
extern const Evidence_t evidence[EV_MAX_STORED_EV];
extern const Evidence_t people[PP_MAX];
#endif

extern int ams;
extern int f18a;
extern int mute;
extern int readerFlag;

#ifdef LOCATION_TYPE_MISSES
#define DEFAULT_MISSES (4)
extern int missesLeft;
extern int missesTarget;
extern int recallMisses;
#endif

#define PPLIDX(i) (((i)-PP_FIRST)>>8)

void clear_text();
void music_delay();
void draw_screen();
void load_image(int index);
void spritestring(const char*str, unsigned char col);
void invert_image();
void normal_image();
void fixed_image();
void black_image();
void white_image();
void add_inventory(unsigned int id);
void remove_inventory(unsigned int id);
int has_inventory(unsigned int id);
void set_textout(const char *p);
void set_name(unsigned int i);
void set_maxlen(int i);
void wait_for_key_release();
int fastputwordwrap(int x, int y, const char *pWork, int cnt);
unsigned char wrap_dsrlnk(struct PAB *pab, unsigned int vdp);

#endif
