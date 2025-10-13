#include "structures.h"

#ifdef LOCATION_TYPE_STORY
// we only need to process the contents of story[]. When we reach CMD_ENDSTORY, the evidence field tells us who to load
// when changing location, be sure to draw black and stop music

#include "structures.h"
#include "engine.h"
#include "sfx.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>

extern Story_t story[];
extern int run_inventory();
extern void run_aid();

// returns the next location to run
int run_story() {
    // story text is very simple - it just has to run the story text until it's finished (or told to exit)
    int index = 0;
    int lastimg = -1;

    for (;;) {
        // process the current line

        // do the image
        if (story[index].frame != lastimg) {
            load_image(story[index].frame);
            lastimg = story[index].frame;
        }

        // check for add inventory - a negative inventory is an add with no command
        if (story[index].evidence < 0) {
            add_inventory(-story[index].evidence);
        }

        // process commands
        switch (story[index].cmdwho&0xff) {
            case CMD_FLASH       : // draw a white flashand play boom - ignore frame (we can invert colors once so we don't need to reload)
                invert_image();
                play_sfx(CMD_BOOMSFX);
                for (int j=0; j<12; ++j) {
                    draw_screen();
                }
                invert_image();
                break;
                
            case CMD_BLACK       : // draw a black screen - ignore frame (but clear last frame so we know to load again)
                black_image();
                lastimg = -1;
                break;

            case CMD_ENDSTORY    : // end this story sequence and return to main loop. Story stores new location in evidence field and will jump to it.
                return story[index].evidence;

            case CMD_REMOVEEV    : // remove evidence from inventory (evidence field) and go to next line
                remove_inventory(story[index].evidence);
                ++index;
                continue;

            case CMD_ADDEV       : // add evidence (evidence field) and go to next line. Only needed if you need the next line part
                add_inventory(story[index].evidence);
                ++index;
                continue;

            case CMD_SHOWEV      : // request show evidence, text will say why. Examination struct will treat as objection.
                break;

            case CMD_ASKOBJECT   : // ask whether we should object, branch to evidence as a story text if we do
                break;

            case CMD_SKIPIFEV    : // skip to 'evidence' line if we have a certain evidence (for story control)
                break;

            case CMD_CROWDSFX    : // play crowd noise
            case CMD_HAMMERSFX   : // play hammer sound
            case CMD_BOOMSFX     : // play boom sound
            case CMD_LAUGHSFX    : // play crowd laughter
            case CMD_BREAKSFX    : // play break psychlock sfx
            case CMD_PARTYSFX    : // play party horn sfx
            case CMD_JOKESFX     : // play rimshot sfx
            case CMD_CRASHSFX    : // play crash sfx
            case CMD_RIPSFX      : // play rip sfx
            case CMD_WHOOSHSFX   : // play whoosh sfx
                play_sfx(story[index].cmdwho&0xff);
                break;

            case CMD_TRIXIEOBJ   : // play trixie objection
            case CMD_PHOENIXOBJ  : // play phoenix objection
            case CMD_TWIOBJ      : // play twilight objection
            case CMD_FLUTTEROBJ  : // play fluttershy objection
            case CMD_JUDGEOBJ    : // play judge objection
            case CMD_GROUPOBJ    : // play group objection
            case CMD_TRIXIEHOLD  : // play trixie holdit
            case CMD_PHOENIXHOLD : // play phoenix holdit
            case CMD_PHOENIXTAKE : // play phoenix take that!
                break;

            case CMD_STOPMUS     : // stop music
                break;

            case CMD_MUSPROLOG   : // Apollo Justice - Prologue
            case CMD_MUSSTEEL    : // Steel Samurai Ringtone
            case CMD_MUSLOUNGE   : // Courtroom Lounge - Another Prelude - Phoenix Wright: Justice for All
            case CMD_MUSMLP      : // My Little Pony - Friendship is Magic Theme (8-bit) - RainbowCrash88
            case CMD_MUSTROUPE   : // Gramarye Troupe - Apollo Justice Ace Attorney
            case CMD_MUSTRIAL    : // Ace Attorney 4 - Trial - Apollo Justice Ace Attorney
            case CMD_MUSTRACE    : // Trance Logic - Apollo Justice Ace Attorney
            case CMD_MUSTRICK    : // Trick and Magic - Phoenix Wright: Justice for All
            case CMD_MUSCRUSADE  : // Crusading - SoloAcapello
            case CMD_MUSEXAM     : // Examination - Moderate 2007 - Apollo Justice Ace Attorney
            case CMD_MUSSTART    : // Apollo Justice - Start of a New Trial! - Apollo Justice Ace Attorney
            case CMD_MUSCHESS    : // Logic Chess - Moderato - Ace Attorney Investigations 2
            case CMD_MUSOBJECT   : // Objection! 2009 - Ace Attorney Investigations 2
            case CMD_MUSTHRILL   : // Thrill Theme - Suspense
            case CMD_MUSINTEREST : // Interesting People - Ace Attorney Investigations
            case CMD_MUSSUSPENSE : // Suspense - Phoenix Wright Ace Attorney
            case CMD_MUSPEARLY   : // With Pearly - Phoenix Wright Justice for All
            case CMD_MUSCROSS    : // Cross Examination - Moderate 2002 - Phoenix Wright Justice For All
            case CMD_MUSSISTER   : // Turnabout Sisters - Capcom
            case CMD_MUSSMILE    : // Smile Instrumental - Hasbro
            case CMD_MUSKLAVIER  : // Klavier's Theme - Capcom
            case CMD_MUSLOCK     : // Lock on the Heart - Capcom
            case CMD_MUSGIGGLE   : // Giggle at the Ghosties - Hasbro
            case CMD_MUSINVEST   : // Investigation Middle - Capcom
            case CMD_MUSCLOCK    : // Like Clockwork - SoloAcapello
            case CMD_MUSSPECIAL  : // Special Delivery! - SoloAcapello
            case CMD_MUSRARITY   : // Rarity's Theme - MandoPony
            case CMD_MUSAJ       : // Applejack's Theme - AcousticBrony
            case CMD_MUSSWEPT    : // Sweptaway Turnabout - Capcom
            case CMD_MUSHOTLINE  : // Hotline to Destiny - Capcom
            case CMD_MUSKG8      : // KG-8 Case - Capcom
            case CMD_MUSPRELUDE  : // Unending Prelude - Capcom
            case CMD_MUSBEGIN    : // Court Begins - Capcom
            case CMD_MUSCOOL     : // Too Cool For You, Dweeb - SoloAcapello
            case CMD_MUSTRUTH    : // Tell the Truth 2002 - Capcom
            case CMD_MUSLYING    : // Lying Coldly - Capcom
            case CMD_MUSMEMORY   : // Memories - SoloAcapello
            case CMD_MUSCOURT    : // Court Begins Orchestrated - Capcom
            case CMD_MUSPURSUIT  : // Pursuit - Questioned - Capcom
            case CMD_MUSEND      : // Ace Attorney ~ End - Capcom
            case CMD_MUSTRIALS   : // Trials and Tribulation WiiWare Rips - HoodieD
            case CMD_MUSMOON     : // Moonlight Sonata - The Orchard Music
            case CMD_MUSCORNERED : // Pursuit Cornered 2001 - Capcom
            case CMD_MUSWON      : // Won the Lawsuit - Magical Trick Society
            case CMD_MUSWINTER   : // Winter Wrap Up - David Larson
                break;

            default:
                break;
        }

        // update name and text
        set_name((story[index].cmdwho & 0xff00) - PP_FIRST);
        set_text(story[index].text);

        // draw out the text - abort loop on keypress
        int len = (int)strlen(story[index].text);
        for (int i=1; i<len; ++i) {
            set_maxlen(i);
            for (int j=0; j<2; ++j) {
                draw_screen();
            }
        }
        set_maxlen(len);

        // now enter command loop
        for (;;) {
            draw_screen();

            // read keyboard - this requires input on the text window...
            if (!_kbhit()) continue;
            int ch = tolower(_getch());

            // act on 'next' or 'inventory'
            if (ch == 'n') {
                ++index;
                break;
            }

            if (ch == 'i') {
                run_inventory();
                continue;
            }

            if (ch == '7') {
                // fctn-7 for AID
                run_aid();
                continue;
            }
        }

    }

    // should never get here
    return 0;
}

#endif
