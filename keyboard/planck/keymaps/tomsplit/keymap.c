// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _PLOVER 5
#define _ADJUST 16
#define _TOMLAYER 10


// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define COLEMAK M(_COLEMAK)
#define DVORAK M(_DVORAK)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)
#define MLAYER MO(_TOMLAYER)
#define M_BL 5
#define PLOVER M(12)
#define EXT_PLV M(13)
#define TOG_OUT M(14)
#define ALFRED LGUI(KC_F1)
#define TERMINAL LALT(KC_F1)


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define SP_SFT SFT_T(KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,     KC_ENT, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  { KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_LCTL,    KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
  { KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,    KC_LALT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {MLAYER,   KC_ESC,  KC_LALT, KC_LGUI, LT(_LOWER, KC_SPC), SP_SFT,     SP_SFT,  LT(_RAISE, KC_SPC),   KC_LCTL, KC_LGUI, KC_LGUI,  MLAYER}
},


[_TOMLAYER] = {
  { KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,     KC_ENT,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  { ALFRED,    KC_S,    KC_D,    KC_F,    KC_G,  KC_LCTL,    KC_BSPC, KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_SCLN},
  { TERMINAL,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT,    KC_LALT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH},
  {_______,   _______,  _______, _______, _______, _______,  _______,  _______, _______, _______, _______,   _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
{ KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC  , KC_TILD , KC_BSPC , KC_CIRC, KC_AMPR    , KC_ASTR    , KC_LPRN , KC_RPRN} ,
{ KC_F1  , KC_F2   , KC_F3   , KC_F4   , KC_F5    , KC_F6  , KC_PIPE , _______  , KC_UNDS    , KC_PLUS    , KC_LCBR , KC_RCBR} ,
{ KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11   , KC_F12 , KC_QUOT, KC_QUOT, S(KC_NUHS) , S(KC_NUBS) , _______ , KC_NUHS} ,
{_______  , _______ , _______ , _______ , _______  , _______ , _______ , _______, _______  , KC_VOLD    , KC_VOLU , KC_MPLY}
}         ,

/* Raise
 * 
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
{  KC_1  , KC_2    , KC_3    , KC_4    , KC_5    , KC_GRV  , KC_BSPC    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0  }  ,
{  KC_F1 , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_BSLS    , _______ , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC} ,
{ KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , S(KC_QUOT) , S(KC_QUOT) , KC_NUHS , KC_NUBS , KC_VOLD , KC_VOLU} ,
{_______ , _______ , _______ , _______ , _______ , _______ , _______    , _______ , _______ , _______ , _______ , _______}
}        ,






/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

const uint16_t PROGMEM fn_actions[] = {

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
            #ifdef AUDIO_ENABLE
              PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
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
