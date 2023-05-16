#ifndef ONYXSHELL_H
#define ONYXSHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>


int builtInCheck(char **arguments, char **environment);
int convertStringToInteger(char *str);
int printenvar(char **arguments, char **environment);
int exitshell(char **arguments, char **environment);
void freeArray(char **array);
void freeStrings(int status, const unsigned int count, ...);
char *getenv(char *name, char **env_list);
void checkpath(char **command, char **environment);
char *copyMemory(char *destination, const char *source, unsigned int n);
void signalHandler(int signalNumber);
int main(int argc, char *argv[], char **envp);

#endif /*ONYXSHELL_H*/
