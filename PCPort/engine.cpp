// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Maybe I can break it up with defines, the cross compiler won't have any trouble with that.
// for now I will not worry about the TI versions of functions

// TODO: Maybe we can go ahead and bring in raylib. For testing, we'll implement
// two side-by-side 256x192 screens - one will pull down and use the TMS9918 bitmaps
// and the other will pull down and use the F18A bitmaps. That way I can test both
// screens at the same time as well as ensure 32 column text alignment and F18A
// text pallettes are good. (F18A can maybe just use two palettes to keep life
// simple - the bottom 8 rows can use the second palette which is the default
// 9918A palette, then I can use the colored text. Though right now I just want grey text.
// Maybe can let the user cycle the colors, people like that. White on blue?

// TODO: text output needs to wordwrap

// need to save current location and current evidence, and color preferences, in vram
// when loading new files. Need a way to save and reload said preferences to disk so can
// save your game and continue.

#include "structures.h"

extern int run_story();
extern Evidence_t evidence[EV_MAX];
extern Evidence_t people[PP_MAX];

#ifdef _WIN32
// being hacky, I'm going to just include the pre-made raylib from Classic99v4
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <string.h>

const int scaler = 4;
int windowXSize = 256*scaler;
int windowYSize = 192*scaler;
Image img;
Texture2D texture;
//Font font;
int fontsize = 10;
const char *pString = NULL;
int maxtext = 32*7;
int iName = -1;

void set_bitmap(unsigned char /*sprite_mode*/) {
    if (!IsWindowReady()) {
        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN);
        InitWindow(windowXSize, windowYSize, "Turnabout Storm");            // TODO: actual size
        SetWindowMinSize(284, 243);
        //SetExitKey(RL_KEY_NULL);  // don't trap escape
        SetTargetFPS(60);
        //font = LoadFont("D:\\work\\raylib\\examples\\textures\\resources\\custom_jupiter_crash.png");
    }
}

void draw_screen() {
    if (WindowShouldClose()) {
        UnloadTexture(texture);
        UnloadImage(img);
        CloseWindow();
        exit(0);
    }

    BeginDrawing();
    ClearBackground(BLACK);

    if (img.width > 1) {
        // assumes the pics we load are not yet scaled
        if (img.width != 256*scaler) {
            ImageResize(&img, 1280, 720);
            Rectangle x = { 190, 14, 904, 476 };
            ImageCrop(&img, x);
            ImageResize(&img, 256*scaler, 128*scaler);
            texture = LoadTextureFromImage(img);
        }
        DrawTexture(texture, 0, 0, WHITE);
    }
    if (iName > PP_FIRST) {
        DrawText(people[iName-PP_FIRST].name, 0, 16*8*scaler, fontsize, WHITE);
    }
    if (pString) {
        // draw out the string one character at time with wordwrap
        // I don't know if the font will fit, guess we'll sort that later
        int cnt = maxtext;
        const char *pWork = pString;
        int y = 17;
        int x = 0;
        while (*pWork) {
            char out[2] = { 0, 0 };
            // check for space
            if (*pWork == ' ') {
                if (x > 0) x++;
                pWork++;
                if (--cnt == 0) break;
                continue;
            }
            // check first if this line fits
            int pos = 0;
            while (pWork[pos]) {
                if (pWork[pos] == ' ') break;
                ++pos;
                if (pos+x > 31) break;
            }
            if (pos+x > 31) {
                if (x > 0) {
                    // too long, and wasn't the whole line, so next line
                    y++;
                    if (y > 23) break; // out of lines
                    x=0;
                } else {
                    // just reduce to one line
                    --pos;
                }
            }
            // output the characters
            while (pos--) {
                out[0] = *(pWork++);
                DrawText(out, x*8*scaler, y*8*scaler, fontsize*scaler, WHITE);
                x++;
                if (*pWork == '\0') break;
                if (--cnt == 0) break;
            }
            if (cnt == 0) break;    // again
        }
    }

    EndDrawing();
}

void load_image(int index) {
    char buf[256];

    sprintf(buf, "D:\\work\\TI\\Phoenix Wright - turnabout storm\\images\\%04d.png", index);
    img = LoadImage(buf);
}

void invert_image() {
    // we assume at least one image is loaded before this
    ImageColorInvert(&img);
    UnloadTexture(texture);
    texture = LoadTextureFromImage(img);
}

void black_image() {
    ImageColorBrightness(&img, -255);
    UnloadTexture(texture);
    texture = LoadTextureFromImage(img);
}

#endif

#ifdef TI99
// TI versions are the real ones


#endif

//------

void add_inventory(int id) {
    if (id >= PP_FIRST) {
        id = id-PP_FIRST;
        people[id].found = 1;
    } else if (id < EV_MAX) {
        evidence[id].found = 1;
    }
}
void remove_inventory(int id) {
    evidence[id].found = 0;
}
void set_text(const char *p) {
    pString = p;
}
void set_maxlen(int i) {
    maxtext = i;
}
void set_name(int i) {
    iName = i;
}

//------

int main()
{
    set_bitmap(0);

    int nextloc = run_story();


}

