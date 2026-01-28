#include QMK_KEYBOARD_H

// Represents the four states a oneshot key can be in
typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

enum charybdis_keymap_layers {
    ABC = 0,
    RTR, // RetroArch
    RUS,
    NUM,
    SYM,
    BSYM,
    FN,
};

enum my_keycodes {
    CODE_ARRAY = SAFE_RANGE,
    CODE_TO,
    CODE_BR,
    CODEBLOCK,
    ARM_MICRO,
    DELETE_LINE,
    LANG,
    VOLTR,

    CommaS,
    DotNS,
    QuesNS,
    ExlmNS,

    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

bool trackball_volume = false;

#undef _______
#define _ KC_NO
#define _______ KC_NO
#define _x KC_TRANSPARENT

// WARN: danger
#undef G
#undef A
#undef X
#undef C

#define Q KC_Q
#define W KC_W

#define F KC_F
#define F_FN LT(FN, KC_F)
#define P KC_P
#define B KC_B
#define J KC_J
#define L KC_L
#define U KC_U
#define Y KC_Y
#define N KC_N
#define R KC_R
#define St KC_S
#define F KC_F
#define S_BSYM LT(BSYM, KC_S)
#define T KC_T
#define G KC_G
#define M KC_M
#define A KC_A
#define A_CG LCG_T(KC_A) // command+control
#define H_CMD MT(MOD_LGUI, KC_H)
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

#define Shift OS_SHFT
#define SpaceShift SFT_T(KC_SPC)
#define Ctrl OS_CTRL
#define Cmd OS_CMD
#define Alt OS_ALT
#define Compose KC_RCTL

#define PgDn KC_PGDN
#define PgUp KC_PGUP
#define Home KC_HOME
#define End KC_END

#define BSlash KC_BSLS
#define Percent KC_PERC
#define Star KC_ASTR
#define At KC_AT
#define Hash KC_HASH
#define Tilda KC_TILD
#define Grave KC_GRV
#define Equal KC_EQL
#define Unds KC_UNDS
#define Minus KC_MINS
#define Plus KC_PLUS

#define Exlm KC_EXLM
#define Quest KC_QUES
#define Slash KC_PSLS
#define Amp KC_AMPR
#define Dot KC_DOT
#define Comma KC_COMM
#define Quote KC_QUOT
#define DQuote KC_DQUO
#define Pipe KC_PIPE
#define DDot KC_COLN
#define DComm KC_SCLN
#define Caret KC_CIRC
#define Dollar KC_DLR

#define VolUp KC_KB_VOLUME_UP
#define VolDn KC_KB_VOLUME_DOWN

#define Leader LCMD(KC_F)

#define NextWin LCMD(KC_GRV)
#define NextWinStack LCMD(KC_TILD)

#define rF KC_KP_1 // ф
#define rJ KC_KP_2 // ж
#define rZ KC_KP_3 // з
#define rT KC_KP_4 // ъ
#define rH KC_KP_5 // х
#define rU KC_KP_6 // ю

#define SpaceNUM LT(NUM, KC_SPC)
#define EscSYM LT(SYM, KC_ESC)
// #define DelWLayer LCTL(KC_BSPC)
#define CtrlZ LCTL(KC_Z)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC] = LAYOUT(
    _,     _,     _, VOLTR,     _,     _,            _,     _,     _,     _,     _,   _,
    Alt,   B,     L,     D,     W,     Z,            CtrlZ, F_FN,  O,     U,     J,   _,
    Ctrl,  N,     R,     T,    S_BSYM, G,            Y,     H_CMD, A,     E,     I, Compose,
    _,     Q,     X,     M,     C,     V,            K,     P,     Alt, Ctrl, Leader, _,
              DelWord, SpaceNUM, KC_BTN2,            Enter, EscSYM,
                          KC_BTN1, Shift,            LANG
  ),

  [RTR] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,    _,
    Alt,   Q,     W,     F,     P,     B,            J,     L,     U,     Y, CtrlZ,    _,
    Ctrl,  N,     R,    St,     T,     G,            M,     A,     E,     I,     O, Compose,
    _,     Z,     X,     C,     D,     V,            K,     H,     Alt, Ctrl, Leader,  _,
                 BSpace, SpaceNUM, VOLTR,            Enter, Esc,
                                _, Shift,            LANG
  ),

  [RUS] = LAYOUT(
    _,     _,     _,    _,      _,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц     У       К      Е             Н      Г      Ш      Й      З
    _,     Q,     W,    F,      P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Х
    rF,    N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rH,  QuesNS,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Ж
    rT,    Z,     X,     C,     D,     V,            K,     H,     O,    rU,    rJ,  ExlmNS,
               CommaS, SpaceShift, DotNS,            Enter, _,
                       Minus, SpaceShift,            _
  ),

  [NUM] = LAYOUT(

    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, Home, End, RGB_TOG,  QK_BOOT,

    _,     B,     _,     _0,   W,    _,             _,   Left,   _9, Right,    _, _,
    _,     _,    _1,     _2,  _3,    _,             _,     _5,   _6,    _8,   Up, _,
    _,     _,     _,    Tab,  _4,    _,             _,     _7, PgUp,  PgDn,    _, _,
                                     _, _, _,        Enter, Down,
                                        _, _,        LCTL(U)
  ),

  [SYM] = LAYOUT(

    QK_BOOT, RGB_TOG, _,   _,    _, EE_CLR,            EE_CLR, _, _, _,   RGB_TOG,  QK_BOOT,

    _,     Star, Slash, Caret, Dollar, _,     _, Bracket, bracket, Borrow, borrow,  _,
    _,     Hash,   At,  DQuote, Quote, _,     _,     Dot,   Comma,  Array,  array,  _,
    _,     Equal, Plus,  Unds,  Minus, _,     _,    DDot,   DComm,   Quest,   Exlm, _,
                              BSpace, Space, _,     _, _,
                                          _, _,     _
  ),

  [BSYM] = LAYOUT(
    _, _, _, _, _, _,    _, _, _, _, _, _,
    _, _, _, _, _, _,    _, Amp, Pipe, Percent, BSlash, _,
    _, _, _, _, _, _,    _, Equal, Tag, tag, Tilda, _,
    _, _, _, _, _, _,    _, Grave, CODEBLOCK, CODE_BR, _, _,

             _, _, _,    TG(RTR), _,
                _, _,    _
  ),

  [FN] = LAYOUT(
    _, _, _, _, _, _,          KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18,
    _, _, _, _, _, _,    KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,
    _, _, _, _, _, _,    KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
    _, _, _, _, _, _,    KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,

             _, _, _,    _, _,
                      _, _,    _
  ),
};
// clang-format on
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case EscSYM:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LANG:
        case EscSYM:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;
bool oneshot_tab_toggle = false;

void with_mods_state_recover(void (*callback)(void)) {
    uint8_t mod_state    = get_mods();
    uint8_t os_mod_state = get_oneshot_mods();
    clear_mods();
    clear_oneshot_mods();

    callback();

    set_mods(mod_state);
    set_oneshot_mods(os_mod_state);
}

void switch_to_english(void) {
    SEND_STRING(SS_TAP(X_F13));
    layer_move(ABC);
};
void switch_to_russian(void) {
    SEND_STRING(SS_TAP(X_F14));
    layer_move(RUS);
};

void send_os_alt_hold(void) {
    SEND_STRING(SS_TAP(X_F15));
}
void send_os_alt_release(void) {
    SEND_STRING(SS_TAP(X_F16));
}
void send_os_ctrl_hold(void) {
    SEND_STRING(SS_TAP(X_F17));
}
void send_os_ctrl_release(void) {
    SEND_STRING(SS_TAP(X_F18));
}
void send_os_shift_hold(void) {
    SEND_STRING(SS_TAP(X_F22));
}
void send_os_shift_release(void) {
    SEND_STRING(SS_TAP(X_F23));
}

void send_os_osm_state(uint16_t osm_key_state, bool hold) {
    switch (osm_key_state) {
        case KC_LALT:
            if (hold == true) {
                with_mods_state_recover(send_os_alt_hold);
            } else {
                with_mods_state_recover(send_os_alt_release);
            }
            break;
        case KC_LCTL:
            if (hold == true) {
                with_mods_state_recover(send_os_ctrl_hold);
            } else {
                with_mods_state_recover(send_os_ctrl_release);
            }
            break;
        case KC_LSFT:
            if (hold == true) {
                with_mods_state_recover(send_os_shift_hold);
            } else {
                with_mods_state_recover(send_os_shift_release);
            }
            break;
        default:
            break;
    }
}

// TODO: replace it with https://docs.qmk.fm/tap_hold#flow-tap
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_BSYM:
        case F_FN:
        case H_CMD:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

bool update_oneshot(oneshot_state *state, uint16_t mod, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    // State: pressed mod
    if (keycode == trigger) {
        // Trigger keydown
        if (record->event.pressed) {
            if (*state == os_up_unqueued) {
                register_code(mod);
                send_os_osm_state(mod, true);
                *state = os_down_unused;
            } else {
                oneshot_tab_toggle = true;
            }
        // Trigger keyup
        } else {
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the mod while trigger was held, queue it.
                    *state = os_up_queued;
                    break;
                case os_down_used:
                    // If we did use the mod while trigger was held, unregister it.
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    send_os_osm_state(mod, false);
                default:
                    break;
            }
        }
    // State: pressed not mod key (a-z or else)
    } else {
        if (record->event.pressed) {
            if (record->tap.count) { // Need for LT keys
                if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                    // Cancel oneshot on designated cancel keydown (ESC).
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    send_os_osm_state(mod, false);
                    oneshot_tab_toggle = false;
                    return false;
                }
            }
        } else {
            if (oneshot_tab_toggle == false && !is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                    case os_down_unused:
                        *state = os_down_used;
                        break;
                    case os_up_queued:
                        *state = os_up_unqueued;
                        unregister_code(mod);
                        send_os_osm_state(mod, false);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return true;
}

uint16_t change_app_timer = 0;
bool     process_record_user(uint16_t keycode, keyrecord_t *record) {
    // clang-format off
    bool result1 = update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode,
  record);
    bool result2 = update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode,
  record);
    bool result3 = update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode,
  record);
    bool result4 = update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode,
  record);

    if (!result1 || !result2 || !result3 || !result4) {
        return false;
    }
    // clang-format on

    switch (keycode) {
        case ARM_MICRO:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F20));
            } else {
                SEND_STRING(SS_TAP(X_F20));
            }
            return false;
        case CODE_ARRAY:
            if (record->event.pressed) {
                SEND_STRING(" => ");
            }
            return false;
        case CODE_TO:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case CODE_BR:
            if (record->event.pressed) {
                SEND_STRING(" {");
                SEND_STRING(SS_TAP(X_ENT));
                SEND_STRING(SS_TAP(X_ENT));
                SEND_STRING("}");
                SEND_STRING(SS_TAP(X_UP));
                SEND_STRING(SS_TAP(X_TAB));
            }
            return false;
        case CODEBLOCK:
            if (record->event.pressed) {
                SEND_STRING("```");
            }
            return false;
        case DELETE_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPC));
            }
            return false;
        case CommaS:
            if (record->event.pressed) {
                SEND_STRING(", ");
            }
            return false;
        case DotNS:
            if (record->event.pressed) {
                SEND_STRING(". ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case QuesNS:
            if (record->event.pressed) {
                SEND_STRING("? ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case ExlmNS:
            if (record->event.pressed) {
                SEND_STRING("! ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            return false;
        case LANG:
            if (record->event.pressed) {
                with_mods_state_recover(switch_to_russian);
            } else {
                with_mods_state_recover(switch_to_english);
            }
            return false;
        case VOLTR:
            if (record->event.pressed) {
                trackball_volume = true;
            } else {
                trackball_volume = false;
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

static int volume_accumulator = 0;
#define SCROLL_DIVIDER 15 // increase for more sensitivity)

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    if (trackball_volume) {
        volume_accumulator += mouse_report.y;

        while (abs(volume_accumulator) >= SCROLL_DIVIDER) {
            if (volume_accumulator > 0) {
                tap_code(VolDn);
                volume_accumulator -= SCROLL_DIVIDER;
            } else {
                tap_code(VolUp);
                volume_accumulator += SCROLL_DIVIDER;
            }
        }

        // Block normal trackball input
        mouse_report.x = 0;
        mouse_report.y = 0;
        mouse_report.h = 0;
        mouse_report.v = 0;
    }
    return mouse_report;
}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (os_alt_state == os_up_queued || os_ctrl_state == os_up_queued || os_shft_state == os_up_queued || os_cmd_state == os_up_queued) {
                rgb_matrix_set_color(index, 0, 0, 0);

                if (os_alt_state == os_up_queued) {
                    if (row == 8) {
                        rgb_matrix_set_color(index, 250, 0, 0);
                    }
                }
                if (os_ctrl_state == os_up_queued) {
                    if (row == 8) {
                        rgb_matrix_set_color(index, 150, 150, 0);
                    }
                }
                if (os_shft_state == os_up_queued) {
                    if (row >= 9) {
                        rgb_matrix_set_color(index, 250, 0, 250);
                    }
                }
                if (os_cmd_state == os_up_queued) {
                    if (row == 9 && col == 1) {
                        rgb_matrix_set_color(index, 250, 0, 0);
                    }
                }
            } else {
                switch(get_highest_layer(layer_state|default_layer_state)) {
                    case 1:
                        if (row == 5 || col == 0) {
                            rgb_matrix_set_color(index, 250, 0, 250);
                        } else {
                            rgb_matrix_set_color(index, RGB_BLUE);
                        }
                        break;
                    case 2:
                        if (row == 5 || col == 0) {
                            rgb_matrix_set_color(index, 250, 30, 0);
                        } else {
                            rgb_matrix_set_color(index, RGB_RED);
                        }
                        break;
                    default:
                        if (row == 5 || col == 0) {
                            rgb_matrix_set_color(index, 250, 0, 250);
                        } else {
                            rgb_matrix_set_color(index, 250, 30, 0);
                        }
                        break;
                    }
            }
        }
    }
    return true;
}
