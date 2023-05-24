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
    pid_t pid = fork();

    (void)num_args;

    

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

        if (!isatty(STDIN_FILENO))
        printf("($)\n");
    }
}
