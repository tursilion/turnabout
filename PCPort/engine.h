#ifndef ENGINE_H
#define ENGINE_H

void draw_screen();
void load_image(int index);
void invert_image();
void normal_image();
void black_image();
void add_inventory(int id);
void remove_inventory(int id);
void set_text(const char *p);
void set_name(int i);
void set_maxlen(int i);

#endif
