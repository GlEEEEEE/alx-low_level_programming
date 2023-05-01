#include "main.h"
#include <stdlib.h>

/**
* argstostr - concatenates all arguments of the program
* @ac: number of arguments
* @av: array of arguments
*
* Return: pointer to concatenated string
*/
char *argstostr(int ac, char **av)
{
int i, j, k, len;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

len = 0;
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
len++;
j++;
}
len++;
}

str = malloc(sizeof(char) * (len + 1));

if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
str[k] = av[i][j];
j++;
k++;
}
str[k] = '\n';
k++;
}
str[k] = '\0';

return (str);
}
