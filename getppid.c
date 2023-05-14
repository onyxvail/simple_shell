#include <stdio.h>
#include <unistd.h>

/**
 * getppid - getppid example
 *
 * Return: Always 0.
 */

int getppid(void)
{
printf("Parent process PID: %d\n", getppid());
return (0);
}
