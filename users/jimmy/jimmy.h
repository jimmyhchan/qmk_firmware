#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Define layer names
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

enum userspace_custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
//define modifiers
#define KC_X0 MT(MOD_LCTL, KC_ESC)
#define KC_X1 LOWER
#define KC_X2 RAISE