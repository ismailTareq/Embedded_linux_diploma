#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root"
    exit 1
fi

add_user() {
    read -p "Enter username: " username
    read -p "Enter password: " password
    useradd -m -s /bin/bash "$username"
    echo "$username:$password" | chpasswd
    echo "User $username added successfully."
}

delete_user() {
    read -p "Enter username to delete: " username
    userdel -r "$username"
    if [ $? -ne 0 ]; then
        echo "Failed to delete user $username. User may not exist."
        exit 1
    fi
    echo "User $username deleted successfully."
}

echo "Choose an option:"
echo "1. Add user"
echo "2. Delete user"
read -p "Enter your choice: " choice

case $choice in
    1)
        add_user
        ;;
    2)
        delete_user
        ;;
    *)
        echo "Invalid choice."
        ;;
esac