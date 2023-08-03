#include "main.h"
/**
 * set_bit - sets the value of a bit at a given index in a decimal number
 * @n: pointer to the number to modify
 * @index: index of the bit to set
 *
 * Return: 1 if the operation was successful, or -1 if an error occurs.
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
