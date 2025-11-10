#include <conio.h>
#include <files.h>
#include <string.h>
#include <kscan.h>
#include <vdp.h>
#include "structures.h"
#include "savegame.h"
#include "music.h"

// static variables
static struct PAB myPab = { 0 };
static char myFilename[16] = "";

// externs
extern int evidence_found[EV_MAX_STORED_EV];
extern int people_found[PP_MAX];
extern int f18a;
extern int ams;

void set_default_data() {
    if (myFilename[0] < ' ') {
        memset(&myPab, 0, sizeof(myPab));
        memset(myFilename, 0, sizeof(myFilename));
        strcpy(myFilename, "DSK1.SAVEFILE");
    }
}

// restore saved data from VDP RAM
void restore_saved_data() {
    // load the save data from VDP
    vdpmemread(SAVE_GAME_VDP, (unsigned char*)&myPab, 10);
    vdpmemread(SAVE_GAME_VDP+10, (unsigned char*)myFilename, 15);
    myFilename[15] = '\0';
    
    // skip location at 32

    VDP_SET_ADDRESS(SAVE_GAME_VDP+34);
    f18a=VDPRD()<<8;
    f18a|=VDPRD();
    ams=VDPRD()<<8;
    ams|=VDPRD();

    for (unsigned int i=0; i<EV_MAX_STORED_EV; ++i) {
        // EV_MAX_STORED_EV can not be larger than 64!
        evidence_found[i]=VDPRD()<<8;
        evidence_found[i]|=VDPRD();
    }

    // skip ahead to the people, we don't necessarily fill all 64 slots
    VDP_SET_ADDRESS(SAVE_GAME_VDP+166);
    for (unsigned int i=0; i<PP_MAX; ++i) {
        // PP_MAX can not be larger than 16
        people_found[i]=VDPRD()<<8;
        people_found[i]|=VDPRD();
    }
}

void store_saved_data() {
    // if we've never set up the savegame PAB, zero the whole mess before we write it, just to be sure
    // TODO: can we manage saving the 'next' scene on final? we have 'nextloc' in the main engine...
    // Or we could just build a dummy 'next' which is nothing BUT the 'you have reached the end' prompt.
    // That would let things like the long investigation not need to be replayed.

    set_default_data();

    vdpmemcpy(SAVE_GAME_VDP, (unsigned char*)&myPab, 10);
    vdpmemcpy(SAVE_GAME_VDP+10, (unsigned char*)myFilename, 15);

    VDP_SET_ADDRESS_WRITE(SAVE_GAME_VDP+32);
    VDPWD(LOCATION_NUMBER>>8);
    VDPWD(LOCATION_NUMBER);
    VDPWD(f18a>>8);
    VDPWD(f18a);
    VDPWD(ams>>8);
    VDPWD(ams);
    for (unsigned int i=0; i<EV_MAX_STORED_EV; ++i) {
        // EV_MAX_STORED_EV can not be larger than 64!
        VDPWD(evidence_found[i]>>8);
        VDPWD(evidence_found[i]);
    }

    // we don't necessarily fill all 64 slots
    VDP_SET_ADDRESS_WRITE(SAVE_GAME_VDP+166);
    for (unsigned int i=0; i<PP_MAX; ++i) {
        // PP_MAX can not be larger than... well, a really big value I didn't bother to work out!
        VDPWD(people_found[i]>>8);
        VDPWD(people_found[i]);
    }
}

// input filename for savegame
// return 0 on normal enter, 1 if back was pressed
static int getfilename() {
    int off;

    // get the filename
    gotoxy(0,23);
    cprintf("Filename: %s", myFilename);

    // a rudimentary text editor to edit the filename (max length 15 - path+10 char filename)
    // not going to use kbhit and cgetc here, too slow. Am going to use full kscan to get arrows and back
    // read until enter pressed
    off = 0;
    while (KSCAN_KEY != 13) {
        // wait for key release, but keep playing music
        while (KSCAN_KEY != 0xff) {
            kscan(5);
            VDP_WAIT_VBLANK_CRU;
            VDP_CLEAR_VBLANK;
            update_music();
        }

        // display cursor
        vdpchar(gImage+23*32+10+off, 30);

        // check input
        kscan(5);
        unsigned char x = KSCAN_KEY;
        if (x == 0xff) {
            VDP_WAIT_VBLANK_CRU;
            VDP_CLEAR_VBLANK;
            update_music();
            continue;
        }
        if (x == 15) {
            // FCTN-9 (back) - just abort and return
            return 1;
        }

        // check editors
        if ((x == 8) && (off > 0)) {
            // left arrow
            // restore character
            if (myFilename[off] < '!') {
                // assuming space or NUL
                vdpchar(gImage+23*32+10+off, ' ');
            } else {
                vdpchar(gImage+23*32+10+off, myFilename[off]);
            }
            --off;
            continue;
        }
        if ((x == 9) && (off < 14)) {
            // right arrow
            if (myFilename[off+1] != '\0') {
                // restore character
                vdpchar(gImage+23*32+10+off, myFilename[off]);
                ++off;
            }
            continue;
        }

        // check text
        if ((x >= ' ') && (x <= 0x7e)) {
            myFilename[off] = x;
            vdpchar(gImage+23*32+10+off, myFilename[off]);
            if (off < 14) {
                ++off;
            }
            continue;
        }
    }
    // walk through myFilename and replace space with NUL
    for (int i=0; i<sizeof(myFilename); ++i) {
        if ((myFilename[i]==' ') || (myFilename[i-1] == '\0')) {
            myFilename[i] = '\0';
        }
    }
    // make sure
    myFilename[sizeof(myFilename)-1] = '\0';

    // normal enter
    return 0;
}

// assumes we are already in a text compatible mode, and that the last line is free to use
void savegame() {
    // if we've never set up the PAB, set it up now
    set_default_data();
    store_saved_data();

    for (;;) {
        unsigned char err;

        // and we're going to set these every time anyway
        myPab.OpCode = DSR_SAVE;
        myPab.RecordNumber = 256;
        myPab.VDPBuffer = SAVE_GAME_VDP;
        myPab.NameLength = 0;
        myPab.pName = (unsigned char*)myFilename;

        if (getfilename()) {
            // skip save
            vdpmemset(gImage+23*32, ' ', 32);
            return;
        }

        // yes, we store the PAB at the same VDP RAM we are saving
        err = dsrlnk(&myPab, SAVE_GAME_VDP);
        if (err == DSR_ERR_NONE) {
            break;
        }
        gotoxy(22, 0);
        cprintf("DSR Error %d", err);
    }

    vdpmemset(gImage+23*32, ' ', 32);
    gotoxy(0,23);
    cputs("Save ok!");
}

// only the loader needs to loadgame
#ifdef LOCATION_IS_LOADER

// assumes we are already in a text compatible mode, and that the last line is free to use
void loadgame() {
    // if we've never set up the PAB, set it up now
    set_default_data();

    for (;;) {
        unsigned char err;

        // and we're going to set these every time anyway
        myPab.OpCode = DSR_LOAD;
        myPab.RecordNumber = 256;
        myPab.VDPBuffer = SAVE_GAME_VDP;
        myPab.NameLength = 0;
        myPab.pName = (unsigned char*)myFilename;

        if (getfilename()) {
            vdpmemset(gImage+23*32, ' ', 32);
            // skip load
            return;
        }

        // yes, we store the PAB at the same VDP RAM we are loading - this should be okay
        // as the loaded data should contain essentially the same PAB
        err = dsrlnk(&myPab, SAVE_GAME_VDP);
        if (DSR_ERR_NONE == err) {
            break;
        }
        gotoxy(22, 0);
        cprintf("DSR Error %d", err);
    }

    // load it back into the variables, except for the location which isn't a variable
    restore_saved_data();
    vdpmemset(gImage+23*32, ' ', 32);
    gotoxy(0,23);
    cputs("Load ok!");
}

#endif
