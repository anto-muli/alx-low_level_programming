#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads file  textand prints to the standard ouput
 * @filename: the file text to be read
 * @letters: the # of read letters
 * Return: w- actual # of bytes rd and printed and 0 when fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t dl;
	ssize_t x;
	ssize_t a;

	dl = open(filename, O_RDONLY);
	if (dl == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	a = read(dl, buf, letters);
	x = write(STDOUT_FILENO, buf, a);

	free(buf);
	close(dl);
	return (x);
}
