# mahadia-qmk-keymap

Keymap for a planck 48 key layout

---
ToDo:
- [] Some way to use swedish Ö Ä Å
  - [] Refactor keymap to use Swedish Language specific keymaps
- [] implement [home row mods]()
- [] home & end working on osx
- [] implement [caps word](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/keyrecords/capwords.md)


## QMK commands
convert c keymap to a json format
```
qmk c2json -km mahadia -kb planck/rev6_drop keymap.c --no-cpp -o mahadia.json
```
