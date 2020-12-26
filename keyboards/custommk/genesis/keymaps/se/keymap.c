/* Copyright 2020 customMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum keyboard_layers {
    _NP,  // numpad
    _MO,  // mouse
    _FN,  // rgb and such
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_NP] = LAYOUT_numpad_5x4(
            MO(_FN) ,  KC_PSLS ,  KC_PAST , KC_PMNS ,
            KC_P7   ,  KC_P8   ,  KC_P9   ,
            KC_P4   ,  KC_P5   ,  KC_P6   , KC_PPLS ,
            KC_P1   ,  KC_P2   ,  KC_P3   ,
            KC_P0   ,             KC_PDOT , KC_ENT
    ),
    [_MO] = LAYOUT_numpad_5x4(
            _______ , _______ , KC_WH_L , KC_WH_R ,
            _______ , KC_MS_U , _______ ,
            KC_MS_L , _______ , KC_MS_R , KC_WH_D ,
            KC_ACL1 , KC_MS_D , KC_BTN3 ,
            KC_BTN1 ,           KC_BTN2 , KC_WH_U
    ),

    [_FN] = LAYOUT_numpad_5x4(
            _______ , KC_NLCK , _______ , RGB_RMOD,
            RGB_HUI , RGB_SAI , RGB_VAI ,
            RGB_HUD , RGB_SAD , RGB_VAD , RGB_MOD ,
            TG(_MO) , _______ , RGB_SPI ,
            _______ ,           RGB_SPD , RGB_TOG
    ) ,

    // [__] = LAYOUT_numpad_5x4(
    //      _______ , _______ , _______ , _______ ,
    //      _______ , _______ , _______ ,
    //      _______ , _______ , _______ , _______ ,
    //      _______ , _______ , _______ ,
    //      _______ ,           _______ , _______
    // ),

};

