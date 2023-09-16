#include "main.h"

/**
* error_env - generate error messages for env in get_env.
* @datash: data relevant (counters, arguments)
* Return: error messages.
*/
char *error_env(data_shell *datash)
{
int ln;
char *error;
char *ver_str;

ver_str = aux_itoa(datash->counter);
ln = _strlen(datash->av[0]) + _strlen(ver_str) + _strlen(datash->args[0]) + 27;
/* Adjusted length calculation*/
error = malloc(sizeof(char) * (ln + 1));

if (error == NULL)
{
free(ver_str);
return (NULL);
}

snprintf(error, length + 1, "%s: \n", datash->av[0], ver_str, datash->args[0]);
free(ver_str);

return (error);
}

/**
* error_path_126 - generate error msgs for path and falre denied permission.
* @datash: data relevant (counter, arguments).
* Return: The error strings.
*/
char *error_path_126(data_shell *datash)
{
int ln;
char *error;
char *ver_str;

ver_str = aux_itoa(datash->counter);
ln = _strlen(datash->av[0]) + _strlen(ver_str) + _strlen(datash->args[0]) + 27;
/* Adjusted length calculation */
error = malloc(sizeof(char) * (ln + 1));

if (error == NULL)
{
free(ver_str);
return (NULL);
}

snprintf(error, length + 1, "%s: \n", datash->av[0], ver_str, datash->args[0]);
free(ver_str);

return (error);
}
