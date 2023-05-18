#ifndef ONYXSHELL_H
#define ONYXSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIMITERS " \t\r\n\a"

char **split_input(char *input);
int get_input(char **input);
int execute_path(char **arguments, char **envp);
void checkpath(char **command, char **environment);
int get_input(char **input);
char **split_input(char *input);
void free_resources(void *ptr);
int builtInCheck(char **arguments, char **environment);
/* unsigned int stringLength(const char *str); */
int convertStringToInteger(char *str);

int printenvar(char **environment);
int exitshell(char **arguments);

void freeArray(char **array);
void freeStrings(int status, const unsigned int count, ...);
char *copyMemory(char *destination, const char *source, unsigned int n);
void signalHandler(int signalNumber);
int main(int argc, char *argv[], char **envp);
/* int compareStrings(const char *str1, const char *str2); */

/* char *concatenateStrings(const char *str1, const char *str2); */
char *getEnvironmentVariable(const char *name, char **environment);


char *getenv_custom(char *name, char **env_list);

int compareStrings(char *str1, char *str2);
char *concatenateStrings(char *str1, char *str2);
int stringLength(char *str);

#endif /*ONYXSHELL_H*/
