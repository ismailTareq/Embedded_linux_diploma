#!/bin/bash

file="report.txt"

addseperator() {
    echo "----------------------------------------" >> "$file"
    echo "--------------------$1------------------" >> "$file"
    echo "----------------------------------------" >> "$file"
}
addseperator "report file"

hostname >> "$file"
whoami >> "$file"
echo "----------------------------------------" >> "$file"
addseperator "system info"
uname -a >> "$file"
echo "----------------------------------------" >> "$file"
addseperator "disk usage"
df -h >> "$file"
echo "----------------------------------------" >> "$file"
addseperator "network info"
ifconfig >> "$file"
echo "----------------------------------------" >> "$file"
addseperator "cpu info"
lscpu >> "$file"
echo "----------------------------------------" >> "$file"
addseperator "memory info"
free -h >> "$file"
echo "----------------------------------------" >> "$file"
