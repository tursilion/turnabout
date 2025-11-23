// This containts the location type ifdef, so needs to be outside it
#include "structures.h"

#ifdef LOCATION_TYPE_STORY
// we only need to process the contents of story[]. When we reach CMD_ENDSTORY, the evidence field tells us who to load
// when changing location, be sure to draw black and stop music

#include <conio.h>
#include <string.h>
#include "cache.h"
#include "engine.h"
#include "sfx.h"
#include "voice.h"
#include "aid.h"
#include "music.h"
#include "kscan.h"
#include "inventory.h"
#include "investigate.h"

// current story index
static int index = 0;
// load loaded story picture
int lastimg = -1;
// last evidence shown
int shownEvidence = EV_NONE;

// conversation prompts that can be prompted
// it's an error to enter prompt mode without registering any!
// TODO: thinking of reducing the maximum to six? Maybe push it down out of the nametag line
struct _PROMPTS {
    int tagid;          // make sure to only register EV_T_xxx tags - zero means unset
    int isread;         // set if the text was read already
    const char *str;    // pointer to the string to display for it (from the story text)
} prompts[8];

// REMEMBER! Any target of a change_index must have a target command less than CMD_VOICEENDLIST
void change_index(int tag) {
    for (index = 0; index < nStorySize; ++index) {
        if ((story[index].evidence == tag) && ((story[index].cmdwho&0xff) < CMD_VOICEENDLIST)) {
            return;
        }
    }
    index = 0;  // couldn't find it - start over
}

void reset_last_img() {
    lastimg = -1;
}

// get a prompt from the user and update the index
void conversation() {
    int max;

    // draw out the menu
    set_name(PP_NONE);  // needed to force the name to redraw after the menu
    set_textout("");
    draw_screen();
    
redraw:
    max = 0;
    for (int i=0; i<8; ++i) {
        if (prompts[i].tagid == 0) break;
        gotoxy(1, 16+i);
        if (prompts[i].isread) reverse(1);
        cprintfmini("%c %s", i+'1', prompts[i].str);
        reverse(0);
        max = i;
    }

    // location 0 can't get here, so we can just do the main string
    int cnt = 0;
    for (;;) {
        music_delay();

        if (cnt%60 == 0) {
            if (cnt%120 == 0) {
                // set up the sprite string for inventory check
                spritestring("I", COLOR_WHITE);
            } else {
                spritestring("I", COLOR_DKGREEN);
            }
        }
        ++cnt;

        kscanfast(0);
        unsigned char x = KSCAN_KEY;
        if ((x > '0') && (x <= max+'1')) break;

        if (x == 'I') {
            run_inventory("Press enter to return to game");
            goto redraw;
        }

        // TODO: hmm. What if we get 7 story options? Should we change it to letters? Would conflict with inventory...
        // I could make = the help screen, but if you accidentally did fctn-= you'd reset after getting there. I can't
        // read the FCTN key otherwise it'd be easy...
        // I'll try to keep options to 6 or fewer...
        if (x == '7') {
            // fctn-7 for AID
            run_aid(0);
            goto redraw;
        }

    }

    int newid = KSCAN_KEY-'1';
    prompts[newid].isread=1;
    change_index(prompts[newid].tagid);
}

// returns the next location to run
int run_story() {
    // story text is very simple - it just has to run the story text until it's finished (or told to exit)

    // prep
    memset(prompts, 0, sizeof(prompts));
    index = 0;

    for (;;) {
        // process the current line
        int cmdID = story[index].cmdwho&0xff;

        // music being somewhat special, we'll check here - if it's a stop command, we should
        // stop it before we load, to reduce hiccups.
        if (cmdID == CMD_STOPMUS) {
            stop_music();
            play_sfx(CMD_CHIMESFX);
        }

        // doing music this way should take less code than in the switch... just keep the order
        if ((cmdID > CMD_MUSTARTLIST) && (cmdID < CMD_MUSENDLIST)) {
            play_music(cmdID);
        } else
        if ((cmdID > CMD_SFXSTARTLIST) && (cmdID < CMD_SFXENDLIST)) {
            play_sfx(cmdID);
        } else
        if ((cmdID > CMD_VOICESTARTLIST) && (cmdID < CMD_VOICEENDLIST)) {
            play_voice(cmdID-CMD_VOICESTARTLIST-1);
        } else
        // process other commands
        switch (cmdID) {
            case CMD_BLACK       : // draw a black screen - ignore frame (but clear last frame so we know to load again)
                black_image();
                lastimg = -1;
                break;

            case CMD_WHITE       : // draw a white screen, play inverted crash - ignore frame (but clear last frame so we know to load again)
                white_image();
                play_sfx(CMD_CHIMESFX);
                lastimg = -1;
                break;

            case CMD_ENDSTORY    : // end this story sequence and return to main loop. Story stores new location in evidence field and will jump to it.
                stop_music();
                return story[index].evidence;

            case CMD_REMOVEEV    : // remove evidence from inventory (evidence field) and go to next line if text if empty
                remove_inventory(story[index].evidence);
                if (story[index].text[0] == '\0') {
                    ++index;
                    continue;
                }
                break;

            case CMD_ADDEV       : // add evidence (evidence field) and go to next line if the text if empty
                add_inventory(story[index].evidence);
                if (story[index].text[0] == '\0') {
                    ++index;
                    continue;
                }
                break;

            case CMD_SHOWEV      : // request the user show evidence, text is in text field, result is saved to test later
                shownEvidence = run_inventory(story[index].text);
                ++index;
                continue;

            case CMD_JUMPIFSHOW  : // if the last evidence shown matches 'evidence', then jump to 'story frame'
                if (shownEvidence == story[index].evidence) {
                    change_index(story[index].frame);
                } else {
                    ++index;
                }
                continue;

            case CMD_JUMPIFEV    : // skip to 'story frame' line (EV_T_xxx) if we have a certain evidence (for story control)
                if (has_inventory(story[index].evidence)) {
                    change_index(story[index].frame);
                } else {
                    ++index;
                }
                continue;

            case CMD_JUMPIFNOEV    : // skip to 'story frame' line (EV_T_xxx) if we do NOT have a certain evidence (for story control)
                if (!has_inventory(story[index].evidence)) {
                    change_index(story[index].frame);
                } else {
                    ++index;
                }
                continue;

            case CMD_JUMP        : // always jump to the line in evidence
                change_index(story[index].evidence);
                continue;

            case CMD_CLRPROMPT   : // clear all prompts from the conversation - continue to run as story
                memset(prompts, 0, sizeof(prompts));
                break;  

            case CMD_ADDPROMPT   : // Add this string and EV_I_name to the conversation prompts (and skip to the next one) - EV is how we find it
                for (int i=0; i<8; ++i) {
                    if (prompts[i].tagid == story[index].evidence) {
                        // already exists
                        break;
                    }
                    if (prompts[i].tagid == 0) {
                        prompts[i].tagid = story[index].evidence;
                        prompts[i].str = story[index].text;
                        prompts[i].isread = 0;
                        break;
                    }
                }
                ++index;
                continue;

            case CMD_CHANGEPROMPT   : // update the EV_xxx prompt with new target and/or text
                for (int i=0; i<8; ++i) {
                    if (prompts[i].tagid == story[index].evidence) {
                        if (story[index].frame != 0) {
                            prompts[i].tagid = story[index].frame;
                        }
                        if (*story[index].text != '\0') {
                            prompts[i].str = story[index].text;
                        }
                        break;
                    }
                }
                ++index;
                continue;

            case CMD_SELPROMPT   : // go back to the prompt selection list (after this line)
                // updates index
                conversation();
                continue;

#ifdef LOCATION_TYPE_INVESTIGATION
            case CMD_INVESTIGATE:
                // assumes image is already loaded. Returns EV_0_1 through EV_I_7 in the shownEvidence field
                // frame contains EV_T_ILEFTOK, EV_T_RIGHTOK, or EV_T_BOTHOK to indicate the legality of returning EV_I_SEARCH_LEFT or EV_I_SEARCH_RIGHT
                shownEvidence = investigate(story[index].frame);
                ++index;
                continue;
#endif

            default:
                break;
        }

        // do the image - if we don't want to, the command should continue above
        if (cmdID != CMD_BLACK) {
            if (story[index].frame != lastimg) {
                // gcc doesn't treat story[index].frame as cachable, 
                // or even story[index], so recalculates it all every access
                int tmp = story[index].frame;
                lastimg = tmp;
                load_image(tmp);
            }
        }

        // special check for BOOM - has to be after picture load
        if (cmdID == CMD_FLASH) {
            invert_image();
            play_sfx(CMD_BOOMSFX);
            for (int j=0; j<12; ++j) {
                draw_screen();
            }
            normal_image();
        }

        // update name and text
        set_name(story[index].cmdwho & 0xff00);
        set_textout(story[index].text);

        // Now after all that, if we are on CMD_NONE and there is no text, then proceed
        // it was probably just a label (but we still want to load images on it)
        if ((cmdID == CMD_NONE) && (story[index].text[0] == '\0')) {
            ++index;
            continue;
        }

        // draw out the text - abort loop on space bar
        int len = (int)strlen(story[index].text);
        for (int i=1; i<len; ++i) {
            set_maxlen(i);
            for (int j=0; j<2; ++j) {
                draw_screen();
            }
            kscanfast(0);
            if (KSCAN_KEY == ' ') {
                break;
            }
        }
        set_maxlen(len);

        // wait for non-space to be released, space is okay as it's not used below
        while ((KSCAN_KEY != 0xff) && (KSCAN_KEY != ' ')) {
            kscanfast(0);
        }

        // now enter command loop
        int cnt = 0;
        for (;;) {
            draw_screen();
            if (cnt%60 == 0) {
#ifdef LOCATION_IS_0
                if (cnt%120 == 0) {
                    // set up the sprite string
                    spritestring("N", COLOR_WHITE);
                } else {
                    spritestring("N", COLOR_DKGREEN);
                }
#else
                if (cnt%120 == 0) {
                    // set up the sprite string
                    spritestring("NI", COLOR_WHITE);
                } else {
                    spritestring("NI", COLOR_DKGREEN);
                }
#endif
            }
            ++cnt;

            // read keyboard
            kscanfast(0);
            if (KSCAN_KEY == 0xff) continue;
            int ch = KSCAN_KEY;

            // act on 'next' or 'inventory'
            if (ch == 'N') {
                ++index;
                break;
            }

            // no inventory on location 0
#ifndef LOCATION_IS_0
            if (ch == 'I') {
                run_inventory("Press enter to return to game");
                continue;
            }
#endif

            if (ch == '7') {
                // fctn-7 for AID
                run_aid(0);
                continue;
            }

            if (ch =='R') {
                // reload current frame
                invalidateCache(lastimg);
                reset_last_img();
                break;
            }
        }

        // clear the sprites
        vdpchar(gSprite, 0xd0);
    }

    // should never get here
    return 0;
}

#endif
