#ifndef MUSIC_H
#define MUSIC_H

// our external needs - code (from page 16) at 0xe000, music data at 0xf000
// WARNING: also hard coded in crt0_pload.asm
#define MUSIC_PAGE 16
#define MUSIC_ADDR 0xE000
// note: if you change MUSIC_DATA_ADDR, you have to change the addresses in musLookup[]
#define MUSIC_DATA_ADDR 0xF000

// wrappers need access to our variables
extern const unsigned char *pSong;
extern int musicPage;
extern int mute;

// the wrappers in engine.cpp
void load_music();
void play_music(int music);
void stop_music();
void update_music();

// the paged versions
void load_music_banked();
void play_music_banked(int music);
void stop_music_banked();
void update_music_banked();

// the loader in music.cpp
void load_one_music(int nMusic);

#endif
