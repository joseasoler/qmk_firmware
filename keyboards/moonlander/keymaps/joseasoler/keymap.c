/* Copyright 2022 José Ángel Soler Ortiz <jose.angel.soler.ortiz@gmail.com>
 * Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "version.h"

#include "keymap_extras/keymap_spanish.h"
#include "keymap_extras/sendstring_spanish.h"

enum layers {
    KL_BASE = 0,   // Base layer.
    KL_NAVIGATION, // Navigation layer.
    KL_SYMBOL,     // Symbol layer.
};

// Custom keycodes used by this keymap.
enum custom_keycodes {
    UNUSED = ML_SAFE_RANGE, // Start of the custom keycode range of this keymap.

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

// Unicode single keycode macros.
#define KU_POUND UC(0xA3) // £
#define KU_DEGRE UC(0xB0) // °

// Momentary activation of layers.
#define MO_SYMBL MO(KL_SYMBOL)
#define MO_NAVIG MO(KL_NAVIGATION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [KL_BASE] = LAYOUT_moonlander(
        // clang-format off
        KC_ESC,   ES_1,     ES_2,     ES_3,     ES_4,     ES_5,     KC_NO,        KC_INS,   ES_6,     ES_7,     ES_8,     ES_9,     ES_0,     CK_QUOT,
        KC_TAB,   ES_Q,     ES_W,     ES_E,     ES_R,     ES_T,     MO_SYMBL,     MO_SYMBL, ES_Y,     ES_U,     ES_I,     ES_O,     ES_P,     CK_QUES,
        _______,  ES_A,     ES_S,     ES_D,     ES_F,     ES_G,     MO_NAVIG,     MO_NAVIG, ES_H,     ES_J,     ES_K,     ES_L,     ES_NTIL,  ES_ACUT,
        KC_LSFT,  ES_Z,     ES_X,     ES_C,     ES_V,     ES_B,                             ES_N,     ES_M,     ES_COMM,  ES_DOT,   CK_EXLM,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LEFT,  KC_RGHT,            MO_NAVIG,     MO_NAVIG,           KC_UP,    KC_DOWN,  KC_ALGR,  KC_MEH,   KC_HYPR,
                                                KC_SPC,   KC_BSPC,  MO_SYMBL,     MO_SYMBL, KC_DELT,  KC_ENT
        // clang-format on
        ),

    [KL_SYMBOL] = LAYOUT_moonlander(
        // clang-format off
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      CK_SHRUG, ES_MORD,  ES_NOT,   _______,  KU_DEGRE, _______,  _______,
        _______,  _______,  CK_ARROW, ES_LABK,  ES_RABK,  ES_HASH,  _______,      _______,  ES_CIRC,  ES_EQL,   ES_AMPR,  ES_PIPE,  ES_TILD,  _______,
        _______,  ES_SLSH,  ES_BSLS,  ES_LPRN,  ES_RPRN,  ES_UNDS,  _______,      _______,  KC_PERC,  ES_PLUS,  ES_MINS,  ES_ASTR,  ES_SLSH,  _______,
        _______,  ES_LBRC,  ES_RBRC,  ES_LCBR,  ES_RCBR,  ES_AT,                            ES_CCED,  KC_DLR,   ES_EURO,  KU_POUND, _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______

        // clang-format on
        ),

    [KL_NAVIGATION] = LAYOUT_moonlander(
        // clang-format off
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    _______,      CK_VRSN,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_BRID,  KC_BRIU,  _______,  KC_PSCR,  KC_F12,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_MPRV,  KC_MNXT,  KC_MPLY,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                          _______,  KC_VOLD,  KC_VOLU,  KC_MUTE, _______,  _______,
        _______,  _______,  _______,  KC_PGUP,  KC_PGDN,            _______,      _______,            KC_HOME,  KC_END,   _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  UC_MOD

        // clang-format on
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Store the current press status of the shift key.
    static bool is_shift_pressed = false;
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        is_shift_pressed = record->event.pressed;
    }

    // Custom keycodes beyond here don't perform any actions on release.
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        // Custom macro keycodes.
        case CK_ARROW: // ->
            tap_code(ES_MINS);
            tap_code16(ES_RABK);
            break;

        // Custom unicode keycodes.
        case CK_SHRUG: //
            send_unicode_string("¯\\_(ツ)_/¯");
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
