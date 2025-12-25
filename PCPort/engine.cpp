// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Maybe I can break it up with defines, the cross compiler won't have any trouble with that.
// for now I will not worry about the TI versions of functions

// need to save current location and current evidence, and color preferences, in vram
// when loading new files. Need a way to save and reload said preferences to disk so can
// save your game and continue.

#include <sound.h>
#include <conio.h>
#include <string.h>
#include <vdp.h>
#include <files.h>
#include <f18a.h>
#include <kscan.h>
#include "engine.h"
#include "structures.h"
#include "music.h"
#include "voice.h"
#include "savegame.h"
#include "aid.h"
#include "cache.h"
#include "story.h"

int evidence_found[EV_MAX_STORED_EV];
int people_found[PP_MAX];

#ifndef CLASSIC99
extern void EA5LD();
extern char FILENAME[];
#endif

extern 
#ifdef __cplusplus
"C"
#endif
const unsigned int F18A_INITIAL[16];

#ifdef CLASSIC99
extern "C" void vgm_pcinit();
#endif

const char *pString = NULL;
const char *pOldString = NULL;
int maxtext = 32*7;
int oldMaxtext = 32*7;
int iName = -1;     // does NOT use PP_FIRST after it's set
int oldName = -2;
int f18a = 0;
int readerFlag = 0; // does some minor updates to work better with screen readers
#ifdef CLASSIC99
int ams = 256;   // we can't actually detect AMS, but i need some for testing the cache code
#else
int ams = 0;
#endif

struct PAB myPab = {0};

// clear the text window (excluding name)
void clear_text() {
    if (readerFlag) {
        // this is awkward, but these extra clears will reset the screen reader
        // history so it doesn't drop words (takes 767 spaces)
        // we are also likely okay to remove the name, so do all 8 lines
        // This prevents the reader from catching JUST the name still on screen during a clear
        vdpmemset(gImage+16*32, ' ', 8*32);
        vdpmemset(gImage+16*32, ' ', 8*32);
        vdpmemset(gImage+16*32, ' ', 32);   // the remainder
    }
    vdpmemset(gImage+17*32, ' ', 7*32);
}

// wait for blank and update music
void music_delay() {
    VDP_WAIT_VBLANK_CRU;
    VDP_CLEAR_VBLANK;
    update_music();
}

// optimized version of cputwordwrap that drops features I don't need to try and
// get it down to a frame per update...
// cnt is used to limit the string to before the NUL termination
// if zero, then the whole string is used - no control codes, direct to output function
void fastputwordwrap(int x, int y, const char *pWork, int cnt) {
    const int width = 32;
    if (cnt == 0) {
        cnt = 32767;    // rely on the NUL terminator
    }

    // where we are writing to
    VDP_SET_ADDRESS(gImage+(y<<5)+x);

    while (*pWork) {
        // check for space
        if (*pWork == ' ') {
            // ignore leading spaces
            if (x > 0) {
                VDPWD(' '|conio_reverseMask);  // direct output
                x++;
                if (x>=width) {
                    x=0;
                    ++y;
                    if (y > 23) break; // out of lines
                    VDP_SET_ADDRESS(gImage+(y<<5)+x);
                }
            }
            pWork++;
            if (--cnt == 0) break;
            continue;
        }
        // check first if this line fits
        int pos = 0;
        while (pWork[pos]) {
            if (pWork[pos] == ' ') break;
            ++pos;
            if (pos+x >= width) break;
        }
        if (pos+x >= width) {
            if (x > 0) {
                // too long, and wasn't the whole line, so next line
                y++;
                if (y > 23) break; // out of lines
                x=0;
                VDP_SET_ADDRESS(gImage+(y<<5)+x);
            } else {
                // just reduce to one line
                --pos;
            }
        }
        // output the characters
        while (pos--) {
            VDPWD((*(pWork++))|conio_reverseMask);  // direct output
            if (*pWork == '\0') break;
            if (--cnt == 0) break;
            ++x;
        }
        if (cnt == 0) break;    // again
    }
}

// more of an update than a draw, per-sae
// Images are loaded directly to video memory, and not in this function
void draw_screen() {
    VDP_WAIT_VBLANK_CRU;
    VDP_CLEAR_VBLANK;

    if (iName != oldName) {
        oldName = iName;
        vdpmemset(gImage+16*32, ' ', 32);
        if (iName >= 0) {
            // we need to OR every character with 0x80 for the color
            reverse(1);
            cputsxy(0, 16, people[iName].name);
            reverse(0);
        }
    } else if ((readerFlag) && (pString != pOldString)) {
        // hide the name from subsequent texts so it reads better
        vdpmemset(gImage+16*32, ' ', 32);
    }

    if ((maxtext != oldMaxtext) || (pString != pOldString))  {
        if ((readerFlag)&&(maxtext < 32*7)) {
            // always draw fully so screen reader doesn't stutter
            maxtext = 32*7;
        }
        oldMaxtext = maxtext;
        pOldString = pString;
        if (pString) {
            // draw out the string one character at time with wordwrap
            fastputwordwrap(0, 17, pString, maxtext);
        } else {
            // clear the text window
            clear_text();
        }
    }

    // also play music - we might need to check frame time on hardware
    update_music();
}

void patch_string(char *buf, int index) {
    int off,tmp;
    off = 0;
    tmp = index/1000;
    buf[off++] = tmp+'0';
    index -= tmp*1000;
    tmp = index/100;
    buf[off++] = tmp+'0';
    index -= tmp*100;
    tmp = index/10;
    buf[off++] = tmp+'0';
    index -= tmp*10;
    buf[off] = index+'0';
}

void load_image(int index) {
    char buf[64];

    if (loadFromCache(index)) {
        return;
    }

    //                     1         2         3         4
    //           01234567890123456789012345678901234567890123456789012345
    strcpy(buf, "PI.HTTP://harmlesslion.com/phoenix/pics9918/P0000.TIAP");
    int off = 45;

    if (f18a) {
        memcpy(&buf[39], "f18a/F", 6);
    }

    // load the index into the string - max 9999
    patch_string(&buf[off], index);

    // check PAB
    if (myPab.OpCode == 0) {
        memset(&myPab, 0, sizeof(myPab));
        myPab.OpCode = DSR_LOAD;
        myPab.RecordNumber = 0x1022;    // only 2/3rds of the screen, plus F18A palette! Rememeber it will fail to load if larger!
    }

    // load patterns
    myPab.VDPBuffer = gPattern;
    myPab.pName = (unsigned char*)buf;
    wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);

    if (f18a) {
        // load the palette - it's at the end of the image there
        // we can just send a palette command to the F18A
        vdpchar(0x3900, 0x01);  // load palette command
    }

    // hitting one beat of music here may help Classic99 a tiny bit, but it's terrible on hardware
    // many tunes which haven't even started yet hang on the first note with a music beat here

    // load colors
    buf[off+8] = 'C';
    myPab.VDPBuffer = gColor;
    wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);

    storeToCache(index);
}

#ifdef LOCATION_IS_LOADER
// loads a full screen title image
void load_title() {
#define VDP_PAB_ADDRESS 0x3800
    char buf[64];
    unsigned char pal[32];
    int off,tmp;

    //                     1         2         3         4
    //           01234567890123456789012345678901234567890123456789012345
    strcpy(buf, "PI.HTTP://harmlesslion.com/phoenix/pics9918/P9999.TIAP");
    off = 53;   // points to the last character, we don't need to change the number

    if (f18a) {
        memcpy(&buf[39], "f18a/F", 6);
    }

    // check PAB
    memset(&myPab, 0, sizeof(myPab));
    myPab.OpCode = DSR_LOAD;
    myPab.RecordNumber = 0x1802;    // 2 extra bytes for DSR security

    // load palette if necessary
    if (f18a) {
        buf[off] = 'M';
        myPab.VDPBuffer = gPattern;
        myPab.pName = (unsigned char*)buf;
        wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);
        // fetch the data
        vdpmemread(0, pal, 32);
        // load both palettes, then the GPU program won't interfere
        loadpal_f18a((unsigned int*)pal, 0, 16);
        loadpal_f18a((unsigned int*)pal, 16, 16);
    }

    // load patterns
    buf[off] = 'P';
    myPab.VDPBuffer = gPattern;
    myPab.pName = (unsigned char*)buf;
    wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);

    // load colors
    buf[off] = 'C';
    myPab.VDPBuffer = gColor;
    wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);

    // reset the pab for later
    myPab.OpCode = 0;
}
#endif

// map a string of sprites (maximum 4) to the display
void spritestring(const char*str, unsigned char col) {
    int i = 0;
    int ch = 0;
    const char* ostr = str;
    while (*str) {
        if (*str != vdpreadchar(gSprite+(i<<2))) {
            ch = 1;
        }
        sprite(i++, *str, col, 16*8-6, i*8+27*8);
        ++str;
    }
    VDPWD(0xd0);    // no sprites after this!

#if 0
    // this is probably more annoying than it's worth
    if ((ch)&&(readerFlag)) {
        cputsxy(21,23,"Keys ");
        cputs(ostr);
    }
#endif
}

void invert_image() {
    // a real invert is too slow, but we can swap the color and pattern tables
    // rather than track it, a separate function can restore them

    // for F18A, invert the palette instead
    if (f18a) {
        vdpchar(0x3900, 0x02);  // invert palette command
    } else {
        VDP_SET_REGISTER(VDP_REG_CT, 0x7f);
	    VDP_SET_REGISTER(VDP_REG_PDT, 0x07);
    }
}

void normal_image() {
    // a real invert is too slow, but we can swap the color and pattern tables
    // rather than track it, a separate function can restore them

    if (f18a) {
        vdpchar(0x3900, 0x01);  // load palette command
    } else {
        VDP_SET_REGISTER(VDP_REG_CT, 0xFF);
	    VDP_SET_REGISTER(VDP_REG_PDT, 0x03);
    }
}

void fixed_image() {
    // load the fixed TI palette into palette 1 (f18a only)

    if (f18a) {
        vdpchar(0x3900, 0x03);  // fixed palette command
    }
}

void black_image() {
    // we'll see if this is just fast enough - black out the color table
    vdpmemset(gColor, 0, 0x1000);
}

void white_image() {
    // white out the color table
    vdpmemset(gColor, 0xff, 0x1000);
}

//------

void add_inventory(unsigned int id) {
    if (id >= PP_FIRST) {
        people_found[PPLIDX(id)] = 1;
    } else if (id < EV_MAX_STORED_EV) {
        evidence_found[id] = 1;
    }
}
void remove_inventory(unsigned int id) {
    // if you are removing a people, make sure you add the replacement right back!
    if (id >= PP_FIRST) {
        people_found[PPLIDX(id)] = 0;
    } else if (id < EV_MAX_STORED_EV) {
        evidence_found[id] = 0;
    }
}
// return non-zero if we have inventory
int has_inventory(unsigned int id) {
    if (id >= PP_FIRST) {
        return (people_found[PPLIDX(id)] != 0);
    } else if (id < EV_MAX_STORED_EV) {
        return (evidence_found[id] != 0);
    }
    return 0;
}
void set_textout(const char *p) {
    clear_text();
    pString = p;
}
void set_maxlen(int i) {
    maxtext = i;
}
void set_name(unsigned int i) {
    // convert into an index, 0 being PP_FIRST, -1 being none
    if (i >= PP_FIRST) {
        iName = PPLIDX(i);
    } else {
        iName = -1;
    }
}
void wait_for_key_release() {
    kscanfast(0);
    while (KSCAN_KEY != 0xff) {
        kscanfast(0);
    }
}

// F18A specific setup
// safer to do this in each app than hope it's still initialized
void setupgpu() {
    // This is now exactly 128 bytes - to extend we need to reserve more space
    static const unsigned char GPUPROG[] = {
        0x04,0xc0,0xd0,0x20,0x70,0x00,0x02,0x80,
        0xff,0x00,0x16,0x05,0x02,0x00,0x01,0x00,
        0xd8,0x00,0x60,0x18,0x10,0xf5,0x02,0x80,
        0x7e,0x00,0x16,0x04,0x04,0xc0,0xd8,0x00,
        0x60,0x18,0x10,0xee,
        0xd0,0x20,0x39,0x00,0x13,0xeb,0x02,0x80,
        0x01,0x00,0x16,0x0b,0x02,0x00,0x10,0x00,
        0x02,0x01,0x50,0x20,0x02,0x02,0x00,0x08,
        0xcc,0x70,0xcc,0x70,0x06,0x02,0x16,0xfc,
        0x10,0x10,0x02,0x80,0x02,0x00,0x16,0x10,
        0x02,0x04,0xff,0xff,0x02,0x00,0x10,0x00,
        0x02,0x01,0x50,0x20,0x02,0x02,0x00,0x10,
        0xc0,0xf0,0x61,0x03,0xcc,0x44,0x06,0x02,
        0x16,0xfb,0x04,0xe0,0x39,0x00,0x10,0xca,
        0x02,0x80,0x03,0x00,0x16,0xc7,0x02,0x00,
        0x50,0x00,0x02,0x01,0x50,0x20,0x02,0x02,
        0x00,0x08,0x10,0xde
    };

    // if we don't put something valid into VDPR1, we'll hang forever waiting
    // for the VDP to tell us about end of frame. 0xe0 is the default, and if
    // we turn off 0x40, we can blank the display. On return bitmap is set up.
    VDP_SET_REGISTER(VDP_REG_MODE1, 0xa0);

    black_image();
    vdpmemcpy(0x3880, GPUPROG, sizeof(GPUPROG));
    
    // for the basics, load the same palette in 1 as well as what's expected in 0
    loadpal_f18a(&F18A_INITIAL[0], 0, 16);
    loadpal_f18a(&F18A_INITIAL[0], 16, 16);
    
    // now it's safe to start
    startgpu_f18a(0x3880);

    // brief pause in case of Classic99
    VDP_WAIT_VBLANK_CRU;
    VDP_CLEAR_VBLANK;
    VDP_WAIT_VBLANK_CRU;
    VDP_CLEAR_VBLANK;

    // set normal palette in 1
    normal_image();
}

#ifdef LOCATION_IS_LOADER

// only the loader needs this - we'll store the result in the VDP savedata
void checkSams() {
    // The CRT0 should have already done the sizing, we just need to ensure we got enough
    // *** TODO *** return true if there is at least ????k
    // how much do we need for the samples?
    // there are 9 samples, each is a bit over a second, so
    // lets say we need 20s worth of samples. At 8khz sampling,
    // 4 bit is 4000 bytes per second, so 20,000 bytes. That
    // means even the 128k AMS is adequate. Note the code in CRT maxes out at 1MB
    if (ams < 32) {
        ams = 0;
    }
}

#endif

//------
#ifdef CLASSIC99
extern "C" void debug_write(char *s, ...);
#else
#define debug_write(...) ((void)0)
#endif

int main()
{
    debug_write("Starting up...");
    files(1);
    stop_music();  // makes sure pSong is zeroed out

#ifdef CLASSIC99
    vgm_pcinit();
#endif

    // I'm not sure why this screws up, but to keep the order sane
    // this is an EXTRA restore call so that load_voices knows whether
    // we have AMS or not. We then do the early F18A detect and restore again
    // in the regular place
#ifndef LOCATION_IS_LOADER
#ifndef CLASSIC99
    // clasic99 build never ran the loader, it goes direct, so keep the f18a setting (never has AMS)
    // restore the data from VDP
    restore_saved_data();
#endif
    load_voices();
    load_music();
#endif

    // detect F18A for graphics (corrupts VDP registers)
    f18a = detect_f18a();
    if (f18a) {
        debug_write("F18A enabled");
    }

#if LOCATION_IS_LOADER
    checkSams();
    memset(evidence_found, 0, EV_MAX_STORED_EV*sizeof(evidence_found[0]));
    memset(people_found, 0, PP_MAX*sizeof(people_found[0]));
    add_inventory(EV_BADGE);
    add_inventory(EV_MAGATAMA);
    add_inventory(PP_PHOENIX);

    // setup bitmap mode
    bitmap_screen();
    vdpwriteinc(gImage, 0, 768);

    // load the full screen title page
    load_title();

    // wait for keypress
    wait_for_key_release();
    while (KSCAN_KEY == 0xff) {
        kscanfast(0);
    }

    // text mode, load charset
    VDP_SET_REGISTER(VDP_REG_MODE1, VDP_MODE1_16K|VDP_MODE1_INT);
    if (f18a) {
        setupgpu();     // load the program and default palette
        fixed_image();  // fix F18A palette
    }
    set_graphics(0);
    vdpmemset(gImage, ' ', 768);
    vdpmemset(gColor, 0xe0, 32);
    charsetlc();

    gotoxy(0,0);
    //     01234567890123456789012345678901
    cputs("Phoenix Wright / My Little Pony\n");
    cputs("- Turnabout Storm\n\n");
    cputs("Original video by PWaaMLPfim\n");
    cputs("https://youtu.be/yUDfoZGhLjE\n\n");
    cputs("Title image by HowXu\n");
    cputs("https://www.deviantart.com/\n");
    cputs("howxu/art/Phoenix-Wright-MLP-\n");
    cputs("FIM-turnabout-storm-304455701\n\n");
    cputs("This game is running LIVE over\n");
    cputs("the internet and is a work in\n");
    cputs("progress! Currently I have\n");
    cputs("implemented 16 scenes which is\n");
    cputs("about 25% of the total script.\n\n");
    // to get the percentage I'm looking at the last timestamp, and dividing it by about 6 hrs

    // some hardware info
    cprintfmini("SAMS detected: %d pages\n", ams);
    cprintfmini("F18A detected: %s\n\n", f18a?"yes":"no");

    // wait for acknowledgement
    cputs("Press any key...");
    wait_for_key_release();
    while (KSCAN_KEY == 0xff) {
        kscanfast(0);
    }

    // will return with selection in KSCAN_KEY
repeataid:
    run_aid(0);
    store_saved_data(); // makes it easier to test if I set up VDP on any key

    // load VDP if requested, then jump to the saved chapter (from 0x3b00)
    int nextloc = 0;
    store_saved_data();
    if (KSCAN_KEY == '2') {
        // load file
        if (!loadgame()) {
            goto repeataid;
        }
        VDP_SET_ADDRESS(SAVE_GAME_VDP + 32);
        nextloc = VDPRD() << 8;
        nextloc |= VDPRD();
    }
     
#else
#ifndef CLASSIC99
    // clasic99 build never ran the loader, it goes direct, so keep the f18a setting (never has AMS)
    // restore the data from VDP
    restore_saved_data();
#endif

    if (f18a) {
        setupgpu();     // load the program and default palette
        fixed_image();  // fix F18A palette
    }

    // hack the character set into the third page before we set bitmap
    // we load it twice so that we can have two colors
    gPattern = 0x1000;
    charsetlc();
    gPattern = 0x1400;
    charsetlc();

    // now set up bitmap mode
    // set top 2/3rds for image, bottom third for text (grey on black)
    bitmap_screen();
    vdpwriteinc(gImage, 0, 512);
    vdpmemset(gImage+16*32, ' ', 8*32);
    // normal text is grey, high bit text is blue
    vdpmemset(gColor+0x1000, 0xe1, 0x400);
    vdpmemset(gColor+0x1400, 0x41, 0x400);
    black_image();

#ifdef LAST_LOCATION
    // no story on last location - this should make the save file record the right location
    run_aid(1);
    // just for build (and if we somehow return)
    int nextloc = LOCATION_NUMBER;
#else
    // start it up!
    int nextloc = run_story();
#endif

#endif

    // load the next section in nextloc...
    // save the current state before we load
    MUTE_SOUND();

    store_saved_data();

    // set up a text mode screen for the loader
    fixed_image();  // fix F18A palette
    if (f18a) {
        reset_f18a();   // turn off GPU program
    }
    my_set_text();  // text mode has fewest requirements
    charsetlc();
    vdpmemset(gImage, ' ', 40*24);
    gotoxy(0,0);
    cputs("Loading...");

    // location index is in nextloc - need to patch the filename
    // The filename is hard coded in the EA5LD assembly, so we
    // need to assume the length! It's 43 chars long:
    // "PI.HTTPS://harmlesslion.com/phoenix/PLOCxx1"
    // loader hard coded to load at VDP >2000 with PABs at VDP >2A00
    // Scratchpad loader must exist higher than >C000 in order for
    // it not to overwrite itself on the first load.
#ifndef CLASSIC99
    FILENAME[39] = (nextloc/10)+'0';
    FILENAME[40] = (nextloc%10)+'0';
    EA5LD();
#endif

    // TODO: we can't return - scratchpad loader is one way. How
    // can we verify the load works before committing? (Actually, it does return sometimes?!
    // Eh, this is last ditch effect to save the user's progress. it's fine.)
    // if we return, the load must have failed to find the first file (later files will just reboot)
    // aid will say we're at the end and at least allow a save
    run_aid(1);
}

// this is music code, but music.o is stored in paged memory, so we need wrappers to be able to call them
// REMEMBER WE NEED TO BE LOADED LOWER THAN >E000 IN RAM!

// this will make sure all needed music is loaded, same as the samples do
void load_music() {
    if (ams == 0) return;

    samsMapPage(MUSIC_PAGE, MUSIC_ADDR);
    samsMapOn();
    load_music_banked();
    restoreSamsMap();
}

void play_music(int music) {
    if (ams == 0) return;
    if (mute) return;

    samsMapPage(MUSIC_PAGE, MUSIC_ADDR);
    samsMapOn();
    play_music_banked(music);
    restoreSamsMap();
}

// this one probably doesn't NEED to be banked, but we'll stay consistent
void stop_music() {
    if (ams == 0) return;

    samsMapPage(MUSIC_PAGE, MUSIC_ADDR);
    samsMapOn();
    stop_music_banked();
    restoreSamsMap();
}

void update_music() {
    if (ams == 0) return;

    samsMapPage(MUSIC_PAGE, MUSIC_ADDR);
    samsMapOn();
    update_music_banked();
    restoreSamsMap();
}

// a hacky wrapper to try failed accesses a second time, since
// web access occasionally fails. Will mean save file access is
// a little slower if it fails, but that's worth it.
unsigned char wrap_dsrlnk(struct PAB *pab, unsigned int vdp) {
    unsigned char ret = dsrlnk(pab, vdp);
    if (ret) {
        ret = dsrlnk(pab, vdp);
    }
    return ret;
}

// Intermediate data is saved in VDP RAM between programs.
//
// VDP MAP:
//
// 0000-0FFF - bitmap pattern table (top) - F18A palette loads 32 bytes after this
// 1000-17FF - bottom third character set - first 4 chars (32 bytes) overwritten in F18A mode
// 1800-19FF - bitmap SIT
// 1A80-1A9F - text screen color table
// 1AA0-1AFF - (60 bytes free)
// 1B00-1B7F - Sprite attribute list
// 1B80-1B9F - help screen color table
// 1BA0-1BFF - (60 bytes free)
// 1C00-1EFF - Text screen SIT
// 1F00-1FFF - (256 bytes free)
// 2000-2FFF - bitmap color table (top)
// 3000-37FF - bottom third color table
// 3800-387F - PAB space
// 3880-38FF - F18A GPU code
// 3900-390F - F18A GPU interface
// 3910-39FF - (240 bytes free)
// 3A00-3AFF - game data for between programs (see savegame.h)
// 3B00-3BE3 - (228 bytes free)
// 3BE4-3FFF - DSR Buffers FILES(1)
