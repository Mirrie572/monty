#include "monty.h"

/**
 * strckr - Checks if a string represents a valid number.
 *
 *  @str: The input string to be checked.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int strckr(char *str)
{
int idx = 0;

if (str[0] == '-')
idx = 1;
for (; str[idx] != 0; idx++)
{
if (!isdigit(str[idx]))
return (0);
}
return (1);
}
