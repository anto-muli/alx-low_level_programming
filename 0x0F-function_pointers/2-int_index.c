#include "function_pointers.h"

/**
 * int_index - Returns the index position if comparison is true, else -1
 * @array: Array
 * @size: Size of elements in the array
 * @cmp: Pointer to a function of one of the three functions in main
 *
 * Return: Index position or -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
