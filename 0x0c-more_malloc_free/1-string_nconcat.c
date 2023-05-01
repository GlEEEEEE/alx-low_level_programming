#include "main.h"
#include <stdlib.h>

/**
* string_nconcat - Concatenates two strings
* @s1: The first string to concatenate
* @s2: The second string to concatenate
* @n: The maximum number of bytes from s2 to concatenate
*
* Return: A pointer to the concatenated string, or NULL if it fails
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat_str;
unsigned int s1_len = 0, s2_len = 0, i, j;

if (s1 == NULL)
s1 = "";

if (s2 == NULL)
s2 = "";

while (s1[s1_len])
s1_len++;

while (s2[s2_len])
s2_len++;

if (n >= s2_len)
n = s2_len;

concat_str = malloc((s1_len + n + 1) * sizeof(char));
if (concat_str == NULL)
return (NULL);

for (i = 0; i < s1_len; i++)
concat_str[i] = s1[i];

for (j = 0; j < n; j++)
concat_str[i + j] = s2[j];

concat_str[i + j] = '\0';

return (concat_str);
}
