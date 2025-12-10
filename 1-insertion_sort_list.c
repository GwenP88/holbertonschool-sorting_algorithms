#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: a doubly linked list of integers
 * Return: nothing, vois function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node)
	{
		next_node = current_node->next;
		prev_node = current_node->prev;

		while (prev_node != NULL && prev_node->n > current_node->n)
		{
			if (prev_node->prev == NULL)
			{
				(*list) = current_node;
				current_node->prev = NULL;
				current_node->next = prev_node;
				prev_node->prev = current_node;
				if (next_node == NULL)
					prev_node->next = NULL;
				else
				{
					prev_node->next = next_node;
					next_node->prev = prev_node;
				}
				next_node = current_node->next;
				/*next_node = swap_head()*/
			}
			else if (current_node->next == NULL)
			{
				(prev_node->prev)->next = current_node;
				current_node->prev = prev_node->prev;
				current_node->next = prev_node;
				prev_node->next = NULL;
				prev_node->prev = current_node;
				next_node = current_node->next;
			}
			else
			{
				(prev_node->prev)->next = current_node;
				current_node->prev = (prev_node->prev);
				current_node->next = prev_node;
				prev_node->next = next_node;
				prev_node->prev = current_node;
				next_node->prev = prev_node;
				next_node = current_node->next;
			}
			print_list(*list);
			prev_node = current_node->prev;
			if (prev_node == NULL)
				break;
		}
		current_node = next_node;
	}
}

listint_t *swap_head(listint_t **list, listint_t *current, listint_t *prev, listint_t *next)
{
	/**
	 * current = current_node
	 * prev = prev_node
	 * next = next_node
	 * remplacer dans le code
	 */


	(*list) = current_node;
	current_node->prev = NULL;
	current_node->next = prev_node;
	prev_node->prev = current_node;
	if (next_node == NULL)
		prev_node->next = NULL;
	else
	{
		prev_node->next = next_node;
		next_node->prev = prev_node;
	}
	next_node = current_node->next;
	return (next);
}


listint_t *swap_tail(listint_t *prev_prev, listint_t *prev, listint_t *current)
{
	listint_t *next;

	prev_prev->next = current;
	current->prev = prev->prev;
	current->next = prev;
	prev->next = NULL;
	prev->prev = current;
	next = current->next;

	return (next);
}

listint_t *swap_middle(listint_t *prev_prev, listint_t *prev, listint_t *current, listint_t *next)
{
	(prev_node->prev)->next = current_node;
	current_node->prev = (prev_node->prev);
	current_node->next = prev_node;
	prev_node->next = next_node;
	prev_node->prev = current_node;
	next_node->prev = prev_node;
	next_node = current_node->next;
	return (next);
}