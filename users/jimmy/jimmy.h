#pragma once

#include "quantum.h"

extern keymap_config_t keymap_config;

// Define layer names
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

// NOT SURE WHY the other keymaps don't use the layer anymore
enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST
};

#define KC_ KC_TRNS
#define KC_RST RESET
#define KC_LOWR MO(_LOWER)
#define KC_RASE MO(_RAISE)
//define modifiers
#define KC_ESCC MT(MOD_LCTL, KC_ESC)
#define KC_X1 LOWER
#define KC_X2 RAISE