#ifndef ENGINE_H
#define ENGINE_H

void clear_text();
void draw_screen();
void load_image(int index);
void spritestring(const char*str, unsigned char col);
void invert_image();
void normal_image();
void bitmap_screen();
void fixed_image();
void black_image();
void add_inventory(int id);
void remove_inventory(int id);
int has_inventory(int id);
void set_textout(const char *p);
void set_name(int i);
void set_maxlen(int i);
void wait_for_key_release();

#endif
