# Linux Revision Course

Welcome to the **Bash Section**!

## All of the commands we used

### 1.rofi
- `rofi -show run`: Launches the application launcher.
- `rofi -show window`: Displays a list of open windows for switching.
- `rofi -dmenu`: Provides a customizable menu for user input.
- `rofi -show ssh`: Lists SSH connections for quick access.
### 2. getopts
- `getopts`: Parses command-line options passed to a shell script.
- Example: `while getopts "a:b:" opt; do echo "Option $opt with value $OPTARG"; done`

### 3. xdotool
- `xdotool key <key>`: Simulates a key press.
- `xdotool mousemove <x> <y>`: Moves the mouse pointer to specified coordinates.
- `xdotool click <button>`: Simulates a mouse button click.

### 4. notify-send
- `notify-send "Title" "Message"`: Sends a desktop notification.
- Example: `notify-send "Reminder" "Time to take a break!"`

### 5. dmenu
- `echo -e "Option1\nOption2\nOption3" | dmenu`: Displays a menu with options for user selection.
- Example: `selected=$(echo -e "Yes\nNo" | dmenu) && echo "You selected $selected"`

### 6. awk
- `awk '{print $1}' file.txt`: Prints the first column of a file.
- `awk '/pattern/ {print $0}' file.txt`: Prints lines matching a pattern.
- `awk '{sum += $1} END {print sum}' file.txt`: Sums up the first column of a file.

### 7. tr
- `echo "text" | tr 'a-z' 'A-Z'`: Converts lowercase to uppercase.
- `echo "text" | tr -d 'aeiou'`: Deletes specified characters.
- `echo "text" | tr ' ' '\n'`: Replaces spaces with newlines.

### 8. if, while, case, and select
#### for Loop
- Syntax:
    ```bash
    for variable in list; do
        # commands
    done
    ```
- Example:
    ```bash
    for i in {1..5}; do
        echo "Number: $i"
    done
    ```

- Example with an array:
    ```bash
    fruits=("apple" "banana" "cherry")
    for fruit in "${fruits[@]}"; do
        echo "Fruit: $fruit"
    done
    ```
- Example with a command substitution:
    ```bash
    for file in $(ls *.txt); do
        echo "Processing $file"
    done
    ```
#### if
- Syntax:
    ```bash
    if [ condition ]; then
            # commands
    elif [ condition ]; then
            # commands
    else
            # commands
    fi
    ```
- Example:
    ```bash
    if [ -f "file.txt" ]; then
            echo "File exists."
    else
            echo "File does not exist."
    fi
    ```

#### while
- Syntax:
    ```bash
    while [ condition ]; do
            # commands
    done
    ```
- Example:
    ```bash
    count=1
    while [ $count -le 5 ]; do
            echo "Count: $count"
            count=$((count + 1))
    done
    ```

#### case
- Syntax:
    ```bash
    case $variable in
            pattern1)
                    # commands
                    ;;
            pattern2)
                    # commands
                    ;;
            *)
                    # default commands
                    ;;
    esac
    ```
- Example:
    ```bash
    read -p "Enter a choice (y/n): " choice
    case $choice in
            y|Y)
                    echo "You chose yes."
                    ;;
            n|N)
                    echo "You chose no."
                    ;;
            *)
                    echo "Invalid choice."
                    ;;
    esac
    ```

#### select
- Syntax:
    ```bash
    select option in list; do
            # commands
    done
    ```
- Example:
    ```bash
    PS3="Choose an option: "
    select option in "Option1" "Option2" "Quit"; do
            case $option in
                    "Option1")
                            echo "You chose Option1."
                            ;;
                    "Option2")
                            echo "You chose Option2."
                            ;;
                    "Quit")
                            break
                            ;;
                    *)
                            echo "Invalid option."
                            ;;
            esac
    done
    ```
### 9. Functions
- Functions allow you to group commands for reuse.
- Syntax:
    ```bash
    function_name() {
        # commands
    }
    ```
- Example:
    ```bash
    greet() {
        echo "Hello, $1!"
    }
    greet "World"
    ```

### 10. Arrays and Map

#### Arrays
- Bash supports indexed arrays.
- Syntax:
    ```bash
    array_name=(value1 value2 value3)
    ```
- Example:
    ```bash
    fruits=("apple" "banana" "cherry")
    echo ${fruits[0]}  # Outputs: apple
    echo ${fruits[@]}  # Outputs all elements
    ```

#### Map (Associative Arrays)
- Bash also supports associative arrays (maps) where keys are mapped to values.
- Syntax:
    ```bash
    declare -A map_name
    map_name[key1]=value1
    map_name[key2]=value2
    ```
- Example:
    ```bash
    declare -A capitals
    capitals["France"]="Paris"
    capitals["Germany"]="Berlin"
    capitals["Italy"]="Rome"
    echo ${capitals["France"]}  # Outputs: Paris
    for country in "${!capitals[@]}"; do
        echo "$country: ${capitals[$country]}"
    done
    ```
- Note: Associative arrays are supported in Bash 4.0 and later.

### 11. Loops
#### for Loop
- Syntax:
    ```bash
    for variable in list; do
        # commands
    done
    ```
- Example:
    ```bash
    for i in {1..5}; do
        echo "Number: $i"
    done
    ```

#### until Loop
- Syntax:
    ```bash
    until [ condition ]; do
        # commands
    done
    ```
- Example:
    ```bash
    count=1
    until [ $count -gt 5 ]; do
        echo "Count: $count"
        count=$((count + 1))
    done
    ```

### 12. Redirection
- Redirect output to a file:
    ```bash
    command > file.txt
    ```
- Append output to a file:
    ```bash
    command >> file.txt
    ```
- Redirect errors:
    ```bash
    command 2> error.log
    ```
- Redirect both output and errors:
    ```bash
    command > output.log 2>&1
    ```

### 13. Background Processes
- Run a command in the background:
    ```bash
    command &
    ```
- View background jobs:
    ```bash
    jobs
    ```
- Bring a background job to the foreground:
    ```bash
    fg %job_number
    ```

### 14. Environment Variables
- View all environment variables:
    ```bash
    printenv
    ```
- Set an environment variable:
    ```bash
    export VAR_NAME=value
    ```
- Access an environment variable:
    ```bash
    echo $VAR_NAME
    ```
### 15. Command-Line Arguments
- Bash scripts can accept arguments passed from the command line.
- Access arguments using `$1`, `$2`, ..., `$n` for the first, second, ..., nth argument.
- `$0` contains the script's name.
- `$#` gives the number of arguments passed.
- `$@` and `$*` represent all arguments.

#### Example:
    ```bash
    #!/bin/bash
    echo "Script name: $0"
    echo "First argument: $1"
    echo "Second argument: $2"
    echo "All arguments: $@"
    echo "Number of arguments: $#"
   
    ```

#### Looping through arguments:
    ```bash
    #!/bin/bash
    for arg in "$@"; do
        echo "Argument: $arg"
    done
    ```

#### Shift Command:
- The `shift` command shifts the positional parameters to the left.
- Example:
    ```bash
    while [ $# -gt 0 ]; do
        echo "Argument: $1"
         shift
    done
     ```

### 16. Alias
`alias` is used to create shortcuts for commands.

- `alias ll='ls -l'` - Creates an alias `ll` for `ls -l`.
- `alias rm='rm -i'` - Prompts for confirmation before deleting files.
- `unalias alias_name` - Removes a specific alias.
- `unalias -a` - Removes all aliases.
there is much MUCH more...

