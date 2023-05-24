#ifndef ONYX_SHELL
#define ONYX_SHELL

/* eviron global variable*/

extern char **environ;

/* Header Files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <linux/limits.h>
#include <errno.h>

extern char **environ;
int _strlen(char *str);
char *_strcpy(char *destn, char *srcs);
int _strcmpr(char *ss1, char *ss2);
char *_strcate(char *destn, char *srcs);
char *_strdupt(char *strt);
char *_strchrs(char *st, char ch);
char **onyx_token(char *strg);
char *itoa(unsigned int nm);
int intleng(int nums);
void rev_array(char *arrs, int leng);
int onyx_builtins(char **args, char *line);
void onyx_abort(char **args, char *line);
int cd(char *path, char **args);
int help(void);
void env(void);
char *findthepath(char *filename);
char *onyx_env(char *nameof);
int onyx_exec(char *cmd, char **args);
void sig_hand(int sign);
void free_arrays(char **arrs);
int onyx_p_error(int indexe, char **argss);

#endif /*ONYXSHELL_H*/
