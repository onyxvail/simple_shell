#include "onyxshell.h"

/**
 * signalHandler - Signal handler function to catch signals
 * @signalNumber: Signal number
 */
void signalHandler(int signalNumber)
{
	if (signalNumber == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "simple_shell$", 13);
	}
}
