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
* get_word_length - Gets the length of a word in a string
* @str: The string containing the word
* @start: The index of the start of the word
*
* Return: The length of the word
*/
int get_word_length(char *str, int start)
{
int length = 0;

while (str[start + length] != ' ' && str[start + length] != '\0')
length++;

return (length);
}

/**
* copy_word - Copies a word from a string to a new buffer
* @str: The string containing the word
* @start: The index of the start of the word
* @length: The length of the word
*
* Return: A pointer to the new buffer containing the word
*/
char *copy_word(char *str, int start, int length)
{
char *word;
int i;

word = malloc((length + 1) * sizeof(char));
if (word == NULL)
return (NULL);

for (i = 0; i < length; i++)
word[i] = str[start + i];

word[length] = '\0';

return (word);
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
int i, j, wc, length;

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

length = get_word_length(str, j);

words[i] = copy_word(str, j, length);
if (words[i] == NULL)
{
for (j = 0; j < i; j++)
free(words[j]);
free(words);
return (NULL);
}

j += length;
}

words[wc] = NULL;
return (words);
}
