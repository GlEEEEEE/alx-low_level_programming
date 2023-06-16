#include <stdlib.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 *
 * Return: On success 1. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _isdigit - Checks if a character is a digit (0 through 9)
 * @c: The character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 */
void multiply(char *num1, char *num2)
{
	int len1, len2, len_res, i, j, carry, n1, n2, sum;
	int *result;

	len1 = str_length(num1);
	len2 = str_length(num2);
	len_res = len1 + len2;
	result = malloc(sizeof(int) * len_res);
	if (result == NULL)
	{
		_putchar('0');
		_putchar('\n');
		exit(98);
	}

	for (i = 0; i < len_res; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry)
			result[i + j + 1] += carry;
	}

	if (result[0] == 0)
		i = 1;
	else
		i = 0;

	for (; i < len_res; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
}

/**
 * str_length - Calculates the length of a string
 * @str: The string
 *
 * Return: The length of the string
 */
int str_length(char *str)
{
	int length = 0;

	while (str[length])
		length++;

	return (length);
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i, j;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
			_putchar('\n');
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; i < 2; i++)
	{
		for (j = 0; num1[j]; j++)
		{
			if (!_isdigit(num1[j]))
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				exit(98);
			}
		}

		if (i == 0)
		{
			num1 = argv[2];
			num2 = argv[1];
		}
	}

	multiply(argv[1], argv[2]);

	return (0);
}
