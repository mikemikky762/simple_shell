#include "main.h"

/**
* free_data - Frees the allocated memory in the data structure.
* @datash: The data structure.
* Return: None.
*/
void free_data(data_shell *datash)
{
unsigned int i;

for (i = 0; datash->_environ[i]; i++)
{
free(datash->_environ[i]);
}

free(datash->_environ);
free(datash->pid);
}

/**
* set_data - Initializes the data structure with necessary values.
* @datash: The data structure.
* @av: The argument vector.
* Return: None.
*/
void set_data(data_shell *datash, char **av)
{
unsigned int i;

datash->av = av;
datash->input = NULL;
datash->args = NULL;
datash->status = 0;
datash->counter = 1;

for (i = 0; environ[i]; i++)
{
/* Count the number of environment variables. */
}

datash->_environ = malloc(sizeof(char *) * (i + 1));

for (i = 0; environ[i]; i++)
{
datash->_environ[i] = _strdup(environ[i]);
}

datash->_environ[i] = NULL;
datash->pid = aux_itoa(getpid());
}

/**
* main - The main entry point of the shell program.
* @ac: The argument count.
* @av: The argument vector.
* Return: Always returns 0 on success.
*/
int main(int ac, char **av)
{
data_shell datash;
(void)ac; /* Suppress unused parameter warning. */

signal(SIGINT, get_sigint); /* Register the Ctrl+C signal handler. */
set_data(&datash, av); /* Initialize the data structure. */
shell_loop(&datash); /* Start the shell loop. */
free_data(&datash); /* Free allocated memory. */

if (datash.status < 0)
return (255); /* Return 255 for negative status. */
{
return (datash.status); /* Return the status code. */
}
}
