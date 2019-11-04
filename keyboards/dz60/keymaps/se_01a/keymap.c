#include QMK_KEYBOARD_H

enum ctrl_layers {
    _CM,  // Colemak
    _QW,  // Querty
    _S1,  // "Swap" back left ctrl/backspace
    _S2,  // "Swap" back left ctrl/backspace
    _AT,  // Left aet = right alt, so I can type accents on linux and windows
    _AR,  // Caps lock hold
    _F2,  // Caps + Tab
    _MO,  // Mouse stuff + Numpad
    _FN,  // RGB, prog and such
};

enum combos {
    CB_DEL
};
const uint16_t PROGMEM del_combo[] = {KC_EQL, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CB_DEL] = COMBO(del_combo, KC_DEL)
};

#define TG_NKRO MAGIC_TOGGLE_NKRO
#define SE_BKSP LT(_AR, KC_BSPC)
#define SE_CTRL LCTL_T(KC_BSPC)
#define SE_MEH  RCTL(RALT(KC_RSFT))  // LALT still sends RALT!?
#define SE_MEH1 RCTL(KC_RALT)

#define SE_ALGR ALGR_T(KC_LEFT)
#define SE_RGUI RGUI_T(KC_DOWN)
#define SE__AR  LT(_AR, KC_UP)
#define SE__FN LT(_FN, KC_RGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CM] = LAYOUT_60_ansi(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        SE_CTRL,          KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, KC_ENT ,
        KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT,
        TT(_AR), KC_LALT,          KC_LGUI,                   KC_SPC ,                            SE_ALGR, SE_RGUI,          SE__AR , SE__FN
        // TT(_AR), KC_LALT,          KC_LGUI,                   KC_SPC ,                            KC_RALT, KC_RGUI,          TT(_AR), MO(_FN)
    ),
    [_QW] = LAYOUT_60_ansi(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        SE_CTRL,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
        KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT,
        TT(_AR), KC_LALT,          KC_LGUI,                   KC_SPC ,                            SE_ALGR, SE_RGUI,          SE__AR , SE__FN
    ),
    [_S1] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        SE_MEH1,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_LCTL, _______,          SE_MEH ,                   _______,                            _______, _______,          _______, _______
    ),
    [_S2] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
    ),
    [_AT] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          KC_RALT,                   _______,                            _______, _______,          _______, _______
    ),
    [_AR] = LAYOUT_60_ansi(
        KC_GRV ,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_DEL ,
        TT(_MO),          KC_MUTE, _______, _______, _______, _______, _______, KC_PGUP, KC_UP  , _______, _______, _______, _______, _______,
        _______,          KC_MPLY, KC_MSTP, KC_VOLU, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        _______,          KC_MPRV, KC_MNXT, KC_VOLD, _______, _______, KC_HOME, KC_END , KC_INS , _______, _______,          _______,
        TG(_AR), _______,          _______,                   _______,                            _______, MO(_F2),          TG(_AR), MO(_FN)
    ),
    [_F2] = LAYOUT_60_ansi(
        _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, MO(_FN)
    ),
    [_MO] = LAYOUT_60_ansi(
        TG(_MO), _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______, _______, _______,          KC_BSPC,
        _______,          KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, _______, KC_WH_D, KC_MS_U, KC_WH_L, KC_WH_R, _______, _______, _______,
        TG(_MO),          KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL2, _______, _______,
        _______,          KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,          _______,
        _______, KC_KP_0,          KC_PDOT,                   KC_ACL1,                            KC_ACL0, _______,          _______, MO(_FN)
    ),
    [_FN] = LAYOUT_60_ansi(
        KC_GRV , DF(_QW), DF(_CM), TG(_AT), TG(_S1), TG(_S2), _______, _______, _______, _______, _______, _______, _______,          KC_DEL ,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET  ,
        KC_CAPS,          _______, _______, _______, _______, _______, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, _______,
        _______,          _______, BL_DEC , BL_TOGG, BL_INC , BL_STEP, TG_NKRO, _______, KC_DEL , KC_END , KC_PGDN,          _______,
        _______, _______,          _______,                   _______,                           KC_LANG2,KC_LANG1,          KC_NUBS , _______
    ),

    // [XXX] = LAYOUT_60_ansi(
    // 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // 	_______, _______,          _______,                   _______,                            _______, _______,          _______, MO(_FN)
    // ),
};

// void led_set_user(uint8_t usb_led) {
// 	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
//         DDRB |= (1 << 2); PORTB &= ~(1 << 2);
// 	} else {
//         DDRB &= (1 << 2); PORTB &= ~(1 << 2);
//     }
// }
