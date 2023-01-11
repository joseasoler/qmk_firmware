#include QMK_KEYBOARD_H

#include "version.h"

#include "keymap_extras/keymap_spanish.h"
#include "keymap_extras/sendstring_spanish.h"

// Definition of keyboard layers.
enum keyboard_layers {
	KL_BASE = 0,	 // Base layer.
	KL_NAVIGATION, // Navigation layer.
	KL_SYMBOL,		 // Symbol layer.
};

// Custom keycodes used by this keymap.
enum custom_keycodes {
	UNUSED = EZ_SAFE_RANGE, // Start of the custom keycode range of this keymap.

	// Macro keycodes.
	CK_ARROW, // ->

	// Unicode keycodes.
	CK_SHRUG, // ¯\_(ツ)_/¯

	// Keycodes with alternate shift characters.
	CK_QUOT, // " -> '
	CK_QUES, // ? -> ¿
	CK_EXLM, // ! -> ¡

	// Special keycodes.
	CK_VRSN, // Outputs the version of this keymap.
};

// Momentary activaton of layer.
#define MO_SYMBL MO(KL_SYMBOL)
#define MO_NAVIG MO(KL_NAVIGATION)

// Other layer keys.
#define LT_SYMBL LT(KL_SYMBOL, ES_ACUT)

// Unicode single keycode macros.
#define KU_POUND UC(0xA3) // £
#define KU_DEGRE UC(0xB0) // °

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[KL_BASE] = LAYOUT_ergodox(
		// clang-format off
		// Left hand.
		KC_ESC,   ES_1,     ES_2,     ES_3,     ES_4,     ES_5,     KC_NO,
		KC_TAB,   ES_Q,     ES_W,     ES_E,     ES_R,     ES_T,     MO_SYMBL,
		MO_SYMBL, ES_A,     ES_S,     ES_D,     ES_F,     ES_G,
		KC_LSFT,  ES_Z,     ES_X,     ES_C,     ES_V,     ES_B,     MO_NAVIG,
		KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LEFT, KC_RGHT,

		                                                            KC_NO,    KC_NO,
		                                                                      KC_HOME,
		                                                  KC_SPC,   KC_BSPC,  KC_END,
		// Right hand.
		          KC_INS,   ES_6,     ES_7,     ES_8,     ES_9,     ES_0,     CK_QUOT,
		          MO_SYMBL, ES_Y,     ES_U,     ES_I,     ES_O,     ES_P,     CK_QUES,
		                    ES_H,     ES_J,     ES_K,     ES_L,     ES_NTIL,  LT_SYMBL,
		          MO_NAVIG, ES_N,     ES_M,     ES_COMM,  ES_DOT,   CK_EXLM,  KC_RSFT,
		                              KC_UP,    KC_DOWN,  KC_ALGR,  KC_MEH,   KC_HYPR,

		KC_NO,    KC_INS,
		KC_PGUP,
		KC_PGDN,  KC_DELT,  KC_ENT
		// clang-format on
		),
	[KL_SYMBOL] = LAYOUT_ergodox(
		// clang-format off
		// Left hand.
		KC_TRNS,  KC_NO,    KC_NO,    KC_NO,     KC_NO,   KC_NO,    KC_TRNS,
		KC_TRNS,  KC_NO,    CK_ARROW, ES_LABK,   ES_RABK, ES_HASH,  KC_TRNS,
		KC_TRNS,  ES_SLSH,  ES_BSLS,  ES_LPRN,   ES_RPRN, ES_UNDS,
		KC_TRNS,  ES_LBRC,  ES_RBRC,  ES_LCBR,   ES_RCBR, ES_AT,    KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,

		                                                            KC_TRNS,  KC_TRNS,
		                                                                      KC_TRNS,
		                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,
		// Right hand.
		          CK_SHRUG, ES_MORD,  ES_NOT,   KC_NO,    KU_DEGRE, KC_NO,    KC_TRNS,
		          KC_TRNS,  ES_CIRC,  ES_EQL,   ES_AMPR,  ES_PIPE,  ES_TILD,  KC_TRNS,
		                    KC_PERC,  ES_PLUS,  ES_MINS,  ES_ASTR,  ES_SLSH,  KC_TRNS,
		          KC_TRNS,  ES_CCED,  KC_DLR,   ES_EURO,  KU_POUND, KC_NO,    KC_TRNS,
		                              KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,

		KC_TRNS,  KC_TRNS,
		KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS
		// clang-format on
		),
	[KL_NAVIGATION] = LAYOUT_ergodox(
		// clang-format off
		// Left hand.
		KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
		KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
		KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
		KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

		                                                            KC_TRNS,  CK_VRSN,
		                                                                      KC_TRNS,
		                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,
		// Right hand.
		          KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
		          KC_TRNS,  KC_NO,    KC_BRID,  KC_BRIU,  KC_NO,    KC_PSCR,  KC_F12,
		                    KC_NO,    KC_MPRV,  KC_MNXT,  KC_MPLY,  KC_NO,    KC_NO,
		          KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,
		                              KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

		KC_TRNS,  UC_MOD,
		KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS
		// clang-format on
		),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	if (keycode == ES_ACUT) {
		return 300U;
	}
	return TAPPING_TERM;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	// Current status of the shift key.
	static bool is_shift_pressed = false;
	if (keycode == KC_LSFT || keycode == KC_RSFT) {
		is_shift_pressed = record->event.pressed;
	}

	// Custom keycodes beyond here don't perform any actions on release.
	if (!record->event.pressed) { return true; }

	switch (keycode) {
	// Custom macro keycodes.
	case CK_ARROW: // ->
		tap_code(ES_MINS);
		tap_code16(ES_RABK);
		break;

	// Custom unicode keycodes.
	case CK_SHRUG: // ¯\_(ツ)_/¯
		// send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
		break;

	// Keycodes with alternate shift characters.
	case CK_QUOT:
		if (!is_shift_pressed) {
			register_code(KC_LSFT);
			tap_code(ES_2); // ES_DQUO
			unregister_code(KC_LSFT);
		} else {
			unregister_code(KC_LSFT);
			tap_code(ES_QUOT);
			register_code(KC_LSFT);
		}
		break;

	case CK_QUES:
		if (!is_shift_pressed) {
			register_code(KC_LSFT);
			tap_code(ES_QUOT); // ES_QUES
			unregister_code(KC_LSFT);
		} else {
			tap_code(ES_IEXL); // ES_IQUE
		}
		break;

	case CK_EXLM:
		if (!is_shift_pressed) {
			register_code(KC_LSFT);
			tap_code(ES_1); // ES_EXLM
			unregister_code(KC_LSFT);
		} else {
			unregister_code(KC_LSFT);
			tap_code(ES_IEXL);
			register_code(KC_LSFT);
		}
		break;

	// Special keycodes.
	case CK_VRSN:
		SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_BUILDDATE);
		break;
	}
	return true;
}

/*
// Runs once the keyboard matrix is initialized, but before other features have
// been set up.
void matrix_init_user(void) {
	// ToDo: Multiplatform support.
	set_unicode_input_mode(UC_LNX);
};
 */

// This runs every time that the layers get changed.
uint32_t layer_state_set_user(uint32_t state) {
	ergodox_board_led_off();

	switch (biton32(state)) {
	case KL_SYMBOL:
		ergodox_right_led_1_on();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
		break;
	case KL_NAVIGATION:
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_on();
		break;
	default:
		ergodox_right_led_1_off();
		ergodox_right_led_2_off();
		ergodox_right_led_3_off();
		break;
	}

	return state;
};
