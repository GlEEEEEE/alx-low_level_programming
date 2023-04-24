#include <stdio.h>

/**
* main - Entry point
*
* Description: Prints the first 98 Fibonacci numbers
*
* Return: Always 0 (Success)
*/

int main(void)
{
unsigned long int i, num1 = 1, num2 = 2, next;

printf("%lu, %lu, ", num1, num2);

for (i = 3; i <= 98; ++i)
{
next = num1 + num2;
num1 = num2;
num2 = next;

if (i < 98)
printf("%lu, ", next);
else
printf("%lu\n", next);
}

return (0);
}
