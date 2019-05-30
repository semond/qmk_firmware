#include QMK_KEYBOARD_H

enum ctrl_layers {
	_BAS,
	_NAV,
	_FNC
};

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout

	// SEM_WHT,  // white
	// SEM_BLU,  // blue
	// SEM_ORA,  // orange
	// SEM_FNK,  // Funky

};

uint16_t sem_color_toggle = 0;

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI, TO(_NAV),MO(_FNC),           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, KC_PPLS, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, TO(_BAS),MO(_FNC),           _______, _______, _______ \
    ),
    [_FNC] = LAYOUT(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        KC_CAPS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, KC_NUBS, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
	[X] = LAYOUT(
	    0,       1,       2,       3,       4,       5,       6,       7,       8,       9,       10,      11,      12,                 13,      14,      15,      \
	    16,      17,      18,      19,      20,      21,      22,      23,      24,      25,      26,      27,      28,      29,        30,      31,      32,      \
	    33,      34,      35,      36,      37,      38,      39,      40,      41,      42,      43,      44,      45,      46,        47,      48,      49,      \
	    50,      51,      52,      53,      54,      55,      56,      57,      58,      59,      60,      61,      62,      \
	    63,      64,      65,      66,      67,      68,      69,      70,      71,      72,      73,      74,                                   75,      \
	    76,      77,      78,                        79,                                 80,      81,      82,      83,                 84,      85,      86      \
	),
    */
};



void rgb_matrix_indicators_user(void)
{
	uint8_t this_led = host_keyboard_leds();

	if (!g_suspend_state && rgb_matrix_config.enable) {
		switch (biton32(layer_state)) {
		case _NAV:
            rgb_matrix_set_color_all(0, 0, 0);

			// if (this_led & (1 << USB_LED_NUM_LOCK)) {
			// 	rgb_matrix_set_color(41, 0xFF, 0x00, 0x00);
			// } else {
			// 	rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
			// }

            // Switch back to base layer
            rgb_matrix_set_color(82, 0, 0xFF, 0);
            // Goto functions
            rgb_matrix_set_color(83, 0xFF, 0, 0);

            // numpad
            // numlock
            if (this_led & (1 << USB_LED_NUM_LOCK)) {
                rgb_matrix_set_color(22, 0x60, 0x00, 0x00);
            } else {
                rgb_matrix_set_color(22, 0xFF, 0x00, 0x00);
            }
            // 7, 8, 9, Slash
            rgb_matrix_set_color(23, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(24, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(25, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(26, 0xFF, 0x40, 0x00);
            // 4, 5, 6, *
			rgb_matrix_set_color(40, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(41, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(42, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(43, 0xFF, 0x40, 0x00);
            // 1, 2, 3, -
			rgb_matrix_set_color(57, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(58, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(59, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(60, 0xFF, 0x40, 0x00);
            // 0, 0, 1, enter, +
			rgb_matrix_set_color(69, 0xFF, 0xFF, 0xFF);
			rgb_matrix_set_color(70, 0xFF, 0xFF, 0xFF);
			rgb_matrix_set_color(71, 0x40, 0x50, 0x40);
			rgb_matrix_set_color(72, 0x00, 0x80, 0xFF);
			rgb_matrix_set_color(73, 0xFF, 0x40, 0x00);

			break;

		case _FNC: {
            rgb_matrix_set_color_all(0, 0, 0);

            // Goto functions
            rgb_matrix_set_color(83, 0xFF, 0, 0);

            // F1..F12 -> F13..F24
            rgb_matrix_set_color(1, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(2, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(3, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(4, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(5, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(6, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(7, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(8, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(9, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(10, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(11, 0xBB, 0xBB, 0xBB);
            rgb_matrix_set_color(12, 0xBB, 0xBB, 0xBB);


            rgb_matrix_set_color(68, 0xFF, 0x00, 0x00); // MD_BOOT
			rgb_matrix_set_color(69, 0xA0, 0x00, 0x60); // TG_NKRO

			rgb_matrix_set_color(32, 0x00, 0x80, 0xFF); // KC_VOLU
			rgb_matrix_set_color(49, 0x00, 0x80, 0xFF); // KC_VOLD

			rgb_matrix_set_color(13, 0xFF, 0x00, 0x00); // KC_MUTE
			rgb_matrix_set_color(30, 0x00, 0xFF, 0x00); // KC_MPLY
			rgb_matrix_set_color(31, 0xFF, 0x00, 0x00); // KC_MSTP

			rgb_matrix_set_color(47, 0xFF, 0x40, 0x00); // KC_MPRV
			rgb_matrix_set_color(48, 0xFF, 0x40, 0x00); // KC_MNXT

            // Caps Lock, USB_LED_CAPS_LOCK
			if (this_led & (1 << USB_LED_CAPS_LOCK)) {
                rgb_matrix_set_color(50, 0xFF, 0xFF, 0xFF);
			} else {
                rgb_matrix_set_color(50, 0x30, 0x30, 0x30);
			}

            // U_T_AUTO et U_T_AGCR
			rgb_matrix_set_color(40, 0xFF, 0x00, 0x00);
			rgb_matrix_set_color(41, 0xFF, 0x00, 0x00);

			// rgb_matrix_set_color(25, 101, 119, 118); // SEM_ORA
			// rgb_matrix_set_color(26, 0x00, 0x00, 0xFF); // SEM_BLU
			// rgb_matrix_set_color(27, 0xBB, 0xBB, 0xBB); // SEM_WHT
			// rgb_matrix_set_color(27, 0xBB, 0x00, 0xBB); // SEM_FNK
		}
		break;
		}
	}
}



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (sem_color_toggle) {
                case 0: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                    sem_color_toggle = 1;
                  }
                  break;
                case 1: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                    sem_color_toggle = 2;
                  }
                  break;
                case 2: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                    sem_color_toggle = 3;
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                    sem_color_toggle = 0;
                } break;
              }
            //   switch (rgb_matrix_get_flags()) {
            //     case LED_FLAG_ALL: {
            //         rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
            //         rgb_matrix_set_color_all(0, 0, 0);
            //       }
            //       break;
            //     case LED_FLAG_KEYLIGHT: {
            //         rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            //         rgb_matrix_set_color_all(0, 0, 0);
            //       }
            //       break;
            //     case LED_FLAG_UNDERGLOW: {
            //         rgb_matrix_set_flags(LED_FLAG_NONE);
            //         rgb_matrix_disable_noeeprom();
            //       }
            //       break;
            //     default: {
            //         rgb_matrix_set_flags(LED_FLAG_ALL);
            //         rgb_matrix_enable_noeeprom();
            //       }
            //       break;
            //   }
            }
            return false;
        // case SEM_BLU:
        //     if (record->event.pressed) {
        //         rgb_matrix_sethsv(222, 79, 78);
        //     }

        //     return false;
        // case SEM_ORA:
        //     if (record->event.pressed) {
        //         rgb_matrix_sethsv(37, 90, 71);
        //     }

        //     return false;
        // case SEM_WHT:
        //     if (record->event.pressed) {
        //         rgb_matrix_sethsv(128, 0, 180);
        //     }

        //     return false;
        default:
            return true; //Process all other keycodes normally
    }
}
