#include "main.h"

/**
 * set_bit - chnages the val of a bit in a deci #
 * @n: Pointer to the updated #
 * @index: The index of the bit to be set.
 *
 * Return: 1 when  successful and -1 when there is an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int num = 1;

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);
	num <<= index;
	*n = *n | num;
	return (1);
}
