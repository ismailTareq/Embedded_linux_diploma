#!/bin/bash

file=$(cat /home/ismail/Desktop/bash\ script/files.txt)

selected=$(echo -e "select\nadd" | rofi -dmenu -p "Select add/select")
if [ "$selected" = "add" ]; then
    selected=$(echo -e "" | rofi -dmenu -p "path to file:")
    if [ -n "$selected" ]; then
        echo "$selected" >> /home/ismail/Desktop/bash\ script/files.txt
        echo "File added to list"
    fi
elif [ "$selected" = "select" ]; then
    selected=$(echo -e "${file[@]}" | rofi -dmenu -p "Select file:")
    code "$selected"
    
fi

