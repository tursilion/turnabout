// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Maybe I can break it up with defines, the cross compiler won't have any trouble with that.
// for now I will not worry about the TI versions of functions

// need to save current location and current evidence, and color preferences, in vram
// when loading new files. Need a way to save and reload said preferences to disk so can
// save your game and continue.

// TODO: alter path for pics depending on whether F18A is available, and have F18A loader (16-color palette)
// we can have a small GPU program change the palette for the bottom half - just use two palettes for quick change

#include <conio.h>
#include <string.h>
#include <vdp.h>
#include <files.h>
#include <f18a.h>
#include "structures.h"

extern int run_story();
extern Evidence_t evidence[EV_MAX];
extern Evidence_t people[PP_MAX];

const char *pString = NULL;
const char *pOldString = NULL;
int maxtext = 32*7;
int oldMaxtext = 32*7;
int iName = -1;     // does NOT use PP_FIRST after it's set
int oldName = -2;
int f18a = 0;

struct PAB myPab = {0};

// clear the text window (excluding name)
void clear_text() {
    vdpmemset(gImage+17*32, ' ', 7*32);
}

// more of an update than a draw, per-sae
// Images are loaded directly to video memory, and not in this function
void draw_screen() {
    VDP_WAIT_VBLANK_CRU;

    if (iName != oldName) {
        oldName = iName;
        vdpmemset(gImage+16*32, ' ', 32);
        if (iName >= 0) {
            // we need to OR every character with 0x80 for the color
            unsigned char *p = (unsigned char*)people[iName].name;
            VDP_SET_ADDRESS_WRITE(16*32+gImage);
            while (*p) {
                VDPWD( (*(p++)) | 0x80);
            }
        }
    }
    if ((maxtext != oldMaxtext) || (pString != pOldString))  {
        oldMaxtext = maxtext;
        pOldString = pString;
        if (pString) {
            // draw out the string one character at time with wordwrap
            cputwordwrap(0, 17, pString, maxtext);
        } else {
            // clear the text window
            clear_text();
        }
    }
}

void load_image(int index) {
#define VDP_PAB_ADDRESS 0x3800
    char buf[256];
    int off,tmp;

    // TODO: select a path for F18A or not
    //                     1         2         3         4
    //           0123456789012345678901234567890123456789012345
    strcpy(buf, "PI.HTTPS://harmlesslion.com/phoenix/0000.tiap");
    off = 36;

    // load the index into the string - max 9999
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

    // check PAB
    if (myPab.OpCode == 0) {
        memset(&myPab, 0, sizeof(myPab));
        myPab.OpCode = DSR_LOAD;
        myPab.RecordNumber = 0x1000;    // only 2/3rds of the screen! Rememeber it will fail to load if larger!
    }

    // load patterns
    myPab.VDPBuffer = gPattern;
    myPab.pName = (unsigned char*)buf;
    dsrlnk(&myPab, VDP_PAB_ADDRESS);

    // load colors (+5 cause we added 3 above for the indexes)
    buf[off+5] = 'c';
    myPab.VDPBuffer = gColor;
    dsrlnk(&myPab, VDP_PAB_ADDRESS);
}

void invert_image() {
    // a real invert is too slow, but we can swap the color and pattern tables
    // rather than track it, a separate function can restore them

    // TODO: for F18A, invert the palette instead

    VDP_SET_REGISTER(VDP_REG_CT, 0x7f);
	VDP_SET_REGISTER(VDP_REG_PDT, 0x07);
}

void normal_image() {
    // a real invert is too slow, but we can swap the color and pattern tables
    // rather than track it, a separate function can restore them

    // TODO: For F18A, just call invert again to change the palette

    VDP_SET_REGISTER(VDP_REG_CT, 0xFF);
	VDP_SET_REGISTER(VDP_REG_PDT, 0x03);
}

void black_image() {
    // we'll see if this is just fast enough - black out the color table
    vdpmemset(gColor, 0, 0x1000);
}

//------

void add_inventory(int id) {
    if (id >= PP_FIRST) {
        id = (id-PP_FIRST)>>8;
        people[id].found = 1;
    } else if (id < EV_MAX) {
        evidence[id].found = 1;
    }
}
void remove_inventory(int id) {
    evidence[id].found = 0;
}
void set_text(const char *p) {
    clear_text();
    pString = p;
}
void set_maxlen(int i) {
    maxtext = i;
}
void set_name(int i) {
    // convert into an index, 0 being PP_FIRST, -1 being none
    if (i >= PP_FIRST) {
        iName = (i-PP_FIRST)>>8;
    } else {
        iName = -1;
    }
}

// F18A specific setup
void setupgpu() {
    // TODO: load a GPU program to set palette 1 at top of frame
    // and palette 0 at scanline 128
    // We should already have a TI compatible palette in palette 0

}

//------
extern "C" void debug_write(char *s, ...);
int main()
{
    debug_write("Starting up...");
    files(1);

    // detect F18A for graphics
    f18a = detect_f18a();
    if (f18a) {
        debug_write("F18A enabled");
        setupgpu();
    }

    // hack the character set into the third page before we set bitmap
    // we load it twice so that we can have two colors
    gPattern = 0x1000;
    charsetlc();
    gPattern = 0x1400;
    charsetlc();

    // now set up bitmap mode
    // set top 2/3rds for image, bottom third for text (grey on black)
    set_bitmap(0);
    vdpwriteinc(gImage, 0, 512);
    vdpmemset(gImage+16*32, ' ', 8*32);
    // normal text is grey, high bit text is blue
    vdpmemset(gColor+0x1000, 0xe1, 0x400);
    vdpmemset(gColor+0x1400, 0x51, 0x400);

    // start it up!
    int nextloc = run_story();



}

// TODO: a boot program that serves as the entrance to the game, and
// lets you load a save or start a new game.
//
// We might cheap out and save by password... or just offer the ability
// to save the password AND display it on the screen? Can we use TIPI netvars?
//
// that program could also offer to disable F18A if detected
//
// Intermediate data is saved in VDP RAM between programs.
//
// VDP MAP:
//
// 0000-0FFF - bitmap pattern table (top)
// 1000-17FF - bottom third character set
// 1800-19FF - bitmap SIT
// 1B00-1A7F - sprite attribute list
// 1B80-1A9F - Text screen color table
// 1BA0-1BFF - 
// 1C00-1EFF - Text screen SIT
// 1F00-1FFF -
// 2000-2FFF - bitmap color table (top)
// 3000-37FF - bottom third color table
// 3800-387F - PAB space
// 3880-3BE3 - game data for between programs
// 3BE4-3FFF - DSR Buffers FILES(1)


