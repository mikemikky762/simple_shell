#include "main.h"

/**
* strcat_cd - Concatenate error messages components.
*
* @datash: Relevant data (directory).
* @msg: Message to print.
* @error: Output message.
* @ver_str: Line counter as a string.
* Return: Error message.
*/
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
char *illegal_flag;

_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, ver_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, msg);

if (datash->args[1][0] == '-')
{
illegal_flag = malloc(3);
illegal_flag[0] = '-';
illegal_flag[1] = datash->args[1][1];
illegal_flag[2] = '\0';
_strcat(error, illegal_flag);
free(illegal_flag);
}
else
{
_strcat(error, datash->args[1]);
}

_strcat(error, "\n");
return (error);
}

/**
* error_get_cd - Generate an error message for the cd command in get_cd.
* @datash: Relevant data (directory).
* Return: Error message.
*/
char *error_get_cd(data_shell *datash)
{
int length, len_id;
char *error, *ver_str, *msg;

ver_str = aux_itoa(datash->counter);

if (datash->args[1][0] == '-')
{
msg = ": Illegal option ";
len_id = 2;
}
else
{
msg = ": can't cd to ";
len_id = _strlen(datash->args[1]);
}

length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
error = malloc(sizeof(char) * (length + 1));

if (error == NULL)
{
free(ver_str);
return (NULL);
}

error = strcat_cd(datash, msg, error, ver_str);

free(ver_str);

return (error);
}

/**
* error_not_found - Generate a generic error message for "command not found."
* @datash: Relevant data (counter, arguments).
* Return: Error message.
*/
char *error_not_found(data_shell *datash)
{
int length;
char *error;
char *ver_str;

ver_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(ver_str);
length += _strlen(datash->args[0]) + 16;
error = malloc(sizeof(char) * (length + 1));

if (error == NULL)
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
_strcat(error, ": not found\n");

free(ver_str);
return (error);
}

/**
* error_exit_shell - Generate a generic error message for "exit" in get_exit.
* @datash: Relevant data (counter, arguments).
* Return: Error message.
*/
char *error_exit_shell(data_shell *datash)
{
int length;
char *error;
char *ver_str;

ver_str = aux_itoa(datash->counter);
length = _strlen(datash->av[0]) + _strlen(ver_str);
length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
error = malloc(sizeof(char) * (length + 1));

if (error == NULL)
{
free(ver_str);
return (NULL);
}

_strcpy(error, datash->av[0]);
_strcat(error, ": ");
_strcat(error, ver_str);
_strcat(error, ": ");
_strcat(error, datash->args[0]);
_strcat(error, ": Illegal number: ");
_strcat(error, datash->args[1]);
_strcat(error, "\n\0");

free(ver_str);

return (error);
}
