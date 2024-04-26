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

		while(tras->prev != NULL && (tras->n < tras->prev->n))
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

			      
/*	listint_t *sorted, *curr, *nxt, *tmp, *new;

	sorted = NULL;
	curr = *list;

	while (curr != NULL)
	{
		nxt = curr->next;
		if (sorted == NULL || sorted->n > curr->n)
		{
			curr->next = sorted;
			sorted = curr;
			print_list(sorted);
		}
		else
		{
			new = sorted;
			while (new->next != NULL && new->next->n <= curr->n)
				new = new->next;
			if (new->next == NULL)
			{
				new->next = curr;
				curr->prev = new;
				curr->next = NULL;
			}
			else
			{
				tmp = new->next;
				new->next = curr;
				curr->prev = new;
				curr->next = tmp;
				tmp->prev = curr;
			}
			print_list(sorted);
		}
		curr = nxt;
	}
	*list = sorted;
*/
}
