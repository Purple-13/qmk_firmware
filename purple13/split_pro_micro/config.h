/*
Copyright 2021 Purple13

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

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xB00B
#define PRODUCT_ID   0x0013
#define DEVICE_VER   0x0007
#define MANUFACTURER Purple13
#define PRODUCT      Split Purple

/* key matrix size  Left and Right hands rows stacked */
#define MATRIX_COLS 7
#define MATRIX_ROWS 8

// use I2C or Serial
//#define USE_I2C
#define SOFT_SERIAL_PIN D1

/* Set Hand    pull to vcc to set left, pull to gnd to set right */
#define SPLIT_HAND_PIN C6

/* pro_micro pin-out */
#define MATRIX_COL_PINS 	{ B6, B2, B3, B1, F7, F6, F5 }
#define MATRIX_ROW_PINS 	{ B5, B4, E6, D7 }
#define UNUSED_PINS 		{ D2, D3, D4, F4 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
