#include "main.h"

/**
* get_sigint - Signal handler function for handling Ctrl+C in the prompt.
* @sig: The signal number.
*/
void get_sigint(int sig)
{
(void)sig; // Suppress unused parameter warning.
write(STDOUT_FILENO, "\n^-^ ", 5); // Print a friendly message.
}
