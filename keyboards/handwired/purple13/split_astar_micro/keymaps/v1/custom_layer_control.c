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

bool swap_hands = false;
bool allow_swap = true;
bool allow_notify = false;
bool mouse_on = false;
uint32_t last_used = 0;


void keyboard_post_init_user(void) { 
		set_single_persistent_default_layer(_DVORAK);
		autoshift_enable();
		allow_swap = true;
}; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SWAP:
            if (record->event.pressed) {
				if (allow_swap){
					if (swap_hands){
						swap_hands = false;
					} else {
						swap_hands = true; 
					}
				}
            }
            return false; 
			
		case NOTIFY:
            if (record->event.pressed) {
					if (allow_notify){
						allow_notify = false;
					} else {
						allow_notify = true; 
					}
            }
            return false;
			
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK); 
				if (allow_notify){
					register_code16(KC_F14); 
					unregister_code16(KC_F14);
				}
				autoshift_enable();
				allow_swap = true;
            }
            return false;
			
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);  
				if (allow_notify){
					register_code16(KC_F15); 
					unregister_code16(KC_F15);
				}
				autoshift_disable();
				allow_swap = false;
            }
            return false;
			
		case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);  
				if (allow_notify){
					register_code16(KC_F16); 
					unregister_code16(KC_F16);
				}
				autoshift_disable();
				allow_swap = false;
            }
            return false;
		
		case MOUSE:
            if (record->event.pressed) { 
					if (mouse_on){
						mouse_on = false;
						set_single_persistent_default_layer(_DVORAK); 
					} else {
						mouse_on = true; 
						set_single_persistent_default_layer(_MOUSE); 
					}	
            }
            return false;
    }
	last_used = timer_read32();
	return true;
};

void housekeeping_task_user(void) {
 /*
	if (mouse_on){
		if (timer_elapsed32(last_used) > 6900) {
				set_single_persistent_default_layer(_DVORAK);  
				if (allow_notify){
				register_code16(KC_F14); 
				unregister_code16(KC_F14);
				}
		autoshift_enable();
		allow_swap = true;
		}
	} 
*/
    if (timer_elapsed32(last_used) > 1300000) {
		set_single_persistent_default_layer(_DVORAK);  
				if (allow_notify){
				register_code16(KC_F14); 
				unregister_code16(KC_F14);
				}
		autoshift_enable();
		allow_swap = true;
    }
};
