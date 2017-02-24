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
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "split_util.h"
#include "pro_micro.h"
#include "config.h"

#include "i2c.h"

#ifndef DEBOUNCE
#  define DEBOUNCE	5
#endif

#define ERROR_DISCONNECT_COUNT 5

static uint8_t debouncing = DEBOUNCE;
static const int ROWS_PER_HAND = MATRIX_ROWS/3;
static uint8_t error_count = 0;
static uint8_t ack_error_count = 0;

static const uint8_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const uint8_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

__attribute__ ((weak))
void matrix_init_quantum(void) {
    matrix_init_kb();
}

__attribute__ ((weak))
void matrix_scan_quantum(void) {
    matrix_scan_kb();
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    debug_enable = true;
    debug_matrix = true;
    debug_mouse = true;
    // initialize row and col
    unselect_rows();
    init_cols();

    TX_RX_LED_INIT;

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }


    matrix_init_quantum();
}

uint8_t _matrix_scan(void)
{
    // keymaps for the hands are stored one after the other so we need to offset it
    int offset = handOffset * (ROWS_PER_HAND);

    for (uint8_t i = 0; i < ROWS_PER_HAND; i++) {
        select_row(i);
        _delay_us(90);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i+offset] != cols) {
            matrix_debouncing[i+offset] = cols;
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < ROWS_PER_HAND; i++) {
                matrix[i+offset] = matrix_debouncing[i+offset];
            }
        }
    }

    return 1;
}

// Get rows from other half over i2c
int i2c_transaction(void) {
    // read over i2c from all the hands
    for (int j = 0; j < NUM_HANDS; ++j) {
        // dont read from self
        if ((uint8_t) j != handOffset) {
            int slaveOffset = j * (ROWS_PER_HAND);

            // TODO: set a different slave address for slave 2, 3 ...etc
            int err = i2c_master_start(((SLAVE_I2C_ADDRESS + j)<<1)  + I2C_WRITE);
            // soft error
            if (err) {
              ack_error_count++;
              continue;
            }

            // start of matrix stored at 0x00
            err = i2c_master_write(0x00);
            if (err) goto i2c_error;

            // Start read
            err = i2c_master_start(((SLAVE_I2C_ADDRESS + j )<<1) + I2C_READ);
            if (err) goto i2c_error;

            if (!err) {
                int i;
                for (i = 0; i < ROWS_PER_HAND-1; ++i) {
                    matrix[slaveOffset+i] = i2c_master_read(I2C_ACK);
                }
                matrix[slaveOffset+i] = i2c_master_read(I2C_NACK);
                i2c_master_stop();
            } else {
      i2c_error: // the cable is disconnceted, or something else went wrong
                i2c_reset_state();
                return err;
            }

        }
    }

    // TODO remove this hard coded debugging also add logic to reset states whenever ack counts change?
    // we have 2 halves and the 3rd is not responding should return 1 ack errors
    if (ack_error_count == 2) {
      ack_error_count = 0;
      i2c_reset_state();
      return 1;
    }
    ack_error_count = 0;
    return 0;
}

uint8_t matrix_scan(void)
{
    int ret = _matrix_scan();



    if( i2c_transaction() ) {
        // turn on the indicator led when halves are disconnected
        TXLED1;

        error_count++;

        if (error_count > ERROR_DISCONNECT_COUNT) {
            // reset all other slaves if disconnected
            for (int j = 0; j < NUM_HANDS; ++j) {
                int slaveOffset = j * (ROWS_PER_HAND);
                if ((uint8_t) j != handOffset) {
                  for (int i = 0; i < ROWS_PER_HAND; ++i) {
                      matrix[slaveOffset+i] = 0;
                  }
                }
            }
        }
    } else {
        // turn off the indicator led on no error
        TXLED0;
        error_count = 0;
    }

    matrix_scan_quantum();

    return ret;
}

void matrix_slave_scan(void) {
    _matrix_scan();

    int offset = handOffset * (ROWS_PER_HAND);

    for (int i = 0; i < ROWS_PER_HAND; ++i) {
        /* i2c_slave_buffer[i] = matrix[offset+i]; */
        i2c_slave_buffer[i] = matrix[offset+i];
    }
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

static void  init_cols(void)
{
    for(int x = 0; x < MATRIX_COLS; x++) {
        _SFR_IO8((col_pins[x] >> 4) + 1) &=  ~_BV(col_pins[x] & 0xF);
        _SFR_IO8((col_pins[x] >> 4) + 2) |= _BV(col_pins[x] & 0xF);
    }
}

static matrix_row_t read_cols(void)
{
    matrix_row_t result = 0;
    for(int x = 0; x < MATRIX_COLS; x++) {
        result |= (_SFR_IO8(col_pins[x] >> 4) & _BV(col_pins[x] & 0xF)) ? 0 : (1 << x);
    }
    return result;
}

static void unselect_rows(void)
{
    for(int x = 0; x < ROWS_PER_HAND; x++) {
        _SFR_IO8((row_pins[x] >> 4) + 1) &=  ~_BV(row_pins[x] & 0xF);
        _SFR_IO8((row_pins[x] >> 4) + 2) |= _BV(row_pins[x] & 0xF);
    }
}

static void select_row(uint8_t row)
{
    _SFR_IO8((row_pins[row] >> 4) + 1) |=  _BV(row_pins[row] & 0xF);
    _SFR_IO8((row_pins[row] >> 4) + 2) &= ~_BV(row_pins[row] & 0xF);
}
