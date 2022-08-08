#include QMK_KEYBOARD_H 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
*	 ,----------------------------------------------------------------------------------.
* 	|	 Home	|	  T		|	  Q		|	  W		|	  E  	|	  R		|	 Esc	|
* 	|-----------------------------------------------------------------------------------|
* 	| 	 DEL 	|	  G		|	  A		|	  S		|	  D 	|	  F		|	 Tab	|
* 	|-----------------------------------------------------------------------------------|
* 	|	 END 	|	  B		|     Z		|	  X		|	  C		|	  V		|  F5 save	|
* 	|-----------------------------------------------------------------------------------|
*  				 			 			|	 ALT	|	CTRL	|	SHIFT	|	SPACE	|
* 		 							  	`-----------------------------------------------'
*/
[0] = LAYOUT_50(
	KC_HOME, 		KC_T, 		KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_ESC,	
	KC_DEL, 		KC_G,		KC_A, 		KC_S, 		KC_D, 		KC_F, 		KC_TAB,
	KC_END, 		KC_B, 		KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_F5,
											KC_LSFT, 	KC_LALT,	KC_LCTL,	KC_SPC		
)
};
