#include <stdlib.h>
#include "dog.h"

/**
* _strdup - duplicates a string
* @str: the string to duplicate
*
* Return: a pointer to the newly-allocated duplicated string
*/
char *_strdup(char *str)
{
char *dup_str;
unsigned int i, len = 0;

if (str == NULL)
return (NULL);

while (str[len] != '\0')
len++;

dup_str = malloc(sizeof(char) * (len + 1));

if (dup_str == NULL)
return (NULL);

for (i = 0; i < len; i++)
dup_str[i] = str[i];

dup_str[i] = '\0';

return (dup_str);
}

/**
* _strlen - returns the length of a string
* @str: the string to measure
*
* Return: the length of the string
*/
unsigned int _strlen(char *str)
{
unsigned int len = 0;

while (str[len] != '\0')
len++;

return (len);
}

/**
* new_dog - creates a new dog
* @name: the name of the dog
* @age: the age of the dog
* @owner: the owner of the dog
*
* Return: a pointer to the newly-allocated dog_t struct
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;

new_dog = malloc(sizeof(dog_t));

if (new_dog == NULL)
return (NULL);

new_dog->name = _strdup(name);

if (new_dog->name == NULL)
{
free(new_dog);
return (NULL);
}

new_dog->age = age;

new_dog->owner = _strdup(owner);

if (new_dog->owner == NULL)
{
free(new_dog->name);
free(new_dog);
return (NULL);
}

return (new_dog);
}
