#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @head: double pointer to the beginning of the list
 *
 * Return: the number of nodes freed
 */
size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *temp, *current = *head;

	while (current)
	{
		count++;
		if (current <= current->next)
		{
			free(current);
			break;
		}
		temp = current->next;
		free(current);
		current = temp;
	}
	*head = NULL;

	return (count);
}
