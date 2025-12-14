// let the user see their inventory

#include "structures.h"
#include "engine.h"
#include "story.h"
#include <conio.h>
#include <vdp.h>
#include <string.h>
#include <kscan.h>

#if defined(LOCATION_IS_LOADER) || defined(LAST_LOCATION)
// nothing to do here
unsigned int run_inventory(const char *pTitle) {
    return 0;
}
#else

// main engine string - we use this to save the old value
extern const char *pString;
// we hack this to force a redraw of the original text
extern int oldMaxtext;
const char *DEFTEXT = "Press letter for description, Enter to select. Period for next page.";

// if it's a special piece, we do the special work for bitmap images
// return 1 for selected itself, return -1 for redraw needed, return 0 for nothing special
int specialinventory(int selected) {
    int imgout = 0;
    unsigned char oldkey = KSCAN_KEY;
    int maxlen = 0;

    // which special evidence is it?
    if (selected == EV_CRIMESCENE) {
        // map image zoomed in
        imgout = 9008;
    } else {
        // nothing special
        return 0;
    }

    // do the shared handling
    // we're going to show an image and text for this
    bitmap_screen();
    normal_image();
    load_image(imgout);
    vdpmemset(gImage+16*32, ' ', 32);

    reverse(1);
    cputsxy(0,23,"Enter: select, period: return");
    reverse(0);

    // and clear the lastimg over in the story handler so it reloads when we're done
    reset_last_img();

    // textout is already set before we are called
    while (1) {
        // handles vblank and music
        if (maxlen < 32*7) {
            if (readerFlag) {
                maxlen = 32*7;
            } else {
                ++maxlen;
            }
            set_maxlen(maxlen);
        }
        draw_screen();

        kscanfast(0);
        if (KSCAN_KEY == oldkey) {
            continue;
        }
        // KSCAN_KEY is volatile (for some reason), so we'll use oldkey
        // to improve optimization chances
        oldkey = KSCAN_KEY;
        if (oldkey == 13) {
            // selected
            return 1;
        }
        if (oldkey == ' ') {
            maxlen = 32*7;
            set_maxlen(maxlen);
            continue;
        }
        if (oldkey == '.') {
            // redraw needed
            return -1;
        }
    }
}

// returns the element selected (might be an item or it might be a person)
// row 0: Inverted, the question (max 32 characters)
// row 1-14: available inventory
// row 16-23: description of inventory
unsigned int run_inventory(const char *pTitle) {
    // the inventory displayed for each character (A-??)
    // this needs to be drawn dynamically
    unsigned int evidx[15];
    unsigned int active = EV_NONE;
    unsigned int selected = EV_NONE;
    int ret = -1;
    int maxlen = 0;
    // save the old string, so we can reuse the drawing code
    // don't change the name, that'll cause us pain ;)
    const char *pOldString = pString;
    unsigned char oldkey = 'I';     // make sure we don't carry 'I' into here

startover:
    set_textout(DEFTEXT);

    // just a text display - so need a custom draw function
    // arrow keys to move a selector up and down, left and right to page
    // pages move to people when at end of inventory
    // enter to select and exit - no cancel needed
    set_alt_text();
    reverse(1);
    cputs(pTitle);
    reverse(0);

    while (ret == -1) {
        // first, draw the selection - there is always at least ONE item
        vdpmemset(gImage+32, ' ', 32*14);
        memset(evidx, 0, sizeof(evidx));
        unsigned int tmp = active;
        int row = 1;
        if (active < PP_FIRST) {
            // manage inventory objects up to the internal items
            while ((row < 15) && (tmp < EV_START_INTERNAL)) {
                if (!has_inventory(tmp)) {
                    ++tmp;
                    continue;
                }
                evidx[row-1] = tmp;
                gotoxy(1, row);
                
                if (selected == tmp) reverse(1);
                cprintfmini("%c.%s", 'A'+row-1, evidence[tmp].name);
                if (selected == tmp) reverse(0);

                ++tmp;
                ++row;
            }
        } else {
            // manage people - note the different step!
            // maybe a bad decision, but it's not important in the long run...
            while ((row < 15) && (tmp < PP_LAST)) {
                if (!has_inventory(tmp)) {
                    tmp += 0x100;
                    continue;
                }
                evidx[row-1] = tmp;
                gotoxy(1, row);
                if (selected == tmp) reverse(1);
                cprintfmini("%c.%s", 'A'+row-1, people[PPLIDX(tmp)].name);
                if (selected == tmp) reverse(0);
                tmp += 0x100;
                ++row;
            }
        }

        // now, update draw_screen while waiting for keypresses
        for (;;) {
            // handles vblank and music
            if (maxlen < 32*7) {
                if (readerFlag) {
                    maxlen = 32*7;
                } else {
                    ++maxlen;
                }
                set_maxlen(maxlen);
            }
            draw_screen();

            kscanfast(0);
            if (KSCAN_KEY == oldkey) {
                continue;
            }
            // KSCAN_KEY is volatile (for some reason), so we'll use oldkey
            // to improve optimization chances
            oldkey = KSCAN_KEY;
            if (oldkey == '.') {
                // find the current highest
                unsigned int next = 0;
                for (int i=0; i<15; ++i) {
                    if (evidx[i] > 0) next = evidx[i];
                }
                // advance to the next page
                if (active < PP_FIRST) {
                    // next inventory, if any. If none, go to people.
                    ++next;     // start with next thing, find next known one
                    while ((next < EV_START_INTERNAL) && (!has_inventory(next))) ++next;
                    if (next >= EV_START_INTERNAL) {
                        active = PP_FIRST;
                    } else {
                        active = next;
                    }
                } else {
                    // next people, if any. If none, go to inventory.
                    next += 0x0100; // start with next people, find next known one
                    while ((next < PP_LAST) && (!has_inventory(next))) next += 0x100;
                    if (next >= PP_LAST) {
                        active = EV_NONE;
                    } else {
                        active = next;
                    }
                }
                // and break out to redraw the screen
                selected = EV_NONE;
                clear_text();
                set_textout(DEFTEXT);
                maxlen = 0;
                break;
            }
            if (oldkey == ' ') {
                maxlen = 32*7;
                set_maxlen(maxlen);
                continue;
            }
            if (oldkey == 13) {
                // mark it selected and break out (including EV_NONE)
                ret = selected;
                break;
            }
            if ((oldkey >= 'A') && (oldkey <= 'O') && (evidx[oldkey-'A'] != 0)) {
                // update the description 
                clear_text();
                hchar(16,0,' ',32);
                selected = evidx[oldkey-'A'];
                if (selected < PP_FIRST) {
                    reverse(1);
                    cputsxy(0,16,evidence[selected].name);
                    reverse(0);

                    set_textout(evidence[selected].description);
                    // special case(s)
                    int x = specialinventory(selected);
                    if (x == 1) {
                        // it was selected
                        ret = selected;
                        break;
                    } else if (x == -1) {
                        // it was not selected, but we need to redraw
                        oldkey = '.';
                        goto startover;
                    }
                    // otherwise it was not special
                } else {
                    reverse(1);
                    cputsxy(0,16,people[PPLIDX(selected)].name);
                    reverse(0);

                    set_textout(people[PPLIDX(selected)].description);
                }
                maxlen = 0;
                // force screen redraw for the color
                break;
            }
        }
    }

    // restore the bitmap screen - we'll just call the bmp function
    bitmap_screen();
    normal_image();

    // restore the old text
    oldMaxtext = 0;
    set_maxlen(32*7-1);
    set_textout(pOldString);

    // and return the value
    return ret;
}

#endif
