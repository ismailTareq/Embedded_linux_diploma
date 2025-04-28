#!/bin/bash

file=$1

select opt in Erase flash
do
    case $opt in
        "Erase")
            echo "Erasing flash..."
            sudo umount /dev/sdb
            sudo dd if=/dev/zero of=/dev/sdb bs=1M count=100
            echo "Flash erased successfully."
            break
            ;;
        "flash")
            echo "Flashing..."
            sudo dd if=$file of=/dev/sdb1 bs=4M 
            echo "Flash completed successfully."
            break
            ;;
        *)
            echo "Invalid option. Please try again."
            ;;
    esac

done
