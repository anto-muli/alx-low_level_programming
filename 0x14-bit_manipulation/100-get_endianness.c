#include "main.h"

/**
 * get_endianness - Decides the endianness of a machine
 *
 * Return: 0 for big endian, 1 for small endian
 */
int get_endianness(void)
{
	unsigned int y = 1;
	char *c = (char *) &y;

	return (*c);
}
