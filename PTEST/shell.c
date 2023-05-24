#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) {
    printf("cisfun$ ");
    read = getline(&line, &len, stdin);
    if (read == -1) {
      if (feof(stdin)) {
        break;
      } else {
        perror("getline");
        exit(1);
      }
    }

    // Split the command line into words.
    char *argv[1024];
    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Execute the command.
    int status;
    if (fork() == 0) {
      if (execvp(argv[0], argv) == -1) {
        perror("execvp");
        exit(1);
      }
    }

    wait(&status);
  }

  free(line);
  return 0;
}
