#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    ABC = 0,
    RUS,
    NUM,
    SYM,
    NAV,
    CODE,
    TMUX,
    FN,
};

enum my_keycodes {
    LANG = SAFE_RANGE,
    VOLTR,
    SCALE,

    CommaS,
    DotNS,
    QuesNS,
    ExlmNS,

    oA,
    oC,
    oCA,
    cA,
    cAND,
    cP,
    cOR,
    cNE,
    cLE,
    cLM,
    cGE,
    cDE,
    cMR,
    cSS,
    cQQ,
    cEE,
    cCC,
    cMM,
    cPP,
    cDDD,

    cCode,
    cSAA,
    cNEE,
    cL,
    cE,
    cG,
    cEEE,
    cTag,
    cArr,
    cBorrow,
    cBorrow2,
    cBracket,

    SMART_NUM, // smart num lock
    DUMB_NUM,

    STRES,
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
#define Bs KC_BSPC
#define Esc KC_ESC
#define Enter KC_ENT
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
#define Equal KC_KP_EQUAL
#define Unds KC_UNDS
#define Minus KC_KP_MINUS
#define Plus KC_KP_PLUS

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

#define Lets LGUI(KC_F)

#define rF KC_KP_1 // ф
#define rJ KC_KP_2 // ж
#define rZ KC_KP_3 // з
#define rT KC_KP_4 // ъ
#define rH KC_KP_5 // х
#define rU KC_KP_6 // ю

#define oS OSM(MOD_LSFT)
// #define OS_LCS OSM(MOD_LCTL | MOD_LSFT)
#define OS_LSA OSM(MOD_LALT | MOD_LSFT)
// #define OS_MEH OSM(MOD_LALT | MOD_LCTL | MOD_LSFT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [ABC] = LAYOUT(
    _,     _,     _,     VOLTR,    SCALE,      _,            _,     _,     _,     _,     _,   OSL(FN),
    Bs,    B,     L,     D,    W,    Esc,            Enter, F,     O,     U,     OSL(TMUX),   Lets,
    oS,    N,     R,     T,    St,     G,            Y,     H,     A,     E,     I,   oS,
  KC_BTN2, Q,     X,     M,    Ct,     V,            K,     P,  OSL(SYM), SMART_NUM, Lets, Lets,
                  C(Bs), Space, J,                   Tab, _,
                              KC_BTN1, Z,            LANG
  ),

  [RUS] = LAYOUT(
    _,     _,     _,    _,      _,     _,            _,     _,     _,     _,     _,    _,
    //     Э      Ц     У       К      Е             Н      Г      Ш      Й      З
    _,     Q,     W,    F,      P,     B,            J,     L,     U,     Y,    rZ,    _,
    //     Щ      Ы      В      А      П             Р      О      Л      Д      Х
    rF,    N,     R,  KC_S,     T,     G,            M,     A,     E,     I,    rH,  QuesNS,
    //     Я      Ч      С      М      И             Т      Ь      Б      Ю      Ж
    rT,    Z,     X,    Ct,     D,     V,            K,     H,     O,    rU,    rJ,  ExlmNS,
                    CommaS, Space, DotNS,            STRES, _,
                    Minus, OSM(MOD_LSFT),            _
  ),

  [NUM] = LAYOUT(
    QK_BOOT, RGB_TOG, _,      _,     _, EE_CLR,           EE_CLR, _, _, _, RGB_TOG,  QK_BOOT,
_, PgUp, Left, _0, Right, Esc,       Enter, _,   _9, _, OSL(TMUX), _,
  _, _, _1, _2,      _3,  End,       _, _5, _6, _8, STRES, _,
  _, PgDn, Up, Down, _4, _,          _, _7, OSL(SYM), oC, _, _,
            Bs, DUMB_NUM, _,         _, STRES,
                       _, _,         _
  ),

  [SYM] = LAYOUT(
    _, _, Array,  array, _, _,            _, _, _, _,   _,  _,
      _, Star, Slash, Caret, Dollar, Esc,     Enter, Bracket, bracket, Borrow, borrow,  _,
    BSlash, Equal, At, Unds, Minus, Hash,     Amp, Dot,   Comma,  Array,  array, Pipe,
    _,     Quest,  Exlm, DQuote, Quote, Plus,     Tilda, DDot,  DComm,  Tag, tag,  Grave,
                           _, QK_LLCK, _,     _, STRES,
                              _, Percent,     _
  ),

  [NAV] = LAYOUT(
    QK_BOOT, RGB_TOG, _,   _,    _, EE_CLR,            EE_CLR, _, _, _,   RGB_TOG,  QK_BOOT,
    _,     _,  Tab,   Up,  End,      Esc,            Enter, _,     Up,    PgUp,     _,    _,
    _,     _, Left, Down, Right,       _,            _,     Left,  Down,  Right,    _,    _,
    _,     _,     _,    PgUp, PgDn,    _,            _,     PgDn,   _,     _,     _,    _,
                          Bs, QK_LLCK, _,            _, STRES,
                        KC_BTN1, KC_BTN2,            _
   ),

  [CODE] = LAYOUT(
    _ , _ , _ , _ , _ , _ , _ , _ , _ , _ , _ , _ ,
    // []    &&    ||   ()        ""
    _, cArr, cAND, cOR, cBracket, cQQ,    _, _, _, _, _, _,
    //   !=   <=   :=   >=    ++                ...   ```
    cCC, cNE, cLE, cDE, cGE, cPP,         _,    cDDD, cCode, _, _, _,
    //   --   <-   ==   ->   ''       - [ ] {   }     {}           <>
    _,   cMM, cLM, cEE, cMR, cSS,       cSAA, cBorrow2, cBorrow, _, cTag, _,
               _, _, _,   STRES, STRES,
                  _, _,    _
   ),

  [TMUX] = LAYOUT(
    _,     _,     _,     _,     _,     _,            _,     _,     _,     _,     _,   _,
    _, LALT(B), LALT(L), LALT(D), LALT(W),     _,            _, LALT(F), LALT(O), LALT(U), LALT(J),   _,
    OS_LSA, LALT(N), oCA, LALT(T), LALT(St), LALT(G),   LALT(Y), LALT(H), LALT(A), LALT(E), LALT(I),   OS_LSA,
    _, LALT(Q), LALT(X), LALT(M), LALT(Ct), LALT(V),       LALT(K), OSL(CODE), oCA, _, _, _,
                 _, oC, LALT(Space),            STRES, _,
                   QK_LLCK, LALT(Z),            _
  ),

  [FN] = LAYOUT(
    _, KC_F1,   KC_F2,  KC_F3,  KC_F4, KC_F5,      KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, _,
    _, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,    KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, _,
    _, KC_F21, KC_F22, KC_F23, KC_F24, _,         _, _, _, _, _, _,
    _, _, _, _, _, _,    _, _, _, _, _, _,
                            _, _, _,            STRES, _,
                         QK_LLCK, _,            _
  ),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(CODE, KC_BTN2):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM(MOD_LSFT):
            return TAPPING_TERM + 300;
        default:
            return TAPPING_TERM;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case Bs:
        case C(Bs):
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
bool trackball_scale = false;

void switch_to_english(void) {
    clear_oneshot_mods(); // In case shift is osm'ed (see DotNS, etc)
    SEND_STRING(SS_TAP(X_F13));
    layer_move(ABC);
};
void switch_to_russian(void) {
    SEND_STRING(SS_TAP(X_F14));
    layer_move(RUS);
};

void reset_kb_state(void) {
    if (is_layer_locked(RUS)) {
        layer_lock_off(RUS);
    }
    if (is_layer_locked(NUM)) {
        layer_lock_off(NUM);
    }
    if (is_layer_locked(SYM)) {
        layer_lock_off(SYM);
    }
    if (is_layer_locked(FN)) {
        layer_lock_off(FN);
    }
    reset_oneshot_layer();
    clear_oneshot_mods();
    caps_word_off();
    // leader_end(); // BUG: it's not for cancel leader seq
    smart_num_on = true;
    trackball_volume = false;
    trackball_scale = false;
    layer_move(ABC);
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
        case OSL(CODE):
            if (record->event.pressed) {
                reset_kb_state();
                set_oneshot_layer(CODE, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            return true;
    }

    if (!record->event.pressed) return true;
    switch (keycode) {
        case VOLTR:
            trackball_volume = !trackball_volume;
            return false;
        case SCALE:
            trackball_scale = !trackball_scale;
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
        case SMART_NUM:
            reset_kb_state();
            layer_lock_on(NUM);
            return false;
        case DUMB_NUM:
            if (smart_num_on == false) {
                reset_kb_state();
            } else {
                smart_num_on = false;
            }
            return false;
        // case OSL(SYM):
        //     if (trackball_scale || trackball_volume) {
        //         trackball_volume = false;
        //         trackball_scale = false;
        //         return false;
        //     }
        //     return true;
        case Esc:
            reset_kb_state();
            return true;
        case STRES:
            reset_kb_state();
            return false;
        case KC_B:
        case KC_W:
        case KC_HOME:
        case KC_END:
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
        case KC_G:
        case KC_SPC:
        case Bs:
        case Enter:
        // case KC_ESC:
        case PgUp:
        case PgDn:
            if (is_layer_locked(NUM) && smart_num_on) {
            tap_code16(keycode);
                layer_lock_off(NUM);
                layer_move(ABC);
                return false;
            }
            return true;
        case oC:
            reset_oneshot_layer();
            layer_move(ABC);
            set_oneshot_mods(MOD_LCTL);
            return false;
        case oA:
            reset_oneshot_layer();
            layer_move(ABC);
            set_oneshot_mods(MOD_LALT);
            return false;
        case oCA:
            reset_oneshot_layer();
            layer_move(ABC);
            set_oneshot_mods(MOD_LCTL | MOD_LALT);
            return false;
        case cA:
            SEND_STRING(" & ");
            reset_kb_state();
            return false;
        case cAND:
            SEND_STRING(" && ");
            reset_kb_state();
            return false;
        case cP:
            SEND_STRING(" | ");
            reset_kb_state();
            return false;
        case cOR:
            SEND_STRING(" || ");
            reset_kb_state();
            return false;
        case cNE:
            SEND_STRING(" != ");
            reset_kb_state();
            return false;
        case cGE:
            SEND_STRING(" >= ");
            reset_kb_state();
            return false;
        case cLE:
            SEND_STRING(" <= ");
            reset_kb_state();
            return false;
        case cLM:
            SEND_STRING("<-");
            reset_kb_state();
            return false;
        case cDE:
            SEND_STRING(" := ");
            reset_kb_state();
            return false;
        case cMR:
            SEND_STRING("->");
            reset_kb_state();
            return false;
        case cSS:
            SEND_STRING("''" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cQQ:
            SEND_STRING("\"\"" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cEE:
            SEND_STRING(" == ");
            reset_kb_state();
            return false;
        case cCC:
            SEND_STRING("// ");
            reset_kb_state();
            return false;
        case cMM:
            SEND_STRING("--");
            reset_kb_state();
            return false;
        case cPP:
            SEND_STRING("++");
            reset_kb_state();
            return false;
        case cDDD:
            SEND_STRING("...");
            reset_kb_state();
            return false;
        case cCode:
            SEND_STRING("```");
            reset_kb_state();
            return false;
        case cSAA:
            SEND_STRING("- [ ] ");
            reset_kb_state();
            return false;
        case cNEE:
            SEND_STRING(" !== ");
            reset_kb_state();
            return false;
        case cEEE:
            SEND_STRING(" === ");
            reset_kb_state();
            return false;
        case cL:
            SEND_STRING(" < ");
            reset_kb_state();
            return false;
        case cG:
            SEND_STRING(" > ");
            reset_kb_state();
            return false;
        case cE:
            SEND_STRING(" = ");
            reset_kb_state();
            return false;
        case cTag:
            SEND_STRING("<>" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cArr:
            SEND_STRING("[]" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cBorrow:
            SEND_STRING("{}" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cBracket:
            SEND_STRING("()" SS_TAP(X_LEFT));
            reset_kb_state();
            return false;
        case cBorrow2:
            send_string_with_delay(" {\n}\eOa", 20);
            reset_kb_state();
            return false;
        default:
            return true;
    }
}

static int volume_accumulator = 0;
static int scale_accumulator = 0;
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
    if (trackball_scale) {
        scale_accumulator += mouse_report.y;

        while (abs(scale_accumulator) >= SCROLL_DIVIDER) {
            if (scale_accumulator > 0) {
                SEND_STRING(SS_LCTL("-"));
                scale_accumulator -= SCROLL_DIVIDER;
            } else {
                SEND_STRING(SS_LCTL("="));
                scale_accumulator += SCROLL_DIVIDER;
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
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, SYM));
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

            if (trackball_volume || trackball_scale || get_oneshot_mods() || is_caps_word_on()) {
                rgb_matrix_set_color(index, 75, 0, 75);
                return true;
            }
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
