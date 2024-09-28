#include <stdio.h>

void print_hex(unsigned char* buffer, int num) {
  for (int i = 0; i < num; i++) {
    if (i % 10 == 0) {
      printf("\n");
    }
    printf("%.2X ", buffer[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  FILE* f = fopen(argv[1], "rb");
  if (!f) {
    perror("Failed to open file");
    return 1;
  }

  unsigned char buffer[1024];
  int num_of_bytes = fread(buffer, 1, sizeof(buffer), f);
  if (num_of_bytes <= 0) {
    perror("Failed to read file");
    fclose(f);
    return 1;
  }
  fclose(f);

  // Print the initial content in hexadecimal
  print_hex(buffer, num_of_bytes);

  while (1) {
    char cmd;
    int loc;
    printf("\nEnter a command ('p' to print, 'e' to edit, 's' to save and exit): ");
    scanf(" %c", &cmd);  // Space before %c to ignore leading whitespace

    if (cmd == 'p') {
      printf("Enter location to print from: ");
      scanf("%d", &loc);

      if (loc >= 0 && loc < num_of_bytes) {
        print_hex(buffer + loc, 10);  // Print 10 bytes starting from loc
      } else {
        printf("Invalid location!\n");
      }
    } else if (cmd == 'e') {
      printf("Enter location to edit: ");
      scanf("%d", &loc);

      if (loc >= 0 && loc < num_of_bytes) {
        unsigned int value;
        printf("Enter new hex value (e.g., 0xFF): ");
        scanf("%x", &value);

        buffer[loc] = (unsigned char)value;
        printf("Value at location %d changed to 0x%.2X\n", loc, buffer[loc]);
      } else {
        printf("Invalid location!\n");
      }
    } else if (cmd == 's') {
      printf("Saving changes and exiting...\n");
      break;
    } else {
      printf("Unknown command! Please try again.\n");
    }
  }

  // Save the modified buffer to the file
  f = fopen(argv[1], "wb");
  if (!f) {
    perror("Failed to open file for writing");
    return 1;
  }

  if (fwrite(buffer, 1, num_of_bytes, f) != num_of_bytes) {
    perror("Failed to write file");
  }
  fclose(f);

  return 0;
}
