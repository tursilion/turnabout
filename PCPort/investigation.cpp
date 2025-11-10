// investigation is the most different - load up the location map and
// let the user use a sprite to select an area on it. Divide the screen
// into 8 grid locations and handle evidence in each as defined. MOVE
// is an option to check out other locations. 
// We will probably need to figure out how to define the exit condition.

#include <vdp.h>
#include <kscan.h>
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

int investigate(int panning) {
    // our sprite will be 32x32, start roughly centered
    unsigned char x = 112;
    unsigned char y = 48;
    int ret = 0;
    unsigned char cpybuf[8];    // used to copy some sprite patterns

    // turn off all sprites (overwrite first four)
    vdpmemset(gSprite, 0xd0, 16);

    // define two sprite patterns - a hollow square and a filled one
    // can't use patterns 0-3 - they contain the F18A pattern (32 bytes)
    vdpmemcpy(gSpritePat+32, spritepats, 32);   // pattern 4-7
    vdpmemset(gSpritePat+64, 0xff, 32);         // pattern 8-11
    vdpmemset(gSpritePat+96, 0x00, 64);         // zero out patterns 12-19
    vdpmemread(gPattern+0x1000+'<'*8, cpybuf, 8);
    vdpmemcpy(gSpritePat+96+4, cpybuf, 8);      // pattern 12-15 = '<'
    vdpmemread(gPattern+0x1000+'>'*8, cpybuf, 8);
    vdpmemcpy(gSpritePat+128+4, cpybuf, 8);     // pattern 16-19= '>'

    // set sprite size to double-size magnified
    // We know we're in bitmap already, so VDP R1 should be 0xE0, and we want 0xE3
    VDP_SET_REGISTER(1, 0xe3);

    // remember to allow AID and INVENTORY
    for (;;) {
        VDP_WAIT_VBLANK_CRU;
        VDP_CLEAR_VBLANK;
        update_music();

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

        // DEBUG code - emit sector
        {
            int x2=(x+32)/64;
            int y2=(y+32)/64;
            vdpchar(23*32,'0'+(y2*4)+x2);
        }

        kscanfast(0);
        unsigned char ch = KSCAN_KEY;

        if ((ch == 'E') && (y > 4)) {
            y-=4;
        } else if ((ch == 'X') && (y < 127-32-4)) {
            y+=4;
        } else if ((ch == 'S') && (x > 4)) {
            x-=4;
        } else if ((ch == 'D') && (x < 256-32-4)) {
            x+=4;
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
            continue;
        } else if (ch == '7') {
            // fctn-7 for AID
            run_aid(0);
            continue;
        } else {
            joystfast(1);
            if ((KSCAN_JOYY == JOY_UP) && (y > 4)) {
                y-=4;
            } else if ((KSCAN_JOYY == JOY_DOWN) && (y < 127-32-4)) {
                y+=4;
            } else if ((KSCAN_JOYX == JOY_LEFT) && (x > 4)) {
                x-=4;
            } else if ((KSCAN_JOYX == JOY_RIGHT) && (x < 256-32-4)) {
                x+=4;
            } else {
                kscan(1);
                if (KSCAN_KEY == JOY_FIRE) {
                    break;
                }
            }
        }
    }

    if (ret == 0) {
        // do a quick animation blinking the box

        for (int i=0; i<30; ++i) {
            VDP_WAIT_VBLANK_CRU;
            VDP_CLEAR_VBLANK;
            update_music();

            // a little wasteful to write the whole sprite table every frame, but that's okay
            sprite(0, 8, COLOR_MEDGREEN, y, x);
        }

        // figure out which sector to return
        x=(x+32)/64;
        y=(y+32)/64;
        ret = EV_I_0 + (y*4)+x;
    } else if (ret == EV_I_SEARCH_LEFT) {
        // do a right to left wipe
        vdpchar(gSprite, 0xd0);

        // we'll use character 31 in both tables
        vdpmemset(gColor+31*8, 0x00, 8);
        vdpmemset(gColor+2048+31*8, 0x00, 8);

        for (int c=31; c>=0; --c) {
            VDP_WAIT_VBLANK_CRU;
            VDP_CLEAR_VBLANK;
            update_music();

            vchar(0, c, 31, 16);
        }

    } else if (ret == EV_I_SEARCH_RIGHT) {
        // do a left to right wipe
        vdpchar(gSprite, 0xd0);

        // we'll use character 0 in both tables
        vdpmemset(gColor, 0x00, 8);
        vdpmemset(gColor+2048, 0x00, 8);

        for (int c=0; c<32; ++c) {
            VDP_WAIT_VBLANK_CRU;
            VDP_CLEAR_VBLANK;
            update_music();

            vchar(0, c, 0, 16);
        }
    }

    // on return, return sprite size to single-size non-magnified
    vdpchar(gSprite, 0xd0);
    VDP_SET_REGISTER(1, 0xe0);

    return ret;
}

#endif
