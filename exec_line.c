#include "main.h"


/**
* exec_line - Functions that identify built-ins and commands and executes it.
* @datash: Data structures containing relevant arguments.
* Return: 1 on success.
*/
int exec_line(data_shell *datash)
{
int (*builtin)(data_shell *datash);

if (datash->args[0] == NULL)
return (1);

builtin = get_builtin(datash->args[0]);

if (builtin != NULL)
return (builtin(datash));

return (cmd_exec(datash));
}
