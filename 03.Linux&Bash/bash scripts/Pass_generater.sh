#!/bin/bash

Pass_length=8
charset="a-zA-Z0-9!@#$%^&*()_+"

generate_password() {
    local length=$1
    local charset=$2

    tr -dc "$charset" < /dev/urandom | head -c "$length";echo
}
while getopts ":l:c:" opt; do
    case $opt in
        l)
            Pass_length=$OPTARG
            ;;
        c)
            charset=$OPTARG
            ;;
        *)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        esac
done

pass=$(generate_password "$Pass_length" "$charset")
echo "Generated password: $pass"