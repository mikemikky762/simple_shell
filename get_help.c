#include "main.h"

/**
* get_help - Display help messages for specific builtins or general help.
* @datash: Data structure containing arguments.
* Return: Always returns 0.
*/
int get_help(data_shell *datash)
{
// Check if a specific builtin name is provided in args[1]
if (datash->args[1] == 0)
aux_help_general(); // Display general help
else if (_strcmp(datash->args[1], "setenv") == 0)
aux_help_setenv(); // Display help for 'setenv' builtin
else if (_strcmp(datash->args[1], "env") == 0)
aux_help_env(); // Display help for 'env' builtin
else if (_strcmp(datash->args[1], "unsetenv") == 0)
aux_help_unsetenv(); // Display help for 'unsetenv' builtin
else if (_strcmp(datash->args[1], "help") == 0)
aux_help(); // Display help for 'help' builtin
else if (_strcmp(datash->args[1], "exit") == 0)
aux_help_exit(); // Display help for 'exit' builtin
else if (_strcmp(datash->args[1], "cd") == 0)
aux_help_cd(); // Display help for 'cd' builtin
else if (_strcmp(datash->args[1], "alias") == 0)
aux_help_alias(); // Display help for 'alias' builtin
else
write(STDERR_FILENO, datash->args[0],
_strlen(datash->args[0])); // Display an error message for unrecognized builtin

datash->status = 0;
return (1);
}
