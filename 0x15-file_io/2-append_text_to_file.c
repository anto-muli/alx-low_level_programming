#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * append_text_to_file - apends text to file's end
 * @filename: file name
 * @text_content: NULL terminated string to add and file's end
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int filedescriptor;
	ssize_t x;
	int size;

	if (!filename)
		return (-1);
	filedescriptor = open(filename, O_WRONLY | O_APPEND);
	if (filedescriptor == -1)
		return (-1);
	if (!text_content)
	{
		close(filedescriptor);
		return (1);
	}
	size = _strlen(text_content);
	x = write(filedescriptor, text_content, size);
	if (x == -1)
	{
		close(filedescriptor);
		return (-1);
	}
	close(filedescriptor);
	return (1);
}

/**
 * _strlen - string length
 *
 * @s: chars pointer
 *
 * Return: Always zero
 */

int _strlen(const char *s)
{
	int a = 0;

	while (*(s + a) != '\0')
	{
		a++;
	}
	return (a);
}

