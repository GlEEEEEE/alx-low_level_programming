#include <stdio.h>

/**
* main - Prints all possible combinations of three digits
*
* Return: Always 0 (Success)
*/
int main(void)
{
int i, j, k;

for (i = 0; i < 1000; i++)
{
j = i / 100; /* hundreds */
k = i / 10 % 10; /* tens */
l = i % 10; /* ones */

if (j < k && k < l)
{
putchar(j + '0');
putchar(k + '0');
putchar(l + '0');

if (i < 789)
{
putchar(',');
putchar(' ');
}
}
}

putchar('\n');

return (0);
}
