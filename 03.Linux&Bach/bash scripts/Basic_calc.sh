#!/bin/bash

show_menu() {
    echo "1. Add"
    echo "2. Subtract"
    echo "3. Multiply"
    echo "4. Divide"
    echo "5. Exit"
}

add() {
    echo "enter two numbers to add"
    read -r a b
    result=$((a + b))
    echo "Result: $result"
}
subtract() {
    echo "enter two numbers to subtract"
    read -r a b
    result=$((a - b))
    echo "Result: $result"
}
multiply() {
    echo "enter two numbers to multiply"
    read -r a b
    result=$((a * b))
    echo "Result: $result"
}
divide() {
    echo "enter two numbers to divide"
    read -r a b
    if [ "$b" -eq 0 ]; then
        echo "Error: Division by zero is not allowed."
    else
        result=$((a / b))
        echo "Result: $result"
    fi
}

while true; do
    show_menu
    echo "Enter your choice (1-5):"
    read -r choice

    case $choice in
        1) add ;;
        2) subtract ;;
        3) multiply ;;
        4) divide ;;
        5) echo "Exiting..."; exit 0 ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done

