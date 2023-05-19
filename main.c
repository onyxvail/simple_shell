#include "shell.h"
int main() {
  char *command = NULL;
  size_t bufsize = 0;
  ssize_t getline_result;
  int status;

  while (1) {
    printf("simple_shell> ");
    fflush(stdout);

    getline_result = getline(&command, &bufsize, stdin);
    if (getline_result == -1) {
      break;
    }

    status = system(command);
    if (status != 0) {
      printf("Error executing command: %d\n", status);
    }

    
  }
    free(command);
    return 0;
}
