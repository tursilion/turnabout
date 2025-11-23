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
    UPPER(xrw) : ORIGIN = 0xA000, LENGTH = 24K
    /* reserving 256 bytes minimum for stack */
    LOWER(xrw) : ORIGIN = 0x2000, LENGTH = 0x1f00 
}

SECTIONS {
    PROVIDE (__executable_start = 0xA000); 

    .text :
    {
        PROVIDE(stextupper = .);

        crt0_ea5.o
        cache.o
        voice.o
        *libti99.a:*
/* we need all the above to finish before 0xf000 for the caching to be safe */
        aid.o
        crossexam.o 
        engine.o 
        inventory.o 
        Locations.o 
        savegame.o 
        sfx.o 
        story.o 
        People.o(.text .rodata)
        scratchloaderStandalone.o

        PROVIDE(etextupper = .);
    } > UPPER

    .lowertext :
    {
        PROVIDE(stextlower = .);

        *libtivgm2.a:*
        Evidence.o(.text .rodata)
        music.o(.text .rodata)
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

    songDatVars : { *(.songDatVars) } > LOWER
    
    _end = .; PROVIDE (end = .);
}
