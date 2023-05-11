#include "shell.h"

int ls_command(void) {
    int i, status;

    for (i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // child process
            char *args[] = {"ls", "-l", "/tmp", NULL};
            if (execve("/bin/ls", args, NULL) < 0) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            // parent process
            if (wait(&status) < 0) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
