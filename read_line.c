#include "main.h"

/**
* read_line - Reads input from standard input and returns it as a string.
* @i_eof: Pointer to store the return value of the getline function.
* Return: A dynamically allocated string containing the input.
*/
char *read_line(int *i_eof)
{
char *input = NULL;     /* Pointer to store the input string. */
size_t bufsize = 0;     /* Initial buffer size for getline. */

*i_eof = getline(&input, &bufsize, stdin);
/* Read a line of input from stdin. */

return (input);
}
