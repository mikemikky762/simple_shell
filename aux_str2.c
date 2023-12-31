#include "main.h"

/**
* _strdup - Will duplicate a string in heap memory.
* @s: Source string.
* Return: Duplicated string or NULL on failure.
*/
char *_strdup(const char *s)
{
char *new;
size_t len;

len = _strlen(s);
new = malloc(sizeof(char) * (len + 1));

if (new == NULL)
return (NULL);

_memcpy(new, s, len + 1);
return (new);
}

/**
* _strlen - Will return the length of a string.
* @s: Source string.
* Return: Length of the string.
*/
int _strlen(const char *s)
{
int len;

for (len = 0; s[len] != '\0'; len++)
{
}
return (len);
}

/**
* cmp_chars - Will compare characters of two strings.
* @str: Input string.
* @delim: Delimiters.
* Return: 1 if the characters match, 0 otherwise.
*/
int cmp_chars(char str[], const char *delim)
{
unsigned int i, j, k;

for (i = 0, k = 0; str[i]; i++)
{
for (j = 0; delim[j]; j++)
{
if (str[i] == delim[j])
{
k++;
break;
}
}
}
if (i == k)
return (1);
return (0);
}

/**
* _strtok - Splits a string by a delimiter.
* @str: Input string.
* @delim: Delimiters.
* Return: The next token in the string.
*/
char *_strtok(char str[], const char *delim)
{
static char *splitted, *str_end;
char *str_start;
unsigned int i, bool;

if (str != NULL)
{
if (cmp_chars(str, delim))
return (NULL);
splitted = str; /* Store first address */
i = _strlen(str);
str_end = &str[i]; /* Store last address */
}
str_start = splitted;
if (str_start == str_end) /* Reaching the end */
return (NULL);

for (bool = 0; *splitted; splitted++)
{
/* Breaking loop finding the next token */
if (splitted != str_start)
if (*splitted && *(splitted - 1) == '\0')
break;
/* Replacing delimiter with null char */
for (i = 0; delim[i]; i++)
{
if (*splitted == delim[i])
{
*splitted = '\0';
if (splitted == str_start)
str_start++;
break;
}
}
if (bool == 0 && *splitted) /* Str != Delim */
bool = 1;
}
if (bool == 0) /* Str == Delim */
return (NULL);
return (str_start);
}

/**
* _isdigit - Determines if a string represents a number.
* @s: Input string.
* Return: 1 if the string is a number, 0 otherwise.
*/
int _isdigit(const char *s)
{
unsigned int i;

for (i = 0; s[i]; i++)
{
if (s[i] < '0' || s[i] > '9')
return (0);
}
return (1);
}
