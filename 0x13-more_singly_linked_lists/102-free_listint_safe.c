#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - Frees a linked list (with loop protection)
 * @h: Pointer to a pointer to the head node
 *
 * Return: The size of the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *next;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		count++;
		next = current->next;
		free(current);
		if (next >= current)
		{
			*h = NULL;
			exit(98);
		}
		current = next;
	}

	*h = NULL;
	return (count);
}
