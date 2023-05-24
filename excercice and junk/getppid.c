#include <stdio.h>
#include <unistd.h>

/**
 * parentprocessid - getppid
 *
 * Return: Always 0.
 */
int parentprocessid(void)
{
    pid_t parent_pid;

    parent_pid = getppid();
    printf("%u\n", parent_pid);
    return (0);
}