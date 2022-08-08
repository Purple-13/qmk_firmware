#include QMK_KEYBOARD_H 
																					//Definitions  
#define CPYPST TD(TD_CPY_PST)				// Tap once for copy, hold for paste
#define PUNC TD(TD_DOT_COMM)			// Tap for dot, hold for Comma
#define LBRAC TD(TD_LPRN_LCBR)			// Tap for (, hold for {
#define RBRAC TD(TD_RPRN_RCBR)			// Tap for ), hold for }
#define LSBRAC TD(TD_LBRC_LT)			// Tap for [, hold for <
#define RSBRAC TD(TD_RBRC_GT)			// Tap for ], hold for >
#define LEQL TD(TD_EQL_SLSH)			// Tap for =, hold for /
#define LPLUS TD(TD_PLUS_MINS)			// Tap for +, hold for - 
#define RQUES TD(TD_QUES_BSLS)			// Tap for ?, hold for \								/
#define RUNDS TD(TD_UNDS_PIPE)			// Tap for _, hold for |
#define NUM_CHAT TD(TD_NUM_CHAT)		// Tap once for chat, hold for num layer
#define NUM_ENT TD(TD_NAV_NUM)			// Tap once for enter, hold for num layer
#define SYM_SPC LT(_SYMBOLS,KC_SPC)
#define CUT RCTL(KC_X)

uint32_t last_used = 0;

bool gaming_chat = false;

enum custom_layers {
	_GAMING = 0,
	_DVORAK = 1,
	_NAV_NUM = 2,
	_SYMBOLS = 3
};

enum custom_keycodes {
	DVORAK = SAFE_RANGE,
	GAMING
}; 

enum {
	TD_CPY_PST,
	TD_DOT_COMM,
	TD_LPRN_LCBR,
	TD_RPRN_RCBR,
	TD_LBRC_LT,
	TD_RBRC_GT,
	TD_EQL_SLSH,
	TD_PLUS_MINS,
	TD_QUES_BSLS,
	TD_UNDS_PIPE,
	TD_NUM_CHAT,
	TD_NAV_NUM
}; 
	
typedef enum {
	TD_NONE,
	TD_UNKNOWN,
	TD_SINGLE_TAP,
	TD_SINGLE_HOLD
} td_state_t;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {				//Keymap
 
/* 																					    	   GAMING	
*	 ,----------------------------------------------------------------------------------.           		,-----------------------------------------------------------------------------------. 
* 	|	 Home	|	  T		|	  Q		|	  W		|	  E  	|	  R		|	 Esc	|       \**\ 		|	  GUI	|	  		|	 		|	  		|	  		|	 		| forceQuit	|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	| 	 DEL 	|	  G		|	  A		|	  S		|	  D 	|	  F		|	 Tab	|		\**\		|			|	  		|	  		|	 		|	  		|			|			|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|	 END 	|	  B		|     Z		|	  X		|	  C		|	  V		|  F5 save	|	     \**\		|			|	  		|	  		|	 		|	  		|			|			|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
*  				 			 			|	 ALT	|	CTRL	|	SHIFT	|	SPACE	|		\**\		| NUM_CHAT	|	  		|	  		|	 		|	
*       							  	`-----------------------------------------------' 					`-----------------------------------------------'    
*/
[_GAMING] = LAYOUT(
																																															
		KC_HOME, 	KC_T, 		KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_ESC,			/**/			KC_LGUI,	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,		KC_NO,		LCA(KC_DEL),
		KC_DEL, 	KC_G,		KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_TAB,			/**/			KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,
		KC_END, 	KC_B, 		KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_F5,			/**/			KC_NO,		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO,
											KC_LALT,	KC_LCTL,	KC_LSFT, 	KC_SPC,       	/**/			NUM_CHAT, 	KC_NO, 		KC_NO, 		KC_NO							
),
/* 																							   DVORAK		
*	 ,----------------------------------------------------------------------------------.           		,-----------------------------------------------------------------------------------. 
* 	|	 Home	|	 `~ 	|	  .,	|	  P		|	  Y		|	  F		|	Esc		|       \**\ 		|	 GUI	|	 G		|	 C		|	 R		|	  L		|	 '"		|	End		|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|	 DEL 	|	  A		|	  O		|	  E		|	  U		|	  I		|	 ({		|		\**\		|	 )}		|	 D		|	 H		|	 T		|	 N		|	 S		| BACKSPACE |
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|    TAB	|	 ;:		|	  Q		|	  J		|	  K		|	  X		|	 =/		|       \**\		|	 ?\		|	 B		|	 M		|	 W		|	 V		|	 Z		|    TAB	|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
*  				 			 			|	SHIFT	|	 ALT	|	NUM_ENT	|	SYM_SPC	|		\**\		|	NUM_ENT	|	SYM_SPC	|	CTRL	|	SHIFT	|	
*       							  	`-----------------------------------------------' 					`-----------------------------------------------'            
*/
[_DVORAK] = LAYOUT(
																																															
		KC_HOME, 	KC_GRV, 	PUNC,		KC_P, 		KC_Y,		KC_F, 		KC_ESC,			/**/			KC_LGUI,	KC_G, 		KC_C, 		KC_R, 		KC_L,		KC_QUOT,	KC_END,
		KC_DEL,		KC_A, 		KC_O, 		KC_E, 		KC_U, 		KC_I, 		LBRAC,			/**/			RBRAC,		KC_D, 		KC_H, 		KC_T, 		KC_N, 		KC_S, 		KC_BSPC,
		KC_TAB, 	KC_SCLN, 	KC_Q, 		KC_J, 		KC_K, 		KC_X, 		LEQL,			/**/			RQUES,		KC_B, 		KC_M, 		KC_W, 		KC_V, 		KC_Z, 		KC_TAB,
											KC_LSFT,	KC_RALT, 	NUM_ENT, 	SYM_SPC, 		/**/			NUM_ENT, 	SYM_SPC, 	KC_LCTL, 	KC_RSFT
), 	
/*																								NUM	
*	 ,----------------------------------------------------------------------------------.           		,-----------------------------------------------------------------------------------. 
* 	|	 	 	|			| 			|	  Up	|	Play	|	Cut		|	GAMING	|       \**\ 		|	DVORAK	|			|	  7		|	  8		|	  9		|			| 			|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|	 DEL 	|	Vol+	|	 Left 	|	 Down	|	Right	|	Copy	|	 [<		|		\**\		|	  ]>	|	  .		|	  4		|	  5		|	  6		|	  0		| BACKSPACE |
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|			|	Vol-	|			|	Prev	|	Next	|			|	 +-		|       \**\		|	  _|	|			|	  1		|	  2		|	  3		|			|			|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
*  				 			 			|	SHIFT	|	 ALT	|	TRNS	|	SPACE	|		\**\		|	TRNS	|	SPACE	|	CTRL	|	SHIFT	|	
*       							  	`-----------------------------------------------' 					`-----------------------------------------------'    
*/	
[_NAV_NUM] = LAYOUT(
																																															
		KC_NO,		KC_NO,	 	KC_NO,		KC_UP, 		KC_MPLY,	CUT, 		GAMING,			/**/			DVORAK,		KC_NO, 		KC_7, 		KC_8, 		KC_9,		KC_NO, 		KC_NO,
		KC_DEL,	 	KC_VOLU,	KC_LEFT, 	KC_DOWN,  	KC_RIGHT, 	CPYPST, 	LSBRAC,			/**/			RSBRAC,		KC_DOT, 	KC_4, 		KC_5, 		KC_6, 		KC_0, 		KC_BSPC,
		KC_NO, 		KC_VOLD, 	KC_NO,		KC_MPRV, 	KC_MNXT, 	KC_NO, 		LPLUS,			/**/			RUNDS,		KC_NO, 		KC_1, 		KC_2, 		KC_3, 		KC_NO, 		KC_NO,
											KC_LSFT,	KC_RALT, 	KC_TRNS, 	KC_SPC, 		/**/			KC_TRNS, 	KC_SPC, 	KC_LCTL, 	KC_LSFT
),
/* 																								SYM			
*	 ,----------------------------------------------------------------------------------.           		,-----------------------------------------------------------------------------------. 
* 	|			|	  ^		|	  #		|	 & 		|	 %		|			|	GAMING	|       \**\ 		|	DVORAK	|			|	 F1		|	 F2		|	 F3 	|	 F4 	|			|	
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|	 DEL 	|	  $		|	 !		|	  @		|	  *		|			|	 [<		|		\**\		|	  ]>	|			|	 F5		|	 F6		|	 F7 	|	 F8		| BACKSPACE |	
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
* 	|			|	  		|	  		|	 		|	  		|			|	 +-		|       \**\		|	  _|	|			|	 F9		|	 F10	|	 F11	|	 F12	|	   		|
* 	|-----------------------------------------------------------------------------------|           		|-----------------------------------------------------------------------------------|
*  				 			 			|	SHIFT	|	 ALT	|	ENT		|	TRNS	|		\**\		|	ENT		|	TRNS	|	CTRL	|	SHIFT	|	
*       							  	`-----------------------------------------------' 					`-----------------------------------------------'    
*/
[_SYMBOLS] = LAYOUT(
																																															
		KC_NO, 		KC_CIRC, 	KC_HASH, 	KC_AMPR, 	KC_PERC, 	KC_NO, 		GAMING,			/**/			DVORAK,	 	KC_NO,	 	KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_NO,
		KC_DEL, 	KC_DLR,	 	KC_EXLM, 	KC_AT,		KC_ASTR, 	KC_NO, 		LSBRAC,			/**/			RSBRAC,	 	KC_NO,		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8,		KC_BSPC,
		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		LPLUS,			/**/			RUNDS, 		KC_NO,	 	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_NO,
											KC_LSFT,	KC_RALT, 	KC_ENT,		KC_TRNS, 		/**/			KC_ENT,		KC_TRNS, 	KC_LCTL, 	KC_RSFT
)
};

																			//Layer Control
							


void keyboard_post_init_user(void) { 
	layer_on(_DVORAK); 
	layer_off(_GAMING);  
	autoshift_enable();
}; 

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_ENT:
            return 100;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {	
	switch (keycode) {
		
		case DVORAK:
            if (record->event.pressed) {
                layer_on(_DVORAK); 
                layer_off(_GAMING);  
				autoshift_enable();
            }
            return false;
			
			
        case GAMING:
            if (record->event.pressed) {
                layer_on(_GAMING);  
                layer_off(_DVORAK); 
				autoshift_disable();
            }
            return false;
    }
	
	last_used = timer_read32();
  
	return true;
};

void housekeeping_task_user(void) {
	if (timer_elapsed32(last_used) > 600000) {
		layer_on(_DVORAK); 
		layer_off(_GAMING);  
		autoshift_enable();
		gaming_chat = false;
    }
};


const uint16_t PROGMEM reset_combo1[] = {KC_LSFT, KC_RSFT, COMBO_END};		//Combo RESET
combo_t key_combos[COMBO_COUNT] = {
    COMBO(reset_combo1, RESET),
};



bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {			//Auto-Shift Settings
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

																			//Tapdance Setup
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

td_state_t cur_dance(qk_tap_dance_state_t *state) {							// Gets number of taps
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }else {
		return TD_UNKNOWN;
	}
};


																			//Defines Tap dance calls
// For the TD_NAV_NUM tap dance. 
void TD_NAV_NUM_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_NAV_NUM_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_NUM_CHAT tap dance. 
void TD_NUM_CHAT_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_NUM_CHAT_reset(qk_tap_dance_state_t *state, void *user_data);
	
// For the TD_CPY_PST tap dance. 
void TD_CPY_PST_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_CPY_PST_reset(qk_tap_dance_state_t *state, void *user_data);

// For the TD_DOT_COMM tap dance. 
void TD_DOT_COMM_finished(qk_tap_dance_state_t *state, void *user_data);
void TD_DOT_COMM_reset(qk_tap_dance_state_t *state, void *user_data);

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


qk_tap_dance_action_t tap_dance_actions[] = {   							//Registers all tap dances
	
    [TD_NAV_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_NAV_NUM_finished, TD_NAV_NUM_reset),		// Tap once for enter, hold for num layer
	
    [TD_NUM_CHAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_NUM_CHAT_finished, TD_NUM_CHAT_reset),	// Tap once for chat, hold for num layer
	
    [TD_CPY_PST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_CPY_PST_finished, TD_CPY_PST_reset),		// Tap once for copy, hold for paste
	
	[TD_DOT_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_DOT_COMM_finished, TD_DOT_COMM_reset),	// Tap for dot, hold for Comma
	
	[TD_LPRN_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_LPRN_LCBR_finished, TD_LPRN_LCBR_reset),	// Tap for (, hold for {
	
	[TD_RPRN_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_RPRN_RCBR_finished, TD_RPRN_RCBR_reset),	// Tap for ), hold for }
	
	[TD_LBRC_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_LBRC_LT_finished, TD_LBRC_LT_reset),		// Tap for [, hold for <
	
	[TD_RBRC_GT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_RBRC_GT_finished, TD_RBRC_GT_reset),		// Tap for ], hold for >
	
	[TD_EQL_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_EQL_SLSH_finished, TD_EQL_SLSH_reset),	// Tap for =, hold for /
	
	[TD_PLUS_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_PLUS_MINS_finished, TD_PLUS_MINS_reset),	// Tap for +, hold for -
	
	[TD_QUES_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_QUES_BSLS_finished, TD_QUES_BSLS_reset),	// Tap for ?, hold for \								/
	
	[TD_UNDS_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, TD_UNDS_PIPE_finished, TD_UNDS_PIPE_reset),	// Tap for _, hold for |
};


																			//TD_NAV_NUM tap dance
static td_tap_t TD_NAV_NUM_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_NAV_NUM_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_NAV_NUM_tap_state.state = cur_dance(state);
    switch (TD_NAV_NUM_tap_state.state) {
        case TD_SINGLE_TAP: break;
		
        case TD_SINGLE_HOLD: 
			layer_on(_NAV_NUM);
			break;
			
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_NAV_NUM_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_NAV_NUM_tap_state.state) {
		
        case TD_SINGLE_TAP: 
			register_code16(KC_ENT);
			unregister_code16(KC_ENT);
			if (gaming_chat) {
                layer_on(_GAMING);  
                layer_off(_DVORAK); 
				autoshift_disable();
				gaming_chat = false;
			} 
			break;
				
        case TD_SINGLE_HOLD: 
			layer_off(_NAV_NUM);
			break;
			        
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_NAV_NUM_tap_state.state = TD_NONE;
};


																			//TD_NUM_CHAT tap dance
static td_tap_t TD_NUM_CHAT_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_NUM_CHAT_finished(qk_tap_dance_state_t *state, void *user_data) {
   TD_NUM_CHAT_tap_state.state = cur_dance(state);
    switch (TD_NUM_CHAT_tap_state.state) {
        case TD_SINGLE_TAP: break;
        case TD_SINGLE_HOLD: 
			layer_on(_NAV_NUM);
			break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_NUM_CHAT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_NUM_CHAT_tap_state.state) {
        case TD_SINGLE_TAP: 
					tap_code(KC_ENT);
					layer_on(_DVORAK); 
					layer_off(_GAMING);  
					autoshift_enable();
					gaming_chat = true;	
			break;
        case TD_SINGLE_HOLD: 
			layer_off(_NAV_NUM);
			break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_NUM_CHAT_tap_state.state = TD_NONE;
};


																			//TD_DOT_COMM tap dance
static td_tap_t TD_DOT_COMM_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_DOT_COMM_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_DOT_COMM_tap_state.state = cur_dance(state);
    switch (TD_DOT_COMM_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_DOT);  break;
        case TD_SINGLE_HOLD: register_code16(KC_COMM);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_DOT_COMM_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_DOT_COMM_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_COMM); break;
        case TD_UNKNOWN: 					//Do elipse ...
			tap_code(KC_DOT);
			tap_code(KC_DOT);
			tap_code(KC_DOT);
			break;
        case TD_NONE: break;
    }
    TD_DOT_COMM_tap_state.state = TD_NONE;
};


																			//TD_CPY_PST tap dance
static td_tap_t TD_CPY_PST_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_CPY_PST_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_CPY_PST_tap_state.state = cur_dance(state);
    switch (TD_CPY_PST_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_V)); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_CPY_PST_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_CPY_PST_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_V)); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_CPY_PST_tap_state.state = TD_NONE;
};


																			//TD_LPRN_LCBR tap dance
static td_tap_t TD_LPRN_LCBR_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_LPRN_LCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_LPRN_LCBR_tap_state.state = cur_dance(state);
    switch (TD_LPRN_LCBR_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LPRN);  break;
        case TD_SINGLE_HOLD: register_code16(KC_LCBR);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_LPRN_LCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_LPRN_LCBR_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LCBR); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_LPRN_LCBR_tap_state.state = TD_NONE;
};


																			//TD_RPRN_RCBR tap dance
static td_tap_t TD_RPRN_RCBR_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_RPRN_RCBR_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_RPRN_RCBR_tap_state.state = cur_dance(state);
    switch (TD_RPRN_RCBR_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RPRN);  break;
        case TD_SINGLE_HOLD: register_code16(KC_RCBR);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_RPRN_RCBR_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_RPRN_RCBR_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_RCBR); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_RPRN_RCBR_tap_state.state = TD_NONE;
};


																			//TD_LBRC_LT tap dance
static td_tap_t TD_LBRC_LT_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_LBRC_LT_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_LBRC_LT_tap_state.state = cur_dance(state);
    switch (TD_LBRC_LT_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LBRC);  break;
        case TD_SINGLE_HOLD: register_code16(KC_LT);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_LBRC_LT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_LBRC_LT_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LBRC); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_LT); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_LBRC_LT_tap_state.state = TD_NONE;
};


																			//TD_RBRC_GT tap dance
static td_tap_t TD_RBRC_GT_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_RBRC_GT_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_RBRC_GT_tap_state.state = cur_dance(state);
    switch (TD_RBRC_GT_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RBRC);  break;
        case TD_SINGLE_HOLD: register_code16(KC_GT);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_RBRC_GT_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_RBRC_GT_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RBRC); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_GT); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_RBRC_GT_tap_state.state = TD_NONE;
};


																			//TD_EQL_SLSH tap dance
static td_tap_t TD_EQL_SLSH_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_EQL_SLSH_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_EQL_SLSH_tap_state.state = cur_dance(state);
    switch (TD_EQL_SLSH_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_EQL);  break;
        case TD_SINGLE_HOLD: register_code16(KC_SLSH);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_EQL_SLSH_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_EQL_SLSH_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_EQL); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_SLSH); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_EQL_SLSH_tap_state.state = TD_NONE;
};


																			//TD_PLUS_MINS tap dance
static td_tap_t TD_PLUS_MINS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_PLUS_MINS_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_PLUS_MINS_tap_state.state = cur_dance(state);
    switch (TD_PLUS_MINS_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_PLUS);  break;
        case TD_SINGLE_HOLD: register_code16(KC_MINS);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_PLUS_MINS_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_PLUS_MINS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_PLUS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_MINS); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_PLUS_MINS_tap_state.state = TD_NONE;
};


																			//TD_QUES_BSLS tap dance
static td_tap_t TD_QUES_BSLS_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_QUES_BSLS_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_QUES_BSLS_tap_state.state = cur_dance(state);
    switch (TD_QUES_BSLS_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_QUES);  break;
        case TD_SINGLE_HOLD: register_code16(KC_BSLS);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_QUES_BSLS_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_QUES_BSLS_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_QUES); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_BSLS); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_QUES_BSLS_tap_state.state = TD_NONE;
};


																			//TD_UNDS_PIPE tap dance
static td_tap_t TD_UNDS_PIPE_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void TD_UNDS_PIPE_finished(qk_tap_dance_state_t *state, void *user_data) {
    TD_UNDS_PIPE_tap_state.state = cur_dance(state);
    switch (TD_UNDS_PIPE_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_UNDS);  break;
        case TD_SINGLE_HOLD: register_code16(KC_PIPE);  break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
};

void TD_UNDS_PIPE_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (TD_UNDS_PIPE_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_PIPE); break;
        case TD_UNKNOWN: break;
        case TD_NONE: break;
    }
    TD_UNDS_PIPE_tap_state.state = TD_NONE;
};
