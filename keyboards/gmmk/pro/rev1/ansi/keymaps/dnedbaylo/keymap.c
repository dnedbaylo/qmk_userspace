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
};

enum custom_keycodes {
    SLKPONE = SAFE_RANGE,   // Slack: :+1:<Enter>
    STR_TLD,                // ~
    STR_GRV,                // `
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0,
    LED_MINS,
    LED_EQL,
};

#define MY_COLOR_RGB_PURPLE 0xC1, 0xB3, 0xD7
#define MY_COLOR_RGB_BLUE 0x6F, 0xB7, 0xD6

#define CS_F10 LCTL(LSFT(KC_F10))
#define CS_F5  LCTL(LSFT(KC_F5))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
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
        KC_LCTL,  KC_LGUI, KC_LALT,                            LCTL_T(KC_SPC),                     KC_RALT,  MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function 1 layout
    [_FN1] = LAYOUT(
//      ESC       F1       F2       F3       F4       F5       F6       F7       F8       F9       F10       F11      F12        Ins               Rotary
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,   KC_SYSREQ,        _______,
//      `~        1        2        3        4        5        6        7        8        9        0         -        =          Backspace         Home
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,    KC_DEL,           _______,
//      Tab       Q        W        E        R        T        Y        U        I        O        P         [        ]          \                 PgUp
        _______,  _______, KC_HOME, KC_END,  CS_F5,   CS_F10,  _______, _______, _______, _______, KC_MPLY,  _______, _______,   RESET,            _______,
//      Fn1       A        S        D        F        G        H        J        K        L        ;         '                   Enter             PgDown
        _______,  _______, _______, KC_DEL,  _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  _______,            _______,          _______,
//      LShift             Z        X        C        V        B        N        M        ,        .         /                   RShift   Up       End
        _______,           _______, STR_TLD, STR_GRV, _______, _______, KC_MNXT, _______, _______, _______,  _______,            _______, _______, _______,
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
        _______,  _______, KC_HOME, KC_END,  _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,    RESET,            _______,
//      Fn1       A        S        D        F        G        H        J        K        L        ;        '                    Enter             PgDown
        _______,  _______, _______, KC_DEL,  DF(_GTA),DF(_WIN),DF(_WR), _______, _______, _______, _______, _______,             _______,          _______,
//      LShift             Z        X        C        V        B        N        M        ,        .        /                    RShift   Up       End
        _______,           _______, _______, _______, _______, _______, KC_MNXT, _______, _______, _______, _______,             _______, _______, _______,
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
        _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______,  SLKPONE, _______, _______,  RESET,            _______,
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
        _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, KC_SYSREQ,        _______,
//      `~        1        2        3        4        5          6        7        8        9        0        -        =        Backspace         Home
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           _______,
//      Tab       Q        W        E        R        T          Y        U        I        O        P        [        ]        \                 PgUp
        _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, RESET,            _______,
//      Fn1       A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______,  _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift             Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,           _______, STR_TLD, STR_GRV, _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl     LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______,  _______, _______,                              _______,                            _______, _______, _______, _______, _______, _______
    ),

    // GTA layout
    [_GTA] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10           F11           F12      Ins               Rotary
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,       KC_F12,  KC_LOCK,          KC_MUTE,
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
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, RESET,            _______,
//      Fn1      A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______, _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift            Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,          _______, _______, _______, _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl    LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______, _______, _______,                              KC_LOCK,                            _______, KC_LGUI, _______, _______, _______, _______
    ),

    // Witcher layout
    [_WR] = LAYOUT(
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10           F11           F12      Ins               Rotary
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,       KC_F11,       KC_F12,  KC_LOCK,          KC_MUTE,
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
        _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______, _______, RESET,            _______,
//      Fn1      A        S        D        F        G          H        J        K        L        ;        '                 Enter             PgDown
        _______, _______, _______, KC_DEL,  _______, DF(_BASE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,
//      LShift            Z        X        C        V          B        N        M        ,        .        /                 RShift   Up       End
        _______,          _______, _______, _______, _______,   _______, KC_MNXT, _______, _______, _______, _______,          _______, _______, _______,
//      LCtrl    LWin     LAlt                                  Space                               Fn2      RAlt     Fn3      Left     Down     Right
        _______, _______, _______,                              KC_LOCK,                            _______, KC_LGUI, _______, _______, _______, _______
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_SPC):
            return TAPPING_TERM + 2000;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_SPC):
            return true;
        default:
            return false;
    }
}

#ifdef RGB_MATRIX_ENABLE

int rgb_current_layer = -1;

#define COLOR_HSV_PURPLE      191, 255, 128
#define COLOR_HSV_BLUE        170, 255, 128
#define COLOR_HSV_GREEN       85, 255, 128
#define COLOR_HSV_RED         0, 255, 128 


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
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
        }
    }
}

#endif // RGB_MATRIX_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SLKPONE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)"\\"SS_UP(X_LSFT)SS_UP(X_LCTL)":+1:"SS_DELAY(250)SS_TAP(X_ENT));
        }         
        break;
    case STR_GRV:
        if (record->event.pressed) {
            SEND_STRING("`");
        }
        break;
    case STR_TLD:
        if (record->event.pressed) {
            SEND_STRING("~");
        }
        break;
    }

    return true;
};
