# Linux Revision Course

Welcome to the **Commands Section**!

## All of the commands we used will not cover every command the are alot

### 1. Ls
`ls` is a command used to list directory contents. Below are some commonly used options:

- `ls` - Lists files and directories in the current directory.
- `ls -l` - Displays detailed information about each file and directory.
- `ls -a` - Shows all files, including hidden files (those starting with `.`).
- `ls -h` - Displays file sizes in a human-readable format.
- `ls -R` - Recursively lists all files in subdirectories.
- `ls -t` - Sorts files by modification time, newest first.
- `ls -S` - Sorts files by size, largest first.
### 2. Cd
`cd` is a command used to change the current working directory. Below are some examples:

- `cd /path/to/directory` - Changes to the specified directory.
- `cd ..` - Moves up one directory level.
- `cd ~` - Changes to the home directory.
- `cd -` - Switches to the previous directory.

### 3. Pwd
`pwd` stands for "print working directory" and displays the current directory path.

- `pwd` - Prints the full path of the current working directory.

### 4. Mkdir
`mkdir` is used to create new directories.
- `mkdir directory_name` - Creates a new directory with the specified name.
- `mkdir -p /path/to/directory` - Creates parent directories as needed.
- `mkdir -v directory_name` - Displays a message for each created directory.
- `mkdir --mode=MODE directory_name` - Sets permissions for the new directory.
- Example: `mkdir --mode=755 new_folder` - Creates a directory with specific permissions.

### 5. Rm
`rm` is used to remove files or directories.

- `rm file_name` - Deletes the specified file.
- `rm -r directory_name` - Deletes a directory and its contents recursively.
- `rm -i file_name` - Prompts for confirmation before deleting a file.
- `rm -f file_name` - Forces deletion without confirmation.

### 6. Cp
`cp` is used to copy files and directories.

- `cp source_file destination` - Copies a file to the specified destination.
- `cp -r source_directory destination` - Copies a directory and its contents recursively.
- `cp -i source_file destination` - Prompts for confirmation before overwriting.

### 7. Mv
`mv` is used to move or rename files and directories.

- `mv source_file destination` - Moves a file to the specified destination.
- `mv old_name new_name` - Renames a file or directory.
- `mv -i source_file destination` - Prompts for confirmation before overwriting.

### 8. Touch
`touch` is used to create empty files or update the timestamps of existing files.

- `touch file_name` - Creates an empty file with the specified name.
- `touch -a file_name` - Updates the access time of the file.
- `touch -m file_name` - Updates the modification time of the file.
- `touch -t YYYYMMDDHHMM file_name` - Sets a specific timestamp for the file.
- `touch -c file_name` - Does not create the file if it does not exist.
- Example: `touch -t 202310101200 example.txt` - Sets the timestamp of `example.txt` to October 10, 2023, at 12:00 PM.

### 9. Cat
`cat` is used to display the contents of a file, combine files, or create new files.

- `cat file_name` - Displays the contents of the specified file.
- `cat file1 file2 > combined_file` - Combines multiple files into one.
- `cat > new_file` - Creates a new file and allows you to input text (press `Ctrl+D` to save).

### 10. Echo
`echo` is used to display a line of text or a variable's value.

- `echo "Hello, World!"` - Prints "Hello, World!" to the terminal.
- `echo $VARIABLE_NAME` - Displays the value of a variable.
- `echo "text" > file_name` - Writes text to a file (overwrites if the file exists).
- `echo "text" >> file_name` - Appends text to a file.

### 11. Man
`man` displays the manual pages for a command.

- `man command_name` - Opens the manual page for the specified command.
- `man -k keyword` - Searches for commands related to a keyword.

### 12. Grep
`grep` is used to search for patterns in files.

- `grep "pattern" file_name` - Searches for a pattern in a file.
- `grep -i "pattern" file_name` - Performs a case-insensitive search.
- `grep -r "pattern" directory` - Searches recursively in a directory.
- `grep -v "pattern" file_name` - Displays lines that do not match the pattern.

### 13. Find
`find` is used to search for files and directories.

- `find /path -name file_name` - Searches for a file by name.
- `find /path -type d` - Searches for directories only.
- `find /path -size +1M` - Finds files larger than 1MB.

### 14. Wc
`wc` is used to count lines, words, and characters in a file.

- `wc file_name` - Displays the line, word, and character count.
- `wc -l file_name` - Counts the number of lines.
- `wc -w file_name` - Counts the number of words.
- `wc -c file_name` - Counts the number of characters.

### 15. Head
`head` is used to display the first few lines of a file.

- `head file_name` - Displays the first 10 lines by default.
- `head -n 5 file_name` - Displays the first 5 lines.

### 16. Tail
`tail` is used to display the last few lines of a file.

- `tail file_name` - Displays the last 10 lines by default.
- `tail -n 5 file_name` - Displays the last 5 lines.
- `tail -f file_name` - Continuously displays new lines added to a file.

### 17. Diff
`diff` is used to compare the contents of two files.

- `diff file1 file2` - Displays the differences between two files.
- `diff -y file1 file2` - Displays the differences side by side.
- `diff -r dir1 dir2` - Compares the contents of two directories.

### 18. History
`history` is used to display the command history.

- `history` - Lists all previously executed commands.
- `!number` - Re-executes a command from the history by its number.
- `history -c` - Clears the command history.

### 19. File System Commands

#### A. `df`
`df` is used to display disk space usage.

- `df` - Shows disk space usage for all mounted file systems.
- `df -h` - Displays disk space usage in a human-readable format.
- `df -T` - Displays the file system type.

#### B. `du`
`du` is used to estimate file and directory space usage.

- `du` - Displays the size of the current directory and its subdirectories.
- `du -h` - Shows sizes in a human-readable format.
- `du -s` - Displays the total size of a directory.
- `du -a` - Includes files in the output.

#### C. `mount`
`mount` is used to mount a file system.

- `mount` - Lists all currently mounted file systems.
- `mount /dev/device_name /mnt` - Mounts a device to the specified directory.
- `mount -o ro /dev/device_name /mnt` - Mounts a device as read-only.

#### D. `umount`
`umount` is used to unmount a file system.

- `umount /mnt` - Unmounts the file system mounted at `/mnt`.
- `umount -f /mnt` - Forces unmounting of a file system.

#### E. `fsck`
`fsck` is used to check and repair file systems.

- `fsck /dev/device_name` - Checks and repairs the specified file system.
### 20. Formatting and Partitioning

#### A. `fdisk`
`fdisk` is a command-line utility for managing disk partitions.

- `fdisk -l` - Lists all available disks and their partitions.
- `fdisk /dev/device_name` - Opens the specified disk for partitioning.
- Inside `fdisk`:
    - `n` - Creates a new partition.
    - `d` - Deletes a partition.
    - `p` - Prints the partition table.
    - `w` - Writes changes and exits.

#### B. `parted`
`parted` is another tool for managing partitions, especially for larger disks.

- `parted /dev/device_name` - Opens the specified disk for partitioning.
- Inside `parted`:
    - `mklabel gpt` - Creates a new GPT partition table.
    - `mkpart primary ext4 1MiB 100%` - Creates a primary partition with the ext4 file system.
    - `print` - Displays the partition table.

#### C. `mkfs`
`mkfs` is used to create a file system on a partition.

- `mkfs.ext4 /dev/partition_name` - Formats the partition with the ext4 file system.
- `mkfs.xfs /dev/partition_name` - Formats the partition with the XFS file system.
- `mkfs.vfat /dev/partition_name` - Formats the partition with the FAT file system.

#### D. `blkid`
`blkid` is used to display information about block devices.

- `blkid` - Lists all block devices and their UUIDs and file system types.

#### E. `lsblk`
`lsblk` is used to display information about block devices in a tree format.

- `lsblk` - Shows all block devices and their mount points.
- `lsblk -f` - Displays file system information for each block device.

#### F. `swap`
Commands related to swap space:

- `mkswap /dev/partition_name` - Sets up a partition as swap space.
- `swapon /dev/partition_name` - Activates the swap space.
- `swapoff /dev/partition_name` - Deactivates the swap space.
- `free -h` - Displays memory and swap usage in a human-readable format.

### 21. Hard and Soft Links

#### A. Hard Links
A hard link is a direct reference to the same inode as the original file. It allows multiple filenames to point to the same data on disk.

- `ln file_name link_name` - Creates a hard link to the specified file.
- Hard links cannot be created for directories.
- Deleting the original file does not affect the hard link.

#### B. Soft Links (Symbolic Links)
A soft link is a pointer to the original file's path. It acts as a shortcut to the file.

- `ln -s target_file link_name` - Creates a symbolic link to the specified file or directory.
- Soft links can span across different file systems.
- Deleting the original file breaks the symbolic link.

#### Differences Between Hard and Soft Links
| Feature            | Hard Link                     | Soft Link                     |
|--------------------|-------------------------------|-------------------------------|
| Type               | Direct reference to inode     | Pointer to file path          |
| File Systems       | Same file system only         | Can span different file systems |
| Directory Linking  | Not allowed                  | Allowed                       |
| Original File Deletion | Link remains functional     | Link breaks                   |

### 22. Piping and Redirection

#### A. Piping
Piping allows you to send the output of one command as input to another command using the `|` operator.

- `command1 | command2` - Sends the output of `command1` to `command2`.
- Example: `ls -l | grep "pattern"` - Lists files and filters the output for a specific pattern.

#### B. Redirection
Redirection allows you to control where the output of a command goes or where input comes from.

- `>` - Redirects output to a file (overwrites if the file exists).
    - Example: `echo "Hello" > file.txt` - Writes "Hello" to `file.txt`.
- `>>` - Appends output to a file.
    - Example: `echo "World" >> file.txt` - Appends "World" to `file.txt`.
- `<` - Redirects input from a file.
    - Example: `cat < file.txt` - Reads input from `file.txt`.
- `2>` - Redirects error output to a file.
    - Example: `command 2> error.log` - Writes errors to `error.log`.
- `2>>` - Appends error output to a file.
    - Example: `command 2>> error.log` - Appends errors to `error.log`.
- `&>` - Redirects both standard output and error to a file.
    - Example: `command &> output.log` - Writes both output and errors to `output.log`.
- `|&` - Pipes both standard output and error to another command.
    - Example: `command1 |& command2` - Sends both output and errors of `command1` to `command2`.

#### C. Combining Piping and Redirection
You can combine piping and redirection for more complex workflows.

- Example: `ls -l | grep "pattern" > result.txt` - Filters the output of `ls -l` and writes it to `result.txt`.
- Example: `command1 | command2 2> error.log` - Pipes the output of `command1` to `command2` and writes errors to `error.log`.

### 23. Inode and Superblock

#### A. Inode
An inode is a data structure used by a file system to store information about a file or directory, excluding its name or actual data.

- **Attributes Stored in an Inode**:
    - File type (regular file, directory, etc.)
    - File size
    - Permissions
    - Owner and group IDs
    - Timestamps (creation, modification, access)
    - Number of hard links
    - Pointers to data blocks

- **Commands to View Inode Information**:
    - `ls -i` - Displays the inode number of files and directories.
    - `stat file_name` - Shows detailed inode information for a file.

#### B. Superblock
A superblock is a metadata structure that contains information about the file system as a whole.

- **Attributes Stored in a Superblock**:
    - File system type
    - Total size of the file system
    - Block size
    - Number of inodes and data blocks
    - Free inodes and blocks
    - Mount status and time of last check

- **Commands to View Superblock Information**:
    - `dumpe2fs /dev/device_name` - Displays detailed information about the file system, including the superblock.
    - `tune2fs -l /dev/device_name` - Lists the superblock details.

- **Recovering a Corrupted Superblock**:
    - File systems often have backup superblocks. Use the following command to locate and restore a backup:
        - `fsck -b backup_superblock /dev/device_name`

### 24. Debugging and System Monitoring Commands

#### A. `strace`
`strace` is used to trace system calls and signals made by a program.
- `strace command` - Traces the system calls made by the specified command.
- `strace -o output.txt command` - Saves the trace output to a file.
- `strace -e trace=network command` - Traces only network-related system calls.

#### B. `dmesg`
`dmesg` is used to display kernel ring buffer messages, often useful for debugging hardware or kernel issues.
- `dmesg` - Displays all kernel messages.
- `dmesg | grep "pattern"` - Filters kernel messages for a specific pattern.
- `dmesg -T` - Displays timestamps in human-readable format.

#### C. `dd`
`dd` is a low-level utility for copying and converting data.
- `dd if=input_file of=output_file` - Copies data from the input file to the output file.
- `dd if=/dev/zero of=file_name bs=1M count=10` - Creates a 10MB file filled with zeros.
- `dd if=/dev/sdX of=backup.img bs=4M` - Creates a disk image of a device.
- `dd if=backup.img of=/dev/sdX bs=4M` - Restores a disk image to a device.
- `dd if=/dev/sdX | gzip > backup.img.gz` - Creates a compressed disk image.


### 25. Advanced Debugging and System Monitoring Commands

#### A. `strace`
- Is a powerful debugging tool used to trace system calls and signals made by a program.
- `strace command` - Traces the system calls made by the specified command.
- `strace -o output.txt command` - Saves the trace output to a file.
- `strace -e trace=network command` - Traces only network-related system calls.
- `strace -p PID` - Attaches to a running process by its PID and traces its system calls.

#### B. `dmesg`
- Is used to display kernel ring buffer messages, which are helpful for diagnosing hardware or kernel-related issues.
- `dmesg` - Displays all kernel messages.
- `dmesg | grep "pattern"` - Filters kernel messages for a specific pattern.
- `dmesg -T` - Displays timestamps in a human-readable format.
- `dmesg -l err` - Shows only error-level messages.

#### C. `dd`
- `dd` is a versatile utility for low-level data copying and conversion.
- `dd if=input_file of=output_file` - Copies data from the input file to the output file.
- `dd if=/dev/zero of=file_name bs=1M count=10` - Creates a 10MB file filled with zeros.
- `dd if=/dev/sdX of=backup.img bs=4M` - Creates a disk image of a device.
- `dd if=backup.img of=/dev/sdX bs=4M` - Restores a disk image to a device.
- `dd if=/dev/sdX | gzip > backup.img.gz` - Creates a compressed disk image.
- `dd if=/dev/sdX of=/dev/sdY bs=4M` - Clones one disk to another.

### 27. `whoami`
`whoami` is used to display the username of the current user.
- `whoami` - Prints the username of the user executing the command.

### 28. Which
`which` is used to locate the executable file associated with a command.
- `which command_name` - Displays the full path of the command's executable.
- Example: `which ls` - Outputs the path to the `ls` command.
- `which -a command_name` - Lists all instances of the command found in the directories listed in the `PATH` environment variable.

### 29. Wildcards and Regular Expressions

#### A. Wildcards
#### A. Wildcards
Wildcards are special characters used to match patterns in filenames or directories.

- `*` - Matches zero or more characters.
    - Example: `ls *.txt` - Lists all files with a `.txt` extension.
- `?` - Matches exactly one character.
    - Example: `ls file?.txt` - Matches `file1.txt`, `file2.txt`, etc.
- `[ ]` - Matches any one character inside the brackets.
    - Example: `ls file[1-3].txt` - Matches `file1.txt`, `file2.txt`, and `file3.txt`.
- `{ }` - Matches a comma-separated list of patterns.
    - Example: `ls {file1,file2}.txt` - Matches `file1.txt` and `file2.txt`.
- `~` - Represents the home directory of the current user.
    - Example: `cd ~/Documents` - Changes to the `Documents` directory in the home folder.
- `**` - Matches directories recursively (used with tools like `find` or `rsync`).
    - Example: `find . -name "**.log"` - Finds all `.log` files in the current directory and subdirectories.
- `!` - Negates a pattern (used in some commands like `find`).
    - Example: `find . ! -name "*.txt"` - Finds all files except those with a `.txt` extension.
- `\` - Escapes a wildcard character to treat it literally.
    - Example: `ls file\*.txt` - Matches a file named `file*.txt` instead of using `*` as a wildcard.

Wildcards are commonly used in commands like `ls`, `cp`, `mv`, and `find` for flexible pattern matching.


#### B. Regular Expressions
Regular expressions (regex) are patterns used for advanced text matching.

- `.` - Matches any single character.
    - Example: `grep "f.l" file.txt` - Matches `fal`, `fil`, etc.
- `^` - Matches the start of a line.
    - Example: `grep "^Hello" file.txt` - Matches lines starting with `Hello`.
- `$` - Matches the end of a line.
    - Example: `grep "world$" file.txt` - Matches lines ending with `world`.
- `*` - Matches zero or more occurrences of the preceding character.
    - Example: `grep "fo*" file.txt` - Matches `f`, `fo`, `foo`, etc.
- `+` - Matches one or more occurrences of the preceding character.
    - Example: `grep "fo+" file.txt` - Matches `fo`, `foo`, etc.
- `?` - Matches zero or one occurrence of the preceding character.
    - Example: `grep "fo?" file.txt` - Matches `f` or `fo`.
- `[ ]` - Matches any one character inside the brackets.
    - Example: `grep "[aeiou]" file.txt` - Matches any vowel.
- `|` - Acts as an OR operator.
    - Example: `grep "cat|dog" file.txt` - Matches `cat` or `dog`.
- `()` - Groups patterns.
    - Example: `grep "a(bc|de)f" file.txt` - Matches `abcf` or `adef`.
- `{n,m}` - Matches between `n` and `m` occurrences of the preceding character.
    - Example: `grep "o{2,4}" file.txt` - Matches `oo`, `ooo`, or `oooo`.

#### C. Combining Wildcards and Regular Expressions
You can use wildcards and regex together in commands like `grep`, `find`, or `sed` for powerful pattern matching.

- Example: `grep -E "file[0-9]{2}.txt" directory/` - Matches files like `file01.txt`, `file23.txt`, etc.
- Example: `find . -name "*.log" | grep -E "error|fail"` - Finds `.log` files and filters for lines containing `error` or `fail`.

### 30. Special Entries: `.` and `..`

In every directory, there are two special entries:

- `.` - Refers to the current directory.
    - Example: `cd .` - Stays in the current directory.
    - Example: `ls .` - Lists the contents of the current directory.

- `..` - Refers to the parent directory.
    - Example: `cd ..` - Moves up one directory level.
    - Example: `ls ..` - Lists the contents of the parent directory.

These entries are useful for navigating and managing directories efficiently.

### 31. TTY

`tty` is used to display the file name of the terminal connected to the standard input.

- `tty` - Prints the terminal device name.
- Example: `/dev/pts/0` - Indicates the terminal device in use.
- Useful for debugging or identifying the terminal session.

### 32. Sort

`sort` is used to sort lines in a file or input.

- `sort file_name` - Sorts the lines in a file alphabetically.
- `sort -r file_name` - Sorts the lines in reverse order.
- `sort -n file_name` - Sorts numerically.
- `sort -k 2 file_name` - Sorts by the second column.
- `sort -u file_name` - Removes duplicate lines while sorting.
- `sort -t ":" -k 2 file_name` - Sorts by the second field using `:` as the delimiter.

Examples:
- `sort data.txt` - Sorts the contents of `data.txt` alphabetically.
- `sort -n numbers.txt` - Sorts the numbers in `numbers.txt` numerically.
- `sort -t "," -k 3 data.csv` - Sorts a CSV file by the third column.

### 33. Cal and Date

#### A. `cal`
`cal` is used to display a calendar.

- `cal` - Displays the current month's calendar.
- `cal 2023` - Displays the calendar for the year 2023.
- `cal 10 2023` - Displays the calendar for October 2023.
- `cal -3` - Displays the previous, current, and next month's calendars.
- `cal -j` - Displays the calendar with Julian dates.

#### B. `date`
`date` is used to display or set the system date and time.

- `date` - Displays the current date and time.
- `date +"%Y-%m-%d"` - Displays the date in `YYYY-MM-DD` format.
- `date +"%H:%M:%S"` - Displays the time in `HH:MM:SS` format.
- `date -u` - Displays the date and time in UTC.
- `date --set="2023-10-10 12:00:00"` - Sets the system date and time (requires root privileges).

Examples:
- `cal` - Displays the current month's calendar.
- `date +"%A, %B %d, %Y"` - Displays the full date in a human-readable format, e.g., "Tuesday, October 10, 2023".

### 34. Grep

`grep` is a powerful command-line tool used to search for patterns in files or input.

#### Basic Usage
- `grep "pattern" file_name` - Searches for a pattern in a file and displays matching lines.
- `grep -i "pattern" file_name` - Performs a case-insensitive search.
- `grep -v "pattern" file_name` - Displays lines that do not match the pattern.
- `grep -c "pattern" file_name` - Counts the number of matching lines.
- `grep -n "pattern" file_name` - Displays matching lines with line numbers.

#### Advanced Options
- `grep -r "pattern" directory` - Searches recursively in a directory.
- `grep -l "pattern" *` - Lists file names containing the pattern.
- `grep -w "pattern" file_name` - Matches whole words only.
- `grep -A n "pattern" file_name` - Displays `n` lines after a matching line.
- `grep -B n "pattern" file_name` - Displays `n` lines before a matching line.
- `grep -C n "pattern" file_name` - Displays `n` lines of context around a matching line.

#### Examples
- `grep "error" log.txt` - Finds lines containing "error" in `log.txt`.
- `grep -i "hello" file.txt` - Searches for "hello" in a case-insensitive manner.
- `grep -r "TODO" .` - Searches for "TODO" in the current directory and subdirectories.
- `grep -A 2 "pattern" file.txt` - Displays 2 lines after each match.

#### Combining with Other Commands
- `ls | grep "pattern"` - Filters the output of `ls` for a specific pattern.
- `cat file.txt | grep "keyword"` - Searches for "keyword" in the contents of `file.txt`.

`grep` is widely used for text processing and log analysis due to its flexibility and speed.

### 35. Locate

`locate` is used to quickly find files and directories by searching a pre-built database.

#### Basic Usage
- `locate file_name` - Searches for files or directories matching `file_name`.
- `locate -i file_name` - Performs a case-insensitive search.
- `locate -n N file_name` - Limits the output to the first `N` matches.

#### Updating the Database
- `sudo updatedb` - Updates the `locate` database (requires root privileges).

#### Examples
- `locate example.txt` - Finds all files named `example.txt`.
- `locate -i document` - Searches for files or directories containing "document" (case-insensitive).
- `locate -n 5 log` - Displays the first 5 results for files or directories containing "log".

The `locate` command is faster than `find` because it uses a pre-built database, but it may not reflect recent changes until the database is updated.

### 36. AWK

`awk` is a powerful text processing tool used for pattern scanning and processing.
- `awk '{print $1}' file_name` - Prints the first column of each line in the file.
- `awk '/pattern/ {print $0}' file_name` - Prints lines matching the pattern.
- `awk '{print $1, $3}' file_name` - Prints the first and third columns of each line.
- `awk -F ":" '{print $1}' file_name` - Uses `:` as the field separator.
- `awk '{if ($3 > 50) print $0}' file_name` - Prints lines where the third column is greater than 50.
- `awk 'BEGIN {print "Header"} {print $1} END {print "Footer"}' file_name` - Adds a header and footer to the output.

#### Examples
- `awk '{sum += $1} END {print sum}' file_name` - Sums up the values in the first column.
- `awk '/error/ {print $0}' log.txt` - Prints lines containing "error" in `log.txt`.

---

### 37. SED

`sed` is a stream editor used for text manipulation.

- `sed 's/old/new/' file_name` - Replaces the first occurrence of "old" with "new" in each line.
- `sed 's/old/new/g' file_name` - Replaces all occurrences of "old" with "new" in each line.
- `sed '/pattern/d' file_name` - Deletes lines matching the pattern.
- `sed -n '/pattern/p' file_name` - Prints only lines matching the pattern.
- `sed '2,4d' file_name` - Deletes lines 2 through 4.
- `sed 's/^/prefix: /' file_name` - Adds a prefix to each line.

#### Examples
- `sed 's/[0-9]/#/g' file_name` - Replaces all digits with `#`.
- `sed -i 's/foo/bar/g' file_name` - Edits the file in place, replacing "foo" with "bar".

`awk` and `sed` are essential tools for text processing and automation in Linux.


### 38. Type
`type` is used to display information about a command, including whether it is a shell built-in, an alias, or an external command.
- `type command_name` - Displays the type of the specified command.
- Example: `type ls` - Outputs whether `ls` is an alias, built-in, or external command.
- `type -a command_name` - Lists all instances of the command found in the `PATH`.
- Example: `type -a echo` - Displays all locations of the `echo` command.

#### Examples
- `type cd` - Shows that `cd` is a shell built-in.
- `type -a grep` - Lists all instances of `grep` in the `PATH`.

### 39. Tree

`tree` is used to display directories and files in a tree-like structure.
- `tree` - Displays the directory structure of the current directory.
- `tree /path/to/directory` - Displays the directory structure of the specified path.
- `tree -L N` - Limits the depth of the directory tree to `N` levels.
- `tree -a` - Includes hidden files and directories in the output.
- `tree -d` - Displays only directories.
- `tree -f` - Displays the full path of each file and directory.
- `tree -h` - Displays file sizes in a human-readable format.
- `tree -P "pattern"` - Displays only files matching the specified pattern.
- `tree -I "pattern"` - Excludes files and directories matching the specified pattern.
- `tree -L 2` - Displays the directory structure up to 2 levels deep.
- `tree -a -h` - Displays all files, including hidden ones, with human-readable sizes.
- `tree -P "*.txt"` - Displays only `.txt` files in the directory tree.
- `tree -I "*.log"` - Excludes `.log` files from the directory tree.

### 40. Pushd and Popd

`pushd` and `popd` are used to manage the directory stack, allowing you to navigate between directories efficiently.

#### A. `pushd`
`pushd` saves the current directory to the stack and switches to a new directory.

- `pushd /path/to/directory` - Saves the current directory to the stack and changes to the specified directory.
- `pushd` - Swaps the top two directories in the stack and changes to the new top directory.

#### B. `popd`
`popd` removes the top directory from the stack and switches to the next directory in the stack.

- `popd` - Removes the top directory from the stack and changes to the next directory.

#### C. Viewing the Directory Stack
- `dirs` - Displays the current directory stack.

### 41. Echo Command in Detail

The `echo` command is used to display text or variables in the terminal. It is commonly used in shell scripting and command-line operations.

#### Basic Usage
- `echo "Hello, World!"` - Prints "Hello, World!" to the terminal.
- `echo $VARIABLE_NAME` - Displays the value of a variable.
- `echo "This is a test"` - Outputs the text "This is a test".

#### Special Characters
- `echo -e` - Enables interpretation of backslash-escaped characters.
    - `\n` - New line.
    - `\t` - Tab space.
    - Example: `echo -e "Line1\nLine2"` - Outputs:
      ```
      Line1
      Line2
      ```

#### Redirecting Output
- `echo "text" > file_name` - Writes text to a file (overwrites if the file exists).
- `echo "text" >> file_name` - Appends text to a file.

#### Suppressing Newline
- `echo -n "text"` - Prints text without a trailing newline.

#### Examples
- `echo "User: $USER"` - Displays the current username.
- `echo -e "Path:\n$PATH"` - Displays the system's PATH variable with a new line.
- `echo -n "Processing..."` - Prints "Processing..." without a newline.

### 42. Uname

`uname` is used to display system information.

#### Basic Usage
- `uname` - Displays the operating system name.
- `uname -a` - Displays all available system information.
- `uname -s` - Displays the kernel name.
- `uname -n` - Displays the network hostname.
- `uname -r` - Displays the kernel release.
- `uname -v` - Displays the kernel version.
- `uname -m` - Displays the machine hardware name.
- `uname -p` - Displays the processor type (if available).
- `uname -i` - Displays the hardware platform (if available).
- `uname -o` - Displays the operating system.

### 43. Screen

`screen` is a terminal multiplexer that allows you to manage multiple terminal sessions within a single window. It is useful for running long processes or managing remote sessions.

#### Basic Usage
- `screen` - Starts a new screen session.
- `screen -S session_name` - Starts a new screen session with a specific name.
- `screen -ls` - Lists all active screen sessions.
- `screen -r session_name` - Reattaches to a detached screen session.

#### Detaching and Reattaching
- `Ctrl+A, D` - Detaches the current screen session, leaving it running in the background.
- `screen -r` - Reattaches to the most recently detached session.

#### Managing Windows
- `Ctrl+A, C` - Creates a new window.
- `Ctrl+A, N` - Switches to the next window.
- `Ctrl+A, P` - Switches to the previous window.
- `Ctrl+A, "` - Displays a list of all windows.

#### Exiting a Screen Session
- `exit` - Closes the current screen session.
- `Ctrl+D` - Exits the current screen session.

#### Examples
- `screen -S my_session` - Starts a new session named `my_session`.
- `screen -r my_session` - Reattaches to the session named `my_session`.
- `screen -ls` - Lists all active sessions.



and there is so much more... i can't even remember