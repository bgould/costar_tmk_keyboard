#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device.
#                Please customize your programmer settings(PROGRAM_CMD)
#
# make teensy = Download the hex file to the device, using teensy_loader_cli.
#               (must have teensy_loader_cli installed).
#
# make dfu = Download the hex file to the device, using dfu-programmer (must
#            have dfu-programmer installed).
#
# make flip = Download the hex file to the device, using Atmel FLIP (must
#             have Atmel FLIP installed).
#
# make dfu-ee = Download the eeprom file to the device, using dfu-programmer
#               (must have dfu-programmer installed).
#
# make flip-ee = Download the eeprom file to the device, using Atmel FLIP
#                (must have Atmel FLIP installed).
#
# make debug = Start either simulavr or avarice as specified for debugging, 
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------

###############################################################################
# Adapted from:                                                               #
# https://github.com/BathroomEpiphanies/costar_keyboard/blob/master/Makefile  #
###############################################################################

## Keyboard models. Un-comment the options you want.

#MODEL = flake_20130602
MODEL = flake_20140521
#MODEL = hoof_20131001
#MODEL = hoof_20150108
#MODEL = paw_20130602
#MODEL = petal_20131001
#MODEL = squid_20140518

# Raise an error if MODEL is used but have not been selected
MODEL ?= $(error MODEL is not set; uncomment the appropriate MODEL in Makefile)

###############################################################################
# End of bpiphany's Makefile... continue with the regular tmk Makefile now    #
###############################################################################

# Target file name (without extension).
TARGET = costar_tmk_$(MODEL)_lufa

# Directory common source filess exist
TMK_DIR = tmk_keyboard/tmk_core

COSTAR_KB_DIR = costar_keyboard

# Directory keyboard dependent files exist
TARGET_DIR = .

# project specific files
SRC =	keymap.c \
	keymap_common.c \
	$(COSTAR_KB_DIR)/hw_interface.c \
	matrix.c \
	led.c

CONFIG_H = config.h

# MCU name, you MUST set this to match the board you are using
# type "make clean" after changing this, so all files will be rebuilt
MCU = atmega32u2

# Processor frequency.
#   Normally the first thing your program should do is set the clock prescaler,
#   so your program will run at the correct speed.  You should also set this
#   variable to same clock speed.  The _delay_ms() macro uses this, and many
#   examples use this variable to calculate timings.  Do not add a "UL" here.
F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)

# Boot Section Size in *bytes*
#   Teensy halfKay   512
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
OPT_DEFS += \
	-DBOOTLOADER_SIZE=4096 \
	-DKEYBOARD_MODEL_FILE='"$(COSTAR_KB_DIR)/models/$(MODEL).h"' \
	-D__TMK_KEYBOARD_COMPAT__


# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes	# Mouse keys(+5000)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+600)
CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
#NKRO_ENABLE = yes	# USB Nkey Rollover(+500)


# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)
VPATH += $(COSTAR_KB_DIR)


include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
