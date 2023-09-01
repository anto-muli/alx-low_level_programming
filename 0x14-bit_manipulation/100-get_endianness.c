#include "main.h"

/**
 * get_endianness - Decides the endianness of amachine
 *
 * Return: 0 for big endian, 1 for small endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *) &x;

	return (*c);
}
