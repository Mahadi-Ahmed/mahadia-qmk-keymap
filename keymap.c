/*
 * TODO:
 *  - Lower right side, after sybmols are useless, look for something else
 *  - Implement macro to double tap for: () => {}
 *  - Implement macro to double tap for :
 *    - eee: qa!
 *  - Try numpad with normal layout instead of current implementation
 *  - Add ASCII layout for all layers in codebase
 */

#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap_swedish_pro_mac_ansi.h" // works well with OSX
// #include "sendstring_swedish.h"

#include "features/custom_shift_keys.h"

enum planck_layers { _QWERTY, _SYMBOLS, _NUMPAD, _MOVEMENT, _FNLAYER, _GUITABS, _SWERTY};
enum planck_keycodes { QWERTY = SAFE_RANGE };

#define SYMBOLS LT(_SYMBOLS, KC_SPC)
#define NUMPAD LT(_NUMPAD, KC_SPC)
#define MOVEMENT LT(_MOVEMENT, KC_ESC)
#define FNLAYER MO(_FNLAYER)
#define GUITABS LT(_GUITABS, KC_SPC)

// Left-hand home row mods
#define HOME_CTL_A LCTL_T(KC_A)
#define HOME_ALT_S LALT_T(KC_S)
#define HOME_GUI_D LGUI_T(KC_D)
#define HOME_SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_RSF_J RSFT_T(KC_J)
#define HOME_GUI_K LGUI_T(KC_K)
#define HOME_ALT_L LALT_T(KC_L)
#define HOME_CTL_DOT RCTL_T(KC_DOT)

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  CSLOG,
  AFUNC
};

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
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        MOVEMENT, HOME_CTL_A, HOME_ALT_S, HOME_GUI_D, HOME_SFT_F, KC_G, KC_H, HOME_RSF_J, HOME_GUI_K, HOME_ALT_L, HOME_CTL_DOT, RALT(KC_QUOT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_SLASH, KC_MINS, KC_ENT,
        FNLAYER, KC_LCTL, KC_LALT, KC_LGUI, NUMPAD, KC_SPC, GUITABS, SYMBOLS, KC_RCTL, KC_RALT, KC_RGUI, KC_SLSH
    ),

   /*  SYMBOLS
    * ┌───┬──────┬─────┬───────────────┬───┬─────┬───┬───┬───┬───┬───┬───┐
    * │ ` │ @    │ <   │ >             │ & │ #   │ | │ ( │ ) │ ! │ ? │ ^ │
    * ├───┼──────┼─────┼───────────────┼───┼─────┼───┼───┼───┼───┼───┼───┤
    * │   │AFUCN │ -   │ +             │ = │ /   │ $ │ { │ } │ % │ ~ │ * │
    * ├───┼──────┼─────┼───────────────┼───┼─────┼───┼───┼───┼───┼───┼───┤
    * │   │      │     │ console.log() │ \ │ ../ │ _ │ [ │ ] │   │   │   │
    * ├───┼──────┼─────┼───────────────┼───┼─────┼───┼───┼───┼───┼───┼───┤
    * │   │ ctrl │ alt │ gui           │   │     │   │   │   │   │   │   │
    * └───┴──────┴─────┴───────────────┴───┴─────┴───┴───┴───┴───┴───┴───┘     
    */

     [_SYMBOLS] = LAYOUT_ortho_4x12(
        KC_GRV, KC_AT, KC_LT, KC_GT, KC_AMPR, KC_HASH, KC_PIPE, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES, KC_CIRC,
        KC_NO, AFUNC, KC_PMNS, KC_PPLS, KC_PEQL, KC_PSLS, KC_DLR, RALT(KC_LCBR), RALT(KC_RCBR), KC_PERC, KC_TILD, KC_ASTR,
        KC_LSFT, KC_NO, KC_NO, CSLOG, KC_BSLS, UPDIR, KC_UNDS, RALT(KC_LBRC), RALT(KC_RBRC), KC_NO, KC_NO, KC_NO,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
     ),

    [_FNLAYER] = LAYOUT_ortho_4x12(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, OSM(MOD_LCTL | MOD_LALT), OSM(MOD_LCTL | MOD_LALT | MOD_LGUI), KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_TRNS, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD
    ),

    [_MOVEMENT] = LAYOUT_ortho_4x12(
        KC_TRNS, KC_BTN2, KC_MS_U, KC_BTN1, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_WH_U, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, LGUI(KC_LEFT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, LGUI(KC_RGHT), KC_NO,
        KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2
    ),

    [_NUMPAD] = LAYOUT_ortho_4x12(
        KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_PAST,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_GUITABS] = LAYOUT_ortho_4x12(
        KC_NO, LGUI(KC_P1), LGUI(KC_P2), LGUI(KC_P3), LGUI(KC_P4), KC_NO, KC_NO, KC_NO, KC_NO, LGUI(LSFT(KC_3)), LGUI(LSFT(KC_4)), KC_NO,
        LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_UP), LCTL(KC_RIGHT), KC_NO, KC_NO,
        LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
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
        case CSLOG:
            if (record->event.pressed) {
                SEND_STRING("console.log()"SS_TAP(X_LEFT));
            } 
            return false;
        case AFUNC:
            if (record->event.pressed) {
                // RALT(KC_LCBR), RALT(KC_RCBR)
                SEND_STRING("() => " SS_RALT("{" SS_RALT("}")) SS_TAP(X_LEFT));
            } 
            return false;
    }
    return true;
}

const custom_shift_key_t custom_shift_keys[] = {
    // {SE_QUOT, SE_DQUO}, HOME_CTL_DOT
    // {KC_DOT, RALT(KC_COLN)},
    {HOME_CTL_DOT, RALT(KC_COLN)},
    {KC_QUOT, KC_DQUO},
    {KC_COMM, RALT(KC_SCLN)}
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


// Need to add Swedish å ä ö to capitalize them as well
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case SE_UNDS:
    case SE_MINS:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
};

// Need to specify the number of combo's in config.h
const uint16_t PROGMEM se_1[] = { KC_V, HOME_CTL_DOT, COMBO_END }; // ö
const uint16_t PROGMEM se_2[] = { KC_V, RALT(KC_QUOT), COMBO_END }; // ä
const uint16_t PROGMEM se_3[] = { KC_V, KC_BSPC, COMBO_END }; // å
combo_t key_combos[COMBO_COUNT] = {
  COMBO(se_1, SE_ODIA),
  COMBO(se_2, SE_ADIA),
  COMBO(se_3, SE_ARNG),
};
