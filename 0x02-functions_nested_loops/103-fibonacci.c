#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
int sum = 0;
int prev = 1;
int curr = 2;
int next = 0;

while (curr < 4000000)
{
if (curr % 2 == 0)
sum += curr;

next = prev + curr;
prev = curr;
curr = next;
}

printf("%d\n", sum);
return (0);
}
