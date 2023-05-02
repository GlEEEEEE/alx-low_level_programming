#include "variadic_functions.h"

/**
 * print_all - prints anything.
 * @format: list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *separator = "";
	print_t p[] = {
		{'c', print_c},
		{'i', print_i},
		{'f', print_f},
		{'s', print_s},
		{0, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (p[j].c)
		{
			if (format[i] == p[j].c)
			{
				printf("%s", separator);
				p[j].f(args);
				separator = ", ";
			}
			j++;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}

/**
 * print_c - prints char.
 * @arg: argument to print
 */

void print_c(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_i - prints integer.
 * @arg: argument to print
 */

void print_i(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_f - prints float.
 * @arg: argument to print
 */

void print_f(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_s - prints string.
 * @arg: argument to print
 */

void print_s(va_list arg)
{
	char *s;

	s = va_arg(arg, char *);

	if (s == NULL)
	{
		s = "(nil)";
	}

	printf("%s", s);
}
