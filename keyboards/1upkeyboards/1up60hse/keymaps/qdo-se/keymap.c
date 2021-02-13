/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
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

enum qd_keycodes {
  QD_ESC,             // default: escape,  shift: ~
  QD_M,               // default: M, ctrl: enter
  QD_ALT              // layout switch
};

#define _BASE 0
#define _FUNCTION 1
#define _RGB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* L0 - Qwerty
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

  /* L1 - Function
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

  /* L2 - RGB
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

  [0] = LAYOUT_60_ansi(
                       QD_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
                       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
                       KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_RCTL,
                       KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT ,  KC_SLSH,                      KC_RSFT,
                       KC_CAPS,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(1),              KC_ENT
                       ),
  [1] = LAYOUT_60_ansi(
                       KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
                       _______,  _______,  KC_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  KC_PGUP,  KC_HOME,  _______,  _______,
                       _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  KC_END,             _______,
                       _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,                      _______,
                       _______,  _______,  _______,                      _______,                                QD_ALT,   MO(2),    _______,            _______
                       ),
  [2] = LAYOUT_60_ansi(
                       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
                       BL_TOGG,  BL_INC,   BL_DEC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                       RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, _______,  _______,            _______,
                       _______,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  _______,                      _______,
                       _______,  _______,  _______,                      _______,                                _______,  _______,  _______,            _______
                       )
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI  (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t kc;
  static bool switching_layout = false;
  static uint16_t current_layout = 0;
  static uint16_t saved_layout = 0;


  switch (keycode) {

  case QD_ESC:
    if (record->event.pressed) {
      if (switching_layout) {
        current_layout = 0;
        layer_move(current_layout);
        return false;
      }

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

  case QD_M:
    if (record->event.pressed) {
      if (MODS_CTRL) {
        bool lctl_on = get_mods() & MOD_BIT(KC_LCTL);
        bool rctl_on = get_mods() & MOD_BIT(KC_RCTL);

        del_mods(MOD_MASK_CTRL);
        kc = KC_ENT;
        register_code(kc);

        if (lctl_on) {
          register_code(KC_LCTL);
        }

        if (rctl_on) {
          register_code(KC_RCTL);
        }
      } else {
        kc = KC_M;
        register_code(kc);
      }
    } else {
      unregister_code(kc);
    }
    return false;

  case MO(1):
    if (record->event.pressed) {
      saved_layout = current_layout;
      layer_move(1);
    } else {
      // If layout is not changed during pressing MO(1), reverse back to previous layout once releaseing MO(1)
      // For example:
      // If active layer is 2, presseing MO(1) will move to layer 1. If active layer is not changed, releasing MO(1) will move back to layer 2.
      // If active layer is 2, presseing MO(1) will move to layer 1. If active layer is changed to 0, releasing MO(1) will do nothing and active layer is 0.
      if (saved_layout == current_layout) {
        layer_move(current_layout);
      } 
    }

    return false;

  case QD_ALT:
    if (record->event.pressed) {
      switching_layout = true;
    } else {
      switching_layout = false;
    }
    return false;

  case KC_GRV:
    if (record->event.pressed) {
      if (switching_layout) {
        current_layout = 0;
        layer_move(current_layout);
        return false;
      }
    }
    return true;

  case KC_1:
  case KC_F1:
    if (record->event.pressed) {
      if (switching_layout) {
        current_layout = 1;
        layer_move(current_layout);
        return false;
      }
    }
    return true;

  case KC_2:
  case KC_F2:
    if (record->event.pressed) {
      if (switching_layout) {
        current_layout = 2;
        layer_move(current_layout);
        return false;
      }
    }
    return true;

  default:
    return true; //Process all other keycodes normally
  }
}
