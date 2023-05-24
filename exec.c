#include "shell.h"

/**
 * execute_command - Execute the command
 * @args: Array of command arguments
 * @num_args: Number of arguments
 * @program_name: Name of the shell program
 *
 * This function executes the given command with the provided arguments.
 * It handles repeating the command multiple times and trimming spaces
 * for the "/bin/ls" command.
 */
void execute_command(char *args[], int num_args, char *program_name)
{
int repeat = 1;
int i;

if (num_args > 1 && isdigit(args[num_args - 1][0]))
{
repeat = atoi(args[num_args - 1]);
args[num_args - 1] = NULL;
num_args--;
}

for (i = 0; i < repeat; i++)
{
pid_t pid = fork();
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
fprintf(stderr, "%s: command not found: %s\n", program_name, args[0]);
exit(1);
}
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
break;  /* Exit the loop if the command executed successfully */

}
}
}
