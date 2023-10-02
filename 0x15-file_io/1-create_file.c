#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * create_file - created file
 * @filename: name of the created file
 * @text_content: NULL terminated string writenint he file
 * Return: chars read
 */

int create_file(const char *filename, char *text_content)
{
	int filedescriptor;
	ssize_t x;
	int size;
	char *mem;

	if (!filename)
	{
		return (-1);
	}
	filedescriptor = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (filedescriptor == -1)
		return (-1);
	if (!text_content)
	{
		close(filedescriptor);
		return (1);
	}
	size = _strlen(text_content);
	mem = malloc(sizeof(char) * size);
	if (!mem)
	{
		close(filedescriptor);
		return (-1);
	}
	x = write(filedescriptor, text_content, size);
	if (x == -1)
	{
		close(filedescriptor);
		free(mem);
		return (-1);
	}
	close(filedescriptor);
	free(mem);
	return (1);
}

/**
 * _strlen - string length
 *
 * @s: pointer to the issue
 *
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int b = 0;

	while (*(s + b) != '\0')
	{
		b++;
	}
	return (b);
}
