#include "shell.h"

int main() {
  char *command;
  char *args[10];
  int i;

  /* Read the user's input. */
  command = getenv("SHELL");
  if (command == NULL) {
    command = "/bin/sh";
  }

  /* Parse the user's input. */
  i = 0;
  while (command != NULL) {
    args[i++] = command;
    command = strtok(NULL, " ");
  }

  /* Execute the command. */
  if (execvp(args[0], args) == -1) {
    perror("execvp");
    exit(1);
  }

  /* Print the output of the command. */
  while (fgets(command, 1024, stdin) != NULL) {
    printf("%s\n", command);
  }

  /* Free any allocated memory. */
  for (i = 0; i < 10; i++) {
    free(args[i]);
  }

  /* Exit the program. */
  return 0;
}
