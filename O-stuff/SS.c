#include "onyxshell.h"

/**
 * signalHandler - Handles the SIGINT signal
 * @signalNumber: The signal number received
 *
 * Return: None
 */
void signalHandler(int signalNumber)
{
    if (signalNumber == SIGINT)
    {
        write(STDOUT_FILENO, "\n", 1);
        write(STDOUT_FILENO, "simple_shell$", 13);
    }

    printf("Received signal: %d\n", signalNumber);
}

int main(int argc, char *argv[], char **envp)
{
    char *input = NULL;
    char **arguments = NULL;
    int status;
    pid_t child_pid;
    (void)argc;

    while (true)
    {
        input = NULL;
        signal(SIGINT, signalHandler);
        if (get_input(&input) == -1)
            continue;
        arguments = split_input(input);
        if (!arguments)
        {
            free_resources(99, arguments, input);
            continue;
        }
        free_resources(99, arguments, input);
        if (builtInCheck(arguments, envp))
            continue;
        child_pid = fork();
        if (child_pid == 0)
        {
            if (execute_path(arguments, envp) == -1)
            {
                perror(*argv);
                free_resources(99, arguments, NULL);
                exit(0);
            }
            if (execve(arguments[0], arguments, NULL) == -1)
            {
                perror(*argv);
                free_resources(99, arguments, NULL);
                exit(0);
            }
        }
        else
        {
            free_resources(99, arguments, NULL);
            if (!wait(&status))
                break;
        }
    }
    return (0);
}
