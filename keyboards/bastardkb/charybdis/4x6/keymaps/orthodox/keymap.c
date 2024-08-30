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
    // LAYER_BASE = 0,
    // LAYER_LOWER,
    // LAYER_RAISE,
    _ALPHA = 0,
    // _ALPHA2,
    _SYMBOL,
    _NUMBER,
    _NAVIGATION,
    _TG,
    _APP,
    _BRACES,
    LAYER_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum my_keycodes {
  CODE_ARRAY = SAFE_RANGE,
  CODE_TO,
  DELETE_LINE,
};

#undef _______
#define _ KC_NO
#define __ KC_NO
#define ____ KC_NO
#define _______ KC_NO
#define ________________ KC_NO

#define _Q KC_Q
#define _W KC_W
#define _F SFT_T(KC_F)
#define _P SFT_T(KC_P)
#define _B KC_B
#define _J KC_J
#define _L SFT_T(KC_L)
#define _U SFT_T(KC_U)
#define _Y KC_Y
#define _N SFT_T(KC_N)
#define _R KC_R
#define _S LT(LAYER_POINTER, KC_S)
#define _T CMD_T(KC_T)
#define _G KC_G
#define _M KC_M
#define _A CMD_T(KC_A)
#define _E CTL_T(KC_E)
#define _I KC_I
#define _O SFT_T(KC_O)
#define _Z LT(LAYER_POINTER, KC_Z)
#define _X KC_X
#define _C KC_C
#define _D ALT_T(KC_D)
#define _V KC_V
#define _K KC_K
#define _H ALT_T(KC_H)

#define _0 KC_0
#define _1 KC_1
#define _2 KC_2
#define _3 KC_3
#define _4 KC_4
#define _5 KC_5
#define _6 KC_6
#define _7 KC_7
#define _8 KC_8
#define _9 KC_9

#define Up KC_UP
#define Down KC_DOWN
#define Left KC_LEFT
#define Right KC_RIGHT

#define SCUp LSFT(LCTL(Up))
#define SCDown LSFT(LCTL(Down))

#define LeftClick KC_BTN1
#define RightClick KC_BTN2
#define WheelUp KC_MS_WH_UP
#define WheelDown KC_MS_WH_DOWN
#define WheelLeft KC_MS_WH_LEFT
#define WheelRight KC_MS_WH_RIGHT
#define MUp KC_MS_UP
#define MDown KC_MS_DOWN
#define MLeft KC_MS_LEFT
#define MRight KC_MS_RIGHT
#define MSpeed0 KC_MS_ACCEL0
#define MSpeed1 KC_MS_ACCEL1
#define MSpeed2 KC_MS_ACCEL2

#define Space KC_SPC
#define Backspace KC_BSPC
#define Delete KC_DEL
#define Command KC_LCMD
#define NextWindow LCMD(KC_GRV)
#define Lang LSFT(KC_CAPS)
#define Control KC_LCTL
#define Alt KC_LALT
#define Shift KC_LSFT
#define Enter KC_ENT
#define Esc KC_ESC
#define Tab KC_TAB

#define PgDn KC_PGDN
#define PgUp KC_PGUP
#define Home KC_HOME
#define End KC_END

#define BackSlash KC_BSLS
#define Percent KC_PERC
#define Asterisk KC_ASTR
#define At KC_AT
#define Hash KC_HASH
#define Tilda KC_TILD
#define Grave KC_GRV
#define Equal KC_EQL
#define Underscore KC_UNDS
#define Minus KC_MINS
#define Plus KC_PLUS

#define Exlm KC_EXLM
#define Question KC_QUES
#define Slash KC_PSLS
#define Ampersand KC_AMPR
#define Dot KC_DOT
#define Comma KC_COMM
#define Quote KC_QUOT
#define DQuote KC_DQUO
#define Pipe KC_PIPE
#define Colon KC_COLN
#define Semicolon KC_SCLN
#define Caret KC_CIRC
#define Dollar KC_DLR

#define LightDec KC_BRID
#define LightInc KC_BRIU
#define SoundDec KC_VOLD
#define SoundInc KC_VOLU
#define Mute KC_KB_MUTE
#define AudioMicMute KC_F20
#define MuteNotify HYPR(KC_0)
#define NoNotify HYPR(KC_6)

#define PrntSc1 HYPR(KC_1)
#define PrntSc2 HYPR(KC_2)
#define PrntSc3 HYPR(KC_3)
#define Vpn HYPR(KC_4)
#define Rec HYPR(KC_5)
#define Restart HYPR(KC_7)

#define NewLine LSFT(Enter)

#define Menu HYPR(Space)
#define Buffer HYPR(KC_V)
// #define Pass HYPR(KC_F)
#define Commands HYPR(KC_O)
#define FPiP LCTL(LSFT(KC_RBRC)) // Firefox. Picture-in-Picture
#define MPiP LCAG(KC_X) // mpv float

#define Browser HYPR(KC_R)
#define Term HYPR(KC_S)
#define Chat HYPR(KC_T)

#define WS_1 HYPR(KC_X)
#define WS_2 HYPR(KC_C)
#define WS_3 HYPR(KC_D)

#define PrevApp LALT(KC_TAB)

#define Tmux LCTL(KC_A)

#define MakeFloat LCAG(KC_C)
#define MoveFloat LCAG(KC_D)
#define ScratchpadMove LCAG(KC_S)
#define ScratchpadShow LCAG(KC_T)
#define Fullscreen KC_F11

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _T:
        case _A:
        // case _S:
        case _E:
        case _D:
        case _H:
        case _F:
        case _P:
        case _L:
        case _U:
        case _N:
        case _O:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

uint16_t change_app_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CODE_ARRAY:
      if (record->event.pressed) { SEND_STRING(" => "); } return false;
    case CODE_TO:
      if (record->event.pressed) { SEND_STRING("->"); } return false;
    case DELETE_LINE:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPC));
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}

#define _RF KC_KP_1  // ф
#define _RJ KC_KP_2  // ж
#define _RZ KC_KP_3  // з
#define _RT KC_KP_4  // ъ
#define _RB KC_KP_5  // б
#define _RYU KC_KP_6 // ю

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        QK_BOOT,   RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_M_P,       RGB_SAI, RGB_SAD, RGB_SPI, RGB_SPD,    KC_0, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    _Q,      _W,      _F,      _P,      _B,         _J,      _L,      _U,      _Y,      _RZ,  KC_BSLS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT,    _N,      _R,      _S,      _T,      _G,         _M,      _A,      _E,      _I,      _O,   KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LCTL,    _Z,      _X,      _C,      _D,      _V,         _K,      _H,      _RB,     _RYU,    _RJ,  KC_LALT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
          LT(_BRACES, Backspace), LT(_NUMBER, Space),  KC_LSFT,    LT(_SYMBOL, Esc), LT(_NAVIGATION, Enter),
                                           Tab, KC_LGUI,             KC_LCTL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUMBER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _,       _,       _,       _,       _,       _,          _,         _,       _,       _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_MOD, _,       _,      _0,       _,       _,          _,         _,       _9,      _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, _,       _1,      _2,      _3,      _,          _,         _5,      _6,      _8,    CODE_TO, _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RGB_RMOD, _,       _,       Tab,     _4,       _,          _,         _7,      Ampersand,Pipe, CODE_ARRAY, _,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _,       _,       _,          Up,        Down,
                                           _,       _,          _
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _,       _,       _,       _,       _,       _,          _,         _,       _,       _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,     BackSlash, Slash, Asterisk,  _,          _,         Exlm,   Question, Underscore, _,  _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       Equal,   Tilda,   Caret,   Dollar,  _,          _,         Dot,     Comma,   Quote, DQuote,  _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       Percent, Hash,    At,      _,          _,         Colon,   Semicolon,Grave,_,       _,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  Minus,   Plus,    _,          _,         _,
                                           _,       _,          _
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_BRACES] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _,       _,       _,       _,       _,       _,          _,         _,       _,       _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,  MuteNotify, NoNotify, KC_LCBR, KC_RCBR, PrntSc1,     _,         KC_LBRC, KC_RBRC, _,     Vpn,     _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,  AudioMicMute,RGB_TOG, KC_LPRN, KC_RPRN, PrntSc2,     _,         Menu,    Buffer,  Commands,_,     _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,  Mute,        Rec,     _RT,     _RF,     PrntSc3,     _,         LightDec,LightInc,SoundDec,SoundInc,_,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                         _,   _,    _,          KC_LT,         KC_GT,
                                           _,       _,          _
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _,       _,       _,       _,       _,       _,          _,         _,       _,       _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       PgUp, Fullscreen, PgDn,    _,          _,         _,       MO(_TG), _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       Home,    _,      Left,     Right,   End,        _,       PrevApp, NextWindow, Tmux, _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       WheelUp,WheelDown,Lang,    KC_CAPS,    _,       Browser, Chat,       Term, WS_3,    _,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                DELETE_LINE,   Delete,    _,    _,       _,
                                           _,       _,          _
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_TG] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _,       _,       _,       _,       _,       _,          _,         _,       _,       _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       PgUp, Fullscreen, PgDn,    _,          _,         _,       MO(_TG), _,     _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       Home,    _,      SCUp,     SCDown,   End,        _,       PrevApp, NextWindow, Tmux, _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       WheelUp,WheelDown,Lang,    KC_CAPS,    _,       Browser, Chat,       Term, WS_3,    _,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                DELETE_LINE,   Delete,    _,    _,       _,
                                           _,       _,          _
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, _,       _,       _,       _,          _,       _,       _,       _,       QK_BOOT,  EE_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       _,       _,       DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, _,       _,       _,       _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _,          _,       KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _,       _,       DRGSCRL, SNIPING, _,       _,          _,       _,       SNIPING, DRGSCRL, _,       _,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           DRGSCRL, SNIPING,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

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
