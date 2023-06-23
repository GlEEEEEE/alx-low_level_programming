#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - Prints a name
* @name: Ptr to the name to print
* @f: Ptr to the function that prints the name
*/
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
f(name);
}
