#include "structures.h"

void run_music(const unsigned char *p, int sz) {
    // TODO: need to link the player in so we can call it, using system hangs
}

void play_music(int music) {
    switch(music) {
#ifdef HAS_MUSPROLOG
    case CMD_MUSPROLOG: // Apollo Justice - Prologue
    {
static
#include "..\music\processed\PROLOG.c"
        run_music(MUS_PROLOG, sizeof(MUS_PROLOG));
    }
        break;
#endif
#ifdef HAS_MUSSTEEL
    case CMD_MUSSTEEL: // Steel Samurai Ringtone
        {
static
#include "..\music\processed\STEEL.c"
        run_music(MUS_STEEL, sizeof(MUS_STEEL));
        }
        break;
#endif
#ifdef HAS_MUSLOUNGE
    case CMD_MUSLOUNGE: // Courtroom Lounge - Another Prelude - Phoenix Wright: Justice for All
        break;
#endif
#ifdef HAS_MUSMLP
    case CMD_MUSMLP: // My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88
        break;
#endif
#ifdef HAS_MUSTROUPE
    case CMD_MUSTROUPE: // Gramarye Troupe - Apollo Justice Ace Attorney
        break;
#endif
#ifdef HAS_MUSTRIAL
    case CMD_MUSTRIAL: // Ace Attorney 4 - Trial - Apollo Justice Ace Attorney
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
#include "..\music\processed\SUSPENSE.c"
            run_music(MUS_SUSPENSE, sizeof(MUS_SUSPENSE));
        }
        break;
#endif
#ifdef HAS_MUSPEARLY
    case CMD_MUSPEARLY: // With Pearly - Phoenix Wright Justice for All
        break;
#endif
#ifdef HAS_MUSCROSS
    case CMD_MUSCROSS: // Cross Examination - Moderate 2002 - Phoenix Wright Justice For All
        break;
#endif
#ifdef HAS_MUSSISTER
    case CMD_MUSSISTER: // Turnabout Sisters - Capcom
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
#ifdef HAS_MUSINVEST
    case CMD_MUSINVEST: // Investigation Middle - Capcom
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

    default:
        break;
    }
}
