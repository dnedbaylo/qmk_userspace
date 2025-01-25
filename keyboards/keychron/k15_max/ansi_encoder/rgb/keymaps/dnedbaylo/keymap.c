/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    W_B,
    W_FN,
    MAC1,
    MAC2,
    MAC3
};
// clang-format off

// Keys help:
// ROT_BUT - rotary control push button
// MC_1, MC_2 etc - macros keys

// COMMAND+RIGHT - for Mac "End"
#define CM_RGHT LCMD(KC_RGHT)
// COMMAND+LEFT - for Mac "Home"
#define CM_LEFT LCMD(KC_LEFT)
// CTRL+SHIFT+F10
#define CS_F10  LCTL(LSFT(KC_F10))
// CTRL+SHIFT+F5
#define CS_F5   LCTL(LSFT(KC_F5))
// Shift + CMD + Backslack - for Slack reaction
#define SLREACT LGUI(LSFT(KC_BSLS))

// MOD-TAP:
// https://docs.qmk.fm/mod_tap
// CTRL when hold, SPACE when tap
#define CTL_SPC LCTL_T(KC_SPC)

// Activate layer MAC1 + Ctrl modifier
#define MAC1_CTL LM(MAC1, MOD_LCTL)

// Activate layer MAC_FN
#define L_MAC_FN MO(MAC_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_MUTE,  KC_ESC,     KC_F1,    KC_F2,    KC_MCTRL, KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_MPLY, KC_MNXT,  KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
//      MC_1,     KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        L_MAC_FN, KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
//      MC_2,     KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_2,     KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
//      MC_3,     KC_CAPS,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_3,     KC_CAPS,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
//      MC_4,     KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_4,     KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
//      MC_5,     KC_LCTL,    KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,            KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        MC_5,     KC_LCTL,    KC_LOPTN,           KC_LCMMD, CTL_SPC,  MO(MAC3),                     KC_SPC,            KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_F3,    KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_F8,   KC_F9,     KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),


//    [MAC_FN] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
//        RGB_TOG,  _______,    KC_BRID,  KC_BRIU,  KC_F3,    KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_F8,    KC_F9,   KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
//      MC_1,     KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
//        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,            _______,
//      MC_2,     KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
//        _______,  _______,    _______,  CM_LEFT,  CM_RGHT,  CS_F5,    CS_F10,   _______,  _______,  CHG_INP,  _______, _______,  _______,  _______,  SLREACT,            _______,
//      MC_3,     KC_CAPS,    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
//        _______,  _______,    _______,  _______,  KC_DEL,   _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT, _______,  _______,            _______,            KC_END,
//      MC_4,     KC_LSFT,              KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
//        _______,  _______,              _______,  KC_TILD,  KC_GRV,   _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,
//      MC_5,     KC_LCTL,    KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,            KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
//        _______,  _______,    _______,            _______,  MAC1_CTL, _______,                      _______,           _______,  _______,            _______,  _______,  _______),

    [W_B] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_1,     KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_3,     MO(W_FN), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        MC_5,     KC_LCTL,  KC_LWIN,            KC_LALT,  CTL_SPC,  MO(W_FN),                     KC_SPC,             KC_RALT,  KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [W_FN] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,            _______,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  _______,  _______,  KC_HOME,  KC_END,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  _______,  _______,  _______,  KC_DEL,   _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,            KC_END,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  _______,            _______,  KC_TILD,  KC_GRV,   _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [MAC1] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            _______,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            _______,            _______,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  _______,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  _______,  _______,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [MAC2] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),

    [MAC3] = LAYOUT_ansi_90(
//      ROT_BUT,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,   KC_F11, KC_F12,     _______,            _______,
//      MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,    KC_9,      KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  _______,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//      MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,    KC_L,      KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            KC_END,
//      MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  _______,            _______,  _______,  _______,  _______,  BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
//      MC_5,     KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,   FUNC,                         KC_SPC,             KC_RCMMD, KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),
        _______,  _______,  _______,            _______,  _______,  _______,                      _______,            _______,  _______,            _______,  _______,  _______),


};

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [MAC_FN]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [W_B]      = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [W_FN]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
        [MAC1]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [MAC2]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [MAC3]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    };
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_SPC:
            return TAPPING_TERM + 1000;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_SPC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

#ifdef RGB_MATRIX_ENABLE

#define COLOR_HSV_PURPLE      191, 255, 255
#define COLOR_HSV_BLUE        170, 255, 255
#define COLOR_HSV_GREEN       85, 255, 255
#define COLOR_HSV_RED         0, 255, 255

int rgb_current_layer = -1;
bool rgb_default_mode_set = false;

void my_set_default_rgb_mode(void){
    rgb_default_mode_set = true;
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(COLOR_HSV_PURPLE);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if(!rgb_default_mode_set){
        my_set_default_rgb_mode();
    }
    int current_default_layer = get_highest_layer(default_layer_state);
    if(rgb_current_layer != current_default_layer){
        my_set_default_rgb_mode();
        rgb_current_layer = current_default_layer;
        switch (rgb_current_layer) {
            case MAC_BASE:
                rgb_matrix_sethsv(COLOR_HSV_PURPLE);
                break;
            case W_B:
                rgb_matrix_sethsv(COLOR_HSV_BLUE);
                break;
            default:
                break;
        }
    }
    return false;
}

#endif // RGB_MATRIX_ENABLE
