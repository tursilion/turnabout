/*
This code is based on version 1.2 of the ELF specification

This program converts an ELF32 source file for a TMS9900 target into a
TI99/4A EA5 binary file.

This is done by copying the .text and .data sections to the output file.
The .text section is placed at the start of the file, and the .data section
is placed immediately after that.

Assumptions:

The entry point for the executable is at the start of the .text ssection.
There is a "_init_data" symbol followed by space for a ten byte record.
That record holds the data required to initialize the .data and.bss 
sections once the EA5 image has been loaded.

Tursi has revamped most of the loader such that any section in the right
memory spaces is saved. We also split to 8k blocks in this app instead of
needing a separate app. Note that no special provision for initialized
data across the two banks is made, but everything in data should be okay.
*/


/*
 ****************************************************************************
 *                                Header Files
 ****************************************************************************
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "elf.h"


/*
 ****************************************************************************
 *                                Data Types
 ****************************************************************************
 */

// Structure used to store initialization data
typedef struct
{
   short data_addr;    // Start of data section
   short data_src;     // Location of initial contents of data section
   short data_size;    // Size of data section
   short bss_addr;     // Start of BSS section
   short bss_size;     // Size of BSS section
} init_data_struct;


/*
 ****************************************************************************
 *                            Function Prototypes
 ****************************************************************************
 */

static unsigned int   reverseBytes4(unsigned int value);
static unsigned short reverseBytes2(unsigned short value);
static unsigned int   dontReverseBytes4(unsigned int value);
static unsigned short dontReverseBytes2(unsigned short value);

static void convertElfHeader(Elf32_Ehdr *ptr);
static void convertSymbolEntry(Elf32_Sym *ptr);
static void convertSectionHeader(Elf32_Shdr *ptr);
static void convertProgramHeader(Elf32_Phdr *ptr);


/*
 ****************************************************************************
 *                                Global Data
 ****************************************************************************
 */

// Pointers to file data translation functions, assume no translation needed
static unsigned int   (*convert4)(unsigned int value)   = dontReverseBytes4;
static unsigned short (*convert2)(unsigned short value) = dontReverseBytes2;

static Elf32_Ehdr  header;  // The ELF header for this file


/*
 ****************************************************************************
 *                                   Code
 ****************************************************************************
 */

// write a TIFILES PROGRAM header for size bytes
void writeTIFILES(FILE *fp, int data_size) {
/*
 * Write TIFILES header for PROGRAM image type
 * TIFILES format: 128-byte header followed by data
 * 
 * Header structure (first 16 bytes are standard):
 * Offset  Size  Description
 * 0x00    8     Identifier: "\x7TIFILES" (not null-terminated)
 * 0x08    2     Total sectors (big-endian, includes header sectors)
 * 0x0A    1     File flags (PROGRAM = 0x01)
 * 0x0B    1     Records per sector (0 for PROGRAM files)
 * 0x0C    1     EOF offset (bytes used in last sector, 0 = 256)
 * 0x0D    1     Record length (0 for PROGRAM files)
 * 0x0E    2     Number of level 3 records (big-endian, 0 for PROGRAM)
 * 0x10    ... Filename and other optional fields follow
 * 
 * Total header is 128 bytes (0x80)
 */
    unsigned char header[128];
    int data_sectors;
    int eof_offset;
    int i;
    const char *tifiles_id = "\x7TIFILES";
    
    /* Calculate data sectors (256 bytes each) */
    data_sectors = (data_size + 255) / 256;
    
    /* Calculate EOF offset (bytes used in last data sector, 0 = 256) */
    eof_offset = data_size % 256;
    
    /* Initialize entire header to zeros */
    memset(header, 0, sizeof(header));
    
    /* Bytes 0-7 Identifier "TIFILES" */
    for (i = 0; i < 8; i++) {
        header[i] = (unsigned char)tifiles_id[i];
    }
    
    /* Bytes 8-9: Total sectors (big-endian) */
    header[8] = (unsigned char)(data_sectors >> 8);
    header[9] = (unsigned char)(data_sectors & 0xFF);
    
    /* Byte 10: File flags = 0x01 (PROGRAM) */
    header[10] = 0x01;
    
    /* Byte 11: Records per sector = 0 (not used for PROGRAM) */
    header[11] = 0x00;
    
    /* Byte 12: EOF offset */
    header[12] = (unsigned char)eof_offset;
    
    /* Byte 13: Record length = 0 (not used for PROGRAM) */
    header[13] = 0x00;
    
    /* Bytes 14-15: Number of level 3 records = 0 (big-endian, not used for PROGRAM) */
    header[14] = 0x00;
    header[15] = 0x00;
    
    /* Write 128-byte header to file */
    fwrite(header, 1, 128, fp);
}

/* Convert string to uppercase in place
 * str: pointer to null-terminated string to convert
 * Returns: pointer to modified string
 */
char* strupr(char* str) {
    char* p = str;
    while (*p) {
        *p = toupper((unsigned char)*p);
        p++;
    }
    return str;
}

/*===========================================================================
 *                                copy_block
 *===========================================================================
 * Description: Copy a block of data
 *
 * Parameters:  input  - Input file
 *              output - Output file
 *              size   - Number of bytes to copy
 *
 * Returns:     1 - None
 */
int copy_block(FILE* input, FILE* output, int size)
{
   // I don't think I use this anymore
   char buffer[1024];
   int readsize = 1024;

   if (size < readsize) readsize = size;
   while(size >= readsize && size > 0)
   {
      if (fread(buffer, readsize, 1, input) <= 0)
      {
         return(0);               
      }
      fwrite(buffer, readsize, 1, output);
      size -= readsize;
      if (size < readsize) readsize = size;
   }
   return(1);
}


/*
 *===========================================================================
 *                                main
 *===========================================================================
 * Description: Entry point for program
 *
 * Parameters:  argc - Number of arguments
 *              argv - Argument list
 *
 * Returns:     
 */
int main(int argc, char **argv)
{
    FILE       *input;         // The currently open ELF file
    FILE       *output;        // The output file
    Elf32_Shdr *all_sections;  // Section header entry
    Elf32_Shdr *section;       // Section header entry
    int         i;             // Section entry counter
    Elf32_Sym   symbol;        // Symbol table entry
    char *strtab;              // Copy of the string table
    int init_data_addr = 0;    // Address of "_init_data" symbol
    // this will need some cleanup. We actually should be using
    // the program headers for proper loading.
    // Use readelf -l <filename> to see how the load blocks are
    // built - it will also tell you which sections are included.
    // the program headers differentiate between load address and
    // run address so are necessary for banked code and code that
    // must be moved.
    Elf32_Phdr *all_proghdrs;  // Program header entry
    Elf32_Phdr *proghdr;       // Program header entry

    Elf32_Shdr *text_section   = NULL;
    Elf32_Shdr *lower_text_section   = NULL;
    Elf32_Shdr *data_section   = NULL;
    Elf32_Shdr *bss_section    = NULL;
    Elf32_Shdr *symtab_section = NULL;
    Elf32_Shdr *strtab_section = NULL;

    int size;
    init_data_struct init_data;
    short ea5_header[3];
    int image_size;

    // Check arguments
    if (argc < 3)
    {
        printf("Usage:\n");
        printf("elf2cart <elf_file> <cart_file>\n");
        printf("\n");

        return(1);
    }

    // Attempt to open file
    input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        // Could not open file
        printf("Cannot open \"%s\"\n", argv[1]);
        return(1);
    }

    // Skip to start of the section entries
    fseek(input, header.e_shoff, SEEK_SET);

    // Read ELF header
    if (fread(&header, sizeof(Elf32_Ehdr), 1, input) <= 0)
    {
        printf("Error: File too short, invalid ELF header\n");
        return(1);
    }

    // Validate this as an ELF file
    if (header.e_ident[0] != 0x7F ||
        header.e_ident[1] != 'E'  ||
        header.e_ident[2] != 'L'  ||
        header.e_ident[3] != 'F')
    {
        // This is not a valid ELF file
        printf("Error: Missing signature, this is not an ELF file\n");
        return(1);
    }

    // Determine endianness of the file
    if (header.e_ident[EI_DATA] == ELFDATA2MSB)
    {
        // We need to reverse all bytes read or saved from the file
        convert4 = reverseBytes4;
        convert2 = reverseBytes2;
    }
    else
    {
        // No need to reverse data, we can use it natively
        convert4 = dontReverseBytes4;
        convert2 = dontReverseBytes2;
    }

    // Convert the header data to native format
    convertElfHeader(&header);
    /*
    printf("\nELF Header\n");
    printf("====================\n");
    printf("type      = 0x%X\n", header.e_type     );
    printf("machine   = 0x%X\n", header.e_machine  );
    printf("version   = 0x%X\n", header.e_version  );
    printf("entry     = 0x%X\n", header.e_entry    );
    printf("phoff     = 0x%X\n", header.e_phoff    );
    printf("shoff     = 0x%X\n", header.e_shoff    );
    printf("flags     = 0x%X\n", header.e_flags    );
    printf("ehsize    = 0x%X\n", header.e_ehsize   );
    printf("phentsize = 0x%X\n", header.e_phentsize);
    printf("phnum     = 0x%X\n", header.e_phnum    );
    printf("shentsize = 0x%X\n", header.e_shentsize);
    printf("shnum     = 0x%X\n", header.e_shnum    );
    printf("shstrndx  = 0x%X\n", header.e_shstrndx );
    */
    // Make sure this is a TMS9900 file
    if (header.e_machine != 0xABBA)
    {
        printf("Error: Not for TMS9900, cannot convert\n");
        return(1);
    } 

    // Read the section headers

    // Move file pointer to the start of the headers
    fseek(input, header.e_shoff, SEEK_SET);

    // Load all section entries
    all_sections = malloc(header.e_shnum * sizeof(Elf32_Shdr));
    for(i = 0; i < header.e_shnum; i++)
    {
        // Read in a section entry
        section = &all_sections[i];
        if (fread(section, sizeof(Elf32_Shdr), 1, input) <= 0)
        {
            printf("Error: Early end of file\n");
            return(1);               
        }

        // Convert to native format
        convertSectionHeader(section);
    }
    
    // load all program headers
    fseek(input, header.e_phoff, SEEK_SET);
    all_proghdrs = malloc(header.e_phnum * sizeof(Elf32_Phdr));
    for(i = 0; i < header.e_phnum; i++)
    {
        // Read in a program header
        proghdr = &all_proghdrs[i];
        if (fread(proghdr, sizeof(Elf32_Phdr), 1, input) <= 0)
        {
            printf("Error: Early end of file\n");
            return(1);               
        }

        // Convert to native format
        convertProgramHeader(proghdr);
    }

    // the TI Memory map (32k) - we load the data into these
    // and then write out what we got
    unsigned char upperRam[24*1024];
    unsigned char lowerRam[8*1024];
    int firstUpper=0, lastUpper=0;
    int firstLower=0, lastLower=0;
    memset(upperRam, 0, sizeof(upperRam));
    memset(lowerRam, 0, sizeof(lowerRam));
    
    // use the program headers to figure out what needs to be loaded to RAM
    for(i = 0; i < header.e_phnum; i++)
    {
        proghdr = &all_proghdrs[i];
        if (proghdr->p_type != PT_LOAD) {
            continue;
        }
        
        // memsz can be larger than filesz to accomodate bss - we've already zeroed so we're good
           
        if ((proghdr->p_paddr >= 0xa000) && (proghdr->p_paddr <= 0xffff)) {
            if (proghdr->p_paddr+proghdr->p_filesz > 0xffff) {
                printf("Error: %d in high bank is too large: 0x%04X - 0x%X\n", i, proghdr->p_paddr, proghdr->p_paddr+proghdr->p_filesz);
                return 1;
            }
            printf("Copying program block %d into high bank at 0x%04X - 0x%04X\n", i, proghdr->p_paddr, proghdr->p_paddr+proghdr->p_filesz);

            if ( ((proghdr->p_paddr >= firstUpper) && (proghdr->p_paddr < lastUpper)) ||
                 ((proghdr->p_paddr+proghdr->p_filesz >= firstUpper) && (proghdr->p_paddr+proghdr->p_filesz < lastUpper))) {
                printf("* Warning: %d in high bank appears to overlap existing code: : 0x%04X, size 0x%X\n", i, proghdr->p_paddr, proghdr->p_filesz);
            }

            fseek(input, proghdr->p_offset, SEEK_SET);
            fread(&upperRam[proghdr->p_paddr-0xa000], 1, proghdr->p_filesz, input);
            if ((proghdr->p_paddr < firstUpper) || (firstUpper == 0)) {
                firstUpper = proghdr->p_paddr;
            }
            if (proghdr->p_paddr+proghdr->p_filesz > lastUpper) {
                lastUpper = proghdr->p_paddr+proghdr->p_filesz;
            }
        } else if ((proghdr->p_paddr >= 0x2000) && (proghdr->p_paddr <= 0x3fff)) {
            if (proghdr->p_paddr+proghdr->p_filesz > 0x3fff) {
                printf("Error: %d in low bank is too large: 0x%04X - 0x%X\n", i, proghdr->p_paddr, proghdr->p_paddr+proghdr->p_filesz);
                return 1;
            }
            printf("Copying program block %d into low bank at 0x%04X - 0x%04X\n", i, proghdr->p_paddr, proghdr->p_paddr+proghdr->p_filesz);

            if ( ((proghdr->p_paddr >= firstLower) && (proghdr->p_paddr < lastLower)) ||
                 ((proghdr->p_paddr+proghdr->p_filesz >= firstLower) && (proghdr->p_paddr+proghdr->p_filesz < lastLower))) {
                printf("* Warning: %d in low bank appears to overlap existing code: : 0x%04X, size 0x%X\n", i, proghdr->p_paddr, proghdr->p_filesz);
            }

            fseek(input, proghdr->p_offset, SEEK_SET);
            fread(&lowerRam[proghdr->p_paddr-0x2000], 1, proghdr->p_filesz, input);
            if ((proghdr->p_paddr < firstLower) || (firstLower == 0)) {
                firstLower = proghdr->p_paddr;
            }
            if (proghdr->p_paddr+proghdr->p_filesz > lastLower) {
                lastLower = proghdr->p_paddr+proghdr->p_filesz;
            }
        } else {
            printf("Skipping proghdr %d, 0x%X, size 0x%X\n", i, proghdr->p_paddr, proghdr->p_filesz);
        }
    }
    

    // Do the old section parsing so we can find init_data, but that's all now
    for(i = 0; i < header.e_shnum; i++)
    {
        char name[64];
        section = &all_sections[i];

        fseek(input, all_sections[header.e_shstrndx].sh_offset + section->sh_name, SEEK_SET);
        if (fread(name, 64, 1, input) <= 0)
        {
            printf("Error: Early end of file\n");
            return(1);               
        }

        // we don't need most of this anymore - maybe the symbol and string tables...
        if (strcmp(name, ".text") == 0)     text_section   = section;
        if (strcmp(name, ".lowertext") == 0) lower_text_section   = section;
        if (strcmp(name, ".data") == 0)     data_section   = section;
        if (strcmp(name, ".bss" ) == 0)     bss_section    = section;
        if (section->sh_type == SHT_SYMTAB) symtab_section = section;
        if (section->sh_type == SHT_STRTAB) strtab_section = section;

        /*
        if (strcmp(name, ".musiccode") == 0) {
            printf("\n\nSECTION %d\n",i);
            printf("====================\n");
            printf("name=%s\n", name);
            printf("sh_name      = %x\n", section->sh_name     );
            printf("sh_type      = %x\n", section->sh_type     );
            printf("sh_flags     = %x\n", section->sh_flags    );
            printf("sh_addr      = %x\n", section->sh_addr     );
            printf("sh_offset    = %x\n", section->sh_offset   );
            printf("sh_size      = %x\n", section->sh_size     );
            printf("sh_link      = %x\n", section->sh_link     );
            printf("sh_info      = %x\n", section->sh_info     );
            printf("sh_addralign = %x\n", section->sh_addralign);
            printf("sh_entsize   = %x\n", section->sh_entsize  );
        }
        */
    }

    // If there's no .text section, there's no code to execute (not strictly true, but we assume it)
    if (text_section == NULL)
    {
        printf("Error: No .text section found\n");
        return(1);
    }

    // Build initialization structure
    // If the .data section is located immediately after the .text 
    // section n the loaded image, no need to fill out the .data
    // initializer fields as the TI loader will take care of that
    // for us when it loads the EA5 file.
    // WARNING: code in .lower_text won't benefit from any of this
    memset(&init_data, 0, sizeof(init_data_struct));
    if (data_section != NULL &&
        data_section->sh_addr != text_section->sh_addr + text_section->sh_size)
    {
        init_data.data_addr   = convert2(data_section->sh_addr);
        init_data.data_size   = convert2(data_section->sh_size);
        init_data.data_src    = convert2(text_section->sh_addr +
        text_section->sh_size);
    }
    if (bss_section != NULL)
    {
        init_data.bss_addr    = convert2(bss_section->sh_addr);
        init_data.bss_size    = convert2(bss_section->sh_size);
    }

    // Try to find "_init_data" symbol
    if (strtab_section == NULL)
    {
        printf("Warning: No string table section found\n");
        return(1);
    }
    else
    {
        // Load symbol table into memory
        strtab = malloc(strtab_section->sh_size);
        fseek(input, strtab_section->sh_offset, SEEK_SET);
        if (fread(strtab, strtab_section->sh_size, 1, input) <= 0)
        {
            printf("Error: Early end of file\n");
            return(1);               
        }      

        // Find "_init_data" symbol
        if (symtab_section == NULL)
        {
            // If there is no symbol table, we can't fill out the
            // initialization record. That might still be OK.
            printf("Warning: No symbol table section found\n");
        }
        else 
        {
            // Read through the symbol table entries 
            fseek(input, symtab_section->sh_offset, SEEK_SET);
            for(i=0; i<symtab_section->sh_size; i+=sizeof(Elf32_Sym))
            {
                if (fread(&symbol, sizeof(Elf32_Sym), 1, input) <= 0)
                {
                    printf("Error: Early end of file\n");
                    return(1);               
                }      
                if (strcmp("_init_data", &strtab[convert4(symbol.st_name)]) == 0)
                {
                    init_data_addr = convert4(symbol.st_value);
                    break;
                }
            }
        }
        free(strtab);
    }

    // Patch the "_init_data" symbol (expected to be in .text)
    fseek(input, text_section->sh_offset, SEEK_SET);
    size = text_section->sh_size;
    if (init_data_addr == 0)
    {
        printf("Warning: no \"_init_data\" symbol found\n");
    }
    else
    {
        printf("Overwriting _init_data at 0x%04X:\n", init_data_addr);
        printf("  Addr: 0x%04X\n  Size: 0x%04X\n  Src : 0x%04X\n  Bss : 0x%04X\n  Size: 0x%04X\n",
            convert2(init_data.data_addr),convert2(init_data.data_size),convert2(init_data.data_src),
            convert2(init_data.bss_addr),convert2(init_data.bss_size));
    {
        init_data.data_addr   = convert2(data_section->sh_addr);
        init_data.data_size   = convert2(data_section->sh_size);
        init_data.data_src    = convert2(text_section->sh_addr +
        text_section->sh_size);
    }
    if (bss_section != NULL)
    {
        init_data.bss_addr    = convert2(bss_section->sh_addr);
        init_data.bss_size    = convert2(bss_section->sh_size);
    }
            
        if (init_data_addr >= 0xa000) {
            // it's in the high block (normal)
            memcpy(&upperRam[init_data_addr-0xa000], &init_data, sizeof(init_data_struct));
        } else if ((init_data_addr >= 0x2000) && (init_data_addr < 0x4000)) {
            // it's in the low block (whatever)
            memcpy(&lowerRam[init_data_addr-0x2000], &init_data, sizeof(init_data_struct));
        } else {
            printf("Error - init data is not in 32k RAM space: 0x%04X\n", init_data_addr);
            return 1;
        }
    }

    // all done loading, now we can write. We'll do the split operation here
    // too, since I never need a single large ELF...
    int split_size = 8192-6;
    int current_addr = firstUpper;
    char outFilename[256];    // really shouldn't be more than 10! But there might be a path involved.
    strncpy(outFilename, argv[2], 10);
    outFilename[sizeof(outFilename)-2] = '\0';
    strcat(outFilename, "1");
    strupr(outFilename);
    int filesLeft = 6;  // prevent runaway - really shouldn't need more than 4...

    // do the top file first
    while ((current_addr != 0) && (current_addr < lastUpper)) {
        int size = lastUpper - current_addr;
        if (size > split_size) size = split_size;
        
        if (filesLeft-- < 1) {
            printf("ERROR: too many files - check data.\n");
            return 1;
        }

        printf("Writing %s: 0x%04X, size 0x%X\n", outFilename, current_addr, size);
        output = fopen(outFilename, "wb");
        if (output == NULL)
        {
            // Could not open file
            printf("Error: Cannot open \"%s\"\n", argv[2]);
            return(1);
        }
        writeTIFILES(output, size+6);   // include the EA5 header - 6 bytes

        // Write EA5 header
        //
        // The EA5 loader assumes the entry point is the load address

        // Is this the last file?
        if ((firstLower == 0) && (current_addr + size >= lastUpper)) {
            ea5_header[0] = 0;                  // Last in file chain (0000=yes, ffff=no) 
        } else {
            ea5_header[0] = 0xffff;
        }
        ea5_header[1] = convert2(size);         // Image + header size
        ea5_header[2] = convert2(current_addr);  // Load address
        fwrite(ea5_header, 6, 1, output);
        fwrite(&upperRam[current_addr-0xa000], 1, size, output);
        
        // pad to sector size if needed
        int padded = size+6;    // include EA5 header here too
        while (padded%256 > 0) {
            fputc(0,output);
            ++padded;
        }
        fclose(output);

        // update filename
        outFilename[strlen(outFilename)-1]++;
        current_addr += size;
    }

    // same loop but for lower - we probably shouldn't need to duplicate the code but wah wah...
    current_addr = firstLower;
    while ((current_addr != 0) && (current_addr < lastLower)) {
        int size = lastLower - current_addr;
        if (size > split_size) size = split_size;

        if (filesLeft-- < 1) {
            printf("ERROR: too many files - check data.\n");
            return 1;
        }

        printf("Writing %s: 0x%04X, size 0x%X\n", outFilename, current_addr, size);
        output = fopen(outFilename, "wb");
        if (output == NULL)
        {
            // Could not open file
            printf("Error: Cannot open \"%s\"\n", argv[2]);
            return(1);
        }
        writeTIFILES(output, size+6);   // include EA5 header

        // Write EA5 header
        //
        // The EA5 loader assumes the entry point is the load address

        // Is this the last file?
        if (current_addr + size >= lastLower) {
            ea5_header[0] = 0;                  // Last in file chain (0000=yes, ffff=no) 
        } else {
            ea5_header[0] = 0xffff;
        }
        ea5_header[1] = convert2(size);         // Image + header size
        ea5_header[2] = convert2(current_addr);  // Load address
        fwrite(ea5_header, 6, 1, output);
        fwrite(&lowerRam[current_addr-0x2000], 1, size, output);
        
        // pad to sector size if needed
        int padded = size+6;    // include EA5 header here too
        while (padded%256 > 0) {
            fputc(0,output);
            ++padded;
        }
        
        fclose(output);

        // update filename
        outFilename[strlen(outFilename)-1]++;
        current_addr += size;
    }

    // All done, clean up
    fclose(input);

    return(0);
}


/*
 *===========================================================================
 *                               reverseBytes4
 *===========================================================================
 * Description: Reverse the order of byytes in a 4-byte value
 *
 * Parameters:  value - The value to reverse
 *
 * Returns:     int - The reversed value
 */
static unsigned int reverseBytes4(unsigned int value)
{
   return( ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8 ) |
           ((value & 0x00FF0000) >> 8 ) |
           ((value & 0xFF000000) >> 24) );
}


/*
 *===========================================================================
 *                               reverseBytes2
 *===========================================================================
 * Description: Reverse the order of byytes in a 2-byte value
 *
 * Parameters:  value - The value to reverse
 *
 * Returns:     int - The reversed value
 */
static unsigned short reverseBytes2(unsigned short value)
{
   return( ((value & 0x00FF) << 8) |
           ((value & 0xFF00) >> 8) );
}


/*
 *===========================================================================
 *                               dontReverseBytes4
 *===========================================================================
 * Description: Do nothing to the value, just return it
 *
 * Parameters:  value - The value to ignore
 *
 * Returns:     int - The ignored value
 */
static unsigned int dontReverseBytes4(unsigned int value)
{
   return(value);
}


/*
 *===========================================================================
 *                            dontReverseBytes2
 *===========================================================================
 * Description: Do nothing to the value, just return it
 *
 * Parameters:  value - The value to ignore
 *
 * Returns:     int - The ignored value
 */
static unsigned short dontReverseBytes2(unsigned short value)
{
   return(value);
}


/*
 *===========================================================================
 *                            convertElfHeader
 *===========================================================================
 * Description: Convert the ELF header to/from native format
 *
 * Parameters:  ptr - Pointer to the header
 *
 * Returns:     None
 */
void convertElfHeader(Elf32_Ehdr *ptr)
{
   ptr->e_type      = convert2(ptr->e_type     );
   ptr->e_machine   = convert2(ptr->e_machine  );
   ptr->e_version   = convert4(ptr->e_version  );
   ptr->e_entry     = convert4(ptr->e_entry    );
   ptr->e_phoff     = convert4(ptr->e_phoff    );
   ptr->e_shoff     = convert4(ptr->e_shoff    );
   ptr->e_flags     = convert4(ptr->e_flags    );
   ptr->e_ehsize    = convert2(ptr->e_ehsize   );
   ptr->e_phentsize = convert2(ptr->e_phentsize);
   ptr->e_phnum     = convert2(ptr->e_phnum    );
   ptr->e_shentsize = convert2(ptr->e_shentsize);
   ptr->e_shnum     = convert2(ptr->e_shnum    );
   ptr->e_shstrndx  = convert2(ptr->e_shstrndx );
}


/*
 *===========================================================================
 *                            convertSectionHeader
 *===========================================================================
 * Description: Convert the section header to/from native format
 *
 * Parameters:  ptr - Pointer to the header
 *
 * Returns:     None
 */
void convertSectionHeader(Elf32_Shdr *ptr)
{
   ptr->sh_name      = convert4(ptr->sh_name     );
   ptr->sh_type      = convert4(ptr->sh_type     );
   ptr->sh_flags     = convert4(ptr->sh_flags    );
   ptr->sh_addr      = convert4(ptr->sh_addr     );
   ptr->sh_offset    = convert4(ptr->sh_offset   );
   ptr->sh_size      = convert4(ptr->sh_size     );
   ptr->sh_link      = convert4(ptr->sh_link     );
   ptr->sh_info      = convert4(ptr->sh_info     );
   ptr->sh_addralign = convert4(ptr->sh_addralign);
   ptr->sh_entsize   = convert4(ptr->sh_entsize  );
}

/*
 *===========================================================================
 *                            convertProgramHeader
 *===========================================================================
 * Description: Convert the program header to/from native format
 *
 * Parameters:  ptr - Pointer to the header
 *
 * Returns:     None
 */
void convertProgramHeader(Elf32_Phdr *ptr)
{
   ptr->p_type      = convert4(ptr->p_type     );
   ptr->p_offset    = convert4(ptr->p_offset   );
   ptr->p_vaddr     = convert4(ptr->p_vaddr    );
   ptr->p_paddr     = convert4(ptr->p_paddr    );
   ptr->p_filesz    = convert4(ptr->p_filesz   );
   ptr->p_memsz     = convert4(ptr->p_memsz    );
   ptr->p_flags     = convert4(ptr->p_flags    );
   ptr->p_align     = convert4(ptr->p_align    );
}
