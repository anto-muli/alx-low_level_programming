#include "main.h"

/**
 * flip_bits - works out the #r of bits that need to be changed to
 * change from one number into another.
 * @n: The 1st #
 * @m: The 2nd #
 *
 * Return: The count of bits to be changed.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		current = exclusive >> a;
		if (current & 1)
			count++;
	}
	return (count);
}
