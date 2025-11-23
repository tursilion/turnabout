#include <conio.h>
#include <files.h>
#include <string.h>
#include <kscan.h>
#include <vdp.h>
#include "structures.h"
#include "savegame.h"
#include "music.h"
#include "engine.h"

// static variables
static struct PAB myPab = { 0 };
static char myFilename[16] = "";

// externs
extern int evidence_found[EV_MAX_STORED_EV];
extern int people_found[PP_MAX];
extern int f18a;
extern int ams;
extern int mute;

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
    mute=VDPRD();
    f18a=VDPRD();
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
    set_default_data();

    vdpmemcpy(SAVE_GAME_VDP, (unsigned char*)&myPab, 10);
    vdpmemcpy(SAVE_GAME_VDP+10, (unsigned char*)myFilename, 15);

    VDP_SET_ADDRESS_WRITE(SAVE_GAME_VDP+32);
    VDPWD(LOCATION_NUMBER>>8);
    VDPWD(LOCATION_NUMBER);
    VDPWD(mute&0xff);
    VDPWD(f18a&0xff);
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
    cprintfmini("Filename: %s", myFilename);
    wait_for_key_release();

    // a rudimentary text editor to edit the filename (max length 15 - path+10 char filename)
    // not going to use kbhit and cgetc here, too slow. Am going to use full kscan to get arrows and back
    // read until enter pressed
    off = 5;
    while (KSCAN_KEY != 13) {
        // wait for key release, but keep playing music
        while (KSCAN_KEY != 0xff) {
            kscan(5);
            music_delay();
        }

        // display cursor
        vdpchar(gImage+23*32+10+off, 30);

        // check input
        kscan(5);
        unsigned char x = KSCAN_KEY;
        if (x == 0xff) {
            music_delay();
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
        if (myFilename[i]==' ') {
            myFilename[i] = '\0';
        } else if ((i > 0) && (myFilename[i-1] == '\0')) {
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
        gotoxy(0, 22);
        cprintfmini("DSR Error %d", err);
        wait_for_key_release();
    }

    vdpmemset(gImage+23*32, ' ', 32);
    gotoxy(0,23);
    cputs("Save ok!");
}

// only the loader needs to loadgame
#ifdef LOCATION_IS_LOADER

// assumes we are already in a text compatible mode, and that the last line is free to use
// returns 1 on load, 0 if cancelled
int loadgame() {
    // we need to preserve the hardware settings, but
    // they are saved cause that's also how they move
    // from program to program
    int oldF18 = f18a;
    int oldams = ams;

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
            return 0;
        }

        // yes, we store the PAB at the same VDP RAM we are loading - this should be okay
        // as the loaded data should contain essentially the same PAB
        err = dsrlnk(&myPab, SAVE_GAME_VDP);
        if (DSR_ERR_NONE == err) {
            break;
        }
        gotoxy(0, 22);
        cprintfmini("DSR Error %d", err);
        wait_for_key_release();
    }

    // load it back into the variables, except for the location which isn't a variable
    restore_saved_data();

    // check if upgrades are needed
    if (!has_inventory(EV_I_REVISION1)) {
        // upgrade from zero to rev 1 - inserted everfree forest after EQ500
        // so shift all evidence up and insert it (even if you didn't get there yet, that's okay)
        for (int i=EV_MAX_STORED_EV-2; i>=EV_EVERFREE; --i) {
            evidence_found[i+1]=evidence_found[i];
        }
        evidence_found[EV_EVERFREE] = 1;
        evidence_found[EV_I_REVISION1] = 1;
    }

    // restore the hardware
    ams = oldams;
    f18a = oldF18;

    // report success!
    vdpmemset(gImage+23*32, ' ', 32);
    gotoxy(0,23);
    cputs("Load ok!");

    return 1;
}

#endif
