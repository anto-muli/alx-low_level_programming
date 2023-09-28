#include "main.h"

/**
 * clear_bit - Clears a bit in a no.
 * @n: Pointer to the modified #
 * @index: The index of the cleared bit.
 *
 * Return: 1 when successful  & -1 if failed
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
