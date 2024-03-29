# mahadia-qmk-keymap

Keymap for a planck 48 key layout

---
ToDo:
- [x] Some way to use swedish Ö Ä Å
  - [x] Refactor keymap to use Swedish Language specific keymaps:
- [x] implement [home row mods](https://precondition.github.io/home-row-mods)
- [x] implement [caps word](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/keyrecords/capwords.md)
- [x] home & end working on osx

# layout
Map of layout & layers for my keymap with planck 48

##### QWERTY

| tab          	| q     	| w          	| e         	| r   	| t   	| y             	| u       	| i    	| o          	| p   	| bspc       	|
|--------------	|-------	|------------	|-----------	|-----	|-----	|---------------	|---------	|------	|------------	|-----	|------------	|
| mvmnt / esc  	| a     	| s          	| d         	| f   	| g   	| h             	| j       	| k    	| l          	| . : 	| ' "        	|
| lshift       	| z     	| x          	| c         	| v   	| b   	| n             	| m       	| , ;  	| / ?        	| - _ 	| rs / enter 	|
| fnl          	| lctrl 	| lalt (opt) 	| gui (cmd) 	| num 	| spc 	| guitabs / spc 	| symbols 	| rctl 	| ralt (opt) 	| gui 	| / ?        	|

##### Symbols

| ` 	| @          	| <           	| >         	| &   	| # 	| \| 	| ( 	| ) 	| ! 	| ? 	| ^ 	|
|---	|------------	|-------------	|-----------	|-----	|---	|----	|---	|---	|---	|---	|---	|
|   	| arrow func 	| -           	| +         	| =   	| / 	| $  	| { 	| } 	| % 	| ~ 	| * 	|
|   	|            	| console log 	| \         	| ../ 	| _ 	| [  	| ] 	|   	|   	|   	|   	|
|   	| ctrl       	| alt (opt)   	| gui (cmd) 	|     	|   	|    	|   	|   	|   	|   	|   	|

##### FN Layer

| f1 	| f2 	| f3              	| f4                     	| f5 	| f6 	| f7   	| f8   	| f9        	| f10          	| f11   	| f12       	|
|----	|----	|-----------------	|------------------------	|----	|----	|------	|------	|-----------	|--------------	|-------	|-----------	|
|    	|    	| osm lctl & lalt 	| osm lctl & lalt & lcmd 	|    	|    	| left 	| down 	| up        	| right        	|       	|           	|
|    	|    	|                 	|                        	|    	|    	|      	|      	|           	| pause / play 	|       	| enter     	|
|    	|    	|                 	| cmd                    	|    	|    	|      	|      	| prev song 	| vol +        	| vol - 	| next song 	|

##### Movement

| tab 	| Mouse btn2 	| Mouse up   	| Mouse btn1  	|   	|            	|      	| Scroll Down 	| Scroll up 	|              	|              	|              	|
|-----	|------------	|------------	|-------------	|---	|------------	|------	|-------------	|-----------	|--------------	|--------------	|--------------	|
|     	| Mouse left 	| Mouse down 	| Mouse right 	|   	| cmd + left 	| left 	| down        	| up        	| right        	| cmd + right  	|              	|
|     	|            	|            	|             	|   	|            	|      	|             	|           	|              	|              	| enter        	|
|     	|            	|            	|             	|   	|            	|      	|             	|           	| accelerate 0 	| accelerate 1 	| accelerate 2 	|

##### NUMPAD

| 0 	| 1 	| 2 	| 3 	| 4 	| 5 	|   	| 4 	| 5 	| 6 	|   	| bspc 	|
|---	|---	|---	|---	|---	|---	|---	|---	|---	|---	|---	|------	|
|   	|   	|   	|   	|   	|   	| 0 	| 1 	| 2 	| 3 	|   	| *    	|
|   	|   	|   	|   	|   	|   	|   	| 7 	| 8 	| 9 	|   	|      	|
|   	|   	|   	|   	|   	|   	|   	|   	|   	|   	|   	|      	|

##### GUITABS

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
- [Home row mods](https://precondition.github.io/home-row-mods)
