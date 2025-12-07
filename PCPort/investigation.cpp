// investigation is the most different - load up the location map and
// let the user use a sprite to select an area on it. Divide the screen
// into 8 grid locations and handle evidence in each as defined. MOVE
// is an option to check out other locations. 
// We will probably need to figure out how to define the exit condition.

#include <vdp.h>
#include <kscan.h>
#include <conio.h>
#include <sound.h>
#include "engine.h"
#include "investigate.h"
#include "music.h"
#include "inventory.h"
#include "aid.h"

#ifdef LOCATION_TYPE_INVESTIGATION

// just the hollow box, the solid we can just memset
const unsigned char spritepats[] = {
    0xff,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
    0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xff,
    0xff,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xff
};
// the arrow patterns (takes less mem to redefine them than copy them - 7 bytes each)
const unsigned char arrowleft[] = {
    0x08,0x10,0x20,0x40,0x20,0x10,0x08
};
const unsigned char arrowright[] = {
    0x20,0x10,0x08,0x04,0x08,0x10,0x20
};

// some audio for non-sighted players
int audiofeedback(unsigned char x, unsigned char y) {
    if (readerFlag) {
        unsigned char pat[8];
        // feedback position
        SOUND(0xaf); SOUND(x>>3); SOUND(0xbf - (y>>3));

        // under cursor feedback - just grab a cell near the center
        // we are 32x32, that's 4 cells each way
        x+=20;  // 16+4 for rounding to 8 pixel cell
        y+=20;
        x>>=3;  // divide by 8
        y>>=3;
        unsigned char c = vdpreadchar(gImage+(y<<5)+x); // get char
        vdpmemread(gColor+(c<<3)+((y>>3)*0x800), pat, 8);
        // add up the 4 bit colors
        int total = 0;
        for (int i=0; i<8; ++i) {
            total+=(pat[i]>>4)+(pat[i]&0xf);
        }
        // value from 0-256 (or 240, really).
        SOUND(0xcf); SOUND(total&0xff); SOUND(0xd0);

        return 3;
    }

    return 0;
}

int investigate(int panning) {
    // our sprite will be 32x32, start roughly centered
    unsigned char x = 112;
    unsigned char y = 48;
    int ret = 0;

    // turn off all sprites (overwrite first four)
    vdpmemset(gSprite, 0xd0, 16);

    // define two sprite patterns - a hollow square and a filled one
    // can't use patterns 0-3 - they contain the F18A pattern (32 bytes)
    vdpmemcpy(gSpritePat+32, spritepats, 32);   // pattern 4-7
    vdpmemset(gSpritePat+64, 0xff, 32);         // pattern 8-11
    vdpmemset(gSpritePat+96, 0x00, 64);         // zero out patterns 12-19
    vdpmemcpy(gSpritePat+96+4, arrowleft, 7);   // pattern 12-15 = '<'
    vdpmemcpy(gSpritePat+128+4, arrowright, 7); // pattern 16-19= '>'

    // set sprite size to double-size magnified
    // We know we're in bitmap already, so VDP R1 should be 0xE0, and we want 0xE3
    VDP_SET_REGISTER(1, 0xe3);

    if (readerFlag) {
        fastputwordwrap(0, 17, "Volume represents altitude, pitch represents left to right. Use 7 if you need to mute music.", 32*7);
        if ((panning == EV_T_ILEFTOK) || (panning == EV_T_IBOTHOK)) {
            cputsxy(0,20,"Press comma to pan left");
        }
        if ((panning == EV_T_IRIGHTOK) || (panning == EV_T_IBOTHOK)) {
            cputsxy(0,21,"Press period to pan right");
        }
    }

    // remember to allow AID and INVENTORY
    int audiotimeout = 0;
    for (;;) {
        music_delay();
        if (readerFlag) {
            if (audiotimeout) {
                --audiotimeout;
                if (audiotimeout == 0) {
                    SOUND(0xbf); SOUND(0xdf);
                }
            }
        }

        // a little wasteful to write the whole sprite table every frame, but that's okay
        sprite(0, 4, COLOR_MEDGREEN, y, x);
        if ((panning == EV_T_ILEFTOK) || (panning == EV_T_IBOTHOK)) {
            sprite(1, 12, COLOR_LTBLUE, 48, 0);
        } else {
            vdpchar(gSprite+4,0xd1);
        }
        if ((panning == EV_T_IRIGHTOK) || (panning == EV_T_IBOTHOK)) {
            sprite(2, 16, COLOR_LTBLUE, 48, 256-16);
        } else {
            vdpchar(gSprite+8, 0xd1);
        }

        kscanfast(0);
        unsigned char ch = KSCAN_KEY;
        if (ch == 0xff) {
            // try joystick for emulator
            joystfast(1);
            if (KSCAN_JOYY == JOY_UP) ch='E';
            else if (KSCAN_JOYY == JOY_DOWN) ch='X';
            else if (KSCAN_JOYX == JOY_LEFT) ch='S';
            else if (KSCAN_JOYX == JOY_RIGHT) ch='D';
            else {
                kscanfast(1);
                if (KSCAN_KEY == JOY_FIRE) {
                    ch=13;
                }
            }
        }

        if ((ch == 'E') && (y > 4)) {
            y-=4;
            audiotimeout = audiofeedback(x,y);
        } else if ((ch == 'X') && (y < 127-32-4)) {
            y+=4;
            audiotimeout = audiofeedback(x,y);
        } else if ((ch == 'S') && (x > 4)) {
            x-=4;
            audiotimeout = audiofeedback(x,y);
        } else if ((ch == 'D') && (x < 256-32-4)) {
            x+=4;
            audiotimeout = audiofeedback(x,y);
        } else if (ch == ',') {
            if ((panning == EV_T_ILEFTOK) || (panning == EV_T_IBOTHOK)) {
                ret = EV_I_SEARCH_LEFT;
                break;
            }
        } else if (ch =='.') {
            if ((panning == EV_T_IRIGHTOK) || (panning == EV_T_IBOTHOK)) {
                ret = EV_I_SEARCH_RIGHT;
                break;
            }
        } else if (ch == 13) {
            break;
        } else if (ch == 'I') {
            run_inventory("Press enter to return to game");
            VDP_SET_REGISTER(1, 0xe3);
            wait_for_key_release();
            continue;
        } else if (ch == '7') {
            // fctn-7 for AID
            run_aid(0);
            VDP_SET_REGISTER(1, 0xe3);
            continue;
        }
    }

    if (readerFlag) {
        SOUND(0xbf); SOUND(0xdf);
    }

    if (ret == 0) {
        // do a quick animation blinking the box

        for (int i=0; i<30; ++i) {
            music_delay();

            // a little wasteful to write the whole sprite table every frame, but that's okay
            sprite(0, 8, COLOR_MEDGREEN, y, x);
        }

        // figure out which sector to return
        x=(x+32)/64;
        y=(y+32)/64;
        ret = EV_I_0 + (y*4)+x;
    } else if (ret == EV_I_SEARCH_LEFT) {
        vdpchar(gSprite, 0xd0);

        // we'll use character 31 in both tables
        vdpmemset(gColor+31*8, 0x00, 8);
        vdpmemset(gColor+2048+31*8, 0x00, 8);

        for (int c=31; c>=0; --c) {
            music_delay();
            vchar(0, c, 31, 16);
        }

        // black out and restore the screen image table
        vdpmemset(gColor, 0, 0x1000);
        vdpwriteinc(gImage, 0, 512);

    } else if (ret == EV_I_SEARCH_RIGHT) {
        // do a left to right wipe
        vdpchar(gSprite, 0xd0);

        // we'll use character 0 in both tables
        vdpmemset(gColor, 0x00, 8);
        vdpmemset(gColor+2048, 0x00, 8);

        for (int c=0; c<32; ++c) {
            music_delay();
            vchar(0, c, 0, 16);
        }

        // black out and restore the screen image table
        vdpmemset(gColor, 0, 0x1000);
        vdpwriteinc(gImage, 0, 512);
    }

    vdpchar(gSprite, 0xd0);
    VDP_SET_REGISTER(1, 0xe0);

    return ret;
}

#endif
