# 📚🖱️ Minimalist X11 GUI Window in C

This project demonstrates how to create a simple graphical window using the X11 library on Linux. It opens a basic GUI window and displays a string using the X11 API.

![chat_server](/screenshots/x11_gui.png)

## ✨ Features

- Creates an X11 window on Linux.
- Draws a text string within the window using the `XDrawString` function.
- Utilizes basic event handling to redraw content when the window is exposed.

## 📂 Files

- `gui.c`: The source file containing the code for the X11 window.


## 🚀 How to Use

1. **Compile the Program:**

```bash
gcc -o gui gui.c -lX11
```
This will create an executable file named `gui`.

2. **Run the Program:**

```bash
./gui
```

A simple window will open with the text `A Simple X11 GUI Window` displayed inside it.
You can exit the program by closing the window or pressing `Ctrl+C` in the terminal.


## ⚙️ How It Works

**Key X11 Functions:**

- `XOpenDisplay(NULL)`: Opens a connection to the X server.
- `XCreateSimpleWindow()`: Creates a window with specified dimensions and colors.
- `XMapWindow()`: Maps (shows) the window on the screen.
- `XSelectInput()`: Specifies that the window will listen for Expose events.
- `XNextEvent()`: Waits for and retrieves the next event from the event queue.
- `XDrawString()`: Draws a string of text at a specific position within the window when an Expose event is triggered.

**Event Handling:**

The program waits in an infinite loop for the Expose event (which occurs when the window is initially shown or needs to be redrawn), and then draws the text inside the window.


## 📦 Dependencies

To compile and run this program, you need the following:

- A Linux system with the X11 development libraries installed.

To install X11 development libraries on Ubuntu or other Debian-based systems, use:

```bash
sudo apt-get install libx11-dev
```


## 🗒️ Notes

- This is a basic X11 application that demonstrates how to create a simple graphical window.
- It can be extended with more functionality, such as handling other types of events (keyboard input, mouse clicks, etc.).
