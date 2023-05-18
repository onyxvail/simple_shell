#include "shell.h"


void executeCommand(char *command) {
    int status = system(command);

    
    if (status != 0) {
        printf("Error executing command: %d\n", status);
    }
}