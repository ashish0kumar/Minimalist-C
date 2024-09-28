# Minimalist Snake Game in C

This is a minimalist Snake game written in C using the `ncurses` library. The player controls a snake that moves around the screen, consumes food, and grows longer. The game continues until the player chooses to exit.

## Features

- Control the snake represented by `~` using arrow keys
- Eat food represented by `@` to grow the snake
- Boundary checking to keep the snake within the terminal window
- Simple graphics using `ncurses`

## Files

- `snake.c`: The C source code for the Snake game.

## How to Use

1. **Install ncurses:** Make sure you have the `ncurses` library installed on your system. You can typically install it using your package manager. For example, on Ubuntu:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

2. **Compile the game:**

```bash
gcc -o snake_game snake.c -lncurses
```

3. **Run the game:**

```bash
./snake_game
```

4. Control the snake:
- Use the arrow keys to move the snake around the screen.
- The snake will grow longer each time it eats the food.

5. Exit the game:
- To exit, you can close the terminal or interrupt the program (`Ctrl+C`).

## Dependencies

- GCC (or any C compiler)
- `ncurses` library

## Notes

- The game uses terminal dimensions for movement, so it will adapt to the size of your terminal window.
- Make sure to run the game in a terminal that supports ncurses for the best experience.
