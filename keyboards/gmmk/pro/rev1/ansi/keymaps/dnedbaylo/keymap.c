/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// LAYERS
enum custom_user_layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3,
    _WIN,  // Windows
    _WIN_FN1,
    _GTA,
    _GTA_FN1,
    _WR,   // Witcher
    _WR_FN1,
    _MB,  // Mac base
    _MD,  // Mac Midi
    _MD1,  // Mac FN 2
};

enum custom_keycodes {
    MIDI_Q = SAFE_RANGE,
    MIDI_A,
    MIDI_Z,
    MIDI_W,
    MIDI_S,
    MIDI_X,
    MIDI_E,
    MIDI_D,
    MIDI_C,
    MIDI_R,
    MIDI_F,
    MIDI_V,
    MIDI_T,
    MIDI_G,
    MIDI_B,
    MIDI_Y,
    MIDI_H,
    MIDI_N,
    MIDI_U,
    MIDI_J,
    MIDI_M,
    MIDI_I,
    MIDI_K,
    MIDI_O,
    MIDI_L,
    MIDI_P,
    MIDI_GRV,
    MIDI_PREV,
    MIDI_NEXT,
    MIDI_LEFT,
    MIDI_RGHT,
    MIDI_HOME,
};

#define MIDI_LAST_KEY MIDI_P

//
// COMMAND+RIGHT - for Mac "End"
#define CM_RGHT LCMD(KC_RGHT)
// COMMAND+LEFT - for Mac "Home"
#define CM_LEFT LCMD(KC_LEFT)

// CTRL+SHIFT+F10
#define CS_F10 LCTL(LSFT(KC_F10))
// CTRL+SHIFT+F5
#define CS_F5  LCTL(LSFT(KC_F5))

// MOD-TAP:
// https://docs.qmk.fm/mod_tap
// CTRL when hold, SPACE when tap
#define CTL_SPC LCTL_T(KC_SPC)

extern MidiDevice midi_device;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.

    // Base layout
    [_BASE] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11       F12       Ins               Rotary
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,           KC_MUTE,
//      `~        1        2        3        4        5        6        7        8        9        0         -         =         Backspace         Home
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_HOME,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [         ]         \                 PgUp
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
//      Fn1       A        S        D        F        G        H        J        K        L        ;         '                   Enter             PgDown
        MO(_FN1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGDN,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                   RShift   Up       End
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_END,
//      LCtrl     LWin     LAlt                                Space                               RAlt      Fn2       Fn3       Left     Down     Right
        KC_LCTL,  KC_LGUI, KC_LALT,                            CTL_SPC,                            KC_RALT,  MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function 1 layout
    [_FN1] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11      F12        Ins               Rotary
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,   KC_SYRQ,          _______,
//      `~        1        2        3        4        5        6        7        8        9        0         -        =          Backspace         Home
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,    KC_DEL,           _______,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [        ]          \                 PgUp
        _______,  _______, KC_HOME, KC_END,  CS_F5,   CS_F10,  _______, _______, _______, _______, KC_MPLY,  _______, _______,   QK_BOOT,          _______,
//      Fn1       A        S        D        F        G        H        J        K        L        ;         '                   Enter             PgDown
        _______,  _______, _______, KC_DEL,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  _______,            _______,          _______,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                   RShift   Up       End
        _______,           _______, KC_TILD, KC_GRV,  _______, _______, KC_MNXT, _______, _______, _______,  _______,            _______, _______, _______,
//      LCtrl     LWin     LAlt                                Space                               RAlt      Fn2      Fn3        Left     Down     Right
        _______,  _______, _______,                            KC_SPC,                             _______,  _______, _______,   _______, _______, _______
    ),

    // Function 2 layout
    [_FN2] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12         Ins               Rotary
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,          _______,
//      `~        1        2        3        4        5        6        7        8        9        0        -        =           Backspace         Home
        KC_GRV,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,          _______,
//      Tab       Q        W        E        R        T        Y        U        I        O        P        [        ]           \                 PgUp
        _______,  _______, KC_HOME, KC_END,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,    QK_BOOT,          _______,
//      Fn1       A        S        D        F        G        H        J        K        L        ;        '                    Enter             PgDown
        _______,  _______, _______, KC_DEL,  DF(_GTA),DF(_WIN),DF(_WR), _______, _______, _______, _______, _______,             _______,          _______,
//      LShift             Z        X        C        V        B        N        M        ,        .        /                    RShift   Up       End
        _______,           _______, _______, _______, _______, _______, KC_MNXT, DF(_MB), _______, _______, _______,             _______, _______, _______,
//      LCtrl     LWin     LAlt                                Space                               RAlt     FN2      Fn3         Left     Down     Right
        _______,  _______, _______,                            KC_SPC,                             _______, _______, _______,    _______, _______, _______
    ),

    // Function 3 layout: Shortcuts and RGB
    // RGB_TOG - toggle RGB on/off
    // RGB_M_P -  RGB Mode: static (no animation)
    // RGB_M_B -  RGB Mode: breathing animation
    // RGB_M_R -  RGB Mode: Full gradient scrolling left to right (uses the RGB_MATRIX_CYCLE_LEFT_RIGHT mode)
    // RGB_M_SW - RGB Mode: Full gradient spinning pinwheel around center of keyboard (uses RGB_MATRIX_CYCLE_PINWHEEL mode)
    //
    // RGB control:
    // RGB_HUI - Increase hue, decrease hue when Shift is held
    // RGB_SAI - Increase saturation, decrease saturation when Shift is held
    // RGB_VAI - Increase value (brightness), decrease value when Shift is held
    // RGB_SPI - Increase effect speed (does not support eeprom yet), decrease speed when Shift is held
    // RGB_MOD - Cycle through modes, reverse direction when Shift is held
    [_FN3] = LAYOUT(
//      ESC       F1       F2       F3       F4        F5       F6       F7       F8       F9        F10      F11      F12       Ins               Rotary
        RGB_TOG,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,  _______, _______, _______,  _______,          _______,
//      `~        1        2        3        4         5        6        7        8        9         0        -        =         Backspace         Home
        _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______,  _______,          _______,
//      Tab       Q        W        E        R         T        Y        U        I        O         P        [        ]         \                 PgUp
        _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______,  QK_BOOT,          _______,
//      Fn1       A        S        D        F         G        H        J        K        L         ;        '                  Enter             PgDown
        _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______,           _______,          _______,
//      LShift             Z        X        C         V        B        N        M        ,         .        /                  RShift   Up       End
        _______,           _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______,           _______, _______, _______,
//      LCtrl     LWin     LAlt                                 Space                                Fn2      RAlt     Fn3       Left     Down     Right
        _______,  _______, _______,                             _______,                             _______, _______, _______,  _______, _______, _______
    ),

    // Windows layout
    [_WIN] = LAYOUT(
//      ESC           F1       F2       F3       F4       F5       F6       F7       F8       F9       F10           F11           F12      Ins               Rotary
        KC_ESC,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,       KC_F12,  KC_INS,           KC_MUTE,
//      `~            1        2        3        4        5        6        7        8        9        0             -             =        Backspace         Home
        KC_GRV,       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_MINS,      KC_EQL,  KC_BSPC,          KC_HOME,
//      Tab           Q        W        E        R        T        Y        U        I        O        P             [             ]        \                 PgUp
        KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_LBRC,      KC_RBRC, KC_BSLS,          KC_PGUP,
//      Fn1           A        S        D        F        G        H        J        K        L        ;             '                      Enter             PgDown
        MO(_WIN_FN1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      KC_QUOT,               KC_ENT,           KC_PGDN,
//      LShift                 Z        X        C        V        B        N        M        ,        .             /                      RShift   Up       End
        KC_LSFT,               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       KC_SLSH,               KC_RSFT, KC_UP,   KC_END,
//      LCtrl         LWin     LAlt                                Space                               Fn2           RAlt          Fn3      Left     Down     Right
        KC_LCTL,      KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT,      MO(_WIN_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Windows Fn layout
    [_WIN_FN1] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5         F6       F7       F8       F9       F10      F11      F12      Ins               Rotary
        _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, KC_SYRQ,          _______,
//      `~        1        2        3        4        5          6        7        8        9        0        -        =        Backspace         Home
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
//      Tab       Q        W        E        R        T          Y        U        I        O        P        [        ]        \                 PgUp
        _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, QK_BOOT,          _______,
//      Fn1       A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______,  _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift             Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,           _______, KC_TILD, KC_GRV,  _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl     LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______,  _______, _______,                              _______,                            _______, _______, _______, _______, _______, _______
    ),

    // GTA layout
    [_GTA] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10           F11           F12      Ins               Rotary
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,       KC_F12,  QK_LOCK,          KC_MUTE,
//      `~       1        2        3        4        5        6        7        8        9        0             -             =        Backspace         Home
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_MINS,      KC_EQL,  KC_BSPC,          KC_HOME,
//      Tab      Q        W        E        R        T        Y        U        I        O        P             [             ]        \                 PgUp
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_LBRC,      KC_RBRC, KC_BSLS,          KC_PGUP,
//      Fn1      A        S        D        F        G        H        J        K        L        ;             '                      Enter             PgDown
        KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      KC_QUOT,               KC_ENT,           KC_PGDN,
//      LShift            Z        X        C        V        B        N        M        ,        .             /                      RShift   Up       End
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       KC_SLSH,               KC_CAPS, KC_UP,   KC_END,
//      LCtrl    LWin     LAlt                                Space                               Fn2           RAlt          Fn3      Left     Down     Right
        KC_LCTL, KC_LCTL, KC_LSFT,                            KC_SPC,                             KC_LALT,      MO(_GTA_FN1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // GTA Fn layout
    [_GTA_FN1] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5         F6       F7       F8       F9       F10      F11      F12      Ins               Rotary
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,          _______,
//      `~       1        2        3        4        5          6        7        8        9        0        -        =        Backspace         Home
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
//      Tab      Q        W        E        R        T          Y        U        I        O        P        [        ]        \                 PgUp
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, QK_BOOT,          _______,
//      Fn1      A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______, _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift            Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,          _______, _______, _______, _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl    LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______, _______, _______,                              QK_LOCK,                            _______, KC_LGUI, _______, _______, _______, _______
    ),

    // Witcher layout
    [_WR] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10           F11           F12      Ins               Rotary
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,       KC_F12,  QK_LOCK,          KC_MUTE,
//      `~       1        2        3        4        5        6        7        8        9        0             -             =        Backspace         Home
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,         KC_MINS,      KC_EQL,  KC_BSPC,          KC_HOME,
//      Tab      Q        W        E        R        T        Y        U        I        O        P             [             ]        \                 PgUp
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,         KC_LBRC,      KC_RBRC, KC_BSLS,          KC_PGUP,
//      Fn1      A        S        D        F        G        H        J        K        L        ;             '                      Enter             PgDown
        KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      KC_QUOT,               KC_ENT,           KC_PGDN,
//      LShift            Z        X        C        V        B        N        M        ,        .             /                      RShift   Up       End
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       KC_SLSH,               KC_CAPS, KC_UP,   KC_END,
//      LCtrl    LWin     LAlt                                Space                               Fn2           RAlt          Fn3      Left     Down     Right
        KC_LCTL, KC_LSFT, KC_LALT,                            KC_SPC,                             KC_LALT,      MO(_WR_FN1),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Witcher Fn layout
    [_WR_FN1] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5         F6       F7       F8       F9       F10      F11      F12      Ins               Rotary
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,          _______,
//      `~       1        2        3        4        5          6        7        8        9        0        -        =        Backspace         Home
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
//      Tab      Q        W        E        R        T          Y        U        I        O        P        [        ]        \                 PgUp
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, QK_BOOT,          _______,
//      Fn1      A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______, _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift            Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,          _______, _______, _______, _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl    LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______, _______, _______,                              QK_LOCK,                            _______, KC_LGUI, _______, _______, _______, _______
    ),

    // Mac Base layout
    [_MB] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11       F12       Ins               Rotary
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,           KC_MUTE,
//      `~        1        2        3        4        5        6        7        8        9        0         -         =         Backspace         Home
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_HOME,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [         ]         \                 PgUp
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
//      Fn1       A        S        D        F        G        H        J        K        L        ;         '                   Enter             PgDown
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGDN,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                   RShift   Up       End
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_END,
//      LCtrl     LWin     LAlt                                Space                               RAlt      Fn2       Fn3       Left     Down     Right
        KC_LCTL,  KC_LOPT, KC_LCMD,                            CTL_SPC,                            KC_ROPT,  DF(_MD),  DF(_BASE), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Mac Midi Base layout
    [_MD] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11       F12       Ins               Rotary
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_INS,           KC_MUTE,
//      `~        1        2        3        4        5        6        7        8        9        0         -         =         Backspace         Home
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_HOME,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [         ]         \                 PgUp
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_PGUP,
//      Fn1       A        S        D        F        G        H        J        K        L        ;         '                   Enter             PgDown
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGDN,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                   RShift   Up       End
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_END,
//      LCtrl     LWin     LAlt                                Space                               RAlt      Fn2       Fn3       Left     Down     Right
        KC_LCTL,  KC_LOPT, KC_LCMD,                            CTL_SPC,                            KC_ROPT,  DF(_MD1), DF(_MB),  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function 1 layout
    [_MD1] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11         F12         Ins                   Rotary
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   LAG(KC_F),   LSG(KC_F),     KC_F,     KC_INS,               MIDI_GRV,
//      `~        1        2        3        4        5        6        7        8        9        0         -           =           Backspace             Home
        MIDI_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     MIDI_GRV,             MIDI_HOME,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [           ]           \                     PgUp
        KC_TAB,   MIDI_Q,  MIDI_W,  MIDI_E,  MIDI_R,  MIDI_T,  MIDI_Y,  MIDI_U,  MIDI_I,  MIDI_O,  MIDI_P,   LCMD(KC_Z), SCMD(KC_Z), KC_BSLS,              KC_PGUP,
//      Caps      A        S        D        F        G        H        J        K        L        ;         '                       Enter                 PgDown
        KC_CAPS,  MIDI_A,  MIDI_S,  MIDI_D,  MIDI_F,  MIDI_G,  MIDI_H,  MIDI_J,  MIDI_K,  MIDI_L,  KC_SCLN,  KC_QUOT,                KC_ENT,               KC_PGDN,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                       RShift     Up         End
        KC_LSFT,           MIDI_Z,  MIDI_X,  MIDI_C,  MIDI_V,  MIDI_B,  MIDI_N,  MIDI_M,  KC_COMM, KC_DOT,   KC_SLSH,                KC_RSFT,   MIDI_PREV, KC_END,
//      LCtrl     LWin     LAlt                                Space                               RAlt      Fn2         Fn3         Left       Down       Right
        KC_LCTL,  KC_LOPT, KC_LCMD,                            KC_SPACE,                           KC_ROPT,  DF(_MD),    KC_NO,      MIDI_LEFT, MIDI_NEXT, MIDI_RGHT
    ),
};





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

#define MIDI_DEFAULT_ENCODER_VALUE 64

static uint8_t current_MIDI_ccNumber = 0;
static uint8_t current_encoder_value = MIDI_DEFAULT_ENCODER_VALUE;

#ifdef RGB_MATRIX_ENABLE

#define COLOR_HSV_PURPLE      191, 255, 128
#define COLOR_HSV_BLUE        170, 255, 128
#define COLOR_HSV_GREEN       85, 255, 128
#define COLOR_HSV_RED         0, 255, 128
#define COLOR_RGB_RED         127, 0, 0
#define COLOR_HSV_MAC         170, 255, 115
#define COLOR_HSV_MACMIDI     146, 250, 196
#define COLOR_HSV_WHITE       0, 0, 170

#define LED_INDEX_FN2 55

int rgb_current_layer = -1;

int midi_CC_number_to_rgb_led[] = {
//  Q   A   Z
    8,  9,  10,
//  W   S   X
    14, 15, 16,
//  E   D   C
    20, 21, 22,
//  R   F   V
    25, 26, 27,
//  T   G   B
    30, 31, 32,
//  Y   H   N
    36, 37, 38,
//  U   J   M
    41, 42, 43,
//  I   K
    46, 47,
//  O   L
    52, 53,
//  P
    58
};

int midi_CC_number_to_rgb_led_size = sizeof(midi_CC_number_to_rgb_led) / sizeof(midi_CC_number_to_rgb_led[0]);


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int current_default_layer = get_highest_layer(default_layer_state);
    if(rgb_current_layer != current_default_layer){
        rgb_current_layer = current_default_layer;
        switch (rgb_current_layer) {
            case _BASE:
                rgb_matrix_sethsv(COLOR_HSV_PURPLE);
                break;
            case _WIN:
                rgb_matrix_sethsv(COLOR_HSV_BLUE);
                break;
            case _GTA:
                rgb_matrix_sethsv(COLOR_HSV_GREEN);
                break;
            case _WR:
                rgb_matrix_sethsv(COLOR_HSV_RED);
                break;
            case _MB:
                rgb_matrix_sethsv(COLOR_HSV_MAC);
                break;
            case _MD:
                rgb_matrix_sethsv(COLOR_HSV_MACMIDI);
                break;
            case _MD1:
                rgb_matrix_sethsv(COLOR_HSV_WHITE);
                break;
        }
    }
    if(current_default_layer == _MD1){
        if (LED_INDEX_FN2 >= led_min && LED_INDEX_FN2 < led_max) {
            rgb_matrix_set_color(LED_INDEX_FN2, COLOR_RGB_RED);
        }
        if(current_MIDI_ccNumber > 0 && (current_MIDI_ccNumber - 1) <= (midi_CC_number_to_rgb_led_size - 1)){
            int led_index = midi_CC_number_to_rgb_led[current_MIDI_ccNumber - 1];
            rgb_matrix_set_color(led_index, COLOR_RGB_RED);
        }
    }

    return false;
}

#endif // RGB_MATRIX_ENABLE

#define MIDI_CHANNEL_1 0
#define MIDI_CHANNEL_2 1

void _encoder_midi_clockwise(void) {
    if(current_encoder_value == 63){
        midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 64);
    }
    midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 65);
    current_encoder_value = 65;
}

void _encoder_midi_counterclockwise(void) {
    if(current_encoder_value == 65){
        midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 64);
    }
    midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 63);
    current_encoder_value = 63;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int current_default_layer = get_highest_layer(default_layer_state);
    if(current_default_layer == _MD1){
        if(keycode >= MIDI_Q && keycode <= MIDI_LAST_KEY){
            if (!record->event.pressed) {
                current_MIDI_ccNumber = 1 + keycode - MIDI_Q;
                midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 64);
            }
            return false;
        }
        if(keycode == MIDI_GRV && current_MIDI_ccNumber){
            if (!record->event.pressed) {
                midi_send_cc(&midi_device, MIDI_CHANNEL_2, current_MIDI_ccNumber, 127);
            }
            return false;
        }
        if(keycode == MIDI_PREV && current_MIDI_ccNumber > 1){
            if (!record->event.pressed) {
                current_MIDI_ccNumber -= 1;
                midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 64);
            }
            return false;
        }
        if(keycode == MIDI_NEXT && current_MIDI_ccNumber && current_MIDI_ccNumber < (1 + MIDI_LAST_KEY - MIDI_Q)){
            if (!record->event.pressed) {
                current_MIDI_ccNumber += 1;
                midi_send_cc(&midi_device, MIDI_CHANNEL_1, current_MIDI_ccNumber, 64);
            }
            return false;
        }
        if(keycode == MIDI_LEFT && current_MIDI_ccNumber){
            if (!record->event.pressed) {
                _encoder_midi_counterclockwise();
            }
            return false;
        }
        if(keycode == MIDI_RGHT && current_MIDI_ccNumber){
            if (!record->event.pressed) {
                _encoder_midi_clockwise();
            }
            return false;
        }
        if(keycode == MIDI_HOME){
            if (!record->event.pressed) {
                midi_send_cc(&midi_device, MIDI_CHANNEL_1, 50, 64);
            }
            return false;
        }
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    int current_default_layer = get_highest_layer(default_layer_state);
    if(current_default_layer == _MD1 && current_MIDI_ccNumber) {
        if(clockwise){
            _encoder_midi_clockwise();
        }
        else {
            _encoder_midi_counterclockwise();
        }
    }
    else if (current_default_layer != _MD1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    current_MIDI_ccNumber = 0;
    current_encoder_value = MIDI_DEFAULT_ENCODER_VALUE;
    return state;
}
