#include "structures.h"
#include "engine.h"
#include "voice.h"
#include "music.h"
#include "sfx.h"
#include "cache.h"
#include <string.h>
#include <sound.h>
#include <vdp.h>
#include <files.h>

// This code must be loaded before 0xf000, so we can bank pages up there
extern int ams;

// we can't play samples in the Classic99 build
#ifdef CLASSIC99
void load_voices() { }
void play_voice(int x) { }
#else

// lookup table - less code to pass a table row
typedef struct {
    int page, tag;
} VOICEINFOSTRUCT;

#ifdef HAS_VOICE
// I could break this down more, but I'm not that desperate for 30 bytes...
static const VOICEINFOSTRUCT vis[] = {
    {   TRIXIE_OBJECT_PAGE,     TRIXIE_OBJECT_TAG    },
    {   PHOENIX_OBJECT_PAGE,    PHOENIX_OBJECT_TAG    },
    {   TWILIGHT_OBJECT_PAGE,   TWILIGHT_OBJECT_TAG    },
    {   FLUTTERSHY_OBJECT_PAGE, FLUTTERSHY_OBJECT_TAG    },
    {   JUDGE_OBJECT_PAGE,      JUDGE_OBJECT_TAG    },
    {   ALL_OBJECT_PAGE,        ALL_OBJECT_TAG    },
    {   TRIXIE_HOLDIT_PAGE,     TRIXIE_HOLDIT_TAG    },
    {   PHOENIX_HOLDIT_PAGE,    PHOENIX_HOLDIT_TAG    },
    {   PHOENIX_TAKETHAT_PAGE,  PHOENIX_TAKETHAT_TAG    }
};
#endif

// warning: must have already checked for AMS
int map_and_check(int idx) {
#ifdef HAS_VOICE
    const VOICEINFOSTRUCT *pVoc = &vis[idx];

    // map the page in
    samsMapPage(pVoc->page, MAP_ADDRESS);
    samsMapOn();

    // possible endianess issue with Classic99 PC build
    // Check if it's already loaded
    if (*((unsigned short*)(MAP_ADDRESS + TAG_OFFSET_WORD)) == pVoc->tag) {
        // it's loaded
        return 1;
    }
#endif

    // it's not loaded
    return 0;
}

void load_one_voice(int idx) {
#ifdef HAS_VOICE
    if (ams) {
        struct PAB myPab = { 0 };
        char myFilename[42];

        if (map_and_check(idx)) {
            // already loaded
            return;
        }

        //                            1         2         3         4
        //                  01234567890123456789012345678901234567890123456789012345
        strcpy(myFilename, "PI.HTTP://harmlesslion.com/phoenix/voc/S0");

        myPab.OpCode = DSR_LOAD;
        myPab.NameLength = 0;
        myPab.pName = (unsigned char*)myFilename;

        myPab.RecordNumber = MAX_VOC_SIZE;  // up to 4k
        myPab.VDPBuffer = VDP_VOC_ADR;      // VDP buffer overtop of the pattern table (we should be on LOADING screen)
        myPab.pName[VOC_OFF] = idx + '0';
        (void)wrap_dsrlnk(&myPab, VDP_PAB_ADDRESS);
        // most VOCs are pretty close to the full page, so don't bother working it out, just copy a full page
        vdpmemread(VDP_VOC_ADR, (unsigned char*)MAP_ADDRESS, MAX_VOC_SIZE); // won't work in Classic99 PC build - bad address
    }
#endif
}

// load a voice sample. In order to better stagger the loads, we will tag each
// page at a fixed offset to determine if the sample is loaded
// We'll load them per scene if we can, but the scene that needs them will make sure all needed are loaded
// Keeping this function even if HAS_VOICE is not defined so we can preload that way
void load_voices() {
    if (ams) {
#ifdef HAS_TRIXIEOBJ
        load_one_voice(TRIXIE_OBJECT_IDX);
#endif

#ifdef HAS_PHOENIXOBJ  
        load_one_voice(PHOENIX_OBJECT_IDX);
#endif

#ifdef HAS_TWIOBJ      
        load_one_voice(TWILIGHT_OBJECT_IDX);
#endif

#ifdef HAS_FLUTTEROBJ  
        load_one_voice(FLUTTERSHY_OBJECT_IDX);
#endif

#ifdef HAS_JUDGEOBJ    
        load_one_voice(JUDGE_OBJECT_IDX);
#endif

#ifdef HAS_GROUPOBJ    
        load_one_voice(ALL_OBJECT_IDX);
#endif

#ifdef HAS_TRIXIEHOLD  
        load_one_voice(TRIXIE_HOLDIT_IDX);
#endif

#ifdef HAS_PHOENIXHOLD 
        load_one_voice(PHOENIX_HOLDIT_IDX);
#endif

#ifdef HAS_PHOENIXTAKE 
        load_one_voice(PHOENIX_TAKETHAT_IDX);
#endif

        // restore SAMS and turn mapping off
        restoreSamsMap();
    }

}

// play voice clips - 4-bit 8192hz, one AMS page per sample
// Remember to subtract CMD_VOICESTARTLIST and one more to get the index
void play_voice(int voice) {
#ifdef HAS_VOICE
    if (ams != 0) {
        unsigned char *pSample = NULL;

        // inline asm is fast enough!
        // First two bytes of the page are the length in bytes, we always play both nibbles.
        if ((voice >= 0) && (voice < CMD_VOICEENDLIST-CMD_VOICESTARTLIST-1)) {
            if (map_and_check(voice)) {
                pSample = (unsigned char*)MAP_ADDRESS;
            }
        }

        if (pSample != NULL) {
            // This loop is hand tuned for 8192Hz playback. It uses all three voices (eh) and should be pretty close!
            // Of course, it was hand tuned in Classic99... so take that with a grain of salt.
            // Also, I don't feel it sounds any damn louder with all three voices...
            __asm__ volatile (
                "li r0,>8100\n\t"   // fastest frequency
                "li r1,>8400\n\t"   // sound chip
                "movb r0,*r1\n\t"   // write first byte
                "swpb r0\n\t"       // prepare
                "movb r0,*r1\n\t"   // write second
                "li r0,>A100\n\t"   // fastest frequency
                "movb r0,*r1\n\t"   // write first byte
                "swpb r0\n\t"       // prepare
                "movb r0,*r1\n\t"   // write second
                "li r0,>C100\n\t"   // fastest frequency
                "movb r0,*r1\n\t"   // write first byte
                "swpb r0\n\t"       // prepare
                "movb r0,*r1\n\t"   // write second
                "mov *%0+,r2\n"     // fetch sample length

              "lp%=\n\t"            // no tab on previous line cause label
                "movb *%0,r0\n\t"   // fetch byte                           14+4+4 = 22
                "srl r0,4\n\t"      // shift down first nibble              12+8   = 20
                "ori r0,>9000\n\t"  // merge in volume command              14+4+8 = 26
                "movb r0,*r1\n\t"   // write to sound chip                  14+8+4 = 26 -> 114 and 6 instructions
                "ai r0,>2000\n\t"   // second channel (doesn't always help, but might be louder)
                "movb r0,*r1\n\t"   // write to sound chip
                "ai r0,>2000\n\t"   // third channel
                "movb r0,*r1\n\t"   // write to sound chip
                "stst r0\n\t"       // waste time                           8      = 8
                "src r0,11\n\t"     // a slow opcode to delay (hand tuned)

                "movb *%0+,r0\n\t"  // refetch byte and increment           14+6+4 = 24
                "andi r0,>0f00\n\t" // mask to second nibble                14+8   = 22
                "ori r0,>9000\n\t"  // merge in volume command              14+4+8 = 26
                "movb r0,*r1\n\t"   // write to sound chip                  14+8+4 = 26
                "ai r0,>2000\n\t"   // second channel (doesn't always help, but might be louder)
                "movb r0,*r1\n\t"   // write to sound chip
                "ai r0,>2000\n\t"   // third channel
                "movb r0,*r1\n\t"   // write to sound chip
                "stst r0\n\t"       // waste time                           8      = 8
                "stst r0\n\t"       // waste time                           8      = 8  -> 114 and 6 instructions 
                "stst r0\n\t"       // waste time                           8      = 8
                "src r0,11\n\t"     // a slow opcode to delay (hand tuned)

                "dec r2\n\t"        // count down                           10     = 10
                "jne lp%=\n\t"      // loop until down                      10     = 10 (added to first sample)
                
                "li r0,>9f00\n\t"   // prepare mute
                "movb r0,*r1\n\t"   // mute it
                "li r0,>bf00\n\t"   // prepare mute
                "movb r0,*r1\n\t"   // mute it
                "li r0,>df00\n\t"   // prepare mute
                "movb r0,*r1\n\t"   // mute it

              : "=r"(pSample)       // just lets us modify it without fear
              : "0"(pSample)        // tells it this is really parameter %0 (the output)
              : "r0","r1","r2");    // clobbers

            // restore SAMS and turn mapping off
            restoreSamsMap();

            return;
        }
    }

    // restore SAMS and turn mapping off
    restoreSamsMap();
#endif

    // if we fall through (bad load or no ams), play crash instead
    play_sfx(CMD_CRASHSFX);
}

#endif

// TODO: write sound test module that can load and play any music, and loads and plays all samples (secret key in loader)
