#include <sound.h>
#include "sfx.h"
#include "structures.h"
#ifdef CLASSIC99
#include "vgmcomp2/CPlayer.h"
#else
#include <TISNPlay.h>
#endif

const unsigned char *pSong;
int mute = 0;

void play_music(int music) {
    if (mute) return;

    switch(music) {
#ifdef HAS_MUSPROLOG
    case CMD_MUSPROLOG: // Apollo Justice - Prologue
    {
static
#include "../music/processed/PROLOG.c"
        pSong = MUS_PROLOG;
        StartSong(MUS_PROLOG, 0);
    }
        break;
#endif
#ifdef HAS_MUSSTEEL
    case CMD_MUSSTEEL: // Steel Samurai Ringtone
        {
static
#include "../music/processed/STEEL.c"
        pSong = MUS_STEEL;
        StartSong(MUS_STEEL, 0);
        }
        break;
#endif
#ifdef HAS_MUSLOUNGE
    case CMD_MUSLOUNGE: // Courtroom Lounge - Overture again
        {
static
#include "../music/processed/LOUNGE.c"
        pSong = MUS_LOUNGE;
        StartSong(MUS_LOUNGE, 0);
        }
        break;
#endif
#ifdef HAS_MUSMLP
    case CMD_MUSMLP: // My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88
        {
static
#include "../music/processed/MLP.c"
        pSong = MUS_MLP;
        StartSong(MUS_MLP, 0);
        }
        break;
#endif
#ifdef HAS_MUSTROUPE
    case CMD_MUSTROUPE: // Gramarye Troupe - Apollo Justice Ace Attorney
        {
static
#include "../music/processed/TROUPE.c"
        pSong = MUS_TROUPE;
        StartSong(MUS_TROUPE, 0);
        }
        break;
#endif
#ifdef HAS_MUSTRIAL
    case CMD_MUSTRIAL: // Ace Attorney 4 - Trial - Apollo Justice Ace Attorney
        {
static
#include "../music/processed/TRIAL.c"
        pSong = MUS_TRIAL;
        StartSong(MUS_TRIAL, 0);
        }
        break;
#endif
#ifdef HAS_MUSTRACE
    case CMD_MUSTRACE: // Trance Logic - Apollo Justice Ace Attorney
        break;
#endif
#ifdef HAS_MUSTRICK
    case CMD_MUSTRICK: // Trick and Magic - Phoenix Wright: Justice for All
        break;
#endif
#ifdef HAS_MUSCRUSADE
    case CMD_MUSCRUSADE: // Crusading - SoloAcapello
        break;
#endif
#ifdef HAS_MUSEXAM
    case CMD_MUSEXAM: // Examination - Moderate 2007 - Apollo Justice Ace Attorney
        break;
#endif
#ifdef HAS_MUSSTART
    case CMD_MUSSTART: // Apollo Justice - Start of a New Trial! - Apollo Justice Ace Attorney
        break;
#endif
#ifdef HAS_MUSCHESS
    case CMD_MUSCHESS: // Logic Chess - Moderato - Ace Attorney Investigations 2
        break;
#endif
#ifdef HAS_MUSOBJECT
    case CMD_MUSOBJECT: // Objection! 2009 - Ace Attorney Investigations 2
        break;
#endif
#ifdef HAS_MUSTHRILL
    case CMD_MUSTHRILL: // Thrill Theme - Suspense
        break;
#endif
#ifdef HAS_MUSINTEREST
    case CMD_MUSINTEREST: // Interesting People - Ace Attorney Investigations
        break;
#endif
#ifdef HAS_MUSSUSPENSE
    case CMD_MUSSUSPENSE: // Suspense - Phoenix Wright Ace Attorney
        {
static
#include "../music/processed/SUSPENSE.c"
            pSong = MUS_SUSPENSE;
            StartSong(MUS_SUSPENSE, 0);
        }
        break;
#endif
#ifdef HAS_MUSPEARLY
    case CMD_MUSPEARLY: // With Pearly - Phoenix Wright Justice for All
        {
static
#include "../music/processed/PEARLY.c"
        pSong = MUS_PEARLY;
        StartSong(MUS_PEARLY, 0);
        }
        break;
#endif
#ifdef HAS_MUSCROSS
    case CMD_MUSCROSS: // Cross Examination - Moderate 2002 - Phoenix Wright Justice For All
        break;
#endif
#ifdef HAS_MUSSISTER
    case CMD_MUSSISTER: // Turnabout Sisters - Capcom
    {
static
#include "../music/processed/SISTERS.c"
        pSong = MUS_SISTERS;
        StartSong(MUS_SISTERS, 0);
    }
        break;
#endif
#ifdef HAS_MUSSMILE
    case CMD_MUSSMILE: // Smile Instrumental - Hasbro
        break;
#endif
#ifdef HAS_MUSKLAVIER
    case CMD_MUSKLAVIER: // Klavier's Theme - Capcom
        break;
#endif
#ifdef HAS_MUSLOCK
    case CMD_MUSLOCK: // Lock on the Heart - Capcom
        break;
#endif
#ifdef HAS_MUSGIGGLE
    case CMD_MUSGIGGLE: // Giggle at the Ghosties - Hasbro
        break;
#endif
#ifdef HAS_MUSMIDDLE
    case CMD_MUSMIDDLE: // Investigation Middle - Capcom
    {
static
#include "../music/processed/MIDDLE.c"
        pSong = MUS_MIDDLE;
        StartSong(MUS_MIDDLE, 0);
    }
        break;
#endif
#ifdef HAS_MUSCLOCK
    case CMD_MUSCLOCK: // Like Clockwork - SoloAcapello
        break;
#endif
#ifdef HAS_MUSSPECIAL
    case CMD_MUSSPECIAL: // Special Delivery! - SoloAcapello
        break;
#endif
#ifdef HAS_MUSRARITY
    case CMD_MUSRARITY: // Rarity's Theme - MandoPony
        break;
#endif
#ifdef HAS_MUSAJ
    case CMD_MUSAJ: // Applejack's Theme - AcousticBrony
        break;
#endif
#ifdef HAS_MUSSWEPT
    case CMD_MUSSWEPT: // Sweptaway Turnabout - Capcom
        break;
#endif
#ifdef HAS_MUSHOTLINE
    case CMD_MUSHOTLINE: // Hotline to Destiny - Capcom
        break;
#endif
#ifdef HAS_MUSKG8
    case CMD_MUSKG8: // KG-8 Case - Capcom
        break;
#endif
#ifdef HAS_MUSPRELUDE
    case CMD_MUSPRELUDE: // Unending Prelude - Capcom
        break;
#endif
#ifdef HAS_MUSBEGIN
    case CMD_MUSBEGIN: // Court Begins - Capcom
        break;
#endif
#ifdef HAS_MUSCOOL
    case CMD_MUSCOOL: // Too Cool For You, Dweeb - SoloAcapello
        break;
#endif
#ifdef HAS_MUSTRUTH
    case CMD_MUSTRUTH: // Tell the Truth 2002 - Capcom
        break;
#endif
#ifdef HAS_MUSLYING
    case CMD_MUSLYING: // Lying Coldly - Capcom
        break;
#endif
#ifdef HAS_MUSMEMORY
    case CMD_MUSMEMORY: // Memories - SoloAcapello
        break;
#endif
#ifdef HAS_MUSCOURT
    case CMD_MUSCOURT: // Court Begins Orchestrated - Capcom
        break;
#endif
#ifdef HAS_MUSPURSUIT
    case CMD_MUSPURSUIT: // Pursuit - Questioned - Capcom
        break;
#endif
#ifdef HAS_MUSEND
    case CMD_MUSEND: // Ace Attorney ~ End - Capcom
        break;
#endif
#ifdef HAS_MUSTRIALS
    case CMD_MUSTRIALS: // Trials and Tribulation WiiWare Rips - HoodieD
        break;
#endif
#ifdef HAS_MUSMOON
    case CMD_MUSMOON: // Moonlight Sonata - The Orchard Music
        break;
#endif
#ifdef HAS_MUSCORNERED
    case CMD_MUSCORNERED: // Pursuit Cornered 2001 - Capcom
        break;
#endif
#ifdef HAS_MUSWON
    case CMD_MUSWON: // Won the Lawsuit - Magical Trick Society
        break;
#endif
#ifdef HAS_MUSWINTER
    case CMD_MUSWINTER: // Winter Wrap Up - David Larson
        break;
#endif
#ifdef HAS_MUSTRUCY
    case CMD_MUSTRUCY:  // Trucy's theme - Child of Magic
    {
static
#include "../music/processed/TRUCY.c"
        pSong = MUS_TRUCY;
        StartSong(MUS_TRUCY, 0);
    }
        break;
#endif
#ifdef HAS_MUSGUILTY
    case CMD_MUSGUILTY:  // Guilty love - Capcom (using ringtone version)
    {
static
#include "../music/processed/GUILTY.c"
        pSong = MUS_GUILTY;
        StartSong(MUS_GUILTY, 0);
    }
        break;
#endif
#ifdef HAS_MUSELEGY
    case CMD_MUSELEGY:  // Guard's elegy - Capcom
    {
static
#include "../music/processed/ELEGY.c"
        pSong = MUS_ELEGY;
        StartSong(MUS_ELEGY, 0);
    }
        break;
#endif
#ifdef HAS_MUSRECALL
    case CMD_MUSRECALL:  // Recollation - Elementary School Trial
    {
static
#include "../music/processed/RECALL.c"
        pSong = MUS_RECALL;
        StartSong(MUS_RECALL, 0);
    }
        break;
#endif
#ifdef HAS_MUSCORE
    case CMD_MUSCORE:  // Investigation Core 2001 - Cadenza
    {
static
#include "../music/processed/CORE.c"
        pSong = MUS_CORE;
        StartSong(MUS_CORE, 0);
    }
        break;
#endif

    default:
        pSong = NULL;
    }
}

void stop_music() {
    MUTE_SOUND();
    StopSong();
    pSong = NULL;
}

void update_music() {
    if (mute) {
        pSong = NULL;
        return;
    }

    if (songNote[3]&SONGACTIVEACTIVE) {
#ifdef CLASSIC99
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
