#include "main.h"

/**
* error_env - generates error messages for env in get_env.
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
* error_path_126 - error messages for path and failure denied permission.
* @datash: data relevants (counter, arguments).
*
* Return: The error strings.
*/
char *error_path_126(data_shell *datash)
{
int length;
char *ver_str;
char *error;

ver_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(ver_str);
length += _strlen(datash->args[0]) + 24;
error = malloc(sizeof(char) * (length + 1));
if (error == 0)
{
free(error);
free(ver_str);
return (NULL);
}
_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, ver_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ": Permission denied\n");
_strcat(error, "\0");
free(ver_str);
return (error);
}
