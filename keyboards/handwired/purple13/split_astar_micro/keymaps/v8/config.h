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

/* Auto Shift Settings */
#define AUTO_SHIFT_TIMEOUT 190

/* how long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too */
#define TAPPING_TERM 190
//#define TAPPING_TERM_PER_KEY

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Force NKRO */
#define FORCE_NKRO

/* Polling rate */
#define USB_POLLING_INTERVAL_MS 1

#define SPLIT_USB_DETECT
