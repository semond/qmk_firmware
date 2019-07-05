#include QMK_KEYBOARD_H

enum ctrl_layers {
    _CM,  // Colemak
    _QW,  // Querty
    _S1,  // "Swap" back left ctrl/backspace
    _AT,  // Left aet = right alt, so I can type accents on linux and windows
    _AR,  // Caps lock hold
    _F2,  // Caps + Tab
    _AH,  // Bottom arrow test
    _MO,  // Mouse stuff + Numpad
    _FN,  // RGB, prog and such
};

#define TG_NKRO             MAGIC_TOGGLE_NKRO
#define SE_BKSP LT(_AR, KC_BSPC)
#define SE_CTRL LCTL_T(KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CM] = LAYOUT_ANSI(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
        SE_CTRL,          KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, KC_ENT ,
        KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT,
        TT(_AR), KC_LALT,          KC_LGUI,                   KC_SPC ,                            KC_RALT, KC_RGUI,          TT(_AR), MO(_FN)
    ),
    [_QW] = LAYOUT_ANSI(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,          KC_BSPC,
        KC_TAB ,          KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        SE_CTRL,          KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
        KC_LSFT,          KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT,
        TT(_AR), KC_LALT,          KC_LGUI,                   KC_SPC ,                            KC_RALT, KC_RGUI,          TT(_AR), MO(_FN)
    ),
    [_S1] = LAYOUT_ANSI(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        SE_BKSP,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        SE_CTRL, _______,          _______,                   _______,                            _______, _______,          _______, MO(_FN)
    ),
    [_AT] = LAYOUT_ANSI(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          KC_RALT,                   _______,                            _______, _______,          _______, MO(_FN)
    ),
    [_AR] = LAYOUT_ANSI(
        KC_GRV,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,          KC_DEL ,
        TT(_MO),          KC_MUTE, _______, _______, _______, _______, _______, KC_PGUP, KC_UP  , _______, _______, _______, _______, _______,
        _______,          KC_MPLY, KC_MSTP, KC_VOLU, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
        _______,          KC_MPRV, KC_MNXT, KC_VOLD, _______, _______, KC_HOME, KC_END , KC_INS , _______, _______,          _______,
        TG(_AR), _______,          _______,                   _______,                            _______, MO(_F2),          TG(_AR), MO(_FN)
    ),
    [_F2] = LAYOUT_ANSI(
        _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, MO(_FN)
    ),
    [_AH] = LAYOUT_ANSI(
    	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    	_______, _______,          _______,                   _______,      ALGR_T(KC_LEFT), RGUI_T(KC_DOWN), LT(_AR, KC_UP), LT(_FN, KC_RGHT)
    ),
    [_MO] = LAYOUT_ANSI(
        TG(_MO), _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______, _______, _______,          KC_BSPC,
        _______,          KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, _______, KC_WH_D, KC_MS_U, KC_WH_L, KC_WH_R, _______, _______, _______,
        TG(_MO),          KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL2, _______, _______,
        _______,          KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,          _______,
        _______, KC_KP_0,          KC_PDOT,                   KC_ACL1,                            KC_ACL0, _______,          _______, MO(_FN)
    ),
    [_FN] = LAYOUT_ANSI(
        KC_GRV,  DF(_QW), DF(_CM), TG(_AT), TG(_S1), TG(_AH), _______, _______, _______, _______, _______, _______, _______,          KC_DEL ,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET  ,
        KC_CAPS,          RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, KC_INS , KC_HOME, KC_PGUP, _______,
        _______,          _______, _______, _______, _______, _______, TG_NKRO, _______, KC_DEL , KC_END , KC_PGDN,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
    ),

    // [XXX] = LAYOUT_ANSI(
    // 	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    // 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // 	_______, _______,          _______,                   _______,                            _______, _______,          _______, MO(_FN)
    // ),
};

void rgb_matrix_layer_helper(uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    uint8_t  this_led   = host_keyboard_leds();
    if (!g_suspend_state) {
        switch (biton32(layer_state)) {
            case _AR:
                rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false);
                break;
            case _F2:
                rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false);
                break;
            case _MO:
                rgb_matrix_layer_helper(0x00, 0x00, 0xFF, false);
                break;
            // Annoying: turn off lights = stuck with these colors.
            // Can't find a proper way to disable them afterward
            // case _FN:
            //     rgb_matrix_layer_helper(0xFF, 0xFF, 0x00, false);
            //     break;
        }
    }
    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
    }
}

void matrix_init_user(void) {
    // user initialization
}

void matrix_scan_user(void) {
    // user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
