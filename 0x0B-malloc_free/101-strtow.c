#include "main.h"
#include <stdlib.h>

/**
* count_words - Counts the number of words in a string
* @str: The string to be counted
*
* Return: The number of words in the string
*/
int count_words(char *str)
{
int words = 0, i;

for (i = 0; str[i]; i++)
if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ')
words++;

return (words);
}

/**
* strtow - Splits a string into words
* @str: The string to be split
*
* Return: A pointer to an array of strings (words), or NULL if it fails
*/
char **strtow(char *str)
{
char **words;
int i, j, k, len, wc = 0;

if (str == NULL || str[0] == '\0')
return (NULL);

wc = count_words(str);
if (wc == 0)
return (NULL);

words = malloc((wc + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

for (i = 0, j = 0; i < wc; i++, j++)
{
while (str[j] == ' ')
j++;

len = 0;
while (str[j + len] != ' ' && str[j + len] != '\0')
len++;

words[i] = malloc((len + 1) * sizeof(char));
if (words[i] == NULL)
{
for (k = 0; k < i; k++)
free(words[k]);
free(words);
return (NULL);
}

for (k = 0; k < len; k++)
words[i][k] = str[j + k];
words[i][len] = '\0';

j += len;
}

words[wc] = NULL;
return (words);
}
