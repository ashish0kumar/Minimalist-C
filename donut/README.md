# 🍩 donut.c

This is a minimalist spinning donut animation written in C. The program renders a rotating 3D torus in the terminal using ASCII characters without using any external math library, relying solely on basic arithmetic and trigonometric approximations implemented in the code.

![donut.c](/screenshots/donut.gif)

## 📂 Files

- `donut.c`:  The C source code for the donut animation.

## 🚀 How to Use

**1. Compile the file:**

```bash
gcc -o donut donut.c
```

**2. Run the animation:**

```bash
./donut
```

## 🗒️ Notes

- The program is designed to be run in a terminal that supports ANSI escape codes for clearing the screen and repositioning the cursor.

- The code avoids floating-point operations by relying on fixed-point arithmetic for efficiency.

- The animation runs indefinitely. To stop it, use `Ctrl+C`.