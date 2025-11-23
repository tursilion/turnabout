#note: no cart in this one

# Paths to TMS9900 compilation tools
TMS9900_DIR?=/home/tursi/newtms9900-gcc/newgcc9900/bin
ELF2EA5_DIR?=/home/tursi/gcc9900/bin
EA5_SPLIT_DIR?=/home/tursi/gcc9900/bin
CLASSIC99_DSK1?=/mnt/d/classic99/DSK1/
LIBTI99?=/mnt/d/work/ti/libti99/

# Full paths to the executables used
GAS=$(TMS9900_DIR)/tms9900-as
LD=$(TMS9900_DIR)/tms9900-ld
CC=$(TMS9900_DIR)/tms9900-gcc

CP=/usr/bin/cp
MV=/usr/bin/mv
NAME=ploc

# Path to elf to binary tools
ELF2EA5=/home/tursi/gcc9900/bin/elf2ea5
EA5PLIT=/home/tursi/gcc9900/bin/ea5split

# Flags used during linking
#
# Locate the code (.text section) and the data (.data section)
#LDFLAGS_EA5= --section-start .text=a000 --section-start .data=2080 -M
LDFLAGS_EA5=-M -T linker.ld

INCPATH=-I/mnt/d/work/libti99ALL -I/mnt/d/work/TI/vgmcomp2/Players/libtivgm2
LIBPATH=-L/mnt/d/work/libti99ALL/buildti -L/mnt/d/work/TI/vgmcomp2/Players/libtivgm2
LIBS=-lti99 -ltivgm2

# warning - only -Os is safe, -O2 has bugs
# -x c forces files to be compiled as C, not C++
C_FLAGS=\
  -x c -DTI99 -DBUILD_TI99 -Os -std=c99 -s --save-temp -fno-peephole2 -fno-builtin -fno-function-cse

# note: crt not explicitly included as its not c
OBJECT_LIST=\
  aid.o crossexam.o engine.o Evidence.o inventory.o investigation.o Locations.o music.o People.o savegame.o sfx.o story.o cache.o voice.o

# map the objects back to source files
SOURCE_LIST := $(OBJECT_LIST:.o=.cpp)

# List of all files needed in executable
PREREQUISITES=\
  $(OBJECT_LIST_EA5)

all: pload ploc0 ploc1 ploc2 ploc3 ploc4 ploc5 ploc6 ploc10 ploc11 ploc12

# Recipe to compile the executable
# Note: The loader (PWRIGHT/etc) is simlinked to the "tipi" folder, but also built into Classic99
pload: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_pload.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_LOADER $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)99.ea5.elf > $(NAME)99_ea5.map
	$(ELF2EA5) $(NAME)99.ea5.elf $(NAME)99.ea5.bin
	$(EA5PLIT) $(NAME)99.ea5.bin
	$(MV) PLOC991 PWRIGHT
	$(MV) PLOC992 PWRIGHU
	-$(MV) PLOC993 PWRIGHV
	$(CP) PWRIGH* /mnt/d/classic99/dsk1/
	rm *.o

ploc0: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_0 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)00.ea5.elf > $(NAME)00_ea5.map
	$(ELF2EA5) $(NAME)00.ea5.elf $(NAME)00.ea5.bin
	$(EA5PLIT) $(NAME)00.ea5.bin
	$(CP) PLOC00* /mnt/d/classic99/dsk1/
	rm *.o

ploc1: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_1 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)01.ea5.elf > $(NAME)01_ea5.map
	$(ELF2EA5) $(NAME)01.ea5.elf $(NAME)01.ea5.bin
	$(EA5PLIT) $(NAME)01.ea5.bin
	$(CP) PLOC01* /mnt/d/classic99/dsk1/
	rm *.o

ploc2: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_2 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)02.ea5.elf > $(NAME)02_ea5.map
	$(ELF2EA5) $(NAME)02.ea5.elf $(NAME)02.ea5.bin
	$(EA5PLIT) $(NAME)02.ea5.bin
	$(CP) PLOC02* /mnt/d/classic99/dsk1/
	rm *.o

ploc3: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_3 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)03.ea5.elf > $(NAME)03_ea5.map
	$(ELF2EA5) $(NAME)03.ea5.elf $(NAME)03.ea5.bin
	$(EA5PLIT) $(NAME)03.ea5.bin
	$(CP) PLOC03* /mnt/d/classic99/dsk1/
	rm *.o

ploc4: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_4 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)04.ea5.elf > $(NAME)04_ea5.map
	$(ELF2EA5) $(NAME)04.ea5.elf $(NAME)04.ea5.bin
	$(EA5PLIT) $(NAME)04.ea5.bin
	$(CP) PLOC04* /mnt/d/classic99/dsk1/
	rm *.o

ploc5: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_5 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)05.ea5.elf > $(NAME)05_ea5.map
	$(ELF2EA5) $(NAME)05.ea5.elf $(NAME)05.ea5.bin
	$(EA5PLIT) $(NAME)05.ea5.bin
	$(CP) PLOC05* /mnt/d/classic99/dsk1/
	rm *.o

ploc6: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_6 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)06.ea5.elf > $(NAME)06_ea5.map
	$(ELF2EA5) $(NAME)06.ea5.elf $(NAME)06.ea5.bin
	$(EA5PLIT) $(NAME)06.ea5.bin
	$(CP) PLOC06* /mnt/d/classic99/dsk1/
	rm *.o

# no 7-9

ploc10: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_10 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)10.ea5.elf > $(NAME)10_ea5.map
	$(ELF2EA5) $(NAME)10.ea5.elf $(NAME)10.ea5.bin
	$(EA5PLIT) $(NAME)10.ea5.bin
	$(CP) PLOC10* /mnt/d/classic99/dsk1/
	rm *.o

ploc11: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_11 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)11.ea5.elf > $(NAME)11_ea5.map
	$(ELF2EA5) $(NAME)11.ea5.elf $(NAME)11.ea5.bin
	$(EA5PLIT) $(NAME)11.ea5.bin
	$(CP) PLOC11* /mnt/d/classic99/dsk1/
	rm *.o

ploc12: $(PREREQUISITES) crt0_ea5.asm
	-rm *.o
	$(GAS) crt0_ea5.asm -o crt0_ea5.o
	$(GAS) scratchloaderStandalone.a99 -o scratchloaderStandalone.o
	$(CC) -c $(C_FLAGS) -DLOCATION_IS_12 $(SOURCE_LIST) $(INCPATH)
	$(LD) crt0_ea5.o $(OBJECT_LIST) scratchloaderStandalone.o $(LIBS) $(LIBPATH) $(LDFLAGS_EA5) -o $(NAME)12.ea5.elf > $(NAME)12_ea5.map
	$(ELF2EA5) $(NAME)12.ea5.elf $(NAME)12.ea5.bin
	$(EA5PLIT) $(NAME)12.ea5.bin
	$(CP) PLOC12* /mnt/d/classic99/dsk1/
	rm *.o


# Recipe to clean all compiled objects
.phony clean:
	rm *.o
	rm *.i
	rm *.s
	rm *.elf
	rm *.map
	rm *.bin
