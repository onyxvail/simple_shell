#ifndef ONYXSHELL_H
#define ONYXSHELL_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

/* Global variable */
extern char **environ;

/* Macros */
#define BUFSIZE 256
#define TOKENSIZE 64
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define ONYXPROMPT "$ "
#define SUCCESS (1)
#define FAILURE (-1)
#define NEUTRAL (0)

/* Struct */

/**
 * struct shl_data - This is global data struct
 * @line: the line of the input
 * @args: the arguments of the  token
 * @error_msg: the global path
 * @cmd: the parsed command
 * @index: the command index
 * @oldpwd: the old path visited
 * @env: the environnment
 *
 * Description: A structure contains all the variables ,memory
 * accessability
 * needed to manage
 * the onyxshell program
 */
typedef struct shl_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} shl_t;
/**
 * struct builtin - Manage the builtin functions
 * @cmd: the command line on string form
 * @f: the associated function
 *
 * Description: this struct made to manage builtins cmd
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(shl_t *data);
} blt_t;
/* ----------Process prototype------------*/
int reading_line(shl_t *);
int spliting_line(shl_t *);
int parsing_line(shl_t *);
int processing_cmd(shl_t *);

/* ----------String prototype------------*/
char *_strdupl(char *str);
char *_strcatt(char *fst, char *snd);
int _strlen(char *str);
char *_strchr(char *str, char c);
int _strcmp(char *s1, char *s2);

/* ----------More String prototype-------*/
char *_strcpyy(char *destn, char *source);

/* ----------Memory prototype------------*/
void *_reallocate(void *ptr, unsigned int o_size, unsigned int n_size);
char *_memsett(char *s, char byt, unsigned int n);
char *_memcpyy(char *destn, char *srcs, unsigned int nb);
int free_datas(shl_t *);

/* ----------Tools prototype-------------*/
void *fill_arr(void *ar, int elm, unsigned int leng);
void sig_handler(int sig);
char *_getenv(char *path_nm);
void index_cmds(shl_t *datas);
void array_revs(char *arrs, int leng);

/* ----------More tools prototype--------*/
char *_itoa(unsigned int nt);
int intleng(int numb);
int _atoi(char *c);
int printing_error(shl_t *data);
int write_hist(shl_t *data);
int _isitalpha(int cc);

/* -------------Builtins-----------------*/
int aborting_prgm(shl_t *data);
int changing_dir(shl_t *data);
int displaying_help(shl_t *data);
int handling_builtins(shl_t *data);
int check_builtin(shl_t *data);

/* -------------Parse-----------------*/
int ispath_form(shl_t *data);
void isshort_form(shl_t *data);
int is_builtin(shl_t *data);

#endif /* ONYXSHELL_H */
