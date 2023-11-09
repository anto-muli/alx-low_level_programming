#include "lists.h"

/**
 * get_dnodeint_at_index - returns the
 * nth node of the dlistint_t linked list
 *
 * @head: head of the doubly linked list
 * @index: index of the nth node in the list
 * Return: nth node in the list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);
	while (head->prev != NULL)
		head = head->prev;
	i = 0;

	while (head != NULL)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}
	return (head);
}