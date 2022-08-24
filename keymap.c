/*
 * version: 1.0.1
 * TODO:
 *   Implement some way for swedish chars
 */

#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers { _QWERTY, _SYMBOLS, _NUMPAD, _MOVEMENT, _FNLAYER, _GUITABS, _SWERTY};
enum planck_keycodes { QWERTY = SAFE_RANGE };

#define SYMBOLS LT(_SYMBOLS, KC_SPC)
#define NUMPAD LT(_NUMPAD, KC_SPC)
#define MOVEMENT LT(_MOVEMENT, KC_ESC)
#define FNLAYER MO(_FNLAYER)
#define GUITABS LT(_GUITABS, KC_SPC)

enum custom_keycodes { UPDIR = SAFE_RANGE };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | esc/mvmnt|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; | '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |FNLAYER| Ctrl | Alt  | GUI  |NUMPAD | spc |GUITABS|SYMBOLS| rctrl|ralt| rgui | ? / |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        MOVEMENT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
        FNLAYER, KC_LCTL, KC_LALT, KC_LGUI, NUMPAD, KC_SPC, GUITABS, SYMBOLS, KC_RCTL, KC_RALT, KC_RGUI, KC_SLSH
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
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_P4, KC_P5, KC_P6, KC_NO, KC_NO,
        KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_P0, KC_P1, KC_P2, KC_P3, KC_NO, KC_PAST,
        KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_1
    ),

    [_SYMBOLS] = LAYOUT_ortho_4x12(
        KC_GRV, KC_AT, KC_LT, KC_GT, KC_AMPR, KC_HASH, KC_PIPE, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES, KC_CIRC,
        KC_NO, KC_PDOT, KC_PMNS, KC_PPLS, KC_PEQL, KC_PSLS, KC_DLR, KC_LCBR, KC_RCBR, KC_PERC, KC_TILD, KC_ASTR,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS, UPDIR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PCMM, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_GUITABS] = LAYOUT_ortho_4x12(
        KC_NO, LGUI(KC_P1), LGUI(KC_P2), LGUI(KC_P3), LGUI(KC_P4), KC_NO, KC_NO, KC_NO, KC_NO, LGUI(LSFT(KC_3)), LGUI(LSFT(KC_4)), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, AG_SWAP, AG_NORM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_SWERTY] = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        MOVEMENT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
        FNLAYER, KC_LCTL, KC_LALT, KC_LGUI, NUMPAD, KC_SPC, GUITABS, SYMBOLS, KC_RCTL, KC_RALT, KC_RGUI, KC_SLSH
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
    }
    return true;
}
