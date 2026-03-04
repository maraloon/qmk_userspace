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

    SMART_NUM, // smart num lock
    DUMB_NUM,
};

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   OSL(FN),
    _,
    B,     L,     D,     W, OSM(MOD_LSFT), OSM(MOD_LSFT), F,     O,     U,     J,   QuesNS,
    Z,     N,     R,     T,    St,     G,            Y,     H,     A,     E,     I, OSM(MOD_LCTL),
    _,     Q,     X,     M,    Ct,     V,            K,     P,     OSM(MOD_LALT), OSL(CTL), Lets, ExlmNS,
               SMART_NUM, Space, KC_BTN2,            _, OSL(SYM),
                          KC_BTN1, VOLTR,            LANG
  ),

  [RUS] = LAYOUT(
    _,     _,     _,    _,      _,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц     У       К      Е             Н      Г      Ш      Й      З
    _,     Q,     W,    F,      P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Х
    rF,    N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rH,  QuesNS,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Ж
    rT,    Z,     X,    Ct,     D,     V,            K,     H,     O,    rU,    rJ,  ExlmNS,
                    CommaS, Space, DotNS,            _, _,
                    Minus, OSM(MOD_LSFT),            _
  ),

  [NUM] = LAYOUT(
    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, Home, End, RGB_TOG,  QK_BOOT,
    _,     B,     _,     _0,   W,    _,       _,   _,      _9,     _,    _, _,
    _,     Left, _1,     _2,  _3,    _,       _,     _5,   _6,    _8,   Up, _,
    _,     _,     _,  Right,  _4,    _,       _,     _7, Down, OSL(CTL), _, _,
                  Esc, Space, DUMB_NUM,       Esc, OSL(SYM),
                                  _, _,       DUMB_NUM
  ),

  [SYM] = LAYOUT(
    QK_BOOT, RGB_TOG, _,   _,    _, EE_CLR,            EE_CLR, _, _, _,   RGB_TOG,  QK_BOOT,
    _,     Star, Slash, Caret, Dollar, _,     _, Bracket, bracket, Borrow, borrow,  _,
   BSlash, Hash,   At,  DQuote, Minus, Tag,   _,     Dot,   Comma,  Array,  array,  _,
    _,     Equal, Plus,  Unds,  Quote, tag,   _,    DDot,   DComm,  Quest,   Exlm,  _,
                  DotNS, OSL(NUM), QK_LLCK,    _, _,
                           QK_LLCK, ExlmNS,    _
  ),

  [CTL] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _,  PgUp,  C(L),  PgDn, C(KC_BSPC), _,           _,  C(F),  C(O),  C(U),  C(J),   _,
    C(Z), C(N), C(R), Type, KC_TAB, C(G),      C(Y),  KC_BSPC,  C(A),  C(E),  C(I),   _,
    _,   C(Q),  C(X), Ent, Esc, C(V),     C(K),  C(P),   OSL(CAL),  _, _, _,
                            _, _, _,            _, _,
                         QK_LLCK, _,            _
  ),

  [CAL] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _, LCA(B), LCA(L), LCA(D), LCA(W),     _,            _, LCA(F), LCA(O), LCA(U), LCA(J),   _,
    LCA(Z), LCA(N), LCA(R), LCA(T), LCA(St), LCA(G),   LCA(Y), LCA(H), LCA(A), LCA(E), LCA(I),   _,
    _, LCA(Q), LCA(X), LCA(M), LCA(Ct), LCA(V),       LCA(K), LCA(P),   _,   _, _, _,
                            _, _, _,            _, _,
                         QK_LLCK, _,            _
  ),

  [FN] = LAYOUT(
    _, KC_F1,   KC_F2,  KC_F3,  KC_F4, KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, _,
    _, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,    KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, _,
    _, KC_F21, KC_F22, KC_F23, KC_F24, _,         _, _, _, _, _, _,
    _, _, _, _, _, _,    _, _, _, _, _, _,
                            _, _, _,            _, _,
                         QK_LLCK, _,            _
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM(MOD_LSFT):
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}
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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case C(KC_BSPC):
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool          smart_num_on     = true;
bool trackball_volume = false;

void switch_to_english(void) {
    SEND_STRING(SS_TAP(X_F13));
    layer_move(ABC);
};
void switch_to_russian(void) {
    SEND_STRING(SS_TAP(X_F14));
    layer_move(RUS);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LANG:
            if (record->event.pressed) {
                switch_to_russian();
            } else {
                switch_to_english();
            }
            return false;
    }

    if (!record->event.pressed) return true;
    switch (keycode) {
        case VOLTR:
            trackball_volume = !trackball_volume;
            return false;
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
        case KC_ESC:
            if (is_layer_locked(NUM)) {
                layer_lock_off(NUM);
                layer_move(ABC);

                smart_num_on = true;
                return false;
            }
            return true;
        case SMART_NUM:
            layer_lock_on(NUM);
            return false;
        case DUMB_NUM:
            smart_num_on = false;
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
        case KC_B:
        case KC_W:
        case KC_SPC:
        case KC_ENT:
            if (is_layer_locked(NUM) && smart_num_on) {
                tap_code(keycode);
                layer_lock_off(NUM);
                layer_move(ABC);
                return false;
            }
            return true;
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

            switch (get_highest_layer(layer_state | default_layer_state)) {
                case 0:
                    if (row == 5 || row == 1 || col == 0) {
                        rgb_matrix_set_color(index, 75, 0, 75);
                    } else {
                        rgb_matrix_set_color(index, 75, 9, 0);
                    }
                    break;
                default:
                    rgb_matrix_set_color(index, 75, 0, 75);
                    break;
            }
        }
    }
    return true;
}
