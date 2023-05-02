#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list, handling loops
 * @head: pointer to the head node of the linked list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow = head, *fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
			printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
			count++;
			break;
		}
	}
	while (head != slow)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}
	printf("[%p] %d\n", (void *)head, head->n);
	count++;
	if (slow == NULL || fast == NULL || fast->next == NULL)
	{
		exit(98);
	}
	return (count);
}
