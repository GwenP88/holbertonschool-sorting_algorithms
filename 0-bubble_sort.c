#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array
 * @size: size of array
 * Return:nothing, void function
 */

void bubble_sort(int *array, size_t size)
{
	/* indices pour parcourir le tableau */
	size_t i, j;
	/* variable temporaire pour l'échange de valeurs */
	int temp;
	/* indicateur pour savoir si un échange a eu lieu */
	int swapped = 0;

	/* si le tableau est NULL ou trop petit, on ne fait rien */
	if (array == NULL || size < 2)
	return;

	/* boucle sur les passes successives dans le tableau */
	for (i = 0; i < size - 1; i++)
	{
		/* boucle interne pour comparer les éléments adjacents */
		for (j = 0; j < size - i - 1; j++)
		{
			/* si l'élément courant est plus grand que le suivant, on les échange */
			if (array[j] > array[j + 1])
			{
			/* échange des deux valeurs */
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			/* on note qu'un échange a eu lieu */
			swapped = 1;
			/* affichage du tableau après chaque échange */
			print_array(array, size);
			}
		}
		/* si aucun échange n'a été fait pendant cette passe, le tableau est déjà trié */
		if (swapped == 0)
		break;
	}
}

