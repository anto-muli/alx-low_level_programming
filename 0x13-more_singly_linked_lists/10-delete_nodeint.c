#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked list at a given index
 * @head: Pointer to the first element in the list.
 * @index: Index of the node to delete  from 0
 *
 * Return: 1 if successful, or -1 if it is a failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *current;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	temp = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (temp == NULL || temp->next == NULL)
			return (-1);
		temp = temp->next;
	}

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
