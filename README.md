TMK firmware for bpiphany's Costar replacement controllers
==========================================================

You can use this repository to build TMK firmware for bpiphany's controllers,
found here:

http://deskthority.net/wiki/Costar_replacement_controllers

and here:

https://geekhack.org/index.php?topic=46700.0

To build, you'll need GCC for AVR, and all the other usual suspects.  See the
documentation for the costar_keyboard and tmk_keyboard projects for more 
information.  To build the firmware, uncomment the model of your controller
in the makefile and run `make`.

You can edit the keymap in `keymap.c` or tweak config options in `config.h`.
The defaults are my preferences, so you probably won't like them and will want
to edit those files.  See the tmk_keyboard documentation for more information.

License is GPLv3
