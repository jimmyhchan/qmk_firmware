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


// HEY jimmy! cd to the lets_split directory and run make rev2-jimmy


// if you soldered the i2c jumpers and the resistors, you can use either serial or i2c
// if you have not, you must use serial
#define USE_I2C
//#define USE_SERIAL

// next, choose what side you want the usb cable to plug into (this will automatically defaults to LEFT if you select neither)
//#define I2C_MASTER_LEFT
//#define I2C_MASTER_RIGHT

// This very optional and only really needed if want to regularly swap the usb side.
//
// Instead of choosing a side, you can have it set in the memory of each side.
//   step 0: the eep files on the QMK repo are incorrect they need to be 11 bytes (start with :0b) long a pull request is incoming
//   step 1: flashed the eeprom to each side (using avrdude.. see the ./flash_eeprom_left and ./flash_eeprom_right scripts)
//   step 2: uncomment out the EE_HANDS line below, comment out any I2C_MASTER_* lines, and re build (make rev2-<your-keymap>)
//   step 3: flash the hex files onto each side
//
#define EE_HANDS

#ifdef SUBPROJECT_rev1
    #include "../../rev1/config.h"
#endif
#ifdef SUBPROJECT_rev2
    #include "../../rev2/config.h"
#endif
