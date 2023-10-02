#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - reads a textfile  and prints it to STDOUT
 * @filename: path to file read into
 * @letters: chars to read by the function
 * Return: No. of chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedescriptor;
	char *buffer;
	ssize_t bytes, a;

	if (!filename)
		return (0);
	filedescriptor = open(filename, O_RDONLY);
	if (filedescriptor == -1)
	{
		close(filedescriptor);
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(filedescriptor);
		return (0);
	}
	bytes = read(filedescriptor, buffer, letters);
	if (bytes == -1)
	{
		close(filedescriptor);
		free(buffer);
		return (0);
	}
	a = write(STDOUT_FILENO, buffer, bytes);
	if (a == -1)
	{
		close(filedescriptor);
		free(buffer);
		return (0);
	}
	close(filedescriptor);
	return (bytes);
}
