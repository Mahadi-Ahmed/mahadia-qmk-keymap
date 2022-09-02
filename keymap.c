/*
 * version: 1.0.1
 * TODO:
 *   Implement some way for swedish chars
 * - Use swedish dot / colon instead of US
 * - Implement custom shift keys for ' & s + ' = "
 */

#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap_swedish_pro_mac_ansi.h" // works well with OSX
#include "sendstring_swedish.h"

#include "features/custom_shift_keys.h"

enum planck_layers { _QWERTY, _SYMBOLS, _NUMPAD, _MOVEMENT, _FNLAYER, _GUITABS, _SWERTY};
enum planck_keycodes { QWERTY = SAFE_RANGE };

#define SYMBOLS LT(_SYMBOLS, KC_SPC)
#define NUMPAD LT(_NUMPAD, KC_SPC)
#define MOVEMENT LT(_MOVEMENT, KC_ESC)
#define FNLAYER MO(_FNLAYER)
#define GUITABS LT(_GUITABS, KC_SPC)

enum custom_keycodes { UPDIR = SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ┌───────────┬───────┬──────┬─────┬─────┬─────┬─────┬─────────┬───────┬──────┬─────┬────────────┐
     * │ tab       │ q     │ w    │ e   │ r   │ t   │ y   │ u       │ i     │ o    │ p   │ bspc       │
     * ├───────────┼───────┼──────┼─────┼─────┼─────┼─────┼─────────┼───────┼──────┼─────┼────────────┤
     * │ mvmnt/esc │ a     │ s    │ d   │ f   │ g   │ h   │ j       │ k     │ l    │ . : │ '          │
     * ├───────────┼───────┼──────┼─────┼─────┼─────┼─────┼─────────┼───────┼──────┼─────┼────────────┤
     * │ lshift    │ z     │ dead │ c   │ v   │ b   │ n   │ m       │ ,     │ .    │  x  │ rs / enter │
     * ├───────────┼───────┼──────┼─────┼─────┼─────┼─────┼─────────┼───────┼──────┼─────┼────────────┤
     * │ fnl       │ lctrl │ lalt │ gui │ num │ spc │ gui │ symbols │ rctrl │ ralt │ gui │ ? /        │
     * └───────────┴───────┴──────┴─────┴─────┴─────┴─────┴─────────┴───────┴──────┴─────┴────────────┘
     */

    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB, SE_Q, SE_W, SE_E, SE_R, SE_T, SE_Y, SE_U, SE_I, SE_O, SE_P, KC_BSPC,
        MOVEMENT, SE_A, SE_S, SE_D, SE_F, SE_G, SE_H, SE_J, SE_K, SE_L, SE_DOT, SE_QUOT,
        KC_LSFT, SE_Z, KC_X, SE_C, SE_V, SE_B, SE_N, SE_M, KC_COMM, KC_DOT, SE_X, KC_SFTENT,
        FNLAYER, KC_LCTL, KC_LALT, KC_LGUI, NUMPAD, KC_SPC, GUITABS, SYMBOLS, KC_RCTL, KC_RALT, KC_RGUI, KC_SLSH
    ),

     /* Symbols
      * ┌─────┬───┬───┬───┬─────┬─────┬───┬───┬───┬───┬───┬───┐
      * │  `  │ @ │ < │ > │ &   │ #   │ | │ ( │ ) │ ! │ ? │ ^ │
      * ├─────┼───┼───┼───┼─────┼─────┼───┼───┼───┼───┼───┼───┤
      * │     │ . │ - │ + │ =   │ /   │ $ │ { │ } │ % │ ~ │ * │
      * ├─────┼───┼───┼───┼─────┼─────┼───┼───┼───┼───┼───┼───┤
      * │     │   │   │   │ \   │ ../ │ _ │ [ │ ] │   │   │   │
      * ├─────┼───┼───┼───┼─────┼─────┼───┼───┼───┼───┼───┼───┤
      * │     │   │   │   │ spc │ spc │   │   │   │   │   │   │
      * └─────┴───┴───┴───┴─────┴─────┴───┴───┴───┴───┴───┴───┘
      */

     [_SYMBOLS] = LAYOUT_ortho_4x12(
        SE_GRV, SE_AT, SE_LABK, SE_RABK, SE_AMPR, SE_HASH, SE_PIPE, SE_LPRN, SE_RPRN, SE_EXLM, SE_QUES, SE_CIRC,
        KC_NO, SE_DOT, SE_MINS, SE_PLUS, SE_EQL, SE_SLSH, SE_DLR, SE_LCBR, SE_RCBR, SE_PERC, SE_TILD, SE_ASTR,
        KC_NO, KC_NO, KC_NO, KC_NO, SE_BSLS, UPDIR, SE_UNDS, SE_LBRC, SE_RBRC, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
     ),

    [_FNLAYER] = LAYOUT_ortho_4x12(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, OSM(MOD_LCTL | MOD_LALT), OSM(MOD_LCTL | MOD_LALT | MOD_LGUI), KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_TRNS, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
    ),

    [_MOVEMENT] = LAYOUT_ortho_4x12(
        KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_WH_U, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, KC_NO,
        KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2
    ),

    [_NUMPAD] = LAYOUT_ortho_4x12(
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, SE_4, SE_5, SE_6, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SE_0, SE_1, SE_2, SE_3, KC_NO, KC_PAST,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SE_7, SE_8, SE_9, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_1
    ),

     
    [_GUITABS] = LAYOUT_ortho_4x12(
        KC_NO, LGUI(KC_P1), LGUI(KC_P2), LGUI(KC_P3), LGUI(KC_P4), KC_NO, KC_NO, KC_NO, KC_NO, LGUI(LSFT(KC_3)), LGUI(LSFT(KC_4)), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AG_SWAP, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {  return false; }
    switch (keycode) {
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
    }
    return true;
}

const custom_shift_key_t custom_shift_keys[] = {
    {SE_QUOT, SE_DQUO},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

