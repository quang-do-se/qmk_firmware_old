/*
  Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FUNCTION,
    _RGB,
    _ENTERTAINMENT,
    _SWITCH
};


enum q_keys {
    QC_ESC,            // default: escape,  shift: ~
    QC_M,              // default: M, ctrl: enter
    QL_BASE,           // layout 0
    QL_FUNCTION,       // layout 1
    QL_RGB,            // layout 2
    QL_ENTERTAINMENT   // layout 3
};


//Tap Dance Declarations
enum {
    TD_RCTL_ENT = 0,
    TD_LSFT_CAPS
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RCTL_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_ENT),
    [TD_LSFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * ,-----------------------------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
     * |-----------------------------------------------------------------------------------------+
     * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
     * |-----------------------------------------------------------------------------------------+
     * |  Ctrl   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Ctrl     |
     * |-----------------------------------------------------------------------------------------+
     * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      Shift      |
     * |-----------------------------------------------------------------------------------------+
     * | Caps  |  GUI  |  Alt  |              Space              |  Alt  |  GUI  |  L1   | Entr  |
     * `-----------------------------------------------------------------------------------------'
     */

    /* FUNCTION
     * ,-----------------------------------------------------------------------------------------.
     * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
     * |-----------------------------------------------------------------------------------------+
     * |        |     | Up  |     |     |     |     |     | Up  |     |PgUp |Home |     |        |
     * |-----------------------------------------------------------------------------------------+
     * |         |Left |Down |Right|     |     |     |Left |Down |Right|PgDn | End |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |     |     |     |     |     | NK  |VolMu|VolDn|VolUp|     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |                                 |QD_ALT |  L2   |       |       |
     * `-----------------------------------------------------------------------------------------'
     */

    /* RGB
     * ,-----------------------------------------------------------------------------------------.
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |   Reset   |
     * |-----------------------------------------------------------------------------------------+
     * | BL Tog |BLInc|BLDec|BLStp|     |     |     |     |     |     |     |     |     |        |
     * |-----------------------------------------------------------------------------------------+
     * | RGB Tog |Mode |Hue I|Sat I|Val I|Spd I|Plain|Breat|Rnbow|Swirl|     |     |             |
     * |-----------------------------------------------------------------------------------------+
     * |           |RMode|Hue D|Sat D|Val D|Spd D|Snake|Knigh|Xmas |Gradi|     |                 |
     * |-----------------------------------------------------------------------------------------+
     * |       |       |       |                                 |       |       |       |       |
     * `-----------------------------------------------------------------------------------------'
     */

    [_BASE] = LAYOUT_60_ansi(
                             QC_ESC,            KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
                             KC_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
                             KC_LCTL,           KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            TD(TD_RCTL_ENT),
                             TD(TD_LSFT_CAPS),  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT ,  KC_SLSH,                      KC_RSFT,
                             MO(_FUNCTION),     KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(_SWITCH),        MO(_FUNCTION)
                             ),

    [_FUNCTION] = LAYOUT_60_ansi(
                                 KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
                                 _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  KC_PGUP,  KC_HOME,  _______,  _______,
                                 _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_END,             _______,
                                 _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_UP,                        MO(_RGB),
                                 _______,  _______,  _______,                      _______,                                KC_LEFT,  KC_DOWN,  KC_RGHT,             MO(_SWITCH)
                                 ),

    [_RGB] = LAYOUT_60_ansi(
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,
                            BL_TOGG,  BL_INC,   BL_DEC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
                            _______,  _______,  _______,                      _______,                                _______,  _______,  _______,             MO(_SWITCH)
                            ),

    [_ENTERTAINMENT] = LAYOUT_60_ansi(
                                      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
                                      _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  KC_PGUP,  KC_HOME,  _______,  _______,
                                      _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_END,             _______,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_UP,                        _______,
                                      _______,  _______,  _______,                      _______,                                KC_LEFT,  KC_DOWN,  KC_RGHT,             MO(_SWITCH)
                                      ),


    [_SWITCH] = LAYOUT_60_ansi(
                               QL_BASE,  QL_FUNCTION, QL_RGB,   QL_ENTERTAINMENT, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,
                               _______,  _______,     _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                               _______,  _______,     _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
                               _______,  _______,     _______,  _______,          _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,                      QL_ENTERTAINMENT,
                               _______,  _______,     _______,                              _______,                                _______,  _______,  _______,             MO(_SWITCH)
                               ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI  (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t kc;

    switch (keycode) {

    case QC_ESC:
        if (record->event.pressed) {
            if (MODS_GUI) {
                kc = KC_ESCAPE;
            } else if (MODS_SHIFT) {
                kc = KC_TILDE;
            } else {
                kc = KC_ESCAPE;
            }

            register_code(kc);
        } else {
            unregister_code(kc);
        }
        return false;

    case QL_BASE:
        if (record->event.pressed) {
            layer_move(_BASE);
            backlight_level(_BASE);
            backlight_disable();
            return false;
        }
        return true;

    case QL_FUNCTION:
        if (record->event.pressed) {
            layer_move(_FUNCTION);
            backlight_level(_FUNCTION);
            backlight_enable();
            return false;
        }
        return true;

    case QL_RGB:
        if (record->event.pressed) {
            layer_move(_RGB);
            backlight_level(_RGB);
            backlight_enable();
            return false;
        }
        return true;

    case QL_ENTERTAINMENT:
        if (record->event.pressed) {
            layer_move(_ENTERTAINMENT);
            backlight_level(_ENTERTAINMENT);
            backlight_enable();
            return false;
        }
        return true;

    default:
        return true; //Process all other keycodes normally
    }
}
