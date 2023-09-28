#include "main.h"

/**
 * get_bit - Retrieves the specific value of a specific bit in a deci #
 * @n: The # to examine
 * @index: The  (index) of the bit to brought back.
 *
 * Return: The value of the bit at the specified index and  -1 on error.
 */
int get_bit(unsigned long int a, unsigned int indexer)
{
	int bit_val;

	if (indexer > 63)
	return (-1);
	bit_val = (a >> indexer) & 1;
	return (bit_val);
}
