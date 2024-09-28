# Minimalist Hex Editor in C

This is a minimalist Hex Editor written in C. It allows you to open a file (e.g., `index.html`), view its contents in hexadecimal format, modify any byte, and save the changes back to the file.

## Features

- **View file in hexadecimal:** The program displays the file's contents in hexadecimal.
- **Edit hex values:** You can modify specific bytes by entering a file offset and a new hex value.
- **Save changes:** After making modifications, you can save the changes back to the file.

## Files

- `hexeditor.c`: The C source code for the hex editor.

## How to Use

1. **Compile the hex editor:**

```bash
gcc -o hexeditor hexeditor.c
```

2. **Run the hex editor:**

```bash
./hexeditor <file>
```

Replace `<file>` with the file you want to edit (e.g., `index.html`).

Example:

```bash
./hexeditor index.html
```

3. **Commands:** Once the file is loaded, you can use the following commands to interact with the file:

- p: Print the file content from a specific location in hexadecimal format.
    - Enter a location (byte offset) from which you want to start printing.
    - The editor will display 10 bytes starting from that location.

- e: Edit the file content at a specific location.
    - Enter a location (byte offset) where you want to edit.
    - Provide a new hexadecimal value (e.g., `0xFF`).
    - The value at that location will be updated to the new hex value.

- s: Save the changes and exit the program.

4. **Example usage:**

```bash
Enter a command ('p' to print, 'e' to edit, 's' to save and exit): p
Enter location to print from: 50

<Displays 10 bytes starting at location 50>

Enter a command ('p' to print, 'e' to edit, 's' to save and exit): e
Enter location to edit: 55
Enter new hex value (e.g., 0xFF): 0xAB
Value at location 55 changed to 0xAB
```

5. **Save changes:** After editing, use the `s` command to save changes and exit.

## Dependencies

- No external libraries required; only standard C libraries.

## Notes

- The editor works on binary files. Be cautious when editing as it directly modifies the file contents.
- It reads and writes up to 1024 bytes from the file. If the file is larger, it will only handle the first 1024 bytes.
