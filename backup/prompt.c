#include "shell1.h"

int main() {
  char *line = malloc(100);
  size_t n = sizeof(line);
  while (1) {
    printf("$ ");
    getline(&line, &n, stdin);
    if (feof(stdin)) {
      break;
    }
    printf("%s\n", line);
  }
  free(line);
  return 0;
}
