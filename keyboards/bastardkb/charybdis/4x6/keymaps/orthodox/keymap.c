#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    _ABC = 0,
    _RUS,
    _SYM,
    _NUM,
    _PNTR,
};

#undef _______
#define _ KC_NO
#define _______ KC_NO

// WARN: danger
#undef G
#undef A
#undef X
#undef C

#define Q KC_Q
#define W KC_W
#define F KC_F
#define P KC_P
#define B KC_B
#define J KC_J
#define L KC_L
#define U KC_U
#define Y KC_Y
#define N KC_N
#define R KC_R
#define S_PTR LT(_PNTR, KC_S)
#define T KC_T
#define G KC_G
#define M KC_M
#define A KC_A
#define E KC_E
#define I KC_I
#define O KC_O
#define Z KC_Z
#define X KC_X
#define C KC_C
#define D KC_D
#define V KC_V
#define K KC_K
#define H KC_H

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

#define Bracket KC_LPRN
#define bracket KC_RPRN
#define Borrow KC_LCBR
#define borrow KC_RCBR
#define Array KC_LBRC
#define array KC_RBRC
#define Tag KC_LT
#define tag KC_GT

#define Space KC_SPC
#define BSpace KC_BSPC
#define DelWord LCTL(KC_BSPC)
#define Enter KC_ENT
#define Esc KC_ESC
#define Tab KC_TAB

// #define Cmd KC_LCMD
// #define Ctrl KC_LCTL
// #define Alt KC_LALT
// #define Shift KC_LSFT
#define Shift OSM(MOD_LSFT)
#define SpaceShift SFT_T(KC_SPC)
#define Ctrl OSM(MOD_LCTL)
#define Alt OSM(MOD_LALT)

#define PgDn KC_PGDN
#define PgUp KC_PGUP
#define Home KC_HOME
#define End KC_END

#define BSlash KC_BSLS
#define Percent KC_PERC
#define Asterisk KC_ASTR
#define At KC_AT
#define Hash KC_HASH
#define Tilda KC_TILD
#define Grave KC_GRV
#define Equal KC_EQL
#define Underscore KC_UNDS
#define Dash KC_MINS
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

#define VolUp KC_KB_VOLUME_UP
#define VolDn KC_KB_VOLUME_DOWN
#define Lang KC_CAPS

#define Leader LCMD(KC_L)
#define WS12 LCMD(KC_1)
#define WS04 LCMD(KC_0)
// #define WS0 LCMD(KC_0)
// #define WS1 LCMD(KC_1)
// #define WS2 LCMD(KC_2)
#define WS3 LCMD(KC_3)
// #define WS4 LCMD(KC_4)
#define WSP LALT(KC_TAB)
#define NextWin LCMD(KC_GRV)

#define rF KC_KP_1  // ф
#define rJ KC_KP_2  // ж
#define rZ KC_KP_3  // з
#define rT KC_KP_4  // ъ
#define rH KC_KP_5  // х
#define rU KC_KP_6  // ю

#define Space_NUM LT(_NUM, KC_SPC)
// #define Enter_SYM LT(_SYM, KC_ENT)
#define Esc_SYM LT(_SYM, KC_ESC)

enum my_keycodes {
  CODE_ARRAY = SAFE_RANGE,
  CODE_TO,
  ARM_MICRO,
  DELETE_LINE,
  LANG,
};

void switch_to_english(void) {
  uint8_t mod_state = get_mods();
  clear_mods();
  SEND_STRING(SS_TAP(X_CAPS));
  layer_move(_ABC);
  set_mods(mod_state);
};


void switch_to_russian(void) {
  // if (get_highest_layer(layer_state) == _RUS) {
  //   switch_to_english();
  // } else {
    uint8_t mod_state = get_mods();
    clear_mods();
    SEND_STRING(SS_TAP(X_CAPS));
    layer_move(_RUS);
    set_mods(mod_state);
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ABC] = LAYOUT(
    _,     _,     _, VolDn, VolUp,     _,            _,    rF,     _,    rT,     _,    _,
    _,     Q,     W,     F,     P,     B,            J,     L,     U,     Y,    rZ,    _,
    rJ,    N,     R, S_PTR,     T,     G,            M,     A,     E,     I,     O,   rH,
    Lang,  Z,     X,     C,     D,     V,            K,     H,  Ctrl, Shift,   Alt,   rU,

                 DelWord, Space_NUM, Tab,            Enter, Esc_SYM,
                        SpaceShift, LANG,            Leader
  ),

  [_RUS] = LAYOUT(
    _,     _,     _, VolDn, VolUp,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц      У      К      Е             Р      Г      Ш      Й      З
    _,     Q,     W,     F,     P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Ж
    _,     N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rJ,    _,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Х
    _,     Z,     X,     C,     D,     V,            K,     H,     O,    rU,    rH,    _,

                                 _, _, _,            rF, SpaceShift,
                                    _, _,            rT
  ),

  [_NUM] = LAYOUT(
    //   {   (    0   )   }
    //   [   1    2   3   ]
    //   <   home end 4   >
    _,      _,       _,   _,       _,      _,        _,      _,    _,     _, _,  _,
    _, Borrow, Bracket,  _0, bracket, borrow,        _, BSlash,   _9, Slash, _,  _,
    _,  Array,      _1,  _2,      _3,  array,        _,     _5,   _6,    _8, Up, _,
    _,    Tag,    Home, End,      _4,    tag,        _,     _7, PgUp,  PgDn, _,  _,

                                     _, _, _,        _, Down,
                                        _, _,        _
  ),

  [_SYM] = LAYOUT(
    //   &   *   ^   $        !   ?   |   %
    //   #   @                .   ,   '   "
    //   =   +   _   -        :   ;   `   ~

    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, _, _,      RGB_TOG,  QK_BOOT,
    _, Ampersand, Asterisk, Caret,      Dollar, _,        _, Exlm,   Question,  Pipe,  Percent, _,
    _, Hash,      At,       Left,       Right,  _,        _, Dot,    Comma,     Quote, DQuote,  _,
    _, Equal,     Plus,     Underscore, Dash,   _,        _, Colon,  Semicolon, Grave, Tilda,   _,

                               NextWin, WS12, WS3,    _,      _,
                                         _,  WS04,    _
  ),

  [_PNTR] = LAYOUT(
    _, _, _, _, _, _,          _, _, _, _, _, _,
    _, _, _, _, KC_BTN3, _,    _, _, _, _, _, _,
    _, _, _, _, KC_BTN1, _,    _, _, _, _, _, _,
    _, _, _, _, KC_BTN2, _,    _, _, _, _, _, _,

             _, CARRETM, _,    _, _,
                      _, _,    _
  ),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_PTR:
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
    case ARM_MICRO:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_F20));
      } else {
          SEND_STRING(SS_TAP(X_F20));
      }
      return false;
    case CODE_ARRAY:
      if (record->event.pressed) { SEND_STRING(" => "); } return false;
    case CODE_TO:
      if (record->event.pressed) { SEND_STRING("->"); } return false;
    case DELETE_LINE:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPC));
      }
      return false;
    case LANG:
      if (record->event.pressed) {
          switch_to_russian();
      } else {
          switch_to_english();
      }
      return false;
    default:
      return true; // Process all other keycodes normally
  }
}


#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _PNTR

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif
#endif

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_PNTR);
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
        layer_off(_PNTR);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, _NUM));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

                rgb_matrix_set_color(index, 100, 10, 0);
                // if (row == 5) {
                //     rgb_matrix_set_color(index, 5, 0, 5);
                // } else {
                //     if (col == 0) {
                //         rgb_matrix_set_color(index, 5, 0, 5);
                //     } else {
                //         rgb_matrix_set_color(index, 160, 20, 0);
                //     }
                // }
        }
    }
    return true;
}
