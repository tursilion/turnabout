// chopbmp.cpp : reduce a TI bitmap to just 2/3rds of a frame
// pass in index number (assumes phoenix 0000.tiap, etc)
// then top/middle/bottom
// Maybe eventually we filter out the name badge too?
// If there is a palette file, the 32 bytes are appended to the pattern

#include <iostream>
#include <stdio.h>

unsigned char buf[8192+32];
FILE *fp;

void fixbuf(unsigned char *buf, char *mode) {
    // remember to save the 128 bytes of TIFILES header!

    if (0 == strcmp(mode,"top")) {
        // nothing to do, it already starts at the top
    } else if (0 == strcmp(mode, "middle")) {
        // take four rows off the top. Each row is 32*8 bytes
        memmove(128+buf, 128+buf+32*8*4, 32*8*16);
    } else if (0 == strcmp(mode, "bottom")) {
        // take 8 rows off the top
        memmove(128+buf, 128+buf+32*8*8, 32*8*16);
    } else {
        printf("Unknown mode %s\n", mode);
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("chopbmp <index> [top|middle|bottom]\n");
        printf("Writes p0000.TIAP and p0000.TIAC (TIAM is appended to TIAP)\n");
        return 1;
    }

    char szfn[1024];
    char workchar = 'p';    // p or f - we'll autodetect

    snprintf(szfn, sizeof(szfn), "%c%04d.TIAP", workchar, atoi(argv[1]));
    fp = fopen(szfn, "rb");
    if (NULL == fp) {
        workchar = 'f';
        snprintf(szfn, sizeof(szfn), "%c%04d.TIAP", workchar, atoi(argv[1]));
        fp = fopen(szfn, "rb");
        if (NULL == fp) {
            printf("Can't open %s\n", szfn);
            return 1;
        }
    }
    printf("Found %s\n", szfn);
    if (fread(buf, 1, 0x1800, fp) < 6144) {
        printf("* Already processed\n");
        return 1;
    }
    fclose(fp);
    remove(szfn);

    // turn 6k into 4k
    fixbuf(buf, argv[2]);
    
    // patch the TIFILES header
    buf[9]=0x10;    // length in sectors from 0x18 to 0x10

    // try for the palette file
    if (workchar == 'f') {
        snprintf(szfn, sizeof(szfn), "%c%04d.TIAM", workchar, atoi(argv[1]));
        fp = fopen(szfn, "rb");
        if (NULL != fp) {
            printf("Found %s\n", szfn);
            fread(&buf[0x1000], 1, 128+32, fp); // include room for the TIFILES header
            fclose(fp);
            // move just the data
            memmove(&buf[0x1000], &buf[0x1080], 32);
            // patch the TIFILES header
            buf[9]=0x11;    // length in sectors from 0x10 to 0x11
            buf[12]=0x20;   // with 32 bytes in the extra sector
            remove(szfn);
        }
    }

    // write it out
    snprintf(szfn, sizeof(szfn), "%c%04d.TIAP", workchar, atoi(argv[1]));
    fp = fopen(szfn, "wb");
    if (NULL == fp) {
        printf("Failed to write %s\n", szfn);
        return 1;
    }
    fwrite(buf, 1, 128+0x1000+buf[12], fp);
    fclose(fp);

    // now color
    snprintf(szfn, sizeof(szfn), "%c%04d.TIAC", workchar, atoi(argv[1]));
    fp = fopen(szfn, "rb");
    if (NULL == fp) {
        printf("Can't open %s\n", szfn);
        return 1;
    }
    printf("Found %s\n", szfn);
    fread(buf, 1, 0x1800, fp);
    fclose(fp);
    remove(szfn);

    // turn 6k into 4k
    fixbuf(buf, argv[2]);

    // black out the last two rows
    int off = 15*32*8;
    for (int c=0; c<32; ++c) {
        memset(&buf[off+c*8+6+128], 0, 2);
    }
    
    // patch the TIFILES header
    buf[9]=0x10;    // length in sectors from 0x18 to 0x10

    snprintf(szfn, sizeof(szfn), "%c%04d.TIAC", workchar, atoi(argv[1]));
    fp = fopen(szfn, "wb");
    if (NULL == fp) {
        printf("Failed to write %s\n", szfn);
        return 1;
    }
    fwrite(buf, 1, 128+0x1000, fp);
    fclose(fp);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
