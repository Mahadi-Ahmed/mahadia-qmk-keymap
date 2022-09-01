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

## Resources & Inspirations:

- [Plain Text Table](https://plaintexttools.github.io/plain-text-table/)
- [Jonas Hietala - The T-34 Keyboard layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/)
- [Pascal Getreuer - QMK: Designing a symbol layer](https://getreuer.info/posts/keyboards/symbol-layer/index.html)
- [Pascal Getreuer - QMK: Macro buttons](https://getreuer.info/posts/keyboards/macros/index.html)
