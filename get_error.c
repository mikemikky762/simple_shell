#include "main.h"

/**
* get_error - Handle errors based on the given evaluation code.
* @datash: Data structure containing arguments and status.
* @eval: The error evaluation code.
* Return: The error message.
*/
int get_error(data_shell *datash, int eval)
{
char *error;

// Handle different error cases based on the evaluation code
switch (eval)
{
case -1:
error = error_env(datash);
break;
case 126:
error = error_path_126(datash);
break;
case 127:
error = error_not_found(datash);
break;
case 2:
if (_strcmp("exit", datash->args[0]) == 0)
error = error_exit_shell(datash);
else if (_strcmp("cd", datash->args[0]) == 0)
error = error_get_cd(datash);
break;
}

// If an error message is generated, print it to STDERR
if (error)
{
write(STDERR_FILENO, error, _strlen(error));
free(error);
}

// Set the status based on the evaluation code and return it
datash->status = eval;
return (eval);
}
