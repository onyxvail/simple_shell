#include "shell.h"

int main() {
  char *command;

  printf("$ ");
  command = getline(NULL, 0, stdin);

  printf("%s\n", command);

  free(command);

  return 0;
}

char **split_command_line(char *command_line) {
  char **words = NULL;
  int word_count = 0;

  char *current_word = command_line;
  while (*current_word != '\0') {
    if (*current_word == ' ') {
      *current_word = '\0';
      words = realloc(words, sizeof(char *) * (word_count + 1));
      words[word_count++] = current_word + 1;
    }
    current_word++;
  }

  words = realloc(words, sizeof(char *) * (word_count + 1));
  words[word_count] = NULL;

  return words;
}

