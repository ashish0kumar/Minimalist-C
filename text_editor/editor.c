#include <stdio.h>
#include <string.h>

void edit_line(char* buffer, int current_line) {
  for (int i = 0; i < current_line; i++) {
    char* newline = strchr(buffer, '\n');
    if (newline == NULL) return;
    buffer = newline + 1;
  }

  char* line_end = strchr(buffer, '\n');
  if (line_end == NULL) return;

  char saved[1024] = {0};
  strcpy(saved, line_end + 1);

  printf("Enter new content: ");
  scanf("%1023s", buffer);

  strcat(buffer, "\n");
  strcpy(buffer + strlen(buffer), saved);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE* f = fopen(argv[1], "r");
  if (f == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char buffer[1024] = {0};
  fread(buffer, 1, sizeof(buffer) - 1, f);
  fclose(f);

  printf("Contents:\n%s\n", buffer);

  int current_line = 0;
  printf("Enter line number to edit: ");
  scanf("%d", &current_line);

  edit_line(buffer, current_line);

  f = fopen(argv[1], "w");
  if (f == NULL) {
    printf("Error opening file for writing.\n");
    return 1;
  }
  
  fwrite(buffer, strlen(buffer), 1, f);
  fclose(f);

  printf("Contents after editing:\n%s\n", buffer);

  return 0;
}
