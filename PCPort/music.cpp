// Music is now stored in AMS (so no music if AMS not available)

// The loader loads the music player for >E000 to page 16
// Songs themselves are loaded to subsequent pages, and mapped at >F000 (but multiple songs may be in one page)
// I'm not using the SBF multi song concept - testing suggests it doesn't save all that much memory anyway
// I'm using the same concept as the voice samples - looking for a tag word to identify that a song
// is loaded. I think I'll use a hard coded tag at the start of each song - I don't even need to
// make it part of the data, I'll make it part of the loader. There's a small chance of random values
// matching, but that was always true anyway.

// So all the songs need to be converted to data files, and I'll need to be able to load and copy them

#include <sound.h>
#include <files.h>
#include <string.h>
#include <vdp.h>
#include "engine.h"
#include "sfx.h"
#include "structures.h"
#include "cache.h"
#include "music.h"
#include "voice.h"    // for voice load settings
#ifdef CLASSIC99
#include "vgmcomp2/CPlayer.h"
#else
#include <TISNPlay.h>
#endif

// needed for the Classic99 wrappers to correctly access memory directly
typedef unsigned short uint16_type;

// these variables are stored in bss, so are in low RAM and always available
// However, the library code is not! Neither is anything in songDatVars!
const unsigned char *pSong;
int musicPage = 0;
int mute = 0;

// we should have enough memory to store a lookup table regardless of used or not... that'll simplify the code a bit
typedef struct {
    unsigned int page;
    unsigned char *pAdr;
} MUSICLOOKUP;

// remember to subtract CMD_MUSSTARTLIST. Address 0 means not defined yet. Songs are 3 digit loaded.
// with the hard coded pages, changing these will suck, so hopefully I'm sure...
// I filled in the AMS pages in 1k blocks as the music was defined, which is not the order of this table,
// so it's kind of a mess... as long as they fit and don't stomp on each other ;)
// We allocated for ourselves pages 17 through 47 (inclusive)
const MUSICLOOKUP musLookup[] = {   /* page   address  */
    /* 000 CMD_MUSTARTLIST */  {  0,    (unsigned char*)0x0000  },
    /* 001 CMD_MUSSTEEL    */  { 17,    (unsigned char*)0xf000  },      // 632 bytes
    /* 002 CMD_MUSSTART    */  {  0,    (unsigned char*)0x0000  }, 
    /* 003 CMD_MUSEXAM     */  { 24,    (unsigned char*)0xf400  },      // 1228 bytes
    /* 004 CMD_MUSCROSS    */  {  0,    (unsigned char*)0x0000  }, 
    /* 005 CMD_MUSTRICK    */  { 17,    (unsigned char*)0xf400  },      // 1376 bytes
    /* 006 CMD_MUSMLP      */  { 17,    (unsigned char*)0xfc00  },      // 836 bytes
    /* 007 CMD_MUSTROUPE   */  { 18,    (unsigned char*)0xf000  },      // 3022 bytes
    /* 008 CMD_MUSTRIAL    */  { 19,    (unsigned char*)0xf000  },      // 2456 bytes
    /* 009 CMD_MUSTRANCE   */  { 20,    (unsigned char*)0xf000  },      // 1544 bytes
    /* 010 CMD_MUSPEARLY   */  { 18,    (unsigned char*)0xfc00  },      // 902 bytes
    /* 011 CMD_MUSSISTER   */  { 20,    (unsigned char*)0xf800  },      // 1470 bytes
    /* 012 CMD_MUSSMILE    */  {  0,    (unsigned char*)0x0000  }, 
    /* 013 CMD_MUSLOCK     */  {  0,    (unsigned char*)0x0000  }, 
    /* 014 CMD_MUSTRIALS   */  {  0,    (unsigned char*)0x0000  }, 
    /* 015 CMD_MUSPROLOG   */  { 19,    (unsigned char*)0xfc00  },      // 886 bytes
    /* 016 CMD_MUSECHESS   */  {  0,    (unsigned char*)0x0000  }, 
    /* 017 CMD_MUSOBJECT   */  {  0,    (unsigned char*)0x0000  }, 
    /* 018 CMD_MUSTHRILL   */  {  0,    (unsigned char*)0x0000  }, 
    /* 019 CMD_MUSINTEREST */  {  0,    (unsigned char*)0x0000  }, 
    /* 020 CMD_MUSKLAVIER  */  {  0,    (unsigned char*)0x0000  }, 
    /* 021 CMD_MUSTRAGIC   */  {  0,    (unsigned char*)0x0000  }, 
    /* 022 CMD_MUSMIDDLE   */  { 21,    (unsigned char*)0xf000  },      // 1828 bytes
    /* 023 CMD_MUSKG8      */  {  0,    (unsigned char*)0x0000  }, 
    /* 024 CMD_MUSLYING    */  {  0,    (unsigned char*)0x0000  }, 
    /* 025 CMD_MUSMOON     */  {  0,    (unsigned char*)0x0000  }, 
    /* 026 CMD_MUSWINTER   */  {  0,    (unsigned char*)0x0000  }, 
    /* 027 CMD_MUSLOUNGE   */  { 21,    (unsigned char*)0xf800  },      // 868 bytes
    /* 028 CMD_MUSHOTLINE  */  {  0,    (unsigned char*)0x0000  }, 
    /* 029 CMD_MUSSUSPENSE */  { 21,    (unsigned char*)0xfc00  },      // 886 bytes
    /* 030 CMD_MUSBEGIN    */  {  0,    (unsigned char*)0x0000  }, 
    /* 031 CMD_MUSTRUTH    */  { 24,    (unsigned char*)0xfc00  },      // 1000 bytes
    /* 032 CMD_MUSPURSUIT  */  {  0,    (unsigned char*)0x0000  }, 
    /* 033 CMD_MUSEND      */  {  0,    (unsigned char*)0x0000  }, 
    /* 034 CMD_MUSCORNERED */  { 22,    (unsigned char*)0xf000  },      // 1858 bytes
    /* 035 CMD_MUSSWEPT    */  {  0,    (unsigned char*)0x0000  }, 
    /* 036 CMD_MUSCORE     */  { 22,    (unsigned char*)0xf800  },      // 948 bytes
    /* 037 CMD_MUSPRELUDE  */  {  0,    (unsigned char*)0x0000  }, 
    /* 038 CMD_MUSGIGGLE   */  {  0,    (unsigned char*)0x0000  }, 
    /* 039 CMD_MUSCOURT    */  {  0,    (unsigned char*)0x0000  }, 
    /* 040 CMD_MUSWON      */  {  0,    (unsigned char*)0x0000  }, 
    /* 041 CMD_MUSAJ       */  {  0,    (unsigned char*)0x0000  }, 
    /* 042 CMD_MUSRARITY   */  {  0,    (unsigned char*)0x0000  }, 
    /* 043 CMD_MUSTRUCY    */  { 23,    (unsigned char*)0xf000  },      // 1144 bytes
    /* 044 CMD_MUSELEGY    */  { 23,    (unsigned char*)0xf800  },      // 1084 bytes
    /* 045 CMD_MUSGUILTY   */  { 22,    (unsigned char*)0xfc00  },      // 422 bytes
    /* 046 CMD_MUSRECALL   */  { 24,    (unsigned char*)0xf000  },      // 874 bytes
    /* 047 CMD_MUSCRUSADE  */  { 25,    (unsigned char*)0xf000  },      // 3734 bytes   (last allocation, full)
    /* 048 CMD_MUSCLOCK    */  {  0,    (unsigned char*)0x0000  }, 
    /* 049 CMD_MUSSPECIAL  */  {  0,    (unsigned char*)0x0000  }, 
    /* 050 CMD_MUSCOOL     */  {  0,    (unsigned char*)0x0000  }, 
    /* 051 CMD_MUSMEMORY   */  {  0,    (unsigned char*)0x0000  },
    /* 052 CMD_MUSSCHESS   */  {  0,    (unsigned char*)0x0000  },
    /* 053 CMD_MUSOBJECT2  */  {  0,    (unsigned char*)0x0000  } 
};

#ifdef CLASSIC99
// access the AMS replacement
extern unsigned char *pAmsMap[16];
extern bool amsMapOn;
extern "C" void debug_write(char *s, ...);
#endif

// this takes the array index, not the CMD_MUSxxxx index
// This function will remap 0xF000 to the correct page
// Return 0 for not there, anything else for is there
int check_music(int nMusic) {
    if (nMusic >= sizeof(musLookup)/sizeof(musLookup[0])) {
        return 0;
    }
    if (musLookup[nMusic].pAdr == NULL) {
        return 0;
    }

    samsMapPage(musLookup[nMusic].page, MUSIC_DATA_ADDR);

    unsigned char *cpuAdr = musLookup[nMusic].pAdr;
#ifdef CLASSIC99
    if (!amsMapOn) debug_write("WARNING: load_one_music but map is off!");
    cpuAdr = pAmsMap[(((int)cpuAdr)&0xf000)>>12]+(((int)cpuAdr)&0x0fff);
#endif

    unsigned int x = *(uint16_type*)cpuAdr;
    if (x == nMusic) {
        return 1;
    }

    return 0;
}

// check if music is already loaded and if not, try to load it
void load_one_music(int nMusic) {
    if (ams) {
        struct PAB myPab = { 0 };
        char myFilename[44];

        // load the music by index, if it's not already loaded
        nMusic -= CMD_MUSTARTLIST;
        if (check_music(nMusic)) {
            return;
        }

        // Build a PAB
        // Build a FILENAME (two digits)
        // Load the file

        //                            1         2         3         4
        //                  01234567890123456789012345678901234567890123456789012345
        strcpy(myFilename, "PI.HTTP://harmlesslion.com/phoenix/mus/M00");

        myPab.OpCode = DSR_LOAD;
        myPab.NameLength = 0;
        myPab.pName = (unsigned char*)myFilename;

        myPab.RecordNumber = MAX_VOC_SIZE;  // up to 4k, same as voice
        myPab.VDPBuffer = VDP_VOC_ADR;      // VDP buffer overtop of the pattern table (we should be on LOADING screen)
        myPab.pName[VOC_OFF] = (nMusic/10) + '0';
        myPab.pName[VOC_OFF+1] = (nMusic%10) + '0';

        // If DSRLNK succeeds, copy it to the song address+2, and since song address to a word equal to music
        // If DSRLNK fails, zero out the song address and return
        unsigned char *cpuAdr = musLookup[nMusic].pAdr;
#ifdef CLASSIC99
        if (!amsMapOn) debug_write("WARNING: load_one_music but map is off!");
        cpuAdr = pAmsMap[(((int)cpuAdr)&0xf000)>>12]+(((int)cpuAdr)&0x0fff);
#endif

        if (wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS)) {
            *(uint16_type*)cpuAdr = 0;   // 0 is MUSSTARTLIST, so is never valid
        } else {
            *(uint16_type*)cpuAdr = nMusic;
            // songs have a 2 byte length header
            vdpmemread(VDP_VOC_ADR, cpuAdr+2, 2);
            uint16_type sz = *(uint16_type*)(cpuAdr+2);
#ifdef CLASSIC99
            // big endian to little endian, cause we loaded this file
            sz = ((sz&0xff)<<8) | ((sz&0xff00)>>8);
            if (sz+musLookup[nMusic].pAdr+2 > (unsigned char*)0xffff) debug_write("Warning: music %d too large for load", nMusic);
#endif
            vdpmemread(VDP_VOC_ADR+2, cpuAdr+2, sz);
        }
    }
}

void play_music_banked(int nMusic) {
    // we check mute and AMS in the wrapper
    nMusic -= CMD_MUSTARTLIST;
    if (check_music(nMusic)) {
        pSong = musLookup[nMusic].pAdr;
        musicPage = musLookup[nMusic].page;
        pSong += 2;     // get the real address - first two bytes are just song index (we don't keep the song length when we load it)

#ifdef CLASSIC99
        if (!amsMapOn) debug_write("WARNING: play_music_banked but map is off!");
        pSong = pAmsMap[(((int)pSong)&0xf000)>>12]+(((int)pSong)&0x0fff);
#endif

        StartSong(pSong, 0);
    } else {
        // it's not there, never mind
        pSong = NULL;
        return;
    }
}

// this one probably doesn't need to be banked since it's all global variables... oh well
void stop_music_banked() {
    MUTE_SOUND();
    StopSong();
    pSong = NULL;
}

void update_music_banked() {
    if (mute) {
        pSong = NULL;
        return;
    }

    // before we continue, map in the right page. The wrapper will unmap for us
    samsMapPage(musicPage, MUSIC_DATA_ADDR);

    if (songNote[3]&SONGACTIVEACTIVE) {
#ifdef CLASSIC99
        if (!amsMapOn) debug_write("WARNING: update_music_banked but map is off!");
        // note: real TI is not safe to call this function directly, it must use the macro
        SongLoop();
#else
        CALL_PLAYER_SN;
#endif
    } else {
        // handle loop, if set
        if (NULL == pSong) {
            StopSong();
        } else {
            StartSong(pSong, 0);
        }
    }
}

// load all music needed for this scene
void load_music_banked() {
    if (mute) return;

#ifdef HAS_MUSPROLOG
    load_one_music(CMD_MUSPROLOG);
#endif
#ifdef HAS_MUSSTEEL
    load_one_music(CMD_MUSSTEEL); // Steel Samurai Ringtone
#endif
#ifdef HAS_MUSLOUNGE
    load_one_music(CMD_MUSLOUNGE); // Courtroom Lounge - Overture again
#endif
#ifdef HAS_MUSMLP
    load_one_music(CMD_MUSMLP); // My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88
#endif
#ifdef HAS_MUSTROUPE
    load_one_music(CMD_MUSTROUPE); // Gramarye Troupe - Apollo Justice Ace Attorney
#endif
#ifdef HAS_MUSTRIAL
    load_one_music(CMD_MUSTRIAL); // Ace Attorney 4 - Trial - Apollo Justice Ace Attorney
#endif
#ifdef HAS_MUSTRANCE
    load_one_music(CMD_MUSTRANCE); // Trance Logic - Apollo Justice Ace Attorney
#endif
#ifdef HAS_MUSTRICK
    load_one_music(CMD_MUSTRICK); // Trick and Magic - Phoenix Wright: Justice for All
#endif
#ifdef HAS_MUSCRUSADE
    load_one_music(CMD_MUSCRUSADE); // Crusading - SoloAcapello
#endif
#ifdef HAS_MUSEXAM
    load_one_music(CMD_MUSEXAM);     // Examination - Moderate 2007 - Apollo Justice Ace Attorney
#endif
#ifdef HAS_MUSSTART
    load_one_music(CMD_MUSSTART); // Apollo Justice - Start of a New Trial! - Apollo Justice Ace Attorney
#endif
#ifdef HAS_MUSCHESS
    load_one_music(CMD_MUSCHESS); // Logic Chess - Moderato - Ace Attorney Investigations 2
#endif
#ifdef HAS_MUSOBJECT
    load_one_music(CMD_MUSOBJECT); // Objection! 2009 - Ace Attorney Investigations 2
#endif
#ifdef HAS_MUSTHRILL
    load_one_music(CMD_MUSTHRILL); // Thrill Theme - Suspense
#endif
#ifdef HAS_MUSINTEREST
    load_one_music(CMD_MUSINTEREST); // Interesting People - Ace Attorney Investigations
#endif
#ifdef HAS_MUSSUSPENSE
    load_one_music(CMD_MUSSUSPENSE); // Suspense - Phoenix Wright Ace Attorney
#endif
#ifdef HAS_MUSPEARLY
    load_one_music(CMD_MUSPEARLY); // With Pearly - Phoenix Wright Justice for All
#endif
#ifdef HAS_MUSCROSS
    load_one_music(CMD_MUSCROSS); // Cross Examination - Moderate 2002 - Phoenix Wright Justice For All
#endif
#ifdef HAS_MUSSISTER
    load_one_music(CMD_MUSSISTER); // Turnabout Sisters - Capcom
#endif
#ifdef HAS_MUSSMILE
    load_one_music(CMD_MUSSMILE); // Smile Instrumental - Hasbro
#endif
#ifdef HAS_MUSKLAVIER
    load_one_music(CMD_MUSKLAVIER); // Klavier's Theme - Capcom
#endif
#ifdef HAS_MUSLOCK
    load_one_music(CMD_MUSLOCK); // Lock on the Heart - Capcom
#endif
#ifdef HAS_MUSGIGGLE
    load_one_music(CMD_MUSGIGGLE); // Giggle at the Ghosties - Hasbro
#endif
#ifdef HAS_MUSMIDDLE
    load_one_music(CMD_MUSMIDDLE); // Investigation Middle - Capcom
#endif
#ifdef HAS_MUSCLOCK
    load_one_music(CMD_MUSCLOCK); // Like Clockwork - SoloAcapello
#endif
#ifdef HAS_MUSSPECIAL
    load_one_music(CMD_MUSSPECIAL);: // Special Delivery! - SoloAcapello
#endif
#ifdef HAS_MUSRARITY
    load_one_music(CMD_MUSRARITY); // Rarity's Theme - MandoPony
#endif
#ifdef HAS_MUSAJ
    load_one_music(CMD_MUSAJ); // Applejack's Theme - AcousticBrony
#endif
#ifdef HAS_MUSSWEPT
    load_one_music(CMD_MUSSWEPT); // Sweptaway Turnabout - Capcom
#endif
#ifdef HAS_MUSHOTLINE
    load_one_music(CMD_MUSHOTLINE); // Hotline to Destiny - Capcom
#endif
#ifdef HAS_MUSKG8
    load_one_music(CMD_MUSKG8); // KG-8 Case - Capcom
#endif
#ifdef HAS_MUSPRELUDE
    load_one_music(CMD_MUSPRELUDE); // Unending Prelude - Capcom
#endif
#ifdef HAS_MUSBEGIN
    load_one_music(CMD_MUSBEGIN); // Court Begins - Capcom
#endif
#ifdef HAS_MUSCOOL
    load_one_music(CMD_MUSCOOL); // Too Cool For You, Dweeb - SoloAcapello
#endif
#ifdef HAS_MUSTRUTH
    load_one_music(CMD_MUSTRUTH); // Tell the Truth 2002 - Capcom
#endif
#ifdef HAS_MUSLYING
    load_one_music(CMD_MUSLYING); // Lying Coldly - Capcom
#endif
#ifdef HAS_MUSMEMORY
    load_one_music(CMD_MUSMEMORY); // Memories - SoloAcapello
#endif
#ifdef HAS_MUSCOURT
    load_one_music(CMD_MUSCOURT); // Court Begins Orchestrated - Capcom
#endif
#ifdef HAS_MUSPURSUIT
    load_one_music(CMD_MUSPURSUIT); // Pursuit - Questioned - Capcom
#endif
#ifdef HAS_MUSEND
    load_one_music(CMD_MUSEND); // Ace Attorney ~ End - Capcom
#endif
#ifdef HAS_MUSTRIALS
    load_one_music(CMD_MUSTRIALS); // Trials and Tribulation WiiWare Rips - HoodieD
#endif
#ifdef HAS_MUSMOON
    load_one_music(CMD_MUSMOON); // Moonlight Sonata - The Orchard Music
#endif
#ifdef HAS_MUSCORNERED
    load_one_music(CMD_MUSCORNERED); // Pursuit Cornered 2001 - Capcom
#endif
#ifdef HAS_MUSWON
    load_one_music(CMD_MUSWON); // Won the Lawsuit - Magical Trick Society
#endif
#ifdef HAS_MUSWINTER
    load_one_music(CMD_MUSWINTER); // Winter Wrap Up - David Larson
#endif
#ifdef HAS_MUSTRUCY
    load_one_music(CMD_MUSTRUCY);  // Trucy's theme - Child of Magic
#endif
#ifdef HAS_MUSGUILTY
    load_one_music(CMD_MUSGUILTY);  // Guilty love - Capcom (using ringtone version)
#endif
#ifdef HAS_MUSELEGY
    load_one_music(CMD_MUSELEGY);  // Guard's elegy - Capcom
#endif
#ifdef HAS_MUSRECALL
    load_one_music(CMD_MUSRECALL);  // Recollation - Elementary School Trial
#endif
#ifdef HAS_MUSCORE
    load_one_music(CMD_MUSCORE);  // Investigation Core 2001 - Cadenza
#endif
}

