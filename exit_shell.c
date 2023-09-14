#include "main.h"

/**
* exit_shell - Function to gracefully exit the shell.
* @datash: Data structure containing relevant information (status and args).
* Return: 0 on successful exit.
*/
int exit_shell(data_shell *datash)
{
unsigned int ustatus;
int is_digit;
int str_len;
int big_number;

if (datash->args[1] != NULL)
{
ustatus = _atoi(datash->args[1]);
is_digit = _isdigit(datash->args[1]);
str_len = _strlen(datash->args[1]);
big_number = ustatus > (unsigned int)INT_MAX;

if (!is_digit || str_len > 10 || big_number)
{
// Error message for invalid exit status
get_error(datash, 2);
datash->status = 2;
return (1);
}
// Set the shell's status to the provided exit status (wrapped around 256)
datash->status = (ustatus % 256);
}
// Return 0 indicating successful shell exit
return (0);
}
