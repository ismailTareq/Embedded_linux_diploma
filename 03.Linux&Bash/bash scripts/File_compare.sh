#!/bin/bash

if [ -z "$1" -o -z "$2" ]; then
    echo "Usage: $0 <file1> <file2>"
    exit 1
fi

file1=$(md5sum "$1" | awk '{print $1}')
file2=$(md5sum "$2" | awk '{print $1}')

if [ "$file1" = "$file2" ]; then
    echo "Files are identical"
else
    echo "Files are different"
fi