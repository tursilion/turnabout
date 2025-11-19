#ifndef SAVEGAME_H
#define SAVEGAME_H

#define SAVE_GAME_VDP 0x3a00

void savegame();
int loadgame();
void restore_saved_data();
void store_saved_data();

/*
Save Game Data
All values are 16-bit big endian ints (even though the VDP is bytes)

Offset  Size    Data
 0      32      Save/Load PAB and Filename
 (gap)
 32      2      Location index
 34      1      Mute flag MSB
 35      1      F18A flag LSB
 36      2      Number of SAMS pages
 38    128      Evidence Found (reads/writes EV_MAX_STORED_EV, max 64)
 (gap)
166     32      People found (up to PP_MAX, max 16)

*/

#endif
