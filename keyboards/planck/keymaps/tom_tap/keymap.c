// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// Define layer names here:

enum{
  _QWERTY=0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TOMLAYER,
  _SWAPPER,

};
enum{
    TD_ESC_TAB=0
};

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define MLAYER MO(_TOMLAYER)
//#define M_BL 5
#define ALFRED LGUI(KC_F1)
#define TERMINAL LALT(KC_F1)
#define DASH LGUI(LALT(KC_F1))
// #define SWAPPER MO(_SWAPPER)
#define PREV_TAB RGUI(S(KC_LBRC))
#define NEXT_TAB RGUI(S(KC_RBRC))
#define TAB_IN RGUI(KC_RBRC)
#define TAB_OUT RGUI(KC_LBRC)

// comment


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Space cadet shift-space
#define SP_SFT SFT_T(KC_SPC)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = {
{ TD(TD_ESC_TAB) , KC_Q   , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P    , KC_ENT}  ,
{ KC_LCTL , KC_A   , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT} ,
{KC_LSFT   , KC_Z   , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_LALT} ,
{LT(_TOMLAYER,KC_ESC) , KC_ESC , KC_BSPC , KC_LGUI , LOWER  , KC_SPC , KC_SPC, RAISE, KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT}
}   ,


[_LOWER] = {
{KC_GRV , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN , KC_BSLS}    ,
{_______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS    , KC_PLUS    , KC_LCBR , KC_RCBR , _______}    ,
{_______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_NUHS) , S(KC_NUBS) , TAB_OUT , TAB_IN  , _______} ,
{_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , _______    , _______ , _______ , _______}
}        ,

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = {
{KC_TILD  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_PIPE}  ,
{_______  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , _______ }  ,
{_______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_NUHS , KC_NUBS , LGUI(LSFT(KC_LBRC)) , LGUI(LSFT(KC_RBRC)) , _______} ,
{_______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    , _______    , _______ , _______ , _______}
}        ,


[_TOMLAYER] = {
{ _______ , DASH  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_BSPC} ,
{ _______ , ALFRED   , _______ , _______ , _______ , _______ , KC_BSPC , _______ , _______ , _______ , _______ , _______} ,
{ _______ , TERMINAL , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_VOLD , KC_VOLU , _______} ,
{_______  , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______}
}         ,

[_ADJUST] = {
{_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
{_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, _______, QWERTY,  _______,_______, _______,  _______},
{_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {

};

const qk_tap_dance_action_t tap_dance_actions[] = {
[TD_ESC_TAB]= ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_ESC)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case _QWERTY:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          break;
        case _LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case _RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {

}


