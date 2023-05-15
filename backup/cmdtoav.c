#include "shell.h"

/**
 * main - entry point of the program
 *
 * Return: always 0 (success)
 */
int main(int argc, char **argv)
{
char **words = split_string(argv[0], " ");
int i;
for (i = 0; words[i] != NULL; i++)
{
printf("%s\n", words[i]);
}
free(words);
return (0);
}

char **split_string(char *str, char *delim) {
  char **words = NULL;
  int word_count = 0;
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == *delim) {
      continue;
    }
    if (words == NULL) {
      words = malloc(sizeof(char *) * 2);
    } else {
      words = realloc(words, sizeof(char *) * (word_count + 2));
    }
    words[word_count] = malloc(sizeof(char) * (i + 1));
    strncpy(words[word_count], str, i);
    words[word_count][i] = '\0';
    word_count++;
  }
  words = realloc(words, sizeof(char *) * (word_count + 1));
  words[word_count] = NULL;
  return words;
}
