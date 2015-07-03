/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "costar_keyboard.h"

#ifndef DEBOUNCE
#define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);

/* number of matrix rows */
inline
uint8_t matrix_rows(void) {
  return MATRIX_ROWS;
}

/* number of matrix columns */
inline
uint8_t matrix_cols(void) {
  return MATRIX_COLS;
}

/* intialize matrix for scaning. should be called once. */
void matrix_init(void) {

  // initialize row and col
  release_rows();
  pins_init();
  
  // initialize matrix state: all keys off
  for (uint8_t i=0; i < MATRIX_ROWS; i++) {
    matrix[i] = 0;
    matrix_debouncing[i] = 0;
  }

}

/* scan all key states on matrix */
uint8_t matrix_scan(void) {
  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    pull_row(i);
    _delay_us(30);  // without this wait read unstable value.
    matrix_row_t cols = 0;
    for (uint8_t j = 0; j < MATRIX_COLS; j++) {
      cols <<= 1;
      cols  |= probe_column(j);
    }
    if (matrix_debouncing[i] != cols) {
      matrix_debouncing[i] = cols;
      debouncing = DEBOUNCE;
    }
    release_rows();
  }
  if (debouncing) {
    if (--debouncing) {
      _delay_ms(1);
    } else {
      for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = bitrev(matrix_debouncing[i]);
      }
    }
  }
  return 1;
}

/* whether modified from previous scan. used after matrix_scan. */
// bool matrix_is_modified(void) __attribute__ ((deprecated));

/* whether a swtich is on */
inline
bool matrix_is_on(uint8_t row, uint8_t col) {
  return (matrix[row] & ((matrix_row_t)1<<col));
}

/* matrix state on row */
inline
matrix_row_t matrix_get_row(uint8_t row) {
  return matrix[row];
}

/* print matrix for debug */
void matrix_print(void) {
  print("\nr/c 0123456789ABCDEF\n");
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    phex(row); print(": ");
    pbin_reverse16(matrix_get_row(row));
    print("\n");
  }
}

