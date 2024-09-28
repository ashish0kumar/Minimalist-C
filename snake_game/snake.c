#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

void initialize();
void cleanup();
void draw(WINDOW* win, int posX, int posY, int foodX, int foodY);
void generateFood(int* foodX, int* foodY, int posX, int posY);

int main() {
  int posX = 0;
  int posY = 0;
  int foodX, foodY;
  int dirX = 1;
  int dirY = 0;

  initialize();

  // Generate initial food position
  generateFood(&foodX, &foodY, posX, posY);

  while (1) {
    int pressed = getch();

    if (pressed == KEY_LEFT) {
      dirX = -1; dirY = 0;
    } else if (pressed == KEY_RIGHT) {
      dirX = 1; dirY = 0;
    } else if (pressed == KEY_UP) {
      dirX = 0; dirY = -1;
    } else if (pressed == KEY_DOWN) {
      dirX = 0; dirY = 1;
    }

    posX += dirX;
    posY += dirY;

        // Boundary checking
    if (posX < 0) posX = 0;
    if (posX >= COLS) posX = COLS - 1;
    if (posY < 0) posY = 0;
    if (posY >= LINES) posY = LINES - 1;

    // Check for food consumption
    if (foodX == posX && foodY == posY) {
      generateFood(&foodX, &foodY, posX, posY);
    }

    draw(stdscr, posX, posY, foodX, foodY);
    usleep(100000);
  }

  cleanup();
  return 0;
}

void initialize() {
  initscr();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(FALSE);
}

void cleanup() {
  endwin();
}

void draw(WINDOW* win, int posX, int posY, int foodX, int foodY) {
  erase();
  mvaddstr(posY, posX, "~");
  mvaddstr(foodY, foodX, "@");
  refresh();
}

void generateFood(int* foodX, int* foodY, int posX, int posY) {
  do {
    *foodX = rand() % COLS;
    *foodY = rand() % LINES;
  } while (*foodX == posX && *foodY == posY);
}
