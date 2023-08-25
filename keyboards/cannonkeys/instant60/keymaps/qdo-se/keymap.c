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
#include "print.h"

//Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3
};

enum layers {
    _BASE,
    _FUNCTION,
    _RGB,
    _ENTERTAINMENT,
    _SWITCH,
    _LAST
};

const char* layerNames [] = {
    [_BASE] = "Base",
    [_FUNCTION] = "Function",
    [_RGB] = "RGB",
    [_ENTERTAINMENT] = "Entertainment",
    [_SWITCH] = "Switch"
};


enum custom_keys {
    QD_ESC = SAFE_RANGE,    // default: escape,  shift: ~
    QD_M,                   // default: M, ctrl: enter
    QD_BASE,                // layout 0
    QD_FUNCTION,            // layout 1
    QD_RGB,                 // layout 2
    QD_ENTERTAINMENT        // layout 3
};


//Tap Dance Declarations
enum tap_dances {
    TD_RCTL_ENT = 0,
    TD_LSFT_CAPS,
    TD_FUNCTION_SWITCH
};


typedef struct {
    bool is_press_action;
    int state;
} tap;

//Declare the functions to be used with your tap dance key(s)

//Function associated with all tap dances
int cur_dance (qk_tap_dance_state_t *state);

//Functions associated with individual tap dances
void mo_finished (qk_tap_dance_state_t *state, void *user_data);
void mo_reset (qk_tap_dance_state_t *state, void *user_data);

void change_backlight(void);

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RCTL_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_ENT),
    [TD_LSFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_FUNCTION_SWITCH]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mo_finished, mo_reset)
};

// Ref: https://github.com/samhocevar-forks/qmk-firmware/blob/master/docs/feature_tap_dance.md#example-6-using-tap-dance-for-momentary-layer-switch-and-layer-toggle-keys
// Determine the current tap dance state
int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return DOUBLE_TAP;
    }
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap mo_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void mo_finished (qk_tap_dance_state_t *state, void *user_data) {
    mo_tap_state.state = cur_dance(state);

    switch (mo_tap_state.state) {
    case SINGLE_TAP:
        break;
    case SINGLE_HOLD:
        layer_on(_FUNCTION);
        break;
    case DOUBLE_TAP:
        //check to see if the layer is already set
        if (layer_state_is(_SWITCH)) {
            //if already set, then switch it off
            layer_off(_SWITCH);
        } else {
            //if not already set, then switch the layer on
            layer_on(_SWITCH);
        }
        break;
    }
}

void mo_reset (qk_tap_dance_state_t *state, void *user_data) {
    // if the key was held down and now is released then switch off the layer
    if (mo_tap_state.state==SINGLE_HOLD) {
        layer_off(_FUNCTION);
    }
    mo_tap_state.state = 0;
}


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
                             QD_ESC,            KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
                             KC_TAB,            KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
                             KC_LCTL,           KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            TD(TD_RCTL_ENT),
                             TD(TD_LSFT_CAPS),  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT ,  KC_SLSH,                      KC_RSFT,
                             MO(_FUNCTION),     KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(_FUNCTION),      TD(TD_FUNCTION_SWITCH)
                             ),

    [_FUNCTION] = LAYOUT_60_ansi(
                                 KC_GRV, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
                                 _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  KC_PGUP,  KC_HOME,  _______,  _______,
                                 _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_END,             _______,
                                 _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_UP,                        _______,
                                 _______,  _______,  _______,                      _______,                                KC_LEFT,  KC_DOWN,  KC_RGHT,            TD(TD_FUNCTION_SWITCH)
                                 ),

    [_RGB] = LAYOUT_60_ansi(
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                            BL_TOGG,  BL_INC,   BL_DEC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
                            _______,  _______,  _______,                      _______,                                _______,  _______,  _______,            TD(TD_FUNCTION_SWITCH)
                            ),

    [_ENTERTAINMENT] = LAYOUT_60_ansi(
                                      KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL, KC_BSPC,
                                      _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,
                                      _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,
                                      _______,  _______,  _______,  _______,  _______, _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_UP,                       _______,
                                      _______,  _______,  _______,                     _______,                                KC_LEFT,  KC_DOWN,  KC_RGHT,           TD(TD_FUNCTION_SWITCH)
                                      ),

    [_SWITCH] = LAYOUT_60_ansi(
                               QD_BASE,  QD_FUNCTION, QD_RGB,   QD_ENTERTAINMENT, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,
                               _______,  _______,     _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QD_ENTERTAINMENT,
                               _______,  _______,     _______,  _______,          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
                               _______,  _______,     _______,  _______,          _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,                      _______,
                               _______,  _______,     _______,                              _______,                                _______,  _______,  _______,            TD(TD_FUNCTION_SWITCH)
                               ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

/* void print_layer(void) { */
/*     for ( int layerInt = _BASE; layerInt != _LAST; layerInt++ ) { */
/*         if (IS_LAYER_ON(layerInt)) { */
/*             printf("\nLayer %s\n", layerNames[layerInt]); */
/*         } */
/*     } */
/* } */


layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);

    backlight_level(current_layer);

    if (current_layer == _BASE) {
        backlight_disable();
    } else {
        backlight_enable();
    }

    return state;
}

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI  (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t kc;

    // Store the current modifier state in the variable for later reference
    uint8_t mod_state = get_mods();

    switch (keycode) {

    case QD_ESC:
        if (record->event.pressed) {
            if (MODS_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                kc = KC_GRV;
            } else {
                kc = KC_ESCAPE;
            }

            // restore mod state
            set_mods(mod_state);
            register_code(kc);
        } else {
            unregister_code(kc);
        }
        return false; // Skip all further processing of this key

    case QD_BASE:
        if (record->event.pressed) {
            layer_move(_BASE);
        }
        return false; // Skip all further processing of this key

    case QD_FUNCTION:
        if (record->event.pressed) {
            layer_move(_FUNCTION);
        }
        return false; // Skip all further processing of this key

    case QD_RGB:
        if (record->event.pressed) {
            layer_move(_RGB);
        }
        return false; // Skip all further processing of this key

    case QD_ENTERTAINMENT:
        if (record->event.pressed) {
            layer_move(_ENTERTAINMENT);
        }
        return false; // Skip all further processing of this key

    default:
        return true; //Process all other keycodes normally
    }
}
