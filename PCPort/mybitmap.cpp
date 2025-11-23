// a clone of libti99 that does not call in scrn_scroll

#ifdef CLASSIC99

extern "C" {
    #include <vdp.h>
    #include <conio.h>

    extern void vsetchar_base(int pAddr, unsigned char ch);
}

#else

#include <vdp.h>
#include <conio.h>
#include "engine.h"

extern void vsetchar_base(int pAddr, unsigned char ch);

#endif

#include "engine.h"

void scroll_nop() { }

void bitmap_screen() {
    // note: no masking, full size bitmap mode
    scrn_scroll = scroll_nop;

	unsigned char unblank = VDP_MODE1_16K | VDP_MODE1_UNBLANK | VDP_MODE1_INT;  // sprite mode of 0
	VDP_SET_REGISTER(VDP_REG_MODE1, unblank);		// no need to OR in the sprite mode for now
	// because we blanked the display, we don't have to worry about VDP timing for the rest of this
	VDP_SET_REGISTER(VDP_REG_MODE0, VDP_MODE0_BITMAP);
	VDP_SET_REGISTER(VDP_REG_SIT, 0x06);	gImage = 0x1800;
	VDP_SET_REGISTER(VDP_REG_CT,  0xFF);	gColor = 0x2000;
	VDP_SET_REGISTER(VDP_REG_PDT, 0x03);	gPattern = 0x0000;
	VDP_SET_REGISTER(VDP_REG_SAL, 0x36);	gSprite = 0x1B00;	vdpchar(gSprite, 0xd0);
	VDP_SET_REGISTER(VDP_REG_SDT, 0x02);	gSpritePat = 0x1000;    // not the same as libti99
	nTextRow = 736;
	nTextEnd = 767;
	nTextPos = nTextRow;
	nTextFlags = TEXT_FLAG_IS_BITMAPPED | TEXT_FLAG_HAS_ATTRIBUTES | TEXT_WIDTH_32;
	vsetchar = vsetchar_base;

    VDP_REG1_KSCAN_MIRROR = unblank;
}

void my_set_text() {
	unsigned char unblank = VDP_MODE1_16K | VDP_MODE1_UNBLANK | VDP_MODE1_TEXT | VDP_MODE1_INT;

    scrn_scroll = scroll_nop;
	
	VDP_SET_REGISTER(VDP_REG_MODE1, unblank);
	// because we blanked the display, we don't have to worry about VDP timing for the rest of this
	VDP_SET_REGISTER(VDP_REG_MODE0, 0);
	VDP_SET_REGISTER(VDP_REG_SIT, 10);	gImage = 0x2800;
	VDP_SET_REGISTER(VDP_REG_PDT, 4);	gPattern = 0x2000;
    VDP_SET_REGISTER(VDP_REG_COL, (COLOR_GRAY<<4)|COLOR_BLACK);

	// no sprites and no color in text mode anyway - values undefined
	nTextRow = 23*40;
	nTextEnd = 23*40+39;
	nTextPos = nTextRow;
	nTextFlags = TEXT_WIDTH_40;
	vsetchar = vsetchar_base;

    VDP_REG1_KSCAN_MIRROR = unblank;
}

// set an alternate text mode that doesn't conflict with the bitmap
// used by inventory and aid
void set_alt_text() {
    // based on set_graphics, but different map and we don't touch the sprite table
    scrn_scroll = scroll_nop;

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
    vdpmemset(gColor, 0xe0, 16);        // grey
    vdpmemset(gColor+16, 0x40, 16);     // blue
    gotoxy(0,0);
}

