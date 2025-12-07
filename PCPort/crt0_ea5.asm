 def _start
 def _init_data
 ref AMS
 
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

# the current version of elf2ea5 (or my linker script) is not correctly
# loading the initialized data segment.. BUT, it doesn't need to as its
# directly loaded as one of the EA5 files. Still, that's a TODO BUG to
# solve in that tool. In my test here, start was correct, size was right,
# but location was just never populated, so other code was stored there
# instead. Anyway, Phoenix doesn't need this, but I need to solve it
# for the final solution (and carts will definitely need it to be right,
# though I didn't change elf2cart). the BSS is correct.
# Initialize data segment to known values
  li   r0, _init_data  # Point to data initialization structure
  mov  *r0+, r1        # R1 = Start of data section
  mov  *r0+, r2        # R2 = Location of initial data
  mov  *r0+, r3        # R3 = Size of data section
  jeq  data_copy_end   # If size is 0, skip the loop
  
  # Copy loop for data initialization
#data_copy_top:
#  mov  *r2+, *r1+      
#  dect r3
#  jgt  data_copy_top
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
  li r1,>0100
  mov r1,@>83fc
  clr @>83c4

# Create the stack
  li sp, >4000
  
# call vdpinit to set critical variables
  bl @vdpinit  

# to make debugging easier, always init the default AMS pages
# Based on SAMS code by JediMatt42
# we should be running at >A000 with regs at >8300
# so we can bank >2000 safely here
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
  sbz 0

# Start running C code
  bl @main

# reset the console on return
  blwp @>0000


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

