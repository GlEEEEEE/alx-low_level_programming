#include <stdio.h>
#include <stdlib.h>

int calculate_minimum_coins(int cents);
int get_coin_count(int cents, int coin_value);

/**
* main - Entry point
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: 0 (Success) or 1 (Error)
*/
int main(int argc, char *argv[])
{
int cents, coins;

if (argc != 2)
{
printf("Error\n");
return (1);
}

cents = atoi(argv[1]);

if (cents < 0)
{
printf("0\n");
return (0);
}

coins = calculate_minimum_coins(cents);
printf("%d\n", coins);

return (0);
}

/**
* calculate_minimum_coins - Calculates the minimum number of coins
* @cents: The amount in cents
*
* Return: The minimum number of coins
*/
int calculate_minimum_coins(int cents)
{
int coins = 0;

coins += get_coin_count(cents, 25);
coins += get_coin_count(cents, 10);
coins += get_coin_count(cents, 5);
coins += get_coin_count(cents, 2);
coins += get_coin_count(cents, 1);

return (coins);
}

/**
* get_coin_count - Calculates the number of coins for a given coin value
* @cents: The amount in cents
* @coin_value: The value of the coin
*
* Return: The number of coins for the given coin value
*/
int get_coin_count(int cents, int coin_value)
{
int count = 0;

while (cents >= coin_value)
{
cents -= coin_value;
count++;
}

return (count);
}
