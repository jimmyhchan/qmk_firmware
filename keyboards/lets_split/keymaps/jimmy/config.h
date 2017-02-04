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

// if you soldered the i2c jumpers and the resistors, you can use either
// if you have not, you must use serial
//#define USE_I2C
#define USE_SERIAL

//  use EE_HANDS and flash to eeprom if you want to regularly swap the usb side
//  otherwise choose what side you want the usb cable to plug into
//#define I2C_MASTER_LEFT
//#define I2C_MASTER_RIGHT
//#define EE_HANDS

#ifdef SUBPROJECT_rev1
    #include "../../rev1/config.h"
#endif
#ifdef SUBPROJECT_rev2
    #include "../../rev2/config.h"
#endif
