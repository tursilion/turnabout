#ifndef ENGINE_H
#define ENGINE_H

#include "structures.h"

extern Evidence_t evidence[EV_MAX];
extern Evidence_t people[PP_MAX];

#define PPLIDX(i) (((i)-PP_FIRST)>>8)

void clear_text();
void draw_screen();
void load_image(int index);
void spritestring(const char*str, unsigned char col);
void invert_image();
void normal_image();
void bitmap_screen();
void fixed_image();
void black_image();
void add_inventory(unsigned int id);
void remove_inventory(unsigned int id);
int has_inventory(unsigned int id);
void set_textout(const char *p);
void set_name(unsigned int i);
void set_maxlen(int i);
void wait_for_key_release();

void set_alt_text();

#endif
