#include "variadic_functions.h"

/**
* print_c - Prints a char
*
* @arg: A va_list pointing to the argument to be printed
*/
void print_c(va_list arg)
{
printf("%c", va_arg(arg, int));
}

/**
* print_i - Prints an int
*
* @arg: A va_list pointing to the argument to be printed
*/
void print_i(va_list arg)
{
printf("%d", va_arg(arg, int));
}

/**
* print_f - Prints a float
*
* @arg: A va_list pointing to the argument to be printed
*/
void print_f(va_list arg)
{
printf("%f", va_arg(arg, double));
}

/**
* print_s - Prints a string
*
* @arg: A va_list pointing to the argument to be printed
*/
void print_s(va_list arg)
{
char *str = va_arg(arg, char *);

if (str == NULL)
{
printf("(nil)");
return;
}

printf("%s", str);
}

/**
* print_all - Prints anything
*
* @format: string containing types of arguments passed to the function
*/
void print_all(const char * const format, ...)
{
print_t p[] = {
{'c', print_c},
{'i', print_i},
{'f', print_f},
{'s', print_s},
{'\0', NULL}
};

va_list args;
int i = 0, j = 0;
char *sep = "";

va_start(args, format);

while (format != NULL && format[i] != '\0')
{
j = 0;

while (p[j].c != '\0')
{
if (p[j].c == format[i])
{
printf("%s", sep);
p[j].f(args);
sep = ", ";
break;
}
j++;
}

i++;
}

printf("\n");

va_end(args);
}
