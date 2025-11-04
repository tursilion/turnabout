 def _start
 def _init_data
 ref ams
 
# Entry point for C runtime initilization code
#
# This will set initial values for data memory and otherwise create
# the conditions needed for the C environment
_start:

# Disable interrupts
#
# This will disable console reset via keyboard, music playback,
# sprite automotion, etc. But will make the environment much simpler
# to work in. Users can re-enable interrupts later if they wish.
  limi 0

# Set initial workspace
#
# The registers will be located at the start of scratchpad memory 
  lwpi >8300

# Initialize data segment to known values
  li   r0, _init_data  # Point to data initialization structure
  mov  *r0+, r1        # R1 = Start of data section
  mov  *r0+, r2        # R2 = Location of initial data
  mov  *r0+, r3        # R3 = Size of data section
  jeq  data_copy_end   # If size is 0, skip the loop
  
  # Copy loop for data initialization
data_copy_top:
  mov  *r2+, *r1+      
  dect r3
  jgt  data_copy_top
data_copy_end:

# Initialize BSS segment to zeroes
  mov  *r0+, r1        # R1 = Start of BSS section
  mov  *r0, r2         # R2 = Size of BSS section
  jeq  bss_clear_end   # If size is 0, skip the loop

  # Clearing loop for BSS initialization
bss_clear_top:
  clr  *r1+
  dect r2
  jgt  bss_clear_top
bss_clear_end:

# Clear flags and user interrupt
  li r1,0x0100
  mov r1,@0x83fc
  clr @0x83c4

# Create the stack
  li sp,0x4000
  
# call vdpinit to set critical variables
  bl @vdpinit  

# test for SAMS (only the loader needs to do this)
# Based on SAMS code by JediMatt42
# we should be running at >A000 with regs at >8300
# so we can bank >2000 safely here
  clr @ams
  li r12,0x1E00
  sbo 0          # enable registers - we have to make a compatible map
  li r0,0x0200   # I'm not sure this will work for all SAMS cards, safer to map BEFORE loading...
  li r1,0x0100   # sets default address for all RAM locations
  mov r0,@>4004
  a r1,r0
  mov r0,@>4006
  li r0,0x0a00
  mov r0,@>4014
  a r1,r0
  mov r0,@>4016
  a r1,r0
  mov r0,@>4018
  a r1,r0
  mov r0,@>401a
  a r1,r0
  mov r0,@>401c
  a r1,r0
  mov r0,@>401e
  sbo 1          # enable mapping

# some useful values
  li r2,0x1234   # magic value
  li r3,0x4004   # register address for >2000
  li r4,0x2000   # address >2000 - should be safe as we don't use till >2080, and no utilities are used

# we are going to start at page 16 so we don't corrupt
# the loaded RAM. 128k would be 32 pages.
  li r1,0x1000   # page 16 (little endian)
  mov r1,*r3
  mov r2,*r4
  
# map page 17 and clear
  clr r1         # page 0 (little endian) (this is mapped to >0000, so safe)
  mov r1,*r3     # register for >2000
  clr *r4
  
# map page 0 and test
  li r1,0x1000  # page 16 (little endian, beyond the normal memory map)
  mov r1,*r3    # register for >2000
  mov *r4,r0
  c r0,r2
  jne nosams
  
# there's something there, let's size it.
# To avoid corrupting memory, we'll just put a
# magic string in page 0 (which is otherwise not used
# as it backs the ROM at 0000), and then read up looking for it.
  clr r1        # for page 0
  mov r1,*r3
  mov r2,*r4+
  mov r2,*r4    # 12341234 should be unique enough
  dect r4
slp1
  inc r1        # next page
  ci r1,0x100   # 1MB limit
  jeq amsize

  swpb r1
  mov r1,*r3
  mov *r4+,r5   # get values
  mov *r4,r6
  dect r4
  swpb r1
  c r5,r2
  jne slp1
  c r6,r2
  jne slp1
  
amsize
  li r0,>0200       # default page for >2000
  mov r0,@>4004
  mov r1,@ams
  
nosams
  sbz 1
  sbz 0

# Start running C code
  bl @main

# reset the console on return
  blwp @0x0000

# Data initialization structure
#
# This structure will be filled in by the ELF conversion program
# after link time.
_init_data:
  data   # Start of data section
  data   # Location of initial contents of data section
  data   # Size of data section
  data   # Start of BSS section
  data   # Size of BSS section

