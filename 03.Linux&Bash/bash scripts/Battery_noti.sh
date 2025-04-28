#!/bin/bash

Battery=$(acpi -b)

read -a array <<< "$Battery"
Battery_per=${array[3]::-1}

tmp=$(echo $Battery_per | tr -d '%')


while true; do
    if [ "${tmp}" -lt 100 ]; then
        notify-send "please charge your battery dummass your battery is ${tmp}%"
        sleep 5
    fi
    acpi -a | grep "on"
    if [ $? -eq 0 ]; then
        notify-send "your battery is charging thanks bitch"
        sleep 5
        break
    fi

done