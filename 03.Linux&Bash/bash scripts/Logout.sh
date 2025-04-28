#!/bin/bash

select=$(echo -e "logout\nshutdown\nreboot" | rofi -dmenu -p "Select an option:")

case $select in
    logout)
        pkill -u "$(id -u)"
        ;;
    shutdown)
        systemctl poweroff
        ;;
    reboot)
        systemctl reboot
        ;;
    *)
        echo "Invalid option"
        ;;
esac