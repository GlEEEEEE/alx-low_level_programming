#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* _strdup - duplicates a string
* @str: string to be duplicated
*
* Return: pointer to the newly allocated duplicated string,
*         or NULL if str is NULL or if memory allocation fails
*/
char *_strdup(const char *str)
{
char *dup;
size_t len, i;

if (str == NULL)
return (NULL);

len = strlen(str);
dup = malloc((len + 1) * sizeof(char));
if (dup == NULL)
return (NULL);

for (i = 0; i <= len; i++)
dup[i] = str[i];

return (dup);
}

/**
* add_node_end - adds a new node at the end of a list_t list
* @head: pointer to the pointer of the head of the list
* @str: string to be duplicated and stored in the new node
*
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *temp;
char *str_dup;
unsigned int str_len = 0;

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

str_dup = _strdup(str);
if (str_dup == NULL)
{
free(new_node);
return (NULL);
}

while (str[str_len] != '\0')
str_len++;

new_node->str = str_dup;
new_node->len = str_len;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
}

return (new_node);
}

