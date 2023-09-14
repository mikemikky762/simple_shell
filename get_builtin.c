#include "main.h"

/**
* get_builtin - Match a command with its corresponding builtin function.
* @cmd: Command to match.
* Return: Function pointer to the corresponding builtin command.
*/
int (*get_builtin(char *cmd))(data_shell *)
{
// Array of built-in command name and function pairs
builtin_t builtin[] = {
{ "env", _env },
{ "exit", exit_shell },
{ "setenv", _setenv },
{ "unsetenv", _unsetenv },
{ "cd", cd_shell },
{ "help", get_help },
{ NULL, NULL }
};
int i;

// Iterate through the array to find a matching command
for (i = 0; builtin[i].name; i++)
{
if (_strcmp(builtin[i].name, cmd) == 0)
break;
}

// Return the function pointer corresponding to the matched command
return (builtin[i].f);
}
