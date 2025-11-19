// display keyboard help - full screen like inventory

#include "structures.h"
#include "engine.h"
#include "savegame.h"
#include "music.h"
#include "aid.h"
#include <conio.h>
#include <kscan.h>
#include <vdp.h>
#include <f18a.h>
#include <system.h>

// reference for diagnostics
extern int f18a, ams;
extern int mute;
extern void reset_last_img();
extern void setupgpu();

// display the help keys, then return
// can we fit them all on screen? Or should we take in which help to show?
void run_aid(int isFinal) {

#ifndef LOCATION_IS_LOADER
    set_alt_text();
#else
    // LOADER is already in text, but do some inline anyway
    vdpmemset(gColor, 0xe0, 16);        // grey
    vdpmemset(gColor+16, 0x40, 16);     // blue
#endif

redraw:
    vdpmemset(gImage, ' ', 768);
    gotoxy(0,0);

    if (isFinal) {
        //     01234567890123456789012345678901
        cputs("You have reached the end for\n");
        cputs("now. You can save your game.\n\n");
    } else {
        //     01234567890123456789012345678901
        cputs("All scenes:\n\n");
        cputs("N - Next text\n");
        cputs("I - Inventory screen\n");
        cputs("R - Reload image\n");
        cputs("7 - Help and save screen (this)\n");
        cputs("SPACE - speed text\n\n");
        cputs("Cross-Examination:\n");
        cputs("P - Press for more info\n");
        cputs("O - Object (present evidence)\n\n");
        cputs("M - toggle music. Current: ");
        if (mute) cputs("Off\n\n"); else cputs("On\n\n");
    }
    
    wait_for_key_release();

#ifdef LOCATION_IS_LOADER
    // ask player if they want to load or start a new game
    // TODO: passwords too in the future? show them on AID screen?
    cputs("Do you want to:\n\n");
    cputs("1 Start a new game\n");
    cputs("2 Load a saved game\n");
    wait_for_key_release();

    for (;;) {
        kscanfast(0);
        unsigned char x = KSCAN_KEY;
        if ((x == '1') || (x == '2')) break;
        if (x == 'M') {
            mute = !mute;
            goto redraw;
        }
    }

#else
    cputs("Press:\n");
    cputs(" QUIT to exit\n");
    cputs(" S - Save game\n");
    if (!isFinal) {
        cputs(" SPACE - return to game\n");
    }

    for (;;) {
        VDP_WAIT_VBLANK_CRU;
        VDP_CLEAR_VBLANK;
        update_music();

        kscanfast(0);
        unsigned char x = KSCAN_KEY;
        if (x == 'S') {
            wait_for_key_release();
            savegame();
            continue;
        }
        if (!isFinal) {
            if (x == ' ') {
                wait_for_key_release();
                break;
            }
            if (x == 'M') {
                mute = !mute;
                if (mute) {
                    stop_music();
                }
                goto redraw;
            }
        }
        if (check_reset()) {
            reset_f18a();
            exit();
        }
    }

    // restore the bitmap screen - we'll just call the bmp function
    bitmap_screen();
    normal_image();
#endif

}
