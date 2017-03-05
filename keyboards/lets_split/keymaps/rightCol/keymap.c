#include "lets_split.h"
#include "action_layer.h"
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
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------------------------------------------.     ,--------.
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |     |   1    |
 * |-------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * |Esc/ctl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |     |    2   |
 * |-------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * | Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |     |    3   |
 * |-------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * | Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |     |    4   |
 * `-----------------------------------------------------------------------------------'`     |--------|
 *                                                                                            |    5   |
 *                                                                                            |--------|
 *                                                                                            |    6   |
 *                                                                                            `--------'
 */
[_QWERTY] = KEYMAP_EXTRA_RIGHT_COLUMN( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,            KC_1,\
  CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,     KC_2,\
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,            KC_3,\
  ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,            KC_4,\
                                                                                                                         KC_5,\
                                                                                                                         KC_6\
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.     ,--------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |     |   1    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |     |    2   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |     |    3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |     |    4   |
 * `-----------------------------------------------------------------------------------'     |--------|
 *                                                                                           |    5   |
 *                                                                                           |--------|
 *                                                                                           |    6   |
 *                                                                                           `--------'
 */
[_COLEMAK] = KEYMAP_EXTRA_RIGHT_COLUMN(\
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,           KC_1,\
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,           KC_2,\
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,           KC_3,\
  ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,           KC_4,\
                                                                                                                        KC_5,\
                                                                                                                        KC_6\
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.     ,--------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |     |   1    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |     |    2   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |     |    3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |     |    4   |
 * `-----------------------------------------------------------------------------------'     |--------|
 *                                                                                           |    5   |
 *                                                                                           |--------|
 *                                                                                           |    6   |
 *                                                                                           `--------'
 */
[_DVORAK] = KEYMAP_EXTRA_RIGHT_COLUMN(\ 
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,           KC_1,\
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,           KC_2,\
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,           KC_3,\
  ADJUST, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,           KC_4,\
                                                                                                                        KC_5,\
                                                                                                                        KC_6\
),

/* Lower
 * ,-----------------------------------------------------------------------------------.     ,--------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |     |   1    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |     |    2   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |     |    3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |     |    4   |
 * `-----------------------------------------------------------------------------------'     |--------|
 *                                                                                           |    5   |
 *                                                                                           |--------|
 *                                                                                           |    6   |
 *                                                                                           `--------'
 */
[_LOWER] = KEYMAP_EXTRA_RIGHT_COLUMN(\
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,     KC_1,\
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,     KC_2,\
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,     KC_3,\
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY,     KC_4,\
                                                                                                                        KC_5,\
                                                                                                                        KC_6\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.     ,--------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |     |   1    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |     |    2   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |     |    3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |     |    4   |
 * `-----------------------------------------------------------------------------------'     |--------|
 *                                                                                           |    5   |
 *                                                                                           |--------|
 *                                                                                           |    6   |
 *                                                                                           `--------'
 */
[_RAISE] = KEYMAP_EXTRA_RIGHT_COLUMN(\
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,        KC_1,\
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,        KC_2,\
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,        KC_3,\
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,        KC_4,\
                                                                                                                        KC_5,\
                                                                                                                        KC_6\
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.     ,--------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |     |   1    |
 * |------+------+------+------+------+-------------+------+------+------+------+------|     |--------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |     |    2   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|     |--------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |     |    3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|     |--------|
 * |      |      |      |      |      |             |      |      |      |      |      |     |    4   |
 * `-----------------------------------------------------------------------------------'     |--------|
 *                                                                                           |    5   |
 *                                                                                           |--------|
 *                                                                                           |    6   |
 *                                                                                           `--------'
 */
[_ADJUST] = KEYMAP_EXTRA_RIGHT_COLUMN(\
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,           KC_1,\
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______,  _______,          KC_2,\
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,           KC_3,\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_4,\
                                                                                                                        KC_5,\
                                                                                                                        KC_6\
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
