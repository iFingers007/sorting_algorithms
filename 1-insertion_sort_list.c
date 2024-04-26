#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 * @list: Pointer to list
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *curr, *tras;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp = curr->next;
		tras = curr;

		while (tras->prev != NULL && (tras->n < tras->prev->n))
		{
			tras->prev->next = tras->next;
			if (tras->next != NULL)
				tras->next->prev = tras->prev;
			tras->next = tras->prev;
			tras->prev = tras->prev->prev;
			tras->next->prev = tras;

			if (tras->prev != NULL)
				tras->prev->next = tras;
			else
				*list = tras;
			print_list(*list);
		}
		curr = tmp;
	}
}
