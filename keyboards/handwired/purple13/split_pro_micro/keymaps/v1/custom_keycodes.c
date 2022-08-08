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

#define CVX TD(TD_CPY_PST)				// Tap once for copy, hold for paste
#define PUNC TD(TD_DOT_COMM)			// Tap for dot, hold for Comma
#define UNDO TD(TD_UNDO_REDO)			// Tap for undo, hold for redo
#define NUM_GUI TD(TD_NUM_GUI)			// Tap for Toggle NUM Layer, hold for GUI

#define LBRAC TD(TD_LPRN_LCBR)			// Tap for (, hold for {
#define RBRAC TD(TD_RPRN_RCBR)			// Tap for ), hold for }
#define LSBRAC TD(TD_LBRC_LT)			// Tap for [, hold for <
#define RSBRAC TD(TD_RBRC_GT)			// Tap for ], hold for >

#define LEQL TD(TD_EQL_SLSH)			// Tap for =, hold for /
#define LPLUS TD(TD_PLUS_MINS)			// Tap for +, hold for - 
#define RQUES TD(TD_QUES_BSLS)			// Tap for ?, hold for \								/
#define RUNDS TD(TD_UNDS_PIPE)			// Tap for _, hold for |
  
#define NUM_ENT LT(_NAV_NUM,KC_ENT)
#define SYM_SPC LT(_SYMBOLS,KC_SPC)
#define SPECIAL MO(_SPECIAL)

enum custom_layers {
  _DVORAK = 0,
  _QWERTY = 1,
  _GAMING = 2,
  _NAV_NUM = 3,
  _SYMBOLS = 4,
  _SPECIAL = 5
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  GAMING,
  QWERTY,
  SWAP,
  NOTIFY
}; 

enum {
	TD_CPY_PST,
	TD_DOT_COMM,
	TD_UNDO_REDO,
	TD_LPRN_LCBR,
	TD_RPRN_RCBR,
	TD_LBRC_LT,
	TD_RBRC_GT,
	TD_EQL_SLSH,
	TD_PLUS_MINS,
	TD_QUES_BSLS,
	TD_UNDS_PIPE,
	TD_NUM_GUI
	};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {		//Auto-Shift Settings
    switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
        case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        case KC_NUHS:
		case KC_SCLN:
		case KC_QUOT:
		case KC_GRAVE:
#    endif
            return true;
    }
    return false;
}

// For the TD_CPY_PST tap dance. 
void TD_CPY_PST_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_CPY_PST_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_DOT_COMM tap dance. 
void TD_DOT_COMM_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_DOT_COMM_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_UNDO_REDO tap dance. 
void TD_UNDO_REDO_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_UNDO_REDO_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_LPRN_LCBR tap dance. 
void TD_LPRN_LCBR_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_LPRN_LCBR_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_RPRN_RCBR tap dance. 
void TD_RPRN_RCBR_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_RPRN_RCBR_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_LBRC_LT tap dance. 
void TD_LBRC_LT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_LBRC_LT_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_RBRC_GT tap dance. 
void TD_RBRC_GT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_RBRC_GT_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_EQL_SLSH tap dance. 
void TD_EQL_SLSH_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_EQL_SLSH_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_PLUS_MINS tap dance. 
void TD_PLUS_MINS_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_PLUS_MINS_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_QUES_BSLS tap dance. 
void TD_QUES_BSLS_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_QUES_BSLS_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_UNDS_PIPE tap dance. 
void TD_UNDS_PIPE_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_UNDS_PIPE_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_NUM_GUI tap dance. 
void TD_NUM_GUI_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_NUM_GUI_reset(qk_tap_dance_state_t *state, void *user_data);


td_state_t cur_dance(qk_tap_dance_state_t *state) {													// Gets number of taps
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    }else return TD_UNKNOWN;
};


qk_tap_dance_action_t tap_dance_actions[] = {														// Registers all tap dances
	
    [TD_CPY_PST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_CPY_PST_finished, TD_CPY_PST_reset),		// Tap once for copy, hold for paste
	
	[TD_DOT_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_DOT_COMM_finished, TD_DOT_COMM_reset),	// Tap for dot, hold for Comma
	
	[TD_UNDO_REDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_UNDO_REDO_finished, TD_UNDO_REDO_reset),	// Tap for undo, hold for redo
	
	[TD_LPRN_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_LPRN_LCBR_finished, TD_LPRN_LCBR_reset),	// Tap for (, hold for {
	
	[TD_RPRN_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_RPRN_RCBR_finished, TD_RPRN_RCBR_reset),	// Tap for ), hold for }
	
	[TD_LBRC_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_LBRC_LT_finished, TD_LBRC_LT_reset),		// Tap for [, hold for <
	
	[TD_RBRC_GT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_RBRC_GT_finished, TD_RBRC_GT_reset),		// Tap for ], hold for >
	
	[TD_EQL_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_EQL_SLSH_finished, TD_EQL_SLSH_reset),	// Tap for =, hold for /
	
	[TD_PLUS_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_PLUS_MINS_finished, TD_PLUS_MINS_reset),	// Tap for +, hold for -
	
	[TD_QUES_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_QUES_BSLS_finished, TD_QUES_BSLS_reset),	// Tap for ?, hold for \								/
	
	[TD_UNDS_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_UNDS_PIPE_finished, TD_UNDS_PIPE_reset),	// Tap for _, hold for |
	
	[TD_NUM_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_NUM_GUI_finished, TD_NUM_GUI_reset)		// Tap for Toggle NUM Layer, hold for GUI
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// TD_NUM_GUI tap dance.
static td_tap_t TD_NUM_GUI_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_NUM_GUI_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_NUM_GUI_tap_state.state = cur_dance(state);
	switch (TD_NUM_GUI_tap_state.state) {
		case TD_SINGLE_TAP: register_code16(KC_RGUI);  break;
        case TD_SINGLE_HOLD: break;
		case TD_DOUBLE_TAP: 
			// Check to see if the layer is already set
            if (layer_state_is(_NAV_NUM)) {
                // If already set, then switch it off
                layer_off(_NAV_NUM);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NAV_NUM);
            } 
			break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
}

void TD_NUM_GUI_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_NUM_GUI_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RGUI);  break;
        case TD_SINGLE_HOLD: break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_NUM_GUI_tap_state.state = TD_NONE;
};


// TD_UNDO_REDO tap dance.
static td_tap_t TD_UNDO_REDO_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_UNDO_REDO_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_UNDO_REDO_tap_state.state = cur_dance(state);
    switch (TD_UNDO_REDO_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_Z));  break;
        case TD_SINGLE_HOLD: register_code16(LCTL(LSFT(KC_Z)));  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_UNDO_REDO_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_UNDO_REDO_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_Z))); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_UNDO_REDO_tap_state.state = TD_NONE;
};


// TD_DOT_COMM tap dance.
static td_tap_t TD_DOT_COMM_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_DOT_COMM_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_DOT_COMM_tap_state.state = cur_dance(state);
    switch (TD_DOT_COMM_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_DOT);  break;
        case TD_SINGLE_HOLD: register_code16(KC_COMM);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_DOT_COMM_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_DOT_COMM_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_COMM); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_DOT_COMM_tap_state.state = TD_NONE;
};


// TD_CPY_PST tap dance.
static td_tap_t TD_CPY_PST_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_CPY_PST_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_CPY_PST_tap_state.state = cur_dance(state);
    switch (TD_CPY_PST_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_V)); break;
		case TD_DOUBLE_TAP: register_code16(LCTL(KC_X));  break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_CPY_PST_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_CPY_PST_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_V)); break;
        case TD_DOUBLE_TAP: unregister_code16(LCTL(KC_X));  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_CPY_PST_tap_state.state = TD_NONE;
};


// TD_LPRN_LCBR tap dance.
static td_tap_t TD_LPRN_LCBR_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_LPRN_LCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_LPRN_LCBR_tap_state.state = cur_dance(state);
    switch (TD_LPRN_LCBR_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LPRN);  break;
        case TD_SINGLE_HOLD: register_code16(KC_LCBR);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_LPRN_LCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_LPRN_LCBR_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_LPRN_LCBR_tap_state.state = TD_NONE;
};


// TD_RPRN_RCBR tap dance.
static td_tap_t TD_RPRN_RCBR_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_RPRN_RCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_RPRN_RCBR_tap_state.state = cur_dance(state);
    switch (TD_RPRN_RCBR_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RPRN);  break;
        case TD_SINGLE_HOLD: register_code16(KC_RCBR);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_RPRN_RCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_RPRN_RCBR_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_RPRN_RCBR_tap_state.state = TD_NONE;
};


// TD_LBRC_LT tap dance.
static td_tap_t TD_LBRC_LT_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_LBRC_LT_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_LBRC_LT_tap_state.state = cur_dance(state);
    switch (TD_LBRC_LT_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LBRC);  break;
        case TD_SINGLE_HOLD: register_code16(KC_LT);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_LBRC_LT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_LBRC_LT_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LT); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_LBRC_LT_tap_state.state = TD_NONE;
};


// TD_RBRC_GT tap dance.
static td_tap_t TD_RBRC_GT_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_RBRC_GT_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_RBRC_GT_tap_state.state = cur_dance(state);
    switch (TD_RBRC_GT_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RBRC);  break;
        case TD_SINGLE_HOLD: register_code16(KC_GT);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_RBRC_GT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_RBRC_GT_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_GT); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_RBRC_GT_tap_state.state = TD_NONE;
};


// TD_EQL_SLSH tap dance.
static td_tap_t TD_EQL_SLSH_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_EQL_SLSH_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_EQL_SLSH_tap_state.state = cur_dance(state);
    switch (TD_EQL_SLSH_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_EQL);  break;
        case TD_SINGLE_HOLD: register_code16(KC_SLSH);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_EQL_SLSH_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_EQL_SLSH_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_SLSH); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_EQL_SLSH_tap_state.state = TD_NONE;
};


// TD_PLUS_MINS tap dance.
static td_tap_t TD_PLUS_MINS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_PLUS_MINS_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_PLUS_MINS_tap_state.state = cur_dance(state);
    switch (TD_PLUS_MINS_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_PLUS);  break;
        case TD_SINGLE_HOLD: register_code16(KC_MINS);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_PLUS_MINS_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_PLUS_MINS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_PLUS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_MINS); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_PLUS_MINS_tap_state.state = TD_NONE;
};


// TD_QUES_BSLS tap dance.
static td_tap_t TD_QUES_BSLS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_QUES_BSLS_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_QUES_BSLS_tap_state.state = cur_dance(state);
    switch (TD_QUES_BSLS_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_QUES);  break;
        case TD_SINGLE_HOLD: register_code16(KC_BSLS);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_QUES_BSLS_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_QUES_BSLS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_QUES); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_BSLS); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_QUES_BSLS_tap_state.state = TD_NONE;
};


// TD_UNDS_PIPE tap dance.
static td_tap_t TD_UNDS_PIPE_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_UNDS_PIPE_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_UNDS_PIPE_tap_state.state = cur_dance(state);
    switch (TD_UNDS_PIPE_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_UNDS);  break;
        case TD_SINGLE_HOLD: register_code16(KC_PIPE);  break;
		case TD_DOUBLE_TAP: break;
    	case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_UNDS_PIPE_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_UNDS_PIPE_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_TAP:  break;
        case TD_DOUBLE_HOLD: break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_UNDS_PIPE_tap_state.state = TD_NONE;
};
