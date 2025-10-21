#ifndef ENGINE_H
#define ENGINE_H

void clear_text();
void draw_screen();
void load_image(int index);
void invert_image();
void normal_image();
void fixed_image();
void black_image();
void add_inventory(int id);
void remove_inventory(int id);
int has_inventory(int id);
void set_textout(const char *p);
void set_name(int i);
void set_maxlen(int i);

#endif
