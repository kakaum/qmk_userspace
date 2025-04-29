/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
     LAYER_BASE = 0,
     LAYER_LOWER,
     LAYER_UPPER,
     LAYER_ADJUST
 };

/** \brief Automatically enable sniping-mode on the pointer layer. */
/* kane
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER
*/

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/* kane
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
*/

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE


#define TGL_CAPS        LCAG(KC_SPACE)
#define HR_CLK          LCAG(KC_A)
#define HR_SCR          LCAG(KC_Z)
#define STG_OPN         LCTL(LGUI(KC_0))
#define NEXT_TAB        LSG(KC_LBRC)
#define PREV_TAB        LSG(KC_RBRC)
#define PRTSCR          LSG(KC_4)
#define GO_BACK         LGUI(KC_LBRC)
#define GO_FWD          LGUI(KC_RBRC)
#define TO_CNFL         LCTL(LGUI(KC_2))
#define TO_JIRA         LCTL(LGUI(KC_3))
#define ENT_CMD         LCMD_T(KC_ENT)
#define UNDERBAR        LSFT(KC_MINS)
#define PLUS            LSFT(KC_EQL)
#define LPAREN          LSFT(KC_9)
#define RPAREN          LSFT(KC_0)
#define LCRLBRC         LSFT(KC_LBRC)
#define RCRLBRC         LSFT(KC_RBRC)
#define OSM_HYPR        OSM(MOD_HYPR)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
    // ╭────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
         KC_GRAVE, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
    // ╰────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                                       DRGSCRL,  ENT_CMD,  TL_LOWR,     TL_UPPR,  KC_SPACE,
                                                 SNIPING,  KC_LCTL,     KC_RALT
    //                               ╰──────────────────────────────╯ ╰──────────────────────────────╯
    ),
    
    [LAYER_LOWER] = LAYOUT(
    // ╭────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
         _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         TGL_CAPS, HR_CLK,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  HR_SCR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  KC_ENT,
    // ╰────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                                       _______,  _______,  _______,     _______,  KC_P0,
                                                 _______,  KC_RCTL,     _______
    //                               ╰──────────────────────────────╯ ╰──────────────────────────────╯
    ),
    
    [LAYER_UPPER] = LAYOUT(
    // ╭────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
         _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       PRTSCR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         STG_OPN,  KC_MINS,  UNDERBAR, KC_EQL,   PLUS,     KC_F11,      KC_HOME,  NEXT_TAB, PREV_TAB, KC_END,   XXXXXXX,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  XXXXXXX,  XXXXXXX,  LPAREN,   RPAREN,   KC_F12,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, XXXXXXX,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  KC_LBRC,  KC_RBRC,  LCRLBRC,  RCRLBRC,  _______,     GO_BACK,  KC_PGDN,  KC_PGUP,  GO_FWD,   XXXXXXX,  _______,
    // ╰────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                                       _______,  _______,  _______,     _______,  _______,
                                                 _______,  _______,     KC_LALT
    //                               ╰──────────────────────────────╯ ╰──────────────────────────────╯
    ),
    [LAYER_ADJUST] = LAYOUT(
    // ╭────────────────────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
         _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  S_D_MOD,  DPI_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  KC_VOLU,  XXXXXXX,  XXXXXXX,  KC_MPLY,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  S_D_RMOD, DPI_RMOD, KC_VOLD,  XXXXXXX,  XXXXXXX,     OSM_HYPR, TO_JIRA,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    // ├────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
         _______,  XXXXXXX,  XXXXXXX,  TO_CNFL,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    // ╰────────────────────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                                       _______,  _______,  _______,     _______,  QK_BOOT,
                                                 _______,  _______,     _______
    //                               ╰──────────────────────────────╯ ╰──────────────────────────────╯
    )
};
// clang-format on


// Combo
const uint16_t PROGMEM combo_mouse_button_left[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_mouse_button_right[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_dragscroll[] = {KC_DOT, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_mouse_button_left, MS_BTN1),
    COMBO(combo_mouse_button_right, MS_BTN2), // keycodes with modifiers are possible too!
    COMBO(combo_dragscroll, DRGSCRL),
};



#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
