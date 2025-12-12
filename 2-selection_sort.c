#include "sort.h"

/**
 *selection_sort - function that sorts an array of integers
 *in ascending order using the selection sort algortithm
 *@array: array
 *@size: size of array
 *Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	/* indices de parcours et index du minimum trouvé */
	size_t i, j, min_index;
	/* variable temporaire pour effectuer un swap */
	int temp;

	/* si le tableau est NULL ou trop petit, rien à trier */
	if (array == NULL || size < 2)
	return;

	/* on place à chaque tour le plus petit élément restant en position i */
	for (i = 0; i < size; i++)
	{
		/* on suppose que le minimum est au début de la zone non triée */
		min_index = i;
		/* recherche du plus petit élément dans la partie [i + 1 .. size - 1] */
		for (j = i + 1; j < size; j++)
		{
			/* si on trouve plus petit que le minimum actuel, on met à jour min_index */
			if (array[j] < array[min_index])
			{
				min_index = j;
			}

		}
		/* si le minimum n'est pas déjà en position i, on échange */
		if (min_index != i)
		{
			/* swap entre array[i] et array[min_index] */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* affichage du tableau après chaque swap */
			print_array(array, size);
		}
	}
}
