// display keyboard help - full screen like inventory

#include "structures.h"
#include "engine.h"
#include "savegame.h"
#include <conio.h>
#include <vdp.h>
#include <f18a.h>
#include <system.h>

// display the help keys, then return
// can we fit them all on screen? Or should we take in which help to show?
void run_aid() {
    // just a text display - so need a custom draw function

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

    clrscr();
    vdpmemset(gColor, 0xe0, 32);
    gotoxy(0,0);

    //     01234567890123456789012345678901
    cputs("All scenes:\n\n");
    cputs("N - next text\n");
    cputs("I - inventory screen\n");
    cputs("7 - Help screen (this)\n");
    cputs("SPACE - speed text\n\n");
    cputs("Investigation/Menus:\n");
    cputs("ESDX - Navigate\n");
    cputs("Enter - select\n\n");
    cputs("Cross-Examination:\n");
    cputs("P - press for more info\n");
    cputs("O - Object (present evidence)\n\n");
    
    cputs("Press:\n");
    cputs("QUIT to exit\n");
    cputs("Q - Save game/passcode\n");
    cputs("SPACE - return to game\n");

    for (;;) {
        if (kbhit()) {
            unsigned char x = cgetc();
            if (x == 'Q') {
                savegame();
                continue;
            }
            if (x == ' ') {
                break;
            }
            if (check_reset()) {
                reset_f18a();
                exit();
            }
        }
        VDP_WAIT_VBLANK_CRU;
    }

    // restore the bitmap screen - we'll just call the bmp function
    set_bitmap(0);
}
