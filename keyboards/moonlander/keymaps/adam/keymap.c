/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
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

//
// Keycode map is here: https://github.com/Adam13531/qmk_firmware#moonlander-notes
//

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _WIN_BASE,  // default layer
    _MAC_BASE,  // default layer but with Mac keys
    _GAMING,    // gaming layer (no LH home-row mods)
    _SYMB,      // symbols
    _NUM,       // numbers
    _FUN,       // fn keys
    _NAV,       // navigation keys
    _MDIA,      // media keys
};

enum custom_keycodes {
    MAC_SWP = ML_SAFE_RANGE,
    // Ctrl on Mac, GUI on Win
    MAC_CTRL_WIN_GUI,
    // GUI on Mac, ctrl on Win
    MAC_GUI_WIN_CTRL,
    // (, {, and [ based on which modifier is held
    KC_LEFT_ENCLOSE,
    // ), }, and ] based on which modifier is held
    KC_RIGHT_ENCLOSE,
};

// This is just to save space over typing "_______" in layouts.
#define XXX KC_NO

// Left-hand home row mods on Windows: GACS (Gui → Alt → Ctrl → Shift)
// ("W_HM" = "Windows home")
#define W_HM_A LGUI_T(KC_A)
#define W_HM_S LALT_T(KC_S)
#define W_HM_D LCTL_T(KC_D)
#define W_HM_F LSFT_T(KC_F)

// Right-hand home row mods on Windows: SCAG
// All of these use the left-hand modifier to make some of the custom code
// easier to write (since there's only a need to check, unset, or set a single
// modifier rather than both).
#define W_HM_J LSFT_T(KC_J)
#define W_HM_K LCTL_T(KC_K)
#define W_HM_L LALT_T(KC_L)
#define W_HM_SCLN LGUI_T(KC_SCLN)

// Left-hand home row mods on Mac: CAGS
#define M_HM_A LCTL_T(KC_A)
#define M_HM_S LALT_T(KC_S)
#define M_HM_D LGUI_T(KC_D)
#define M_HM_F LSFT_T(KC_F)

// Right-hand home row mods on Mac: SGAC
#define M_HM_J LSFT_T(KC_J)
#define M_HM_K LGUI_T(KC_K)
#define M_HM_L LALT_T(KC_L)
#define M_HM_SCLN LCTL_T(KC_SCLN)

enum combos { UI_HYPHEN, UIO_CAPS, COMBO_LENGTH };
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ui_hyphen[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM uio_caps[]  = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    [UI_HYPHEN] = COMBO(ui_hyphen, KC_MINS),
    [UIO_CAPS]  = COMBO(uio_caps, KC_CAPS),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN_BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    A(KC_LSFT),    A(KC_LSFT), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LGUI,W_HM_A, W_HM_S,  W_HM_D,  W_HM_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H, W_HM_J,  W_HM_K,  W_HM_L,W_HM_SCLN, LT(_MDIA, KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,KC_LEFT,LT(_FUN,KC_ESC),KC_LALT,                  LCTL_T(KC_ENT),LT(_SYMB,KC_BSPC),KC_DOWN, KC_LBRC, KC_RBRC, TT(_SYMB),
                LT(_NAV, KC_SPC),  LT(_NUM, KC_TAB), LT(_FUN, KC_ESC),            KC_DEL,  KC_ENT, LT(_SYMB, KC_BSPC)
    ),
    [_MAC_BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    A(KC_LSFT),    A(KC_LSFT), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_HYPR, M_HM_A,M_HM_S,  M_HM_D,  M_HM_F,    KC_G,    KC_HYPR,           KC_MEH, KC_H,  M_HM_J,  M_HM_K,  M_HM_L,  M_HM_SCLN, LT(_MDIA, KC_QUOT),
        KC_LSFT, LGUI_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,KC_LEFT,LT(_FUN,KC_ESC),KC_LALT,                  LGUI_T(KC_ENT), LT(_SYMB,KC_BSPC),KC_DOWN, KC_LBRC, KC_RBRC, TT(_SYMB),
                LT(_NAV, KC_SPC),  LT(_NUM, KC_TAB), LT(_FUN, KC_ESC),            KC_DEL,  KC_ENT, LT(_SYMB, KC_BSPC)
    ),
    [_GAMING] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,         TG(_GAMING), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_9,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_8,              KC_MEH, KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, LT(_MDIA, KC_QUOT),
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,KC_LGUI,KC_LALT,KC_LEFT,  KC_SPC, KC_LALT,                        LCTL_T(KC_ESC), LT(_SYMB,KC_BSPC),KC_DOWN, KC_LBRC, KC_RBRC, TT(_SYMB),
                        KC_SPC,  LT(_NUM, KC_TAB), LT(_FUN, KC_ESC),              KC_DEL,  LT(_NAV,KC_ENT), LT(_SYMB, KC_BSPC)
    ),

    // Having numpad-specific numbers (e.g. KC_P1 instead of KC_1) isn't
    // important for almost anything other than typing alt codes on Windows. I
    // opted for regular number keys so that I could use win+# more naturally to
    // move between open applications.
    [_SYMB] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______,   _______,   _______,    _______, _______,
        _______, _______, _______, KC_MINS,  KC_EQL, KC_BSLS, _______,           _______, _______, _______,   _______,   _______,    _______, _______,
        _______, KC_GRV,  KC_QUOT,KC_LEFT_ENCLOSE,KC_RIGHT_ENCLOSE,XXX,XXX,       XXX, XXX, KC_LSFT,MAC_GUI_WIN_CTRL,KC_LALT,MAC_CTRL_WIN_GUI, _______,
        _______, _______, _______, KC_LBRC, KC_RBRC, _______,                             _______, _______,   _______,   _______,    _______, _______,
        _______, _______, _______, _______, TG(_SYMB),        _______,           _______,          _______,   _______,   _______,    _______, TG(_SYMB),
                                            _______, _______, _______,           TG(_SYMB),_______,_______
    ),

    [_NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_NLCK, KC_7,     KC_8,      KC_9,    KC_PAST, _______,
_______,MAC_CTRL_WIN_GUI,KC_LALT,MAC_GUI_WIN_CTRL,KC_LSFT,_______,_______,       _______, KC_MINS, KC_4,     KC_5,      KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______,                             KC_COMM, KC_1,     KC_2,      KC_3,    KC_SLSH, _______,
        _______, _______, _______, _______, _______,        _______,             _______,          KC_0,     KC_0,    KC_DOT,    KC_EQL , _______,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [_FUN] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______,   _______,  _______,   _______, _______,
        _______, _______, _______,   _______, _______, _______, _______,         _______, KC_CAPS, KC_F7,     KC_F8,      KC_F9,    KC_F12, _______,
_______,MAC_CTRL_WIN_GUI,KC_LALT,MAC_GUI_WIN_CTRL,KC_LSFT,_______,_______,       _______, _______, KC_F4,     KC_F5,      KC_F6,    KC_F11, _______,
        _______, _______, _______, _______, _______, _______,                             _______, KC_F1,     KC_F2,      KC_F3,    KC_F10, _______,
        _______, _______, _______, _______, _______,        _______,             _______,          _______,   _______,  _______,   _______, _______,
                                            _______, _______, _______,           _______,_______, _______
    ),

    [_NAV] = LAYOUT_moonlander(
        _______,_______,_______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TAB, _______,
    _______,MAC_CTRL_WIN_GUI,KC_LALT,MAC_GUI_WIN_CTRL,KC_LSFT,_______,_______,   _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                             KC_ESC,  KC_BSPC, KC_ENT,  KC_DEL,  _______, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          C(S(KC_TAB)),C(KC_TAB), _______, _______, _______,
                                            _______, _______, _______,           _______, _______, KC_BSPC
    ),

    // For some reason, if _NAV is above _MDIA, then the mouse movement from _MDIA starts affecting _NAV.
    [_MDIA] = LAYOUT_moonlander(
    TO(_GAMING),_______,_______, _______, _______, _______, DF(_WIN_BASE),       DF(_MAC_BASE), _______, _______, KC_MS_BTN3, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_PSCR, _______,
    _______,MAC_CTRL_WIN_GUI,KC_LALT,MAC_GUI_WIN_CTRL,KC_LSFT,_______,_______,   _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPLY, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, KC_BTN2, _______,
        _______, _______, _______, _______, _______,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, KC_BTN1
    ),
};
// clang-format on

// Sets all keycodes specified in the array to the given color. This is good for
// coloring arbitrary keys like WASD or all of the number keys at once.
void set_all_keys_colors(const uint8_t keycodes[], uint8_t len, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < len; ++i) {
        rgb_matrix_set_color(keycodes[i], r, g, b);
    }
}

// Sets keys that fall within a contiguous keycode range to a given color.
// The start and end codes are inclusive.
void set_color_for_contiguous_keycodes(uint8_t start_code, uint8_t end_code, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = start_code; i <= end_code; ++i) {
        rgb_matrix_set_color(i, r, g, b);
    }
}

void light_up_left_mods(uint8_t r, uint8_t g, uint8_t b) {
    const uint8_t left_mod_keycodes[] = {7, 12, 17, 22};
    set_all_keys_colors(left_mod_keycodes, sizeof(left_mod_keycodes) / sizeof(uint8_t), r, g, b);
}

void light_up_right_mods(uint8_t r, uint8_t g, uint8_t b) {
    const uint8_t right_mod_keycodes[] = {58, 53, 48, 43};
    set_all_keys_colors(right_mod_keycodes, sizeof(right_mod_keycodes) / sizeof(uint8_t), r, g, b);
}

bool is_mac_the_default(void) { return layer_state_cmp(default_layer_state, _MAC_BASE); }

// RGB_MATRIX_INDICATOR_SET_COLOR is just a reference to rgb_matrix_set_color
#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _WIN_BASE:
            // Common colors between Windows and Mac
            // rgb_matrix_set_color(22, 0x00, 0xF8, 0xF8);  // 'F' key
            // rgb_matrix_set_color(58, 0x00, 0xF8, 0xF8);  // 'J' key

            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                // When caps lock is on, make it REALLY obvious.
                set_color_for_contiguous_keycodes(0, 31, 0x64, 0x00, 0x64);
                set_color_for_contiguous_keycodes(36, 67, 0x64, 0x00, 0x64);
            }

            rgb_matrix_set_color(24, 0x64, 0x64, 0x64);  // '→' key
            rgb_matrix_set_color(32, 0x64, 0x00, 0x64);  // LH piano key 1
            rgb_matrix_set_color(33, 0x00, 0x64, 0x00);  // LH piano key 2
            rgb_matrix_set_color(34, 0x64, 0x64, 0x64);  // LH piano key 3
            // rgb_matrix_set_color(60, 0x00, 0x00, 0x64);  // '↑' key
            rgb_matrix_set_color(68, 0x00, 0x00, 0x64);  // RH piano key 1

            // MAC (this is here because default layers just work strangely I guess; when the Mac layer is default, the Windows layer is still the highest layer)
            if (is_mac_the_default()) {
                rgb_matrix_set_color(65, RGB_WHITE);  // Mac key
            } else {
                // WINDOWS
                rgb_matrix_set_color(29, RGB_GREEN);  // Win key
            }

            break;
        case _GAMING:
            set_color_for_contiguous_keycodes(0, 31, RGB_RED);
            rgb_matrix_set_color(66, RGB_RED);  // Leave gaming mode

            const uint8_t wasd_keycodes[] = {11, 7, 12, 17};
            set_all_keys_colors(wasd_keycodes, sizeof(wasd_keycodes) / sizeof(uint8_t), RGB_GREEN);
            break;
        case _SYMB: {
            light_up_right_mods(RGB_BLUE);
            const uint8_t sym_keycodes[] = {7, 17, 22, 16, 21, 26};
            set_all_keys_colors(sym_keycodes, sizeof(sym_keycodes) / sizeof(uint8_t), RGB_BLUE);
            break;
        }
        case _NUM: {
            light_up_left_mods(RGB_GREEN);
            rgb_matrix_set_color(62, 0x64, 0x00, 0x00);  // 'Y' key
            if (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK)) {
                rgb_matrix_set_color(62, RGB_YELLOW);  // 'Y' key
            }

            const uint8_t numpad_keycodes[] = {57, 58, 59, 60, 52, 53, 54, 55, 47, 48, 49};
            set_all_keys_colors(numpad_keycodes, sizeof(numpad_keycodes) / sizeof(uint8_t), RGB_GREEN);
            break;
        }
        case _FUN: {
            light_up_left_mods(RGB_WHITE);

            rgb_matrix_set_color(62, 0x64, 0x00, 0x00);  // 'Y' key
            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                rgb_matrix_set_color(62, RGB_YELLOW);  // 'Y' key
            }
            const uint8_t numpad_keycodes[] = {57, 58, 59, 52, 53, 54, 47, 48, 49, 42, 43, 44};
            set_all_keys_colors(numpad_keycodes, sizeof(numpad_keycodes) / sizeof(uint8_t), RGB_WHITE);
            break;
        }
        case _NAV: {
            light_up_left_mods(RGB_MAGENTA);
            rgb_matrix_set_color(64, 0x64, 0x64, 0x64);  // 'N' key
            rgb_matrix_set_color(42, 0x64, 0x64, 0x64);  // 'P' key
            rgb_matrix_set_color(59, 0x64, 0x00, 0x00);  // 'M' key
            rgb_matrix_set_color(54, 0x64, 0x64, 0x64);  // ',' key
            rgb_matrix_set_color(49, 0x64, 0x00, 0x00);  // '.' key
            rgb_matrix_set_color(62, 0x00, 0x64, 0x00);  // 'Y' key
            rgb_matrix_set_color(63, 0x00, 0x64, 0x00);  // 'H' key
            rgb_matrix_set_color(57, 0x64, 0x64, 0x00);  // 'U' key
            rgb_matrix_set_color(47, 0x64, 0x64, 0x00);  // 'O' key

            rgb_matrix_set_color(60, 0x64, 0x64, 0x64);  // '↑' key
            rgb_matrix_set_color(55, 0x64, 0x64, 0x64);  // '↓' key

            const uint8_t keycodes[] = {52 /*I*/, 58 /*J*/, 53 /*K*/, 48 /*L*/};
            set_all_keys_colors(keycodes, sizeof(keycodes) / sizeof(uint8_t), 0x64, 0x00, 0x64);
            break;
        }
        case _MDIA: {
            light_up_left_mods(RGB_CYAN);

            const uint8_t mouse_keycodes[] = {58, 51, 52, 53, 48, 44, 68};
            set_all_keys_colors(mouse_keycodes, sizeof(mouse_keycodes) / sizeof(uint8_t), RGB_CYAN);

            const uint8_t media_keycodes[] = {60, 54, 55, 49, 50, 43};
            set_all_keys_colors(media_keycodes, sizeof(media_keycodes) / sizeof(uint8_t), RGB_WHITE);

            rgb_matrix_set_color(62, 0x00, 0x64, 0x00);  // 'Y' key
            rgb_matrix_set_color(63, 0x00, 0x64, 0x00);  // 'H' key
            rgb_matrix_set_color(57, 0x00, 0x64, 0x00);  // 'U' key
            rgb_matrix_set_color(47, 0x00, 0x64, 0x00);  // 'O' key

            rgb_matrix_set_color(42, RGB_GREEN);  // 'P' key
            rgb_matrix_set_color(36, RGB_RED);    // RESET key

            rgb_matrix_set_color(0, RGB_RED);     // Gaming
            rgb_matrix_set_color(29, RGB_GREEN);  // Win key
            rgb_matrix_set_color(65, RGB_WHITE);  // Mac key
            break;
        }
        default:  //  for any other layers, or the default layer
            break;
    }
}
#endif

void keyboard_post_init_user(void) {
    rgblight_sethsv(HSV_MAGENTA);

    // This is good in case I screw anything up with bad code; it's REALLY hard
    // to fix it when mods get messed up since it can mess up the whole OS.
    clear_mods();
}

// https://github.com/qmk/qmk_firmware/issues/4611#issuecomment-446713700
// https://www.reddit.com/r/olkb/comments/oflwv6/how_do_i_change_qmk_layer_tap_behavior/h4l7u8n/?utm_source=reddit&utm_medium=web2x&context=3
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool isPressed   = record->event.pressed;
    bool isCtrlHeld  = get_mods() & MOD_BIT(KC_LCTL);
    bool isShiftHeld = (get_mods() & MOD_BIT(KC_LSFT)) || (get_mods() & MOD_BIT(KC_RSFT));

    switch (keycode) {
        // case MAC_SWP:
        //     if (isPressed) {
        //         if (layer_state_cmp(default_layer_state, _WIN_BASE)) {
        //             // set_single_persistent_default_layer(_MAC_BASE);
        //             default_layer_set(_MAC_BASE);
        //         } else {
        //             default_layer_set(_WIN_BASE);
        //         }
        //     }
        //     break;
        case MAC_CTRL_WIN_GUI: {
            // When in Mac, send ctrl. When on Windows, send GUI.
            uint16_t mod = is_mac_the_default() ? KC_LCTL : KC_LGUI;
            if (isPressed) {
                register_mods(MOD_BIT(mod));
            } else {
                unregister_mods(MOD_BIT(mod));
            }
            return false;
        }
        case MAC_GUI_WIN_CTRL: {
            // When in Mac, send GUI. When on Windows, send ctrl.
            uint16_t mod = is_mac_the_default() ? KC_LGUI : KC_LCTL;
            if (isPressed) {
                register_mods(MOD_BIT(mod));
            } else {
                unregister_mods(MOD_BIT(mod));
            }
            return false;
        }
        case KC_LEFT_ENCLOSE:
            // No mod → (
            // Ctrl → [
            // Shift → {
            if (isPressed && (IS_LAYER_ON(_NAV) || IS_LAYER_ON(_SYMB))) {
                if (isCtrlHeld && !isShiftHeld) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    tap_code_delay(KC_LBRC, 0);
                    register_mods(MOD_BIT(KC_LCTL));
                } else if (isShiftHeld) {
                    tap_code_delay(KC_LBRC, 0);
                } else {
                    tap_code16(S(KC_9));
                }
                return false;
            }
            break;
        case KC_RIGHT_ENCLOSE:
            // No mod → )
            // Ctrl → ]
            // Shift → }
            if (isPressed && (IS_LAYER_ON(_NAV) || IS_LAYER_ON(_SYMB))) {
                if (isCtrlHeld && !isShiftHeld) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    tap_code_delay(KC_RBRC, 0);
                    register_mods(MOD_BIT(KC_LCTL));
                } else if (isShiftHeld) {
                    tap_code_delay(KC_RBRC, 0);
                } else {
                    tap_code16(S(KC_0));
                }
                return false;
            }
            break;
    }

    return true;
}

// Increasing the tapping term means that dual-function keys have to be held for
// longer before they're treated as their "hold" action.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // The shift keys are much more common and typically more deliberate as
        // a result.
        case W_HM_F:
        case W_HM_J:
            return TAPPING_TERM - 30;
        // "A" and "S" are the source of a lot of rolls, so activating their
        // hold functions too soon can be a cause of frustration.
        //
        // I just tend to hold "L" for longer, and since it's bound to alt and
        // all of my numbers are also on my right hand, I may as well increase
        // it.
        //
        // Note that it seems like an absolute value of about 185 is good.
        case W_HM_A:
        case M_HM_A:
        case W_HM_S:
        case W_HM_L:
            // case M_HM_L: // ← this is the same between Windows and Mac
            // case M_HM_S: // ← this is the same between Windows and Mac
            return TAPPING_TERM + 25;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Make DF JK be permissive-hold keys. I don't want pinkies to be
        // permissive hold due to rolling those more frequently. I learned the
        // same thing happens with my ring fingers too (especially with the word
        // "said").
        // Windows
        case W_HM_D:
        case W_HM_F:
        case W_HM_J:
        case W_HM_K:
        // Mac
        // case M_HM_F: // ← this is the same between Windows and Mac
        // case M_HM_J: // ← this is the same between Windows and Mac
        case M_HM_D:
        case M_HM_K:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // "UI" is a common enough bigram in software engineering ("UI",
        // "build", "requirements") that the combo time needs to be pretty low
        // so that natural typing doesn't trigger it.
        case UI_HYPHEN:
            return 20;
    }

    return COMBO_TERM;
}
