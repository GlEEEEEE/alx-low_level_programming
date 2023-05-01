#include "main.h"

/**
* malloc_checked - cause normal process termination with a status value of 98
*                  if malloc fails
* @b: The number of bytes to allocate
*
* Return: A pointer to the allocated memory
*         NULL if malloc fails
*/
void *malloc_checked(unsigned int b)
{
void *ptr;

ptr = malloc(b);
if (ptr == NULL)
exit(98);

return (ptr);
}
