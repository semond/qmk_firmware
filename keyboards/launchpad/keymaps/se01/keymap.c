// Below layout is based upon /u/That-Canadian's planck layout
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _FUNC 15

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------.
 * |   1  |  2   |
 * |------+------|
 * |   3  |  4   |
 * |------+------|
 * |   5  |  6   |
 * |------+------|
 * | FUNC |  8   |
 * `-------------'
 */
[_QWERTY] = LAYOUT( \
    KC_MPLY,   KC_MUTE, \
    KC_MPRV,   KC_MNXT, \
    KC_VOLD,      KC_VOLU, \
    MO(_FUNC), KC_F17  \
),

/* Function
 * ,-------------.
 * |   Q  |CALDEL|
 * |------+------|
 * |   A  |TSKMGR|
 * |------+------|
 * |   Z  |  X   |
 * |------+------|
 * |      |  C   |
 * `-------------'
 */
[_FUNC] = LAYOUT( \
    KC_F23,    LCTL(LSFT(KC_POWER)), \
    KC_F21,    KC_F22, \
    KC_F19,    KC_F20, \
    _______, KC_F18 \
)

};

void matrix_init_user(void) {

}
