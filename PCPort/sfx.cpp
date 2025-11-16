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
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
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

#ifdef HAS_ICRASHSFX
        case CMD_ICRASHSFX    : // play inverted crash sfx
            SOUND(0xe5);        // select noise
            for (unsigned char i=31; i>0; i--) {
                SOUND(0xf0+(i>>1));  // fade in
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0xff);        // make sure it ends muted
            break;
#endif

#ifdef HAS_MAGICSFX
        case CMD_MAGICSFX:    // play magic sfx
            SOUND(0x80);
            SOUND(0x10);
            SOUND(0xA0);
            SOUND(0x20);
            SOUND(0x9F);
            SOUND(0xBF);      // two channels rising pitch and volume
/*
sfx.cpp:166: error: unrecognizable insn (on the 0x10-(i/3)):
(insn 93 92 94 10 sfx.cpp:109 (set (reg:QI 36 [ D.1257 ])
        (minus:QI (const_int 16 [0x10])
            (reg:QI 37 [ D.1256 ]))) -1 (expr_list:REG_EQUAL (minus:QI (const_int 16 [0x10])
            (reg:QI 37 [ D.1256 ]))
        (nil)))
sfx.cpp:166: internal compiler error: in extract_insn, at recog.c:2048
*/
            for (unsigned int i=0; i<32; i++) {     // QI subtraction compiler error, so use ints
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
                SOUND(0x80);
                SOUND(0x10-(i/3));
                SOUND(0xa0);
                SOUND(0x20-(i/3));
                SOUND(0x9f-(i/2));
                SOUND(0xBF-(i/2));
            }
            SOUND(0x9f);        // make sure it ends muted
            SOUND(0xbf);        // make sure it ends muted
            break;
#endif

#ifdef HAS_BADMAGSFX
        case CMD_BADMAGSFX:    // play bad magic sfx - like chime but with 2 channel synth
            SOUND(0x87);
            SOUND(0x09);      // frequency will waver a bit around the 7
            SOUND(0xa7);
            SOUND(0x0a);      // frequency will waver a bit around the 7
            for (unsigned char i=0; i<32; i++) {
                SOUND(0x87+(i&3));  // warble? probably should be a sine wave
                SOUND(0xa8+(i&3));  // warble? probably should be a sine wave
                SOUND(0x90+(i>>1)); // fade
                SOUND(0xb0+(i>>1)); // fade
                VDP_WAIT_VBLANK_CRU;
                VDP_CLEAR_VBLANK;
            }
            SOUND(0x9f);    // make sure it ends muted
            SOUND(0xbf);    // make sure it ends muted
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
