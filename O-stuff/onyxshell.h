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

void execute_path(char **arguments, char **envp);
void checkpath(char **command, char **environment);
int get_input(char **input);
char **split_input(char *input);
void free_resources(int arg1, int arg2, char *arg3);
int builtInCheck(char **arguments, char **environment);
unsigned int stringLength(const char *str);
int convertStringToInteger(char *str);
int printenvar(char **arguments, char **environment);
int exitshell(char **arguments, char **environment);
void freeArray(char **array);
void freeStrings(int status, const unsigned int count, ...);
char *copyMemory(char *destination, const char *source, unsigned int n);
void signalHandler(int signalNumber);
int main(int argc, char *argv[], char **envp);
int compareStrings(const char *str1, const char *str2);


#endif /*ONYXSHELL_H*/
