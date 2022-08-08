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

bool allow_swap = true;
uint32_t last_used = 0;


void keyboard_post_init_user(void) { 
		set_single_persistent_default_layer(_DVORAK);
		autoshift_enable();
		allow_swap = true;
		writePin(D2, 1);	//Green
		writePin(D3, 0);	//Blue	
}; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case SWAP:
            if (record->event.pressed) {
				if (allow_swap){
					if (swap_hands){
						swap_hands = false;
						writePin(D2, 1);	//Green
						writePin(D3, 0);	//Blue
					} else {
						swap_hands = true; 
						writePin(D2, 1);	//Green
						writePin(D3, 1);	//Blue
					}
				}
            }
            return false;
		
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
				autoshift_enable();
				allow_swap = true;
				writePin(D2, 1);	//Green
				writePin(D3, 0);	//Blue
            }
            return false;
			
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
				autoshift_disable();
				allow_swap = false;
				writePin(D2, 0);	//Green
				writePin(D3, 1);	//Blue
            }
            return false;
			
		case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
				autoshift_disable();
				allow_swap = false;
				writePin(D2, 1);	//Green
				writePin(D3, 1);	//Blue
            }
            return false;
    }
	last_used = timer_read32();
	return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
		default: //  for All layers
			if (swap_hands){
				swap_hands = false;
				writePin(D2, 1);	//Green
				writePin(D3, 0);	//Blue
			}
			break;
    }
  return state;
};

void housekeeping_task_user(void) {
    if (timer_elapsed32(last_used) > 1300000) {
		set_single_persistent_default_layer(_DVORAK);
		autoshift_enable();
		allow_swap = true;
		writePin(D2, 1);	//Green
		writePin(D3, 0);	//Blue	
    }
};
