#include "shell.h"


int main() {
    char *command = NULL;
    size_t bufsize = 0;
    ssize_t getline_result;

    while (1) {
        printf("simple_shell> ");
        fflush(stdout);

        getline_result = getline(&command, &bufsize, stdin);
        if (getline_result == -1) {
            break;
        }

        executeCommand(command);
    }

    free(command);
    return 0;
}
