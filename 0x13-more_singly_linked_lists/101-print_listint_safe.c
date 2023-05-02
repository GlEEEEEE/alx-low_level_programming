#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list checks loop
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *temp = head, *prev = NULL;

	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;
		if (temp > prev)
			prev = temp;
		else
		{
			printf("-> [%p] %d\n", (void *)temp, temp->n);
			break;
		}
		temp = temp->next;
	}
	return (count);
}
