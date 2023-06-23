#include <stdio.h>
#include <stdlib.h>

/**
* main - Entry point
* @argc: The number of command-line arguments
* @argv: An array containing the command-line arguments
*
* Return: 0 on success, 1 if the number of arguments is incorrect,
*         or 2 if the number of bytes is negative
*/
int main(int argc, char *argv[])
{
int i, bytes;

if (argc != 2)
{
printf("Error\n");
return (1);
}

bytes = atoi(argv[1]);

if (bytes < 0)
{
printf("Error\n");
return (2);
}

unsigned char *main_ptr = (unsigned char *)main;

for (i = 0; i < bytes; i++)
printf("%02x ", main_ptr[i]);

printf("\n");

return (0);
}
