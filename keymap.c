/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 0: default
   * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
   * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |Pwr|Slp|Wak|
   * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
   * ,-----------------------------------------------------------. ,-----------. ,---------------.
   * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Ins|Hom|PgU| |NmL|  /|  *|  -|
   * |-----------------------------------------------------------| |-----------| |---------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
   * |-----------------------------------------------------------| `-----------' |-----------|  +|
   * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
   * |-----------------------------------------------------------|     ,---.     |---------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
   * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
   * |Ctrl |Gui |Alt |         Space         |Alt |Gui |Menu|Ctrl| |Lef|Dow|Rig| |      0|  .|   |
   * `-----------------------------------------------------------' `-----------' `---------------'
   */
  KEYMAP( GRV,        F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,   PSCR,SLCK,PAUS,                      \
          ESC,    1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC,   INS,HOME,PGUP,  NLCK,PSLS,PAST,PMNS, \
          TAB,    Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSLS,   DEL, END,PGDN,    P7,  P8,  P9,PPLS, \
          LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT,      ENT,                     P4,  P5,  P6,      \
          LSFT,NUBS,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,     RSFT,          UP,        P1,  P2,  P3,PENT, \
          FN0, LGUI,LALT,                SPC,               RALT,RGUI, APP,RCTL,   LEFT,DOWN,RGHT,   P0,     PDOT,      \
          \
          NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, \
          NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, \
          NO, NO, NO, NO, NO, NO, NO
  ),

  /* 1: SpaceFN
   * ,-----------------------------------------------------------.
   * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |Spc|PgD|`  |~  |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  KEYMAP( TRNS,     F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,      BTN3,BTN4,BTN5,
          TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,      BTN1,MS_U,BTN2,    NLCK,PSLS,PAST,PMNS,
          TRNS,TRNS,TRNS,ESC, TRNS,TRNS,TRNS,HOME,UP,  END, PSCR,SLCK,PAUS,INS,      MS_L,MS_D,MS_R,    P7,  VOLU,  P9,PPLS,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS,                        P4,  MUTE,  P6,
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, PGDN,GRV, FN1, TRNS,TRNS,     TRNS,          WH_U,         P1,  VOLD,  P3,PENT,
          TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS,     WH_L,WH_D,WH_R,    P0,       PDOT,
          \
          NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, 
          NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,
          NO, NO, NO, NO, NO, NO, NO
  ),

};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [1] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),    // tilde
};

