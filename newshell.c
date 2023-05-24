#include "shell.h"

int main(void)
{
    char command[100];
    const char *prompt = "$ ";

    while (1)
    {
        pid_t pid;

        printf("%s", prompt);
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            /* End of file (Ctrl+D) encountered, exit the shell */
            printf("\n");
            break;
        }

        /* Remove the trailing newline character from the command */
        command[strcspn(command, "\n")] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            /* Child process */
            if (execlp(command, command, NULL) == -1)
            {
                fprintf(stderr, "%s: command not found: %s\n", command, command);
                exit(1);
            }
        }
        else
        {
            /* Parent process */
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return (0);
}
