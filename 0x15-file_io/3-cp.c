#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/**
 * error_exit - Prints an error message and exits with the specified code
 * @code: Exit code
 * @msg: Error message
 * @file: File name
 */
void error_exit(int code, const char *msg, const char *file)
{
	dprintf(STDERR_FILENO, "%s%s%s\n", msg, file, (errno == 0 ? "" : ":"));
	exit(code);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 97-100 on error
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, num_read, num_written;
	char buffer[BUF_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file ", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to ", argv[2]);

	while ((num_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		num_written = write(fd_to, buffer, num_read);
		if (num_written == -1 || num_written != num_read)
			error_exit(99, "Error: Can't write to ", argv[2]);
	}

	if (num_read == -1)
		error_exit(98, "Error: Can't read from file ", argv[1]);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd ", argv[1]);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd ", argv[2]);

	return (0);
}

