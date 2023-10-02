#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * main - check the code.
 * @argc: nummber of argument counts
 * @argv: the argument values
 * Return: Always zero
 */
int main(int argc, char **argv)
{
	int source, to, exiter, x, y;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
	source = open(argv[1], O_RDONLY);
	if (source == -1)
		dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
	while (1)
	{
		y = read(source, buffer, 1024);
		if (y == -1)
			dprintf(STDERR_FILENO, READ_ERR, argv[1]), exit(98);
		if (y > 0)
		{
			x = write(to, buffer, y);
			if (x == -1)
				dprintf(STDERR_FILENO, WRITE_ERR, argv[2]), exit(99);
		} else
			break;
	}
	exiter = close(source);
	if (exiter == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source), exit(100);
	exiter = close(to);
	if (exiter == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to), exit(100);
	return (0);
}
