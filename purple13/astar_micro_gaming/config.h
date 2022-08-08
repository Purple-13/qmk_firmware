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
#define DEVICE_VER   0x0002
#define MANUFACTURER Purple13
#define PRODUCT      Purple Gaming

#define MATRIX_COLS 7
#define MATRIX_ROWS 4

/* astar_micro pin-out */
#define MATRIX_COL_PINS 	{B5, B4, E6, D7, C6, D4, D3}
#define MATRIX_ROW_PINS 	{F7, F6, B6, B7}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
