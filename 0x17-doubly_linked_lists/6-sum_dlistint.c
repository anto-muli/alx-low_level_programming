#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n)
 * in the doubly linked list
 *
 * @head: head of the doubly linked list
 * Return: sum of the data in the list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}
	return (sum);
}
