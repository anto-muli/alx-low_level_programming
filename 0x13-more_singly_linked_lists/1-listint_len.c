#include "lists.h"

/**
 * listint_len - a function that returns
 * the number of elements in a linked list.
 * @h: linked list of the type listint_t
 *
 * Return:  the number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}

