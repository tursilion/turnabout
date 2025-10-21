#include "structures.h"

#ifdef LOCATION_TYPE_STORY
// we only need to process the contents of story[]. When we reach CMD_ENDSTORY, the evidence field tells us who to load
// when changing location, be sure to draw black and stop music

// TODO: we can use sprites to show blinking letters of available keys (N, P, O, etc)

#include <conio.h>
#include <string.h>
#include "engine.h"
#include "sfx.h"
#include "music.h"
#include "kscan.h"

extern Story_t story[];
extern int nStorySize;
extern int run_inventory();
extern void run_aid();

// current story index
static int index = 0;

// conversation prompts that can be prompted
// it's an error to enter prompt mode without registering any!
struct _PROMPTS {
    int tagid;          // make sure to only register EV_T_xxx tags - zero means unset
    int isread;         // set if the text was read already
    const char *str;    // pointer to the string to display for it (from the story text)
} prompts[8];

void change_index(int tag) {
    for (index = 0; index < nStorySize; ++index) {
        if ((story[index].evidence == tag) && ((story[index].cmdwho&0xff) == CMD_NONE)) {
            return;
        }
    }
    index = 0;  // couldn't find it - start over
}

// get a prompt from the user and update the index
void conversation() {
    // draw out the menu
    set_name(PP_NONE);  // needed to force the name to redraw after the menu
    set_text("");
    draw_screen();
    int max = 0;
    for (int i=0; i<8; ++i) {
        if (prompts[i].tagid == 0) break;
        gotoxy(2, 16+i);
        if (prompts[i].isread) reverse(1);
        cprintf("%c %s", i+'1', prompts[i].str);
        reverse(0);
        max = i;
    }

    for (;;) {
        VDP_WAIT_VBLANK_CRU;
        VDP_CLEAR_VBLANK;
        update_music();

        kscanfast(0);
        if ((KSCAN_KEY > '0') && (KSCAN_KEY <= max+'1')) break;
    }

    int newid = KSCAN_KEY-'1';
    prompts[newid].isread=1;
    change_index(prompts[newid].tagid);
}

// returns the next location to run
int run_story() {
    // story text is very simple - it just has to run the story text until it's finished (or told to exit)
    int lastimg = -1;

    // prep
    memset(prompts, 0, sizeof(prompts));
    index = 0;

    for (;;) {
        // process the current line
        int cmdID = story[index].cmdwho&0xff;

        // music being somewhat special, we'll check here - if it's a stop command, we should
        // stop it before we load, to reduce hiccups.
        if (cmdID == CMD_STOPMUS) {
            // TODO: We can't easily fade out. Should we play a chime like the animation does?
            stop_music();
        }

        // check for add inventory - a negative inventory is an add with no command
        if (story[index].evidence < 0) {
            add_inventory(-story[index].evidence);
        }

        // doing music this way should take less code than in the switch... just keep the order
        if ((cmdID > CMD_MUSTARTLIST) && (cmdID < CMD_MUSENDLIST)) {
            play_music(cmdID);
        } else
        if ((cmdID > CMD_SFXSTARTLIST) && (cmdID < CMD_SFXENDLIST)) {
            play_sfx(cmdID);
        } else
        if ((cmdID > CMD_VOICESTARTLIST) && (cmdID < CMD_VOICEENDLIST)) {
            play_voice(cmdID);
        } else
        // process other commands
        switch (cmdID) {
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

            case CMD_SKIPIFEV    : // skip to 'evidence' line (EV_T_xxx) if we have a certain evidence (for story control)
                if (has_inventory(story[index].evidence)) {
                    change_index(story[index].frame);
                } else {
                    ++index;
                }
                continue;

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

            case CMD_DELPROMPT   : // delete the EV_xxx prompt from the list (only used if we need to, let the user go back)
                for (int i=0; i<8; ++i) {
                    if (prompts[i].tagid == story[index].evidence) {
                        prompts[i].tagid = 0;
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

            default:
                break;
        }

        // do the image - if we don't want to, the command should continue above
        if (cmdID != CMD_BLACK) {
            if (story[index].frame != lastimg) {
                load_image(story[index].frame);
                lastimg = story[index].frame;
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
        set_text(story[index].text);

        // draw out the text - abort loop on space bar
        int len = (int)strlen(story[index].text);
        for (int i=1; i<len; ++i) {
            set_maxlen(i);
            for (int j=0; j<2; ++j) {
                draw_screen();
            }
            if (kbhit()) {
                if (cgetc() == ' ') {
                    break;
                }
            }
        }
        set_maxlen(len);

        // now enter command loop
        for (;;) {
            draw_screen();

            // read keyboard
            if (!kbhit()) continue;
            int ch = tolower(cgetc());

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
