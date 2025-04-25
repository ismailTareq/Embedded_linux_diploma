#!/bin/bash

show_cpp(){
    echo "=============================="
    echo "==========C++ example========="
    echo "=============================="
    cat << EOF
#include <iostream>

int main() 
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOF
    read -p "Press enter to continue"
}

show_python(){
    echo "=============================="
    echo "==========Python example======="
    echo "=============================="
    cat << EOF
print("Hello, World!")
EOF
    read -p "Press enter to continue"
}

show_bash(){
    echo "=============================="
    echo "==========Bash example========="
    echo "=============================="
    cat << EOF
#!/bin/bash
echo "Hello, World!"
EOF
    read -p "Press enter to continue"
}

show_linux(){
    echo "=============================="
    echo "==========Linux example========="
    echo "=============================="
    cat << EOF
# file operations
ls - list directory contents
cd - change directory
pwd - print working directory
mkdir - create a new directory
rm - remove files or directories
cp - copy files or directories
mv - move or rename files or directories
# process management
ps - display information about running processes
top - display real-time information about system processes
kill - terminate a process
# network operations
ping - check connectivity to a host
ifconfig - display network interface configuration
netstat - display network connections
ssh - secure shell for remote login
scp - secure copy for file transfer
# system information
uname - display system information
df - display disk space usage
free - display memory usage
uptime - display system uptime
# package management
apt-get - package manager for Debian-based systems
yum - package manager for Red Hat-based systems
# user management
useradd - add a new user
userdel - delete a user
passwd - change user password
chown - change file ownership
chmod - change file permissions
# file permissions
r - read permission
w - write permission
x - execute permission
# file types
f - regular file
d - directory
l - symbolic link
b - block device
c - character device
s - socket
p - named pipe
EOF
    read -p "Press enter to continue"
}

show_menu(){
    echo "=============================="
    echo "==========Wiki.sh============="
    echo "=============================="
    echo "1. C++ example"
    echo "2. Python example"
    echo "3. Bash example"
    echo "4. Linux example"
    echo "5. Exit"
    read -p "Select an option: " option
}

while true; do
    show_menu

    case $option in
        1) show_cpp ;;
        2) show_python ;;
        3) show_bash ;;
        4) show_linux ;;
        5) exit 0 ;;
        *) echo "Invalid option" ;;
    esac
done

