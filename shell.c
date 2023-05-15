#include "shell.h"

int onyxshell_cd(char **args);
int onyxshell_exit(char **args);
char *builtin_str[] = {"cd", "exit"};

int (*builtin_function[]) (char **) = {&onyxshell_cd, &onyxshell_exit};

int onyxshell_builtins()
{
return sizeof(builtin_str) / sizeof(char *);
}

int onyxshell_cd(char **args)
{
if (args[1] == NULL)
{
    fprintf(stderr, "Onyxshell: expected argument to cd\n");
}
else
{
    if (chdir(args[1]) != 0)
    {
        perror("Onyxhsell");
    }
}
return (1);
}

int onyxshell_exit(char **args)
{
    return (0);
}

int onyxshell_process(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
    if (execvp(args[0], args) == -1)
    {
        perror("Onyxshell");
    }
exit(EXIT_FAILURE);
    
} else if (pid < 0)
{
    perror("Onyxshell");
}
else
{
    do
    {
        waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    {
        return (1);
    }
}
}

int onyxshell_execute(char **args)
{
int i;
if (args[0] == NULL)
{
    return (1);
}
for (i =0; i < onyxshell_builtins(); i++)
{
    if (strcmp(args[0], builtin_str[i]) == 0)
    {
        return (*builtin_function[i])(args);
    }
}
return onyxshell_process(args);
}

char read_line(void)
{
    char *line = NULL;
ssize_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
    if (feof(stdin))
    {
        exit(EXIT_SUCCESS)
    }
    else
    {
        perror("Onyxshell: getline\n");
        exit(EXIT_FAILURE);
    }
}
return (line);
}

#define Onyxshell_BUFSIZE 1024
int bufsize = Onyxshell_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;
if (!buffer)
{
    fprintf(stderr, "Onyxshell: allocation error\n");
    exit(EXIT_FAILURE);
}
while (1)
{
    c = getchar();
    if (c = EOF)
    {
        exit(EXIT_SUCCESS);
    }
    else if (c == '\n')
    {
        buffer[position] = '\0' ;
        return buffer;
    } else {
        buffer[position] = c;
    }
    position++;
    if (position >= bufsize)
    {
        bufsize += Onyxshell_BUFSIZE;
        buffer = realloc(buffer, bufsize);
        if (!buffer)
        {
            fprintf(stderr, "Onyxshell: aloocation error\n");
            exit(EXIT_FAILURE);
        }
    }
}

#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"
char **split_line(char *line)
{
    int bufsize = TOKEN_BUFSIZE, position = 0;
    char **tokens = mallor9(bufsize * sizeof(char *));
    char *token, **tokens_backup;
    if (!tokens)
    {
        fprintf(stderr, "Onyxshell: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, TOKEN_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;
        if (position >= bufsize)
        {
            bufsize += TOKEN_BUFSIZE;
            tokens_backup = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                free(tokens_backup);
                fprintf(stderr, "Onyxshell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, TOKEN_DELIM);
    }
    tokens[position] = NULL;
    return (tokens);
}

void prompt(void)
{
char *line;
char **args;
int status;
do
{
    printf("Onyxhsell>> ");
    line = read_line();
    args = split_line(line);
    status = onyxshell_execute(args);
    free(line);
    free(args);
} while (status);
}

int main(int argc, char **argv)
{
prompt();
return (EXIT_SUCCESS); 
}
