#include "lists.h"
#include <stdlib.h>

/**
* free_list - frees a list_t list
* @head: pointer to the head of the list
*
* Description: Frees each node of a linked list_t list,
*              including the strings stored in each node.
*/
void free_list(list_t *head)
{
list_t *current;
list_t *temp;

current = head;
while (current != NULL)
{
temp = current;
current = current->next;
free(temp->str);
free(temp);
}
}

