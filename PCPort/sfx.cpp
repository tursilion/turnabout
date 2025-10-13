#include "structures.h"

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
