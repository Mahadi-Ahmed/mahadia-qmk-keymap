# mahadia-qmk-keymap

Keymap for a planck 48 key layout

---
ToDo:
- [x] Some way to use swedish Ö Ä Å
  - [x] Refactor keymap to use Swedish Language specific keymaps:
- [x] implement [home row mods](https://precondition.github.io/home-row-mods)
- [] home & end working on osx
- [x] implement [caps word](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/keyrecords/capwords.md)


## QMK commands
convert c keymap to a json format
```
qmk c2json -km mahadia -kb planck/rev6_drop keymap.c --no-cpp -o mahadia.json
```

### Notes
Currently using keymap_swedish_pro_mac_ansi.h , works well with OSX but not with W10
Look into which QMK swedish keymap header works well with [Swerty](https://johanegustafsson.net/projects/swerty/)

---
#### Edit the file qmk/quantum/keymap_extras/sendstring_swedish.h
include the same swedish version of keymap you're using in keymap.c

## Resources & Inspirations:

- [Plain Text Table](https://plaintexttools.github.io/plain-text-table/)
- [Jonas Hietala - The T-34 Keyboard layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/)
- [Pascal Getreuer - QMK: Designing a symbol layer](https://getreuer.info/posts/keyboards/symbol-layer/index.html)
- [Pascal Getreuer - QMK: Macro buttons](https://getreuer.info/posts/keyboards/macros/index.html)
- [Pascal Getreuer - QMK: Custom shift keys](https://getreuer.info/posts/keyboards/custom-shift-keys/index.html)
- [QMK Swedish keymap](https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_swedish.h)
- [Swerty software keyboard layout](https://johanegustafsson.net/projects/swerty/)
