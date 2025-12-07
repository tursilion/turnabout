/* 
 32k EA#5 application but some code is in lower 8k
*/

OUTPUT_FORMAT("elf32-tms9900", "elf32-tms9900",
              "elf32-tms9900")
OUTPUT_ARCH(tms9900)
ENTRY(_start)
SEARCH_DIR("/home/tursi/gcc9900/tms9900/lib");

MEMORY
{
    UPPERFIXED(xrw) : ORIGIN = 0xA000, LENGTH = 0x4000
    /* reserving 256 bytes minimum for stack */
    LOWER(xrw) : ORIGIN = 0x2000, LENGTH = 0x1f00 
    /* bank switched region for music player (linker doesnt handle music itself) */
    BANKMUSIC(xrw): ORIGIN = 0xE000, LENGTH = 4K
}

SECTIONS {
    PROVIDE (__executable_start = 0xA000); 

    .text :
    {
        PROVIDE(stextupper = .);
        
        crt0_ea5.o  /* must be first, must load at 0xA000 */
        cache.o
        voice.o
        music.o(.text .rodata)
        *libti99.a:*
    } > UPPERFIXED

/* only the loader program will contain this section! Needs to start early to beat >E000 */
    .musiccode :
    {
        PROVIDE(mustextlower = .);

        *libtivgm2.a:*
        songDatVars:*

        PROVIDE(mustextlower = .);
    } > BANKMUSIC AT> UPPERFIXED
    PROVIDE(__musiccode_load = LOADADDR(.musiccode));

    /* we need all the above to finish before 0xe000 for the paging to be safe */
    /* __musiccode_load is the binary load address to copy from! */

    /* Calculate next free address after above usage */
    PROVIDE(__upperpre_end = LOADADDR(.musiccode) + SIZEOF(.musiccode));

    /* Rest of code starts at next free address */
    /* note because there's no memory section it's not warning about overrun */
    .textpost __upperpre_end :
    {
        aid.o(.text .rodata)
        crossexam.o(.text .rodata)
        engine.o(.text .rodata)
        mybitmap.o(.text .rodata)
        inventory.o(.text .rodata)
        Locations.o(.text .rodata)
        savegame.o(.text .rodata)
        sfx.o(.text .rodata)
        story.o(.text .rodata)
        People.o(.text .rodata)
        scratchloaderStandalone.o

        PROVIDE(etextupper = .);
    }

    .lowertext :
    {
        PROVIDE(stextlower = .);

        Evidence.o(.text .rodata)
        cache.o(.text .rodata)
        investigation.o(.text .rodata)

        PROVIDE(etextlower = .);
    } > LOWER

    PROVIDE(sdata = .);
    .data : { *(.data) } > LOWER
    PROVIDE(edata = .);
    
    PROVIDE(sbss = .);
    .bss :  { *(.bss) libti99.a:*(.bss)  } > LOWER
    PROVIDE(ebss = .);

    _end = .; PROVIDE (end = .);
}
