#include "main.h"

/**
* check_prime - checks if a number is prime recursively
*
* @n: check number
* @divisor: check this divisor
*
* Return: 1 if n is prime,else 0
*/

int check_prime(int n, int divisor)
{
if (n % divisor == 0) /* found factor */
return (0);
else if (divisor >= n / 2) /* no factors */
return (1);
else
return (check_prime(n, divisor + 1));
}

/**
* is_prime_number - checks if a number is prime
*
* @n: the number to check
*
* Return: 1 if n is prime, 0 otherwise
*/

int is_prime_number(int n)
{
if (n < 2) /* 0 and 1 are not prime */
return (0);
return (check_prime(n, 2));
}
