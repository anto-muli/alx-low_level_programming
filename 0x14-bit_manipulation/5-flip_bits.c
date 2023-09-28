#include "main.h"

/**
 * flip_bits - calculates the # of bits to be changed to
 * change from one number into another.
 * @n: The 1st #
 * @m: The 2nd #
 *
 * Return: The count of bits to be changed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		current = exclusive >> x;
		if (current & 1)
			count++;
	}
	return (count);
}
