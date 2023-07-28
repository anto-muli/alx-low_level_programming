#include <stdlib.h>
#include "lists.h"

/**
 * free_list - a function that frees a linked list when it runs.
 * @head: Points to the list_t list that need to be freed.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
