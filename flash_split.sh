#! /usr/bin/env bash

# you can also use the arduino app to help find your serial port

# CHANGE ME make sure you figure out what port your device is on
# PORT=/dev/tty.usbmodem1421
PORT=/dev/tty.usbmodem1411


# see https://nicholaskell.wordpress.com/tag/leonardo/
#  I needed this python script the first time since it refused to enter bootloader
# python reset.py $PORT
# sleep 3
avrdude -v -patmega32u4 -cavr109 -P$PORT -Uflash:w:lets_split_rev2_jimmyi2c.hex

