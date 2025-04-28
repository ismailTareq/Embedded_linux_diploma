#!/bin/bash

Log_FILE="./log.txt"
Keyword="ERROR"

send_notification() {
    notify-send "Log Alert" "Keyword '$Keyword' found in log file." --icon=dialog-warning
}

tail -Fn0 "$Log_FILE" | \
while read line; do
    if echo "$line" | grep "$Keyword"; then
        send_notification
    fi
done

