#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    ABC = 0,
    UPPER,
    RUS,
    NUM,
    SYM,
    FN,
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
    OSM_RST,

    LOCK_NUM,
};

bool trackball_volume = false;

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

#define Lets LCMD(KC_F)
#define Type QK_LEAD

#define rF KC_KP_1 // ф
#define rJ KC_KP_2 // ж
#define rZ KC_KP_3 // з
#define rT KC_KP_4 // ъ
#define rH KC_KP_5 // х
#define rU KC_KP_6 // ю

#define SpaceNUM LT(NUM, KC_SPC)

const key_override_t c_h_o  = ko_make_basic(MOD_MASK_CTRL, KC_H, KC_BSPC);
const key_override_t c_w_o  = ko_make_basic(MOD_MASK_CTRL, KC_W, LCTL(KC_BSPC));
const key_override_t c_m_o  = ko_make_basic(MOD_MASK_CTRL, KC_M, KC_ENTER);
const key_override_t c_c_o  = ko_make_basic(MOD_MASK_CTRL, KC_C, KC_ESC);
const key_override_t c_ar_o = ko_make_basic(MOD_MASK_CTRL, Array, KC_ESC);
const key_override_t c_t_o  = ko_make_basic(MOD_MASK_CTRL, KC_T, KC_TAB);
const key_override_t c_f_o  = ko_make_basic(MOD_MASK_CTRL, KC_F, KC_PGDN);
const key_override_t c_b_o  = ko_make_basic(MOD_MASK_CTRL, KC_B, KC_PGUP);

const key_override_t cm_h_o = ko_make_basic(MOD_MASK_GUI, KC_H, LCTL(KC_H));
const key_override_t cm_w_o = ko_make_basic(MOD_MASK_GUI, KC_W, LCTL(KC_W));
const key_override_t cm_m_o = ko_make_basic(MOD_MASK_GUI, KC_M, LCTL(KC_M));
const key_override_t cm_c_o = ko_make_basic(MOD_MASK_GUI, KC_C, LCTL(KC_C));
const key_override_t cm_t_o = ko_make_basic(MOD_MASK_GUI, KC_T, LCTL(KC_T));
const key_override_t cm_n_o = ko_make_basic(MOD_MASK_GUI, KC_N, LCTL(KC_N));

const key_override_t *key_overrides[] = {&c_h_o, &c_w_o, &c_m_o, &c_c_o, &c_t_o, &c_ar_o, &c_t_o, &c_f_o, &c_b_o, &cm_h_o, &cm_c_o, &cm_w_o, &cm_m_o, &cm_t_o, &cm_t_o, &cm_n_o, NULL};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC] = LAYOUT(
    _,     _,     _, VOLTR,     _,     _,            _,     _,     _,     _,     _,   OSL(FN),
    _,     B,     L,     D,     W,  Type,       OSL(UPPER), F,     O,     U,     J,   _,
    Z,     N,     R,     T,    St,     G,            Y,     H,     A,     E,     I, Cmd,
    _,     Q,     X,     M,     C,     V,            K,     P,     Alt, Ctrl, Lets, _,
                    _, SpaceNUM, KC_BTN2,            OSM_RST, OSL(SYM),
                          KC_BTN1, Shift,            LANG
  ),

  [UPPER] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _,  S(B),  S(L),  S(D),  S(W),     _,            _,  S(F),  S(O),  S(U),  S(J),   _,
 S(Z),  S(N),  S(R),  S(T), S(St),  S(G),         S(Y),  S(H),  S(A),  S(E),  S(I),   _,
    _,  S(Q),  S(X),  S(M), S(C),   S(V),         S(K),  S(P),     _,     _,     _,   _,
                                 _, _, _,         _, _,
                                    _, _,         _
  ),

  [RUS] = LAYOUT(
    _,     _,     _,    _,      _,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц     У       К      Е             Н      Г      Ш      Й      З
    _,     Q,     W,    F,      P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Х
    rF,    N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rH,  QuesNS,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Ж
    rT,    Z,     X,     C,     D,     V,            K,     H,     O,    rU,    rJ,  ExlmNS,
               CommaS, SpaceShift, DotNS,            _, _,
                       Minus, SpaceShift,            _
  ),

  [NUM] = LAYOUT(

    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, Home, End, RGB_TOG,  QK_BOOT,

    _,     B,     _,     _0,   W,    Type,    _,   Left,   _9, Right,    _, _,
    _,     _,    _1,     _2,  _3, OSL(SYM), OSL(SYM), _5,  _6,    _8,    _, _,
    _,     _,    Up,   Down,  _4,    _,       _,     _7, Down,    Up,    _, _,
                           _, Space, _,       TG(NUM), _,
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
// clang-format on
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case OSM_RST:
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
    osm_holded,
    osm_used,
} oneshot_state;

oneshot_state os_shft_state = osm_0;
oneshot_state os_ctrl_state = osm_0;
oneshot_state os_alt_state  = osm_0;
oneshot_state os_cmd_state  = osm_0;
bool          osm_pinned    = false;

void switch_to_english(void) {
    SEND_STRING(SS_TAP(X_F13));
    layer_move(ABC);
};
void switch_to_russian(void) {
    SEND_STRING(SS_TAP(X_F14));
    layer_move(RUS);
};

static inline void reset_osm(oneshot_state *state, uint16_t mod) {
    *state = osm_0;
    unregister_code(mod);
}

void update_oneshot(oneshot_state *state, uint16_t mod, uint16_t osm_key, uint16_t keycode, keyrecord_t *record) {
    bool on_keydown = record->event.pressed;
    bool on_keyup   = !record->event.pressed;
    bool is_osm     = keycode == osm_key;

    // OSM keydown - init
    if (is_osm && on_keydown && *state == osm_0) {
        register_code(mod);
        *state = osm_holded;
        return;
    }
    // OSM keydown-keyup. Регистрируем mod как нажатый one-shot, ожидающий нажатия a-z
    if (is_osm && on_keyup && *state == osm_holded) {
        *state = osm_queued;
        return;
    }
    // OSM double keydown - регистрируем "залипший" mod
    if (is_osm && on_keydown && *state != osm_0) {
        osm_pinned = true;
        return;
    }
    // Нажали OSM cancel-key. Сбрасываем до дефолтных
    if (is_oneshot_cancel_key(keycode)) {
        if (on_keydown && *state != osm_0) {
            reset_osm(state, mod);
            osm_pinned = false;
        }
        return;
    }

    // Нажали a-z
    if (!is_osm && on_keyup) {
        if (is_oneshot_ignored_key(keycode) || osm_pinned) {
            return;
        }

        // Если osm зажат, то говорим, что он отработал и ждем когда его отожмут
        if (*state == osm_holded) {
            *state = osm_used;
            return;
        }
        // Если osm был тапнут как one-shot, то сбрасываем до дефолтных
        if (*state == osm_queued) {
            reset_osm(state, mod);
            return;
        }
    }

    // Когда был hold OSM, потом нажали a-z, потом палец с OSM убрали. Сбрасываем до дефолтного состояния
    if (is_osm && on_keyup && *state == osm_used) {
        reset_osm(state, mod);
        return;
    }

    return;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // clang-format off
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);
    // clang-format on

    switch (keycode) {
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
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
        case KC_W:
        case KC_B:
            if (record->event.pressed && layer_state_is(NUM) && is_layer_locked(NUM)) {
                tap_code(keycode);
                layer_lock_off(NUM);
                layer_move(ABC);
                return false;
            }
            return true;
        case KC_S:
            if (record->event.pressed && (get_mods() & MOD_MASK_CTRL)) {
                if (get_mods() & ~MOD_MASK_CTRL) {
                    return true;
                }
                layer_on(NUM);
                layer_lock_on(NUM);
                return false;
            }
            return true;
        case LOCK_NUM:
            if (record->event.pressed) {
                layer_on(NUM);
                layer_lock_on(NUM);
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
                    case 3:
                        if (row == 6) {
                            rgb_matrix_set_color(index, 250, 250, 250);
                        }
                    case 4:
                        if (row == 7) {
                            rgb_matrix_set_color(index, 250, 250, 250);
                        }
                    case 5:
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
