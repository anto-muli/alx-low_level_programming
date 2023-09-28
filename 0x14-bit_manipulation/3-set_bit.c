#include "main.h"

/**
 * set_bit - changes the value of a bit in a deci #
 * @n: Pointer to the updated no.
 * @index: The index of the bit set to
 *
 * Return: 1 when  successful and -1 when not successful
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
