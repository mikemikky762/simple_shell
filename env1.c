#include "main.h"

/**
* cmp_env_name - Compares environment variable names with the given name.
* @nenv: Name of the environment variable.
* @name: Name to compare.
* Return: 0 if they are not equal; otherwise, another value.
*/
int cmp_env_name(const char *nenv, const char *name)
{
int i;

for (i = 0; nenv[i] != '='; i++)
{
if (nenv[i] != name[i])
{
return (0);
}
}

return (i + 1);
}

/**
* _getenv - Gets the value of an environment variable.
* @name: Name of the environment variable.
* @_environ: Environment variables.
* Return: The value of the environment variable if found, or NULL otherwise.
*/
char *_getenv(const char *name, char **_environ)
{
char *ptr_env;
int i, mov;

/* Initialize ptr_env to NULL */
ptr_env = NULL;
mov = 0;

/* Compare with all environment variables */
for (i = 0; _environ[i]; i++)
{
/* If name and env are equal */
mov = cmp_env_name(_environ[i], name);

if (mov)
{
ptr_env = _environ[i];
break;
}
}

return (ptr_env + mov);
}

/**
* _env - Prints the environment variables.
* @datash: Data relevant to the shell.
* Return: 1 on success.
*/
int _env(data_shell *datash)
{
int i, j;

for (i = 0; datash->_environ[i]; i++)
{
for (j = 0; datash->_environ[i][j]; j++)
;

write(STDOUT_FILENO, datash->_environ[i], j);
write(STDOUT_FILENO, "\n", 1);
}

datash->status = 0;
return (1);
}
