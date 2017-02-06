#! /usr/bin/env bash

# disconnect the TRRS. Plug the USB into the left hand
# then run this script

# Set EE_HANDS in your config.h and remove any I2C_MASTER_*
# build another hex file and flash it to both sides

# CHANGE ME make sure you figure out what port your device is on
# PORT=/dev/tty.usbmodem1421
PORT=/dev/tty.usbmodem1411

sleep 3; avrdude -v -patmega32u4 -cavr109 -P$PORT -Ueeprom:w:eeprom-lefthand.eep

