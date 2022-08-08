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

#define TAPPING_TOGGLE 2

/* Mouse Cursor settings */
#define MOUSEKEY_DELAY							7			// Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL						3			// Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA						1			// Step size
#define MOUSEKEY_MAX_SPEED 						13			// Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX					170			// Time until maximum cursor speed is reached
#define MOUSEKEY_INITIAL_SPEED					75			// Initial speed of the cursor in pixel per second
#define MOUSEKEY_BASE_SPEED						100			// Maximum cursor speed at which acceleration stops
#define MOUSEKEY_ACCELERATED_SPEED				2000		// Accelerated cursor speed

/* Mouse Wheel settings */
#define MOUSEKEY_WHEEL_DELAY					200			// Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL					69			// Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED				10			// Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX				250			// Time until maximum scroll speed is reached
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS	2000		// Accelerated wheel movements			
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS		1			// Initial number of movements of the mouse wheel
