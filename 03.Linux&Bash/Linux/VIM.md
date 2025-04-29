# Linux Revision Course

Welcome to the **Vim Section**!

## All of the commands we used

### 1. Normal mode
- `h` - Move cursor left
- `l` - Move cursor right
- `j` - Move cursor down
- `k` - Move cursor up
- `dd` - Delete the current line
- `yy` - Yank (copy) the current line
- `p` - Paste after the cursor
- `u` - Undo the last action
- `Ctrl+r` - Redo the undone action
- `:w` - Save the file
- `:q` - Quit Vim
- `:wq` - Save and quit
- `:q!` - Quit without saving
### 2. Insert mode
- `i` - Insert before the cursor
- `I` - Insert at the beginning of the line
- `a` - Append after the cursor
- `A` - Append at the end of the line
- `o` - Open a new line below the current line
- `O` - Open a new line above the current line
- `x` - Delete the character under the cursor
- `dw` - Delete from the cursor to the end of the current word
- `dd` - Delete the current line
- `d$` - Delete from the cursor to the end of the line
- `dgg` - Delete from the cursor to the beginning of the file
- `dG` - Delete from the cursor to the end of the file
- `cw` - Change the current word
- `cc` - Change the current line
- `c$` - Change from the cursor to the end of the line
### 3. Visual mode
- `v` - Start visual mode (character-wise selection)
- `V` - Start visual line mode (line-wise selection)
- `Ctrl+v` - Start visual block mode (block-wise selection)
- `y` - Yank (copy) the selected text
- `d` - Delete the selected text
- `c` - Change the selected text
- `>` - Indent the selected text
- `<` - Unindent the selected text
- `=` - Auto-indent the selected text
- `u` - Convert selected text to lowercase
- `U` - Convert selected text to uppercase

### 4. Command-line mode
- `:` - Enter command-line mode
- `:set nu` - Show line numbers
- `:set nonu` - Hide line numbers
- `:set hlsearch` - Highlight search results
- `:set nohlsearch` - Remove search highlights
- `:set ignorecase` - Ignore case in search patterns
- `:set noignorecase` - Case-sensitive search
- `:set incsearch` - Incremental search
- `:set noincsearch` - Disable incremental search
- `:!` - Run a shell command
- `:r` - Read content from a file into the current buffer
- `:e` - Open a file in Vim
- `:bd` - Close the current buffer
- `:sp` - Split the window horizontally
- `:vsp` - Split the window vertically
- `:tabnew` - Open a new tab
- `:tabn` - Switch to the next tab
- `:tabp` - Switch to the previous tab
- `:tabc` - Close the current tab

### 5. Recording and Macros
- `q<register>` - Start recording a macro into the specified register (e.g., `qa` to record into register `a`).
- `q` - Stop recording the macro.
- `@<register>` - Play back the macro stored in the specified register (e.g., `@a` to play back the macro in register `a`).
- `@@` - Replay the last executed macro.
- `:reg` - View the contents of all registers, including recorded macros.

### 6. Search and Replace
- `/pattern` - Search forward for "pattern".
- `?pattern` - Search backward for "pattern".
- `n` - Repeat the last search in the same direction.
- `N` - Repeat the last search in the opposite direction.
- `:%s/old/new/g` - Replace all occurrences of "old" with "new" in the entire file.
- `:%s/old/new/gc` - Replace all occurrences of "old" with "new" in the entire file, with confirmation.
- `:s/old/new/` - Replace the first occurrence of "old" with "new" in the current line.
- `:s/old/new/g` - Replace all occurrences of "old" with "new" in the current line.
- `:noh` - Clear search highlighting.

