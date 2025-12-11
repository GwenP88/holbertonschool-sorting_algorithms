#include "sort.h"

/* ------------ prototypes ------------ */
listint_t *swap_head(listint_t **list,
	listint_t *current, listint_t *prev, listint_t *next);
listint_t *swap_tail(listint_t *prev_prev,
	listint_t *prev, listint_t *current);
listint_t *swap_middle(listint_t *prev_prev,
	listint_t *prev, listint_t *current, listint_t *next);

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
				next_node = swap_head(list, current_node, prev_node, next_node);
			}
			else if (current_node->next == NULL)
			{
				next_node = swap_tail(prev_node->prev, prev_node, current_node);
			}
			else
			{
				next_node = swap_middle
					(prev_node->prev, prev_node, current_node, next_node);
			}
			print_list(*list);
			prev_node = current_node->prev;
			if (prev_node == NULL)
				break;
		}
		current_node = next_node;
	}
}

/**
 * swap_head - déplace un nœud vers la tête de la liste
 * @list: adresse du pointeur vers la liste
 * @current: nœud qui doit remonter dans la liste
 * @prev: ancien précédent du nœud actuel (devient le suivant)
 * @next: nœud suivant avant l’opération de swap
 * Return: pointeur vers le prochain nœud à traiter dans l’algorithme
 */

listint_t *swap_head(listint_t **list,
	listint_t *current, listint_t *prev, listint_t *next)
{
	(*list) = current;
	current->prev = NULL;
	current->next = prev;
	prev->prev = current;
	if (next == NULL)
		prev->next = NULL;
	else
	{
		prev->next = next;
		next->prev = prev;
	}
	next = current->next;
	return (next);
}

/**
 * swap_tail - réinsère un nœud juste avant la fin de la liste
 * @prev_prev: nœud situé avant @prev
 * @prev: nœud actuellement placé avant la fin de la liste
 * @current: nœud à repositionner
 * Return: pointeur vers le prochain nœud à analyser dans le tri
 */

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

/**
 * swap_middle - déplace un nœud au milieu de la liste
 * @prev_prev: nœud placé avant @prev
 * @prev: nœud précédent actuellement @current
 * @current: nœud à repositionner dans la liste
 * @next: nœud suivant la position initiale de @current
 * Return: pointeur vers le nœud suivant pour la boucle externe
 */

listint_t *swap_middle(listint_t *prev_prev,
	listint_t *prev, listint_t *current, listint_t *next)
{
	prev_prev->next = current;
	current->prev = prev_prev;
	current->next = prev;
	prev->next = next;
	prev->prev = current;
	next->prev = prev;
	next = current->next;
	return (next);
}
