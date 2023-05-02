#include "lists.h"
#include <stdlib.h>

/**
* delete_nodeint_at_index - deletes the node at a given position
* @head: pointer to a pointer to the first node of a linked list
* @index: index of the node to delete
*
* Return: 1 if the deletion was successful, -1 otherwise
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

current = *head;

if (index == 0)
{
*head = current->next;
free(current);
return (1);
}

prev = current;
current = current->next;

for (i = 1; current != NULL && i <= index; i++)
{
if (i == index)
{
prev->next = current->next;
free(current);
return (1);
}
prev = current;
current = current->next;
}

return (-1);
}
