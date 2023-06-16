#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for an array and initializes it to zero
 * @nmemb: The number of elements in the array
 * @size: The size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return ((void *)ptr);
}
