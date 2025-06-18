#!/bin/bash
set -x 
echo -e 'power on \nconnect 36:95:FB:D1:5B:02 \nquit ' | bluetoothctl
while true; do
	out=$(echo -e 'info' | bluetoothctl)
	if [[ "${out}" == *"Connected: yes"* ]]
	then
		break
	fi
	sleep 1
done
mpg123 ~/Downloads/ytmp3free.cc_lord-huron-the-night-we-met-official-audio-youtubemp3free.org.mp3

