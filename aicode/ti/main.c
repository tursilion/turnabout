#include <vdp.h>
#include <files.h>
#include <system.h>

/**
 * Load pattern data from disk file directly to VDP memory
 * filename: Name of pattern file on disk
 * Returns: 0 on success, non-zero on error
 */
int load_pattern_table(const char* filename) {
    struct PAB pab;
    unsigned char status;
    unsigned int vdp_pab_addr = 0x3800; /* Safe VDP address for PAB */
    
    /* Set up PAB for loading PROGRAM file directly to VDP */
    pab.OpCode = DSR_LOAD;
    pab.Status = 0; /* Will be set by DSR */
    pab.VDPBuffer = gPattern; /* Load directly to pattern table */
    pab.RecordLength = 0; /* Not used for PROGRAM files */
    pab.CharCount = 0; /* Will be set by DSR */
    pab.RecordNumber = 0x1802; /* Buffer size - prevents data truncation in disk ROM bug */
    pab.ScreenOffset = 0;
    pab.NameLength = 0; /* Use C string length */
    pab.pName = (unsigned char*)filename;
    
    /* Load the file directly to VDP pattern table */
    status = dsrlnk(&pab, vdp_pab_addr);
    
    return (status == 0) ? 0 : -1;
}

/**
 * Load color data from disk file directly to VDP memory
 * filename: Name of color file on disk
 * Returns: 0 on success, non-zero on error
 */
int load_color_table(const char* filename) {
    struct PAB pab;
    unsigned char status;
    unsigned int vdp_pab_addr = 0x3800; /* Safe VDP address for PAB */
    
    /* Set up PAB for loading PROGRAM file directly to VDP */
    pab.OpCode = DSR_LOAD;
    pab.Status = 0; /* Will be set by DSR */
    pab.VDPBuffer = gColor; /* Load directly to color table */
    pab.RecordLength = 0; /* Not used for PROGRAM files */
    pab.CharCount = 0; /* Will be set by DSR */
    pab.RecordNumber = 0x1802; /* Buffer size - prevents data truncation in disk ROM bug */
    pab.ScreenOffset = 0;
    pab.NameLength = 0; /* Use C string length */
    pab.pName = (unsigned char*)filename;
    
    /* Load the file directly to VDP color table */
    status = dsrlnk(&pab, vdp_pab_addr);
    
    return (status == 0) ? 0 : -1;
}

/**
 * Initialize name table for bitmap mode
 * Sets up the name table with sequential pattern references for each screen third
 */
void init_name_table(void) {
    unsigned char pattern_num = 0;
    
    /* Fill name table with sequential pattern numbers */
    /* In bitmap mode, each 8x8 cell references its corresponding pattern */
    /* Each third of screen (256 patterns) uses patterns 0-255 */
    for (int i = 0; i < 768; i++) {  /* 768 = 32*24 screen positions */
        vdpscreenchar(i, pattern_num);
        pattern_num = (pattern_num + 1) % 256;
    }
}

/**
 * Main application entry point
 */
int main(void) {
    /* Initialize file system for 1 open file */
    files(1);
    
    /* Initialize VDP for bitmap mode with 8x8 sprites */
    set_bitmap(VDP_SPR_8x8);
    
    /* Initialize name table for bitmap display */
    init_name_table();
    
    /* Load pattern data from disk */
    if (load_pattern_table("DSK1.PATTERN") != 0) {
        /* Pattern load failed - halt system */
        halt();
    }
    
    /* Load color data from disk */
    if (load_color_table("DSK1.COLOR") != 0) {
        /* Color load failed - halt system */
        halt();
    }
    
    /* Main loop - keep program running and handle interrupts */
    while (1) {
        /* Wait for vertical interrupt to maintain display timing */
        vdpwaitvint();
    }
    
    return 0;
}
