#include "main.h"

/**
* _strlen_recursion - returns length of string.
*
* @s: string to measure.
*
* Return: length of the string.
*/
int _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);
else
return (_strlen_recursion(s + 1) + 1);
}
