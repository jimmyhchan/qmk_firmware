#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "split_util.h"
#include "matrix.h"
#include "keyboard.h"
#include "config.h"

#include "i2c.h"

volatile uint8_t handOffset = 0x00;

static void setup_handedness(void) {

  uint8_t eehand = eeprom_read_byte(EECONFIG_HANDEDNESS);
  // for compatiblity with the original lets split
  // the hands are numbered left(1), right(0) third(2)
  if ( eehand == 0x00) {
    handOffset = 0x01;
  } else if (eehand == 0x01) {
    handOffset = 0x00;
  }

}

static void keyboard_master_setup(void) {
  i2c_master_init();
}

static void keyboard_slave_setup(void) {
  i2c_slave_init((SLAVE_I2C_ADDRESS + handOffset)<<1);
}

bool has_usb(void) {
   USBCON |= (1 << OTGPADE); //enables VBUS pad
   _delay_us(5);
   return (USBSTA & (1<<VBUS));  //checks state of VBUS
}

void split_keyboard_setup(void) {
   setup_handedness();

   if (has_usb()) {
      keyboard_master_setup();
   } else {
      keyboard_slave_setup();
   }
   sei();
}

void keyboard_slave_loop(void) {
   matrix_init();

   while (1) {
      matrix_slave_scan();
   }
}

// this code runs before the usb and keyboard is initialized
void matrix_setup(void) {
    split_keyboard_setup();

    if (!has_usb()) {
        keyboard_slave_loop();
    }
}
