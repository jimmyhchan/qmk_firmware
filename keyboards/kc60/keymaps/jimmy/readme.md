# Jimmy Layout

* Online keyboard layout editor: http://www.keyboard-layout-editor.com/#/gists/2ce67d73d948414384ccf70643f177d3
* Online keyboard layout editor (fn layer): http://www.keyboard-layout-editor.com/#/gists/abdbf40c96f1b24081bbf52e4c6e2bcd
* Online keyboard layout editor (fn2 layer): TBD

# Programming Instructions:
$ make kc60:jimmy:flashbin
Enter into programming mode and run the following command.
(keyboard led should start blinking)
```
$ cp kc60_jimmy.bin /Volumes/LUFA\ BOOT/FLASH.BIN
$ sudo umount /Volumes/LUFA\ BOOT

```
Hit escape key on the keyboard
(keyboard led should stop blinking)
