#include <stdio.h>
#include <unistd.h>

int getppidc(void) {
    pid_t parent_pid = getppid();
    printf("Parent PID: %u\n", parent_pid);

    return 0;
}
