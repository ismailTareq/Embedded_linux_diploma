#!/bin/bash

word=" 0% packet loss"

for i in {1..20}
do 
    result=$(ping "192.168.1.$i" -c 1 -W 1)
    if [[ $result == *"${word}"* ]]; then
        echo "192.168.1.$i is reachable"
    fi
done
