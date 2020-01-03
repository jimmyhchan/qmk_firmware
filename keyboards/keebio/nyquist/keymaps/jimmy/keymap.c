#include "jimmy.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Wants:
// ctrl-esc at capslock ~ ESCC
// . home row arrows (hjkl) ... no toggle layers :( quot x3 and overloaded ctrl/esc key
// mirrored layer triggers
// an option key in the middle 6 key bottom row MT(MOD_LALT, KC_LEFT)
// thumb shift OSM(MOD_LSFT) and enter (M key)
// one key for ⇧⌘ and for ⌥⌘
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , B  ,      J  , L  , U  , Y  ,SCLN,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ESCC, A  , R  , S  , T  , G  ,      K  , N  , E  , I  , O  ,QOX3,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , D  , V  ,      M  , H  ,COMM,DOT ,SLSH,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LCTL,LCTL,LALT,LGUI, X1 ,OSFT,      SPC, X2 ,ALTL,DOWN, UP ,RGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     ESCC, A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QOX3,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,ENT ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LCTL,LCTL,LALT,LGUI, X1 ,OSFT,      SPC, X2 ,ALTL,DOWN, UP ,RGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,  1 ,  2 ,  3 ,LPRN,         ,    ,    ,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       X3,  0 ,  4 ,  5 ,  6 ,LCBR,     BSPC, EQL,MINS,LCBR,RCBR,GRV ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,  7 ,  8 ,  9 ,LBRC,      ENT,UNDS,BSLS,LBRC,RBRC,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,GUIS,    ,    ,         ,    ,GUIA,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,  1 ,  2 ,  3 ,LPRN,         ,    ,    ,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       X3,  0 ,  4 ,  5 ,  6 ,LCBR,     BSPC, EQL,MINS,LCBR,RCBR,GRV ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,  7 ,  8 ,  9 ,LBRC,      ENT,UNDS,BSLS,LBRC,RBRC,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,GUIS,    ,    ,         ,    ,GUIA,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NAV] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    , END,    ,    ,         ,    ,PGUP,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,HOME,    ,    ,    ,    ,     LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,PGDN,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | REST |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | V+   |  V-  |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______ \
  )


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
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
