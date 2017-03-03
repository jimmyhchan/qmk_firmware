#ifndef SPLIT_KEYBOARD_UTIL_H
#define SPLIT_KEYBOARD_UTIL_H

#include <stdbool.h>

#define EECONFIG_BOOTMAGIC_END      (uint8_t *)10
#define EECONFIG_HANDEDNESS         EECONFIG_BOOTMAGIC_END
#define SLAVE_I2C_ADDRESS           0x19 // 7-bit address
#define NUM_HANDS                   3 // count of all slaves and the master

extern volatile uint8_t handOffset;

// slave version of matix scan, defined in matrix.c
void matrix_slave_scan(void);

void split_keyboard_setup(void);
bool has_usb(void);
void keyboard_slave_loop(void);

#endif
