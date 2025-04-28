#!/bin/bash

Username="ismail"
Password="0812"

read -rp "Enter username: " user
read -srp "Enter password: " pass
echo 
if [ "$user" == "$Username" ] && [ "$pass" == "$Password" ]; then
    echo "Login successful"
else
    echo "Login failed"
fi


