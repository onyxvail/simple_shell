#include "onyxshell.h"

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
        signal(SIGINT, signal_handler);
        if (get_input(&input) == -1)
            continue;
        arguments = split_input(input);
        if (!arguments)
        {
            free_resources(99, 1, input);
            continue;
        }
        free_resources(99, 1, input);
        if (check_builtin(arguments, envp))
            continue;
        child_pid = fork();
        if (child_pid == 0)
        {
            execute_path(arguments, envp);
            if (execve(arguments[0], arguments, NULL) == -1)
            {
                perror(*argv);
                free_resources(arguments);
                exit(0);
            }
        }
        else
        {
            free_resources(arguments);
            if (!wait(&status))
                break;
        }
    }
    return 0;
}
