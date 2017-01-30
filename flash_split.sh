#! /usr/bin/env bash

#see https://nicholaskell.wordpress.com/tag/leonardo/

PORT=/dev/cu.usbmodem1421
python reset.py $PORT
sleep 3
avrdude -v -patmega32u4 -cavr109 -P$PORT -Uflash:w:lets_split_rev2_jimmyi2c.hex

