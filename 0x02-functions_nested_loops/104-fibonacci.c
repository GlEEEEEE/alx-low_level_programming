#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
unsigned int i, count = 2;
unsigned long int first = 1, second = 2, next;

printf("%lu, %lu", first, second);

for (i = 3; i <= 98; i++)
{
next = first + second;
first = second;
second = next;
if (next > 999999999)
{
first /= 10;
next /= 10;
}
printf(", %lu", next);
count += 1;
}
putchar('\n');
return (0);
}
