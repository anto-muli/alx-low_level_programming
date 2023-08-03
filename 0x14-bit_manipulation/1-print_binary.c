#include "main.h"

/**
 * print_binary - reproduces the binary coresponding of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;
	const unsigned long int ONE = 1UL << 63;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & ONE)
		{
			_putchar('1');
			count++;
		}
		else if (count)
		{
			_putchar('0');
		}
	}
	if (!count)
	{
		_putchar('0');
	}
}

