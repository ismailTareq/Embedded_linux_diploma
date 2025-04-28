#!/bin/bash

declare -A colors=(
    [Red]="\e[31m"
    [Green]="\e[32m"
    [Yellow]="\e[33m"
    [Blue]="\e[34m"
    [Magenta]="\e[35m"
    [Cyan]="\e[36m"
    [White]="\e[37m"
    [BLACK]="\e[30m"
    [BOLD]="\e[1m"
    [UNDERLINE]="\e[4m"
    [RESET]="\e[0m"
)

names=(
    "Red"
    "Green"
    "Yellow"
    "Blue"
    "Magenta"
    "Cyan"
    "White"
    "BLACK"
    "BOLD"
    "UNDERLINE"
    "RESET"
)

select=$(printf "%s\n" "${names[@]}" | rofi -dmenu -p "Select a color:")

xdotool type "${colors[$select]}}"