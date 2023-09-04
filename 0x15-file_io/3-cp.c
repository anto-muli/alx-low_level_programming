#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates a buffer 1024 bytes
 * @file: The file name of the buffer  buffer to store chars
 *
 * Return: the pointer to the newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - shuts down file descriptors.
 * @fd: The file descriptor shut down
 */
void close_file(int fd)
{
	int a;

	a = close(fd);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to a new file.
 * @argc: The number of args supplied to the program.
 * @argv: An array of pointers to the args.
 *
 * Return: 0 when successful
 *
 * Description: If the arg count is incorrect - exit code 97.
 * If file_from does not exist or can't be read - exit code 98.
 * If file_to can't be created or written to - exit code 99.
 * If file_to or file_from can't be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, a, b;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		b = write(to, buffer, a);
		if (to == -1 || b == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		a = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
