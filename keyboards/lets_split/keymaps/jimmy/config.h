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

//  otherwise choose what side you want the usb cable to plug into (defaults to LEFT)
//#define I2C_MASTER_LEFT
//#define I2C_MASTER_RIGHT

// can't get EE prom working :(
// use EE_HANDS if you want to regularly swap the usb side and you have flashed the eeprom to each side
// #define EE_HANDS

#ifdef SUBPROJECT_rev1
    #include "../../rev1/config.h"
#endif
#ifdef SUBPROJECT_rev2
    #include "../../rev2/config.h"
#endif
