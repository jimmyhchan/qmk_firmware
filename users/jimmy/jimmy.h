#pragma once

#include "quantum.h"

extern keymap_config_t keymap_config;

// Define layer names
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 3
#define _RAISE 4
#define _NAV 5
#define _ADJUST 6

// NOT SURE WHY the other keymaps don't use the layer anymore
enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  NAV,
  ADJUST
};
#define KC_ KC_TRNS
#define KC_RST RESET
//define modifiers
#define KC_ALTL MT(MOD_LALT, KC_LEFT)
#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define KC_X1 MO(_LOWER)
#define KC_X2 MO(_RAISE)
#define KC_X3 MO(_NAV)
#define KC_QOX3 LT(_NAV, KC_QUOT)
#define KC_TGX3 TG(_NAV)
#define KC_OSFT OSM(MOD_LSFT)

#define KC_GUIA A(KC_LGUI)
#define KC_GUIS S(KC_LGUI)
#define KC_SFTA S(KC_LALT)