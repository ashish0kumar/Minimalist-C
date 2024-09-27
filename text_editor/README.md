# Minimalist Text Editor in C

This is a minimalist text editor implemented in C that allows you to edit a specified line in a text file. You can enter the line number you wish to edit, provide new content for that line, and the editor will save the changes back to the file.

## Features

- Edit a specific line in a text file by providing the line number
- Display the file contents before and after modification
- Supports basic error handling for file operations

## Files

- `editor.c`: The C source code for the text editor.

## How to Use

1. Compile the editor:

```bash
gcc -o text_editor editor.c
```

2. Run the editor:

```bash
./text_editor <filename>
```

Replace <filename> with the path to the text file you want to edit.

3. Edit a line:
- The editor will display the current contents of the file.
- Enter the line number you want to edit.
- Provide the new content for that line.

4. View results:
- The editor will display the modified contents of the file.

## Dependencies

- GCC (or any C compiler)

## Notes

- The editor supports only basic line editing and assumes that the text file is smaller than 1024 bytes.
- Ensure that the file you want to edit exists in the specified path.
