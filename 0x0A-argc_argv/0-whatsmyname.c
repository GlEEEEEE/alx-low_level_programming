#include "main.h"
#include <stdio.h>

/**
* main - starting
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0
*/
int main(int argc, char *argv[])
{
int i;

for (i = 0; i < argc; i++)
{
int j;

for (j = 0; argv[i][j] != '\0'; j++)
{
_putchar(argv[i][j]);
}
_putchar('\n');
}

return (0);
}

/**
* _putchar - Wrtes a char to the standard output (stdout)
* @c: The char to be written
*
* Return: 1 on success, -1 on error
*/
int _putchar(char c)
{
return (putchar(c));
}
