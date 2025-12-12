#include "sort.h"

/* ------------ prototypes ------------ */

listint_t *swap_head(listint_t **list, listint_t *current, listint_t *prev, listint_t *next);
listint_t *swap_tail(listint_t *prev_prev, listint_t *prev, listint_t *current);
listint_t *swap_middle(listint_t *prev_prev, listint_t *prev, listint_t *current, listint_t *next);

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: a doubly linked list of integers
 * Return: nothing, vois function
 */

void insertion_sort_list(listint_t **list)
{
	/* pointeurs de travail : nœud courant, nœud précédent, nœud suivant */
	listint_t *current_node, *prev_node, *next_node;

	/* si la liste est invalide, vide, ou avec un seul élément, rien à trier */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* on démarre au deuxième nœud (le premier est déjà "trié" par définition) */
	current_node = (*list)->next;

	/* on parcourt la liste de gauche à droite */
	while (current_node)
	{
		/* on sauvegarde le nœud suivant avant de potentiellement déplacer current_node */
		next_node = current_node->next;
		/* on commence les comparaisons avec le nœud précédent */
		prev_node = current_node->prev;

		/* tant qu'on peut remonter et que l'ordre est incorrect, on décale current_node vers la gauche */
		while (prev_node != NULL && prev_node->n > current_node->n)
		{
			/* cas 1 : prev_node est la tête (son prev est NULL) -> swap spécifique tête */
			if (prev_node->prev == NULL)
			{
				/* swap et récupération de la "bonne" référence de next_node après la rotation */
				next_node = swap_head(list, current_node, prev_node, next_node);
			}
			/* cas 2 : current_node est la queue (son next est NULL) -> swap spécifique queue */
			else if (current_node->next == NULL)
			{
				/* swap en fin de liste, next_node est recalculé par la fonction */
				next_node = swap_tail(prev_node->prev, prev_node, current_node);
			}
			/* cas 3 : current_node est au milieu -> swap standard au milieu */
			else
			{
				/* swap au milieu et mise à jour de next_node pour garder la bonne itération */
				next_node = swap_middle
					(prev_node->prev, prev_node, current_node, next_node);
			}
			/* affiche la liste après chaque swap (souvent demandé dans les projets Holberton) */
			print_list(*list);

			/* après le swap, current_node a changé de position :
			 * on récupère son nouveau précédent pour continuer à remonter si nécessaire
			 */
			prev_node = current_node->prev;

			/* si current_node est devenu la tête, on arrête cette remontée */
			if (prev_node == NULL)
				break;
		}
		/* on reprend l'itération à partir du nœud suivant sauvegardé */
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

listint_t *swap_head(listint_t **list, listint_t *current, listint_t *prev, listint_t *next)
{
	/* la tête devient current après l'échange */
	(*list) = current;
	/* current n'a plus de précédent : il devient la nouvelle tête */
	current->prev = NULL;
	/* current pointe vers prev (qui passe après lui) */
	current->next = prev;
	/* prev pointe désormais vers current comme précédent */
	prev->prev = current;

	/* si next n'existe pas, prev devient la queue */
	if (next == NULL)
		prev->next = NULL;
	else
	{
		/* sinon prev pointe vers next */
		prev->next = next;
		/* et next pointe vers prev comme précédent */
		next->prev = prev;
	}
	/* on renvoie le nœud à traiter ensuite : le nœud suivant current (qui est prev après swap) */
	next = current->next;
	/* retourne le pointeur next mis à jour */
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
	/* pointeur vers le nœud à traiter ensuite après l'échange */
	listint_t *next;

	/* relie le nœud avant prev (prev_prev) à current (qui va passer devant prev) */
	prev_prev->next = current;
	/* met à jour le prev de current : il devient l'ancien prev de prev (prev_prev) */
	current->prev = prev->prev;
	/* current pointe vers prev (qui passe après lui) */
	current->next = prev;
	/* prev devient la queue : son next est NULL */
	prev->next = NULL;
	/* prev pointe vers current comme précédent */
	prev->prev = current;
	/* next correspond au nœud suivant current (qui est prev après swap) */
	next = current->next;

	/* retourne le pointeur next mis à jour */
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

listint_t *swap_middle(listint_t *prev_prev, listint_t *prev, listint_t *current, listint_t *next)
{
	/* relie le nœud avant prev (prev_prev) à current (qui passe devant prev) */
	prev_prev->next = current;
	/* met à jour le prev de current : il devient prev_prev */
	current->prev = prev_prev;
	/* current pointe vers prev (qui passe après lui) */
	current->next = prev;
	/* prev pointe vers next (le nœud qui suivait current) */
	prev->next = next;
	/* prev pointe vers current comme précédent */
	prev->prev = current;
	/* next pointe vers prev comme précédent */
	next->prev = prev;
	/* next à retourner : le nœud suivant current (qui est prev après swap) */
	next = current->next;
	/* retourne le pointeur next mis à jour */
	return (next);
}
