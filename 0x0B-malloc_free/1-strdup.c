#include "main.h"
#include <stdlib.h>

/**
* _strdup - returns a pointer to a newly allocated space in memory
* containing a copy of the string given as parameter
* @str: string to duplicate
*
* Return: pointer to the duplicated string, or NULL if insufficient memory
* was available or if str is NULL
*/
char *_strdup(char *str)
{
char *new_str;
int len, i;

if (str == NULL)
return (NULL);

len = _strlen(str);
new_str = malloc(sizeof(char) * (len + 1));

if (new_str == NULL)
return (NULL);

for (i = 0; i <= len; i++)
new_str[i] = str[i];

return (new_str);
}
