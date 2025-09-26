This is a test conversion to test the bulk convert, to remove the text boxes and still keep as much of the important image as possible, in as few steps as possible. Steps used:

- resize to 1280x720 to have a fixed starting point
- run filter blur
- run process general enhancement
- run process contrast enhancement
- crop to 544x470 at 368,18     -- this will cause problems with the scenes with new items and scenes with magnatoma locks (manually fix?)
- resize to 148x128
- add background (black) to 256x128

Alternate approach that keeps a little more vertical and horizontal, at the expense of needing to blur out the text area:

- resize to 1280x720 to have a fixed starting point
- run filter blur
- run process general enhancement
- run process contrast enhancement
- crop to 904x476 at 190,14
- bad area is 168x51 at 0,425 - need to copy or mirror area at 0,374 (hoping our pixelization hides it)
- resize to 256x128 (ignore aspect)

I will need to remove the bad area externally... 

Most of the images come out all right this way. There are some I should hand-convert. It's not perfect, but if I don't want to redraw every frame, I think it'll do.
Note that Inventory Items were already sized in the source folder and should not run though this sequence, though the blur/process/process steps are worth doing.

For conversion, might want to convert to 256x192 to make sure Convert9918 aligns correctly. Recommend Atkinson dither with a high luma emphasize (200%), slightly higher gamma (110%), and high color shift (40%). Some frames need tuning (like 0000, raise gamma to get a faint outline of the ponies). Twilight goes grey, but.. whatever.

Cartoon color conversion - try to figure out what color something is. We have these options:

Red, green, blue, cyan (green/blue), magenta (red/blue), yellow (red/green), grey (including black and white)
- that's 7 options. Most colors have several shades. So the idea in cartoon color is to determine which one the original color was meant to be, and use that to restrict the mapping of the output color.

So we can generate a strength by subtracting the expected color from all others.
                                red     green   blue    magenta yellow  cyan    grey128
red = red*2-green-blue          512     -256    -256    256     256     -256    0
green = green*2-red-blue        -256    512     -256    -512    256     256     0
blue = blue*2-red-green         -256    -256    512     256     -512    256     0
magenta = (red+blue)-green      256     -256    256     512     0       0       128
yellow = (red+green)-blue       256     256     -256    0       512     0       128
cyan = (green+blue)-red         -256    256     256     0       0       512     128
grey = yellow*2-abs(yellow-cyan)-abs(yellow-magenta)
                                0       -1530   0       0       -510    -510    256  
                                