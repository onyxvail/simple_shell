#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"
#define Onyxshell_BUFSIZE 1024

extern char *builtin_str[];
extern int (*builtin_function[]) (char **);

int onyxshell_execute(char **args);
char *read_line(void);
int onyxshell_builtins();
int onyxshell_cd(char **args);

int onyxshell_process(char **args);
char **split_line(char *line);
void prompt(void);


int onyxshell_cd(char **args);
int onyxshell_exit();



#endif /*SHELL_H*/
