// display keyboard help - full screen like inventory

#include "structures.h"
#include "engine.h"
#include "savegame.h"
#include "music.h"
#include <conio.h>
#include <kscan.h>
#include <vdp.h>
#include <f18a.h>
#include <system.h>

// reference for diagnostics
extern int f18a, ams;

// display the help keys, then return
// can we fit them all on screen? Or should we take in which help to show?
void run_aid() {
    // based on set_graphics, but different map and we don't touch the sprite table
    scrn_scroll = scrn_scroll_default;

    // this mode can exist without corrupting the bitmap screens
    unsigned char reg1 = VDP_MODE1_16K | VDP_MODE1_UNBLANK | VDP_MODE1_INT | 0;
	VDP_SET_REGISTER(VDP_REG_MODE1, reg1);
    VDP_REG1_KSCAN_MIRROR = reg1;
	VDP_SET_REGISTER(VDP_REG_MODE0, 0);
	VDP_SET_REGISTER(VDP_REG_SIT, 7);	gImage = 0x1C00;
	VDP_SET_REGISTER(VDP_REG_CT, 110);	gColor = 0x1b80;
	VDP_SET_REGISTER(VDP_REG_PDT, 2);	gPattern = 0x1000;
    // leaving sprites at bitmap default of 0x1b00 and sprite patterns at 0x1800
    // text information is the same too, except for the flags
	nTextFlags = TEXT_WIDTH_32;
    fixed_image();  // fix F18A palette
    vdpchar(gSprite, 0xd0);  // sprites off

    vdpmemset(gImage, ' ', 768);
    vdpmemset(gColor, 0xe0, 32);
    gotoxy(0,0);

    //     01234567890123456789012345678901
    cputs("All scenes:\n\n");
    cputs("N - next text\n");
    cputs("I - inventory screen\n");
    cputs("7 - Help screen (this)\n");
    cputs("SPACE - speed text\n\n");
    cputs("Cross-Examination:\n");
    cputs("P - press for more info\n");
    cputs("O - Object (present evidence)\n\n");
    
    cputs("Press:\n");
    cputs("QUIT to exit\n");
    cputs("Q - Save game/passcode\n");
    cputs("SPACE - return to game\n");

    for (;;) {
        VDP_WAIT_VBLANK_CRU;
        VDP_CLEAR_VBLANK;
        update_music();

        kscanfast(0);
        if (KSCAN_KEY == 'Q') {
            wait_for_key_release();
            savegame();
            continue;
        }
        if (KSCAN_KEY == ' ') {
            wait_for_key_release();
            break;
        }
        if (check_reset()) {
            reset_f18a();
            exit();
        }
    }

    // restore the bitmap screen - we'll just call the bmp function
    bitmap_screen();
    normal_image();
}
