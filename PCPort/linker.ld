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
    LOWER(xrw) : ORIGIN = 0x2080, LENGTH = 8064
}

SECTIONS {
    PROVIDE (__executable_start = 0xA000); 

    .text :
    {
        PROVIDE(stextupper = .);

        crt0_ea5.o
        aid.o
        crossexam.o 
        engine.o 
        inventory.o 
        Locations.o 
        savegame.o 
        sfx.o 
        story.o 
        *libti99.a:*
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
