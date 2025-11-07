// This code is based on version 1.2 of the ELF specification


/*
 *******************************************************************************
 *                               Header Files
 *******************************************************************************
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "elf.h"


/*
 *******************************************************************************
 *                             Defined Constants
 *******************************************************************************
 */


/*
 *******************************************************************************
 *                                Data Types
 *******************************************************************************
 */


/*
 *******************************************************************************
 *                        Private Function Prototypes
 *******************************************************************************
 */

static unsigned int   reverseBytes4(unsigned int value);
static unsigned short reverseBytes2(unsigned short value);
static unsigned int   dontReverseBytes4(unsigned int value);
static unsigned short dontReverseBytes2(unsigned short value);

static void convertElfHeader(Elf32_Ehdr *ptr);
static void convertSymbolEntry(Elf32_Sym *ptr);
static void convertSectionHeader(Elf32_Shdr *ptr);



/*
 *******************************************************************************
 *                                Global Data
 *******************************************************************************
 */

// Pointers to file data translation functions, assume no translation needed
static unsigned int   (*convert4)(unsigned int value)   = dontReverseBytes4;
static unsigned short (*convert2)(unsigned short value) = dontReverseBytes2;

static Elf32_Ehdr  header;  // The ELF header for this file


/*
 *******************************************************************************
 *                                  Code
 *******************************************************************************
 */




/*
 *==============================================================================
 *                                elfOpen
 *==============================================================================
 * Description: Open an ELF file
 *
 * Parameters:  filename - The ELF file to open
 *
 * Returns:     ELF_SUCCESS   - Elf file now open
 *              ELF_NOT_FOUND - Could not open filename
 *              ELF_NOT_VALID - File is not an ELF file
 */
int main(int argc, char **argv)
{
   FILE       *input;    // The currently open ELF file
   FILE       *output;   // The output file
   Elf32_Shdr  section;  // Section header entry
   int         i;        // Section entry counter

   if(argc < 3)
   {
      printf("Usage:\n");
      printf("elf2cart <elf_file> <cart_file>\n");
      printf("\n");

      return(1);
   }

   // Attempt to open file
   input = fopen(argv[1], "rb");
   if(input == NULL)
   {
      // Could not open file
      printf("Cannot open \"%s\"\n", argv[1]);
      return(1);
   }

   // Skip to start of the section entries
   fseek(input, header.e_shoff, SEEK_SET);

   // Read ELF header
   if(fread(&header, sizeof(Elf32_Ehdr), 1, input) <= 0)
   {
      printf("File too short, invalid ELF header\n");
      return(1);
   }

   // Validate this as an ELF file
   if(header.e_ident[0] != 0x7F ||
      header.e_ident[1] != 'E'  ||
      header.e_ident[2] != 'L'  ||
      header.e_ident[3] != 'F')
   {
      // This is not a valid ELF file
      printf("Missing signature, this is not an ELF file\n");
      return(1);
   }

   // Determine endianness of the file
   if(header.e_ident[EI_DATA] == ELFDATA2MSB)
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
   if(header.e_machine != 0xABBA)
   {
      printf("Not for TMS9900, cannot convert\n");
      return(1);
   } 

   // Read the section headers

   // Move file pointer to the start of the headers
   fseek(input, header.e_shoff, SEEK_SET);

   // Load all section entries
   for(i = 0; i < header.e_shnum; i++)
   {
      // Read in a section entry
      if(fread(&section, sizeof(Elf32_Shdr), 1, input) <= 0)
      {
         printf("Early end of file, giving up\n");
         return(1);               
      }

      // Convert to native format
      convertSectionHeader(&section);
/*
      printf("\n\nSECTION %d\n",i);
      printf("====================\n");
      printf("sh_name      = %d\n", section.sh_name     );
      printf("sh_type      = %d\n", section.sh_type     );
      printf("sh_flags     = %d\n", section.sh_flags    );
      printf("sh_addr      = %d\n", section.sh_addr     );
      printf("sh_offset    = %d\n", section.sh_offset   );
      printf("sh_size      = %d\n", section.sh_size     );
      printf("sh_link      = %d\n", section.sh_link     );
      printf("sh_info      = %d\n", section.sh_info     );
      printf("sh_addralign = %d\n", section.sh_addralign);
      printf("sh_entsize   = %d\n", section.sh_entsize  );
*/
      if(section.sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
      {
         char buffer[1024];
         int readsize = 1024;
         int size = section.sh_size;
         int padsize = 0x2000 - size;
         char padding = 0;
       
         output = fopen(argv[2], "wb");
         if(output == NULL)
         {
            // Could not open file
            printf("Cannot open \"%s\"\n", argv[2]);
            return(1);
         }

         fseek(input, section.sh_offset, SEEK_SET);
         if(size < readsize) readsize = size;
         while(size >= readsize && size > 0)
         {
            if(fread(buffer, readsize, 1, input) <= 0)
            {
               printf("Early end of file, giving up\n");
               return(1);               
            }
            fwrite(buffer, readsize, 1, output);
            size -= readsize;
            if(size < readsize) readsize = size;
         }

         // Pad cart image out to 0x2000 bytes
         while(padsize-- > 0)
         {
            fwrite(&padding, 1, 1, output);
         }
         fclose(output);
         return(0);
      }
   }
   printf("Cannot find .text section in source file\n");
   return(1);
}


/*
 *******************************************************************************
 *                             Private code
 *******************************************************************************
 */


/*
 *==============================================================================
 *                               reverseBytes4
 *==============================================================================
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
 *==============================================================================
 *                               reverseBytes2
 *==============================================================================
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
 *==============================================================================
 *                               dontReverseBytes4
 *==============================================================================
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
 *==============================================================================
 *                            dontReverseBytes2
 *==============================================================================
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
 *==============================================================================
 *                            convertElfHeader
 *==============================================================================
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
 *==============================================================================
 *                            convertSectionHeader
 *==============================================================================
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

