#include QMK_KEYBOARD_H
#include <math.h>

enum layers {
    _QWERTY = 0,
    _NUM,
    _MED,
    _NAV,
    _SYM,
    _FUN,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

/* #define LT_SPC   LT(_NUM, KC_SPC) */
/* #define LT_TAB   LT(_NAV, KC_TAB) */
#define LT_ESC   LT(_SYM, KC_ESC)

#define MT_A MT(MOD_LCTL, KC_A)
#define MT_S MT(MOD_LALT, KC_S)
#define MT_D MT(MOD_LGUI, KC_D)
#define MT_F MT(MOD_LSFT, KC_F)

#define MT_J MT(MOD_RSFT, KC_J)
#define MT_K MT(MOD_RGUI, KC_K)
#define MT_L MT(MOD_RALT, KC_L)
#define MT_SCLN MT(MOD_RCTL, KC_SCLN)

#define ESP_AT RALT(KC_2)
#define ESP_OCT RALT(KC_3)
#define LCURLY RALT(KC_QUOTE)
#define RCURLY RALT(KC_BSLS)
#define LPAREN LSFT(KC_8)
#define RPAREN LSFT(KC_9)
#define LBRACK RALT(KC_LBRC)
#define RBRACK RALT(KC_RBRC)
#define BANG LSFT(KC_1)
#define DQUOT LSFT(KC_2)
#define DOLL LSFT(KC_4)
#define PERC LSFT(KC_5)
#define AMPS LSFT(KC_6)
#define SQUOT KC_MINUS
#define TILD RALT(KC_SCLN)
#define EQUALS LSFT(KC_0)

#define LINE RALT(KC_1)
#define BACKSLS RALT(KC_NUBS)
#define QUEST LSFT(KC_MINS)
#define CIRCUN LSFT(KC_LBRC)
#define BACKTK KC_LBRC
#define LESSTH KC_GRV
#define GREATTH LSFT(KC_GRV)
#define SEMIC LSFT(KC_COMM)
#define COLON LSFT(KC_DOT)
#define GORRO LSFT(KC_LBRC)

#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DWN KC_KB_VOLUME_DOWN

#define ___0___ TO(_QWERTY)
#define NAV_ESC LT(_NAV, KC_ESC)
#define SYM_ENT LT(_SYM, KC_ENT)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
         BANG,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   SQUOT,
       KC_TAB,    MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                                        KC_H,    MT_J,    MT_K,    MT_L, MT_SCLN, KC_QUOT,
   LCTL(KC_A),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,MO(_MED),  KC_MEH, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   QUEST,
                               OSL(_FUN), _______,MO(_NUM),  KC_SPC, NAV_ESC, SYM_ENT, KC_BSPC, _______, _______, _______
    ),
    [_NUM] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_COMM,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                                        KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                                     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_SYM] = LAYOUT(
      XXXXXXX,    TILD,    LINE,   DQUOT,  LBRACK,  LESSTH,                                     GREATTH,  RBRACK,    BANG,  EQUALS,   QUEST,   SQUOT,
      XXXXXXX, XXXXXXX,    PERC,    DOLL,  LPAREN, KC_PAST,                                     KC_PPLS,  RPAREN,  ESP_AT, ESP_OCT, XXXXXXX, XXXXXXX,
      XXXXXXX,  BACKTK,    AMPS,  CIRCUN,  LCURLY, BACKSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,  RCURLY,   SEMIC,   COLON, KC_SLSH, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MED] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FUN] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F11, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      KC_F10,   KC_F4,   KC_F5,   KC_F6,  KC_F12, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),



// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
/* const uint16_t PROGMEM num_layer_combo[] = {KC_SPC, KC_BSPC, COMBO_END}; */
/* const uint16_t PROGMEM num_layer_combo[] = {KC_SPC, MT_F, COMBO_END}; */
/* combo_t key_combos[] = { */
/*     COMBO(num_layer_combo, MO(_NUM)), */
/* }; */


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_SLSH:
        case KC_SCLN: // because spanish layout
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

