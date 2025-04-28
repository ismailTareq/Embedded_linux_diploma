#!/bin/bash

cmdlist="./cmdlist"

if [ $# -eq 0 ]; then
    echo "Usage: $0 <command>"
    cat "$cmdlist"
    echo
    exit 1
fi

key=$1
while read -r line
do
    if echo "${line}" | grep -q "^$key"; then
        cmd=$(echo "${line}" | cut -d "=" -f 2)
        echo "Command found: $cmd"
    fi
done < "$cmdlist"

if [ -z "$cmd" ]; then
    echo "Command not found in cmdlist"
    cat "$cmdlist"
    echo
else 
    echo "Executing command: $cmd"
    if eval "$cmd"; then
        echo "Command executed successfully"
    else
        echo "Command execution failed"
    fi

#    echo ${cmd} > "$tmpfile"
#    echo "Command saved to $tmpfile"
#    bash ${tmpfile}
fi


