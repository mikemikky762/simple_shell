#include "main.h"

/**
* rev_string - Will reverse a string in-place.
* @s: The input string to reverse.
* Return: None.
*/
void rev_string(char *s)
{
int count = 0, i, j;
char *str, temp;

<<<<<<< HEAD
/* Determine the length of the string */
=======
// Determines the length of the string
>>>>>>> da8f7d1b7cdcf45c373cf04ca41d2f74b77ea9b8
while (count >= 0)
{
if (s[count] == '\0')
break;
count++;
}
str = s;

/* Swap characters to reverse the string */
for (i = 0; i < (count - 1); i++)
{
for (j = i + 1; j > 0; j--)
{
temp = *(str + j);
*(str + j) = *(str + (j - 1));
*(str + (j - 1)) = temp;
}
}
}
