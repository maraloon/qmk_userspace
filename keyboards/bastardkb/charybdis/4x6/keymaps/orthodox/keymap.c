#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    ABC = 0,
    RUS,
    NUM,
    SYM,
    FN,
    CAL,
    CTL,
};

enum my_keycodes {
    LANG = SAFE_RANGE,
    VOLTR,

    CommaS,
    DotNS,
    QuesNS,
    ExlmNS,

    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    NUMLOCK,
};

bool trackball_volume = false;

#undef _______
#define _ KC_NO
#define _______ KC_NO

// WARN: danger
#undef G
#undef A
#undef X

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
#define St KC_S
#define T KC_T

#define G KC_G
#define M KC_M
#define A KC_A
#define E KC_E
#define I KC_I
#define O KC_O
#define Z KC_Z
#define X KC_X
#define Ct KC_C
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
#define Esc KC_ESC
#define Ent KC_ENT
#define Tab KC_TAB

#define Shift OS_SHFT
#define SpaceShift SFT_T(KC_SPC)
#define Ctrl OS_CTRL
#define Cmd OS_CMD
#define Alt OS_ALT

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

#define Lets KC_F12
#define Type QK_LEAD

#define rF KC_KP_1 // ф
#define rJ KC_KP_2 // ж
#define rZ KC_KP_3 // з
#define rT KC_KP_4 // ъ
#define rH KC_KP_5 // х
#define rU KC_KP_6 // ю

#define SpaceNUM LT(NUM, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC] = LAYOUT(
    _,     _,     _, VOLTR,     _,     _,            _,     _,     _,     _,     _,   OSL(FN),
    _,     B,     L,     D,     W,  Type,            Shift, F,     O,     U,     J,   _,
    Z,     N,     R,     T,    St,     G,            Y,     H,     A,     E,     I, Ctrl,
    _,     Q,     X,     M,    Ct,     V,            K,     P,     Alt, OSL(CTL), Lets, _,
                    _, SpaceNUM, KC_BTN2,            KC_ESC, OSL(SYM),
                        KC_BTN1, KC_LSFT,            LANG
  ),

  [RUS] = LAYOUT(
    _,     _,     _,    _,      _,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц     У       К      Е             Н      Г      Ш      Й      З
    _,     Q,     W,    F,      P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Х
    rF,    N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rH,  QuesNS,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Ж
    rT,    Z,     X,    Ct,     D,     V,            K,     H,     O,    rU,    rJ,  ExlmNS,
               CommaS, SpaceShift, DotNS,            _, _,
                          Minus, KC_LSFT,            _
  ),

  [NUM] = LAYOUT(

    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, Home, End, RGB_TOG,  QK_BOOT,

    _,     B,     _,     _0,   W,    Type,    _,   Left,   _9, Right,    _, _,
    _,     _,    _1,     _2,  _3, OSL(SYM), OSL(SYM), _5,  _6,    _8,   Up, _,
    _,     _,  Left,  Right,  _4,    _,       _,     _7, Down,    Up,    _, _,
                           _, Space, _,       TG(NUM), Down,
                                  _, _,       LCTL(U)
  ),

  [SYM] = LAYOUT(

    QK_BOOT, RGB_TOG, _,   _,    _, EE_CLR,            EE_CLR, _, _, _,   RGB_TOG,  QK_BOOT,

    _,     Star, Slash, Caret, Dollar, _,     _, Bracket, bracket, Borrow, borrow,  _,
   BSlash, Hash,   At,  DQuote, Quote, Tag,   _,     Dot,   Comma,  Array,  array,  _,
    _,     Equal, Plus,  Unds,  Minus, tag,   _,    DDot,   DComm,  Quest,   Exlm,  _,
                                  _, _, _,    _, _,
                                     _, _,    _
  ),

  [CTL] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _,  PgUp,  C(L),  PgDn, C(KC_BSPC), _,           _,  C(F),  C(O),  C(U),  C(J),   _,
    C(Z), C(N), C(R), KC_TAB, NUMLOCK, C(G),      C(Y),  KC_BSPC,  C(A),  C(E),  C(I),   _,
    _,   C(Q),  C(X), Ent, Esc, C(V),     C(K),  C(P),   OSL(CAL),  _, _, _,
                    _, _, _,            TG(ABC), _,
                        _, _,            _
  ),

  [CAL] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _, LCA(B), LCA(L), LCA(D), LCA(W),     _,            _, LCA(F), LCA(O), LCA(U), LCA(J),   _,
    LCA(Z), LCA(N), LCA(R), LCA(T), LCA(St), LCA(G),   LCA(Y), LCA(H), LCA(A), LCA(E), LCA(I),   _,
    _, LCA(Q), LCA(X), LCA(M), LCA(Ct), LCA(V),       LCA(K), LCA(P),   _,   _, _, _,
                    _, _, _,            TG(ABC), _,
                        _, _,            _
  ),

  [FN] = LAYOUT(
    _, KC_F1,   KC_F2,  KC_F3,  KC_F4, KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, _,
    _, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,    KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, _,
    _, KC_F21, KC_F22, KC_F23, KC_F24, _,         _, _, _, _, _, _,
    _, _, _, _, _, _,    _, _, _, _, _, _,
             _, _, _,    _, _,
                _, _,    _
  ),
};

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_H, KC_O)) {
        SEND_STRING("~");
    } else if (leader_sequence_two_keys(KC_P, KC_R)) {
        SEND_STRING("%");
    } else if (leader_sequence_two_keys(KC_G, KC_R)) {
        SEND_STRING("`");
    } else if (leader_sequence_two_keys(KC_B, KC_K)) {
        SEND_STRING("```");
    } else if (leader_sequence_three_keys(KC_A, KC_R, KC_R)) {
        SEND_STRING("=>");
    } else if (leader_sequence_two_keys(KC_G, KC_T)) {
        SEND_STRING(">=");
    } else if (leader_sequence_two_keys(KC_L, KC_T)) {
        SEND_STRING("<=");
    } else if (leader_sequence_two_keys(KC_E, KC_Q)) {
        SEND_STRING("===");
    } else if (leader_sequence_three_keys(KC_N, KC_E, KC_Q)) {
        SEND_STRING("!==");
    } else if (leader_sequence_two_keys(KC_A, KC_M)) {
        SEND_STRING("&");
    } else if (leader_sequence_two_keys(KC_P, KC_I)) {
        SEND_STRING("|");
    } else if (leader_sequence_two_keys(KC_A, KC_N)) {
        SEND_STRING("&&");
    } else if (leader_sequence_two_keys(KC_O, KC_R)) {
        SEND_STRING("||");
    } else if (leader_sequence_two_keys(KC_A, KC_L)) {
        SEND_STRING("<-");
    } else if (leader_sequence_two_keys(KC_A, KC_R)) {
        SEND_STRING("->");
    } else if (leader_sequence_three_keys(KC_E, KC_A, KC_H)) {
        SEND_STRING("{");
        SEND_STRING(SS_TAP(X_ENT));
        SEND_STRING(SS_TAP(X_ENT));
        SEND_STRING("}");
        SEND_STRING(SS_TAP(X_UP));
        SEND_STRING(SS_TAP(X_TAB));
    } else if (leader_sequence_two_keys(KC_M, KC_M)) {
        SEND_STRING("mara@the-witch.ru");
    } else if (leader_sequence_two_keys(KC_M, KC_Y)) {
        SEND_STRING("zeroly@ya.ru");
    } else if (leader_sequence_two_keys(KC_M, KC_S)) {
        SEND_STRING("sdvk1369@gmail.com");
    }
    // else if (leader_sequence_two_keys(KC_A, KC_Z)) {
    //     // Leader, a, s => GUI+S
    //     tap_code16(LGUI(KC_S));
    // }
}


void oneshot_layer_changed_user(uint8_t layer) {
    if (layer) {
        tap_code(KC_F17);
    } else {
        tap_code(KC_F18);
    }
}

// clang-format on
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case KC_ESC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LANG:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX - 1:
            return true;
        default:
            return false;
    }
}

// Represents the four states a oneshot key can be in
typedef enum {
    osm_0,
    osm_queued,
} oneshot_state;

oneshot_state os_shft_state = osm_0;
oneshot_state os_ctrl_state = osm_0;
oneshot_state os_alt_state  = osm_0;
oneshot_state os_cmd_state  = osm_0;
bool          osm_state     = false;

void switch_to_english(void) {
    SEND_STRING(SS_TAP(X_F13));
    layer_move(ABC);
};
void switch_to_russian(void) {
    SEND_STRING(SS_TAP(X_F14));
    layer_move(RUS);
};

static bool on_num_lock(uint16_t keycode) {
    if (is_layer_locked(NUM)) {
        tap_code(keycode);
        layer_lock_off(NUM);
        layer_move(ABC);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool on_keydown = record->event.pressed;
    bool on_keyup   = !record->event.pressed;

    switch (keycode) {
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            if (on_keydown) {
                if (!get_oneshot_mods()) {
                    osm_state = true;
                    tap_code(KC_F15);
                }
                switch (keycode) {
                    case OS_SHFT:
                        add_oneshot_mods(MOD_BIT(KC_LSFT));
                        return false;
                    case OS_CTRL:
                        add_oneshot_mods(MOD_BIT(KC_LCTL));
                        return false;
                    case OS_ALT:
                        add_oneshot_mods(MOD_BIT(KC_LALT));
                        return false;
                    case OS_CMD:
                        add_oneshot_mods(MOD_BIT(KC_LCMD));
                        return false;
                }
            }
        default:
            if (is_oneshot_cancel_key(keycode)) {
                if (on_keydown && get_oneshot_mods()) {
                    osm_state = false;
                    clear_oneshot_mods();
                    tap_code(KC_F16);
                }
                return true;
            }
            if (!is_oneshot_ignored_key(keycode) && osm_state == true && on_keyup) {
                osm_state = false;
                tap_code(KC_F16);
            }
    }

    switch (keycode) {
        case LANG:
            if (record->event.pressed) {
                switch_to_russian();
            } else {
                switch_to_english();
            }
            return false;
        case VOLTR:
            if (record->event.pressed) {
                trackball_volume = true;
            } else {
                trackball_volume = false;
            }
            return false;
    }

    if (!record->event.pressed) return true;

    switch (keycode) {
        case KC_W:
            return on_num_lock(keycode);
        case CommaS:
            SEND_STRING(", ");
            return false;
        case DotNS:
            SEND_STRING(". ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            return false;
        case QuesNS:
            SEND_STRING("? ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            return false;
        case ExlmNS:
            SEND_STRING("! ");
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            return false;
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
            return on_num_lock(keycode);
        case KC_S:
            if ((get_oneshot_mods() & MOD_MASK_CTRL) && !(get_oneshot_mods() & ~MOD_MASK_CTRL)) {
                layer_lock_on(NUM);
                return false;
            }
            return true;
        case NUMLOCK:
            layer_lock_on(NUM);
            return false;
        default:
            return true;
    }
}

static int volume_accumulator = 0;
#define SCROLL_DIVIDER 15 // increase for more sensitivity)

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (trackball_volume) {
        volume_accumulator += mouse_report.y;

        while (abs(volume_accumulator) >= SCROLL_DIVIDER) {
            if (volume_accumulator > 0) {
                tap_code(KC_KB_VOLUME_DOWN);
                volume_accumulator -= SCROLL_DIVIDER;
            } else {
                tap_code(KC_KB_VOLUME_UP);
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

layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, NUM));
    return state;
}

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (os_alt_state == osm_queued || os_ctrl_state == osm_queued || os_shft_state == osm_queued || os_cmd_state == osm_queued) {
                rgb_matrix_set_color(index, 0, 0, 0);

                if (os_alt_state == osm_queued) {
                    if (row == 8) {
                        rgb_matrix_set_color(index, RGB_RED);
                    }
                }
                if (os_ctrl_state == osm_queued) {
                    if (row == 7) {
                        rgb_matrix_set_color(index, 150, 150, 0);
                    }
                }
                if (os_shft_state == osm_queued) {
                    if (row == 6) {
                        rgb_matrix_set_color(index, 250, 0, 250);
                    }
                }
                if (os_cmd_state == osm_queued) {
                    if (row == 9 && col == 1) {
                        rgb_matrix_set_color(index, 250, 0, 0);
                    }
                }
            } else {
                switch (get_highest_layer(layer_state | default_layer_state)) {
                    case 1:
                        if (col == 5) {
                            rgb_matrix_set_color(index, 250, 0, 250);
                        } else {
                            rgb_matrix_set_color(index, 0, 0, 0);
                        }
                        break;
                    case 2:
                        if (row == 6) {
                            rgb_matrix_set_color(index, 250, 250, 250);
                        }
                    case 3:
                        if (row == 7) {
                            rgb_matrix_set_color(index, 250, 250, 250);
                        }
                    case 4:
                        if (row == 8) {
                            rgb_matrix_set_color(index, 250, 250, 250);
                        }
                        break;
                    default:
                        if (row == 5 || col == 0) {
                            rgb_matrix_set_color(index, 75, 0, 75);
                        } else {
                            rgb_matrix_set_color(index, 75, 9, 0);
                        }
                        break;
                }
            }
        }
    }
    return true;
}
