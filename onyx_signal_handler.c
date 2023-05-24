#include "onyxshell.h"

/**
 *sig_hand - A signal handler Fn of the command ctr+C
 *@sign: integer
 *
 *Return: VOID
 */

void sig_hand(int sign)
{
if (sign == SIGINT)
{
write(STDOUT_FILENO, "\n", 2);
write(STDOUT_FILENO, "$ ", 2);
}
}
