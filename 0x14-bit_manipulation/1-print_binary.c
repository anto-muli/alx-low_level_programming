#include "main.h"

/**
 * print_binary - Prints the binary reps of a decimal #s
 * @a: The decimal #s to be converted and printed as bins.
 */
void print_binary(unsigned long int a)
{
	if (a > 1)
		print_binary(a >> 1);
	_putchar((a & 1) + '0');
}
