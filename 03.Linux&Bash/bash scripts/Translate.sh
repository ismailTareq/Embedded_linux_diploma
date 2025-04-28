#!/bin/bash
word=$(xclip -o)
url="https://translate.google.com.eg/?hl=ar&sl=auto&tl=ar&text=${word}&op=translate"
firefox  "$url"