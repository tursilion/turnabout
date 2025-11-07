#include "structures.h"
#include <sound.h>
#include <vdp.h>

void play_sfx(int sfx) {
    switch (sfx) {
#ifdef HAS_CROWDSFX
        case CMD_CROWDSFX    : // play crowd noise
            break;
#endif

#ifdef HAS_HAMMERSFX
        case CMD_HAMMERSFX   : // play hammer sound
            break;
#endif

#ifdef HAS_BOOMSFX
        case CMD_BOOMSFX     : // play boom sound
            SOUND(0xe6);        // select noise
            for (unsigned char i=0; i<16; i++) {
                SOUND(0xf0+i);  // fade
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0xff);        // make sure it ends muted
            break;
#endif

#ifdef HAS_LOCKSFX
        case CMD_LOCKSFX     :
            // pulsing noise for the chain
            SOUND(0xe4);        // select noise
            for (unsigned char i=0; i<48; i++) {
                SOUND(0xf6+((i&7)-4));
            }
            // three booms for three locks
            SOUND(0xe6);        // select noise
            SOUND(0x81);
            SOUND(0x00);        // lowest pitch
            for (unsigned char i=0; i<48; i++) {
                SOUND(0xf0+(i&0xf));  // fade
                SOUND(0x90+(i&0xf));  // noise+bass
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0xff);        // make sure it ends muted
            SOUND(0x9f);
            break;
#endif

#ifdef HAS_CHIMESFX
        case CMD_CHIMESFX     : // play chime sound
            SOUND(0x87);
            SOUND(0x09);      // frequency will waver a bit around the 7
            for (unsigned char i=0; i<32; i++) {
                SOUND(0x87+(i&3));  // warble? probably should be a sine wave
                SOUND(0x90+(i>>1)); // fade
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0x9f);    // make sure it ends muted
            break;
#endif

#ifdef HAS_LAUGHSFX
        case CMD_LAUGHSFX    : // play crowd laughter
            break;
#endif

#ifdef HAS_BREAKSFX
        case CMD_BREAKSFX    : // play break psychlock sfx
            break;
#endif

#ifdef HAS_PARTYSFX
        case CMD_PARTYSFX    : // play party horn sfx
            break;
#endif

#ifdef HAS_JOKESFX
        case CMD_JOKESFX     : // play rimshot sfx
            break;
#endif

#ifdef HAS_CRASHSFX
        case CMD_CRASHSFX    : // play crash sfx
            SOUND(0xe5);        // select noise
            for (unsigned char i=0; i<32; i++) {
                SOUND(0xf0+(i>>1));  // fade
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0xff);        // make sure it ends muted
            break;
#endif

#ifdef HAS_FALLSFX
        case CMD_FALLSFX    : // play falling sfx
            SOUND(0x80);
            SOUND(0x10);
            SOUND(0xA0);
            SOUND(0x20);
            SOUND(0xCF);
            SOUND(0x30);
            SOUND(0x90);
            SOUND(0xB0);
            SOUND(0xD0);    // three tones, 0-1 fall in pitch, 2 fades out
            for (unsigned char i=0; i<32; i++) {
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
                SOUND(0x80);
                SOUND(0x10+(i/3));
                SOUND(0xa0);
                SOUND(0x20+(i/3));
                if (i < 16) {
                    SOUND(0xD0+i);
                } else {
                    SOUND(0xDF);
                }
            }
            SOUND(0x9f);        // make sure it ends muted
            SOUND(0xbf);        // make sure it ends muted
            SOUND(0xdf);        // make sure it ends muted
            SOUND(0xdf);        // make sure it ends muted
            break;
#endif

#ifdef HAS_RIPSFX
        case CMD_RIPSFX      : // play rip sfx
            break;
#endif

#ifdef HAS_WHOOSHSFX
        case CMD_WHOOSHSFX   : // play whoosh sfx
            break;
#endif

    default:
        break;
    }
}

// play voice clips - TODO: still deciding what these will look like
void play_voice(int voice) {
}
