#include "keycodes.h"
#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _LAY1,
  _LAY2,
  _LAY3,
};

#define LAY1 MO(_LAY1)
#define LAY2 MO(_LAY2)
#define LAY3 MO(_LAY3)

// COMMAND+LEFT - for Mac "Home"
#define CMD_LEFT LCMD(KC_LEFT)
// COMMAND+RIGHT - for Mac "End"
#define CMD_RGHT LCMD(KC_RGHT)

// OPT+LEFT - word left
#define OPT_LEFT LOPT(KC_LEFT)
// OPT+RIGHT - word right
#define OPT_RGHT LOPT(KC_RGHT)

/* Template
 * ,-------------1--------2--------3--------4--------5---.                     ,----6--------7--------8--------9-------0-------------.
 * |  ESC   |        |        |        |        |        |                     |        |        |        |        |        | BackSP |
 * |--------+----q---+----w---+----e---+----r---+----t---|                     |----y---+----u---+----i---+----o---+---p----+--------|
 * |  TAB   |        |        |        |        |        |                     |        |        |        |        |        | Enter  |
 * |--------+----a---+----s---+----d---+----f---+----g---|                     |----h---+----j---+----k---+----l---+---;:---+---'"---|
 * |  CAPS  |        |        |        |        |        |--------.   ,--------|        |        |        |        |        |        |
 * |--------+----z---+----x---+----c---+----v---+----b---|        |   |        |----n---+----m---+----,<--+----.>--+---/?---+--------|
 * | LShift |        |        |        |        |        |--------|   |--------|        |        |        |        |        | RShift |
 * `----------------------------------------------------/        /     \        \----------------------------------------------------'
 *                        |  LCtl  |  LOpt  |  LCmd  | /  Space /       \ Space  \ | Layer1 | Layer2 | Layer3 |
 *                        `--------------------------''--------'         '--------''--------------------------'
*/
/*
[_LAY1] = LAYOUT(
// ,---esc------1--------2--------3--------4--------5----.                     ,---6--------7--------8--------9--------0--------bsp--.
// |        |        |        |        |        |        |                     |        |        |        |        |        |        |
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
// |        |        |        |        |        |        |                     |        |        |        |        |        |        |
// |---tab--+---q----+---w----+---e----+---r----+---t----|                     |---y----+---u----+---i----+---o----+---p----+--ent---|
// |        |        |        |        |        |        |                     |        |        |        |        |        |        |
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
// |        |        |        |        |        |        |                     |        |        |        |        |        |        |
// |--caps--+---a----+---s----+---d----+---f----+---g----|                     |---h----+---j----+---k----+---l----+---;:---+---'"---|
// |        |        |        |        |        |        |                     |        |        |        |        |        |        |
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
// |        |        |        |        |        |        |--------.   ,--------|        |        |        |        |        |        |
// |--shft--+---z----+---x----+---c----+---v----+---b----|        |   |        |---n----+---m----+---,<---+---.>---+---/?---+--shft--|
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
// |        |        |        |        |        |        |--------|   |--------|        |        |        |        |        |        |
// `----------------------------------------------------/        /     \        \----------------------------------------------------'
//                        |        |        |        | /        /       \        \ |        |        |        |
                            _______, _______, _______,   _______,         _______,   _______, _______, _______
//                        `--------------------------''--------'         '--------''--------------------------'
),

[LAYOUT_TMPL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                            _______, _______, _______,   _______,         _______,   _______, _______, _______
),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Base layer
  * ,-------------1--------2--------3--------4--------5---.                     ,----6--------7--------8--------9-------0-------------.
  * |  ESC   |    1   |    2   |    3   |    4   |    5   |                     |    6   |    7   |    8   |    9   |   0    | BackSP |
  * |--------+----q---+----w---+----e---+----r---+----t---|                     |----y---+----u---+----i---+----o---+---p----+--------|
  * |  TAB   |    Q   |    W   |    E   |    R   |    T   |                     |    Y   |    U   |    I   |    O   |   P    | Enter  |
  * |--------+----a---+----s---+----d---+----f---+----g---|                     |----h---+----j---+----k---+----l---+---;:---+---'"---|
  * |  CAPS  |    A   |    S   |    D   |    F   |    G   |--------.   ,--------|    H   |    J   |    K   |    L   |   ;    |   '    |
  * |--------+----z---+----x---+----c---+----v---+----b---|   [    |   |   ]    |----n---+----m---+----,<--+----.>--+---/?---+--------|
  * | LShift |    Z   |    X   |    C   |    V   |    B   |--------|   |--------|    N   |    M   |    ,   |    .   |   /    | RShift |
  * `----------------------------------------------------/        /     \        \----------------------------------------------------'
  *                        |  LCtl  |  LOpt  |  LCmd  | /  Space /       \ Space  \ | Layer1 | Layer2 | Layer3 |
  *                        `--------------------------''--------'         '--------''--------------------------'
 */

 [_BASE] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,     KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            KC_LCTL, KC_LALT, KC_LGUI,   KC_SPC,          KC_SPC,    LAY1,    LAY2,    LAY3
),

/* LAYER 1
 * ,--esc--------1--------2--------3--------4--------5---.                     ,----6--------7--------8--------9-------0-------back--.
 * |  ESC   |   F1   |   F2   |   F3   |   F4   |   F5   |                     |   F6   |   F7   |   F8   |   F9   |  F10   |  Del   |
 * |--tab---+----q---+----w---+----e---+----r---+----t---|                     |----y---+----u---+----i---+----o---+---p----+---ent--|
 * |  TAB   |        |CMD_LEFT|CMD_RGHT|        |        |                     |        |        |        |        | PageUp |  Home  |
 * |--caps--+----a---+----s---+----d---+----f---+----g---|                     |----h---+----j---+----k---+----l---+---;:---+---'"---|
 * |  CAPS  |        |        |   DEL  |OPT_RGHT|        |--------.   ,--------|  Left  |  Down  |   Up   |  Right |   -    |  End   |
 * |--shft--+----z---+----x---+----c---+----v---+----b---|   _    |   |   =    |----n---+----m---+----,<--+----.>--+---/?---+--shft--|
 * | LShift |        |        |        |        |OPT_LEFT|--------|   |--------| PageDn |  Left  |  Down  |  Right |   +    | RShift |
 * `----------------------------------------------------/        /     \        \----------------------------------------------------'
 *                        |  LCtl  |  LOpt  |  LCmd  | /  Space /       \ Space  \ |        |        |        |
 *                        `--------------------------''--------'         '--------''--------------------------'                        */
[_LAY1] = LAYOUT(
/* ,------------1--------2--------3--------4--------5----.                     ,---6--------7--------8--------9--------0-------------.
 * |        |        |        |        |        |        |                     |        |        |        |        |        |        | */
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
/* |        |        |        |        |        |        |                     |        |        |        |        |        |        | */
/* |--------+---q----+---w----+---e----+---r----+---t----|                     |---y----+---u----+---i----+---o----+---p----+--ent---|
 * |        |        |        |        |        |        |                     |        |        |        |        |        |        | */
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_HOME,
/* |        |        |        |        |        |        |                     |        |        |        |        |        |        | */
/* |--------+---a----+---s----+---d----+---f----+---g----|                     |---h----+---j----+---k----+---l----+---;:---+---'"---|
 * |        |        |        |        |        |        |                     |        |        |        |        |        |        | */
    _______, _______, _______, _______, _______, _______,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_END,
/* |        |        |        |        |        |        |--------.   ,--------|        |        |        |        |        |        |
 * |--------+---z----+---x----+---c----+---v----+---b----|        |   |        |---n----+---m----+---,<---+---.>---+---/?---+--------| */
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
/* |        |        |        |        |        |        |--------|   |--------|        |        |        |        |        |        |
 * `----------------------------------------------------/        /     \        \----------------------------------------------------'
 *                        |        |        |        | /        /       \        \ |        |        |        |                        */
                           _______, _______, _______,   _______,         _______,   _______, _______, _______
/*                        `--------------------------''--------'         '--------''--------------------------'                        */
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
