#include "sort.h"

void recursion_quick_sort(int *array, int index_start,int index_end, size_t size);
int partition(int *array, int index_start, int index_end, size_t size);
void swap_print(int *array, int index_low, int index_high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: pointer to the array to sort
 * @size: number of elements in the array
 * Return: nothing, void function
 */

void quick_sort(int *array, size_t size)
{
	/* bornes de la zone à trier (indices) */
	int index_start, index_end;

	/* si le tableau est NULL ou trop petit, rien à trier */
	if (array == NULL || size < 2)
		return;

	/* début de tableau */
	index_start = 0;
	/* fin de tableau (dernier index) */
	index_end = size - 1;

	/* appel de la fonction récursive sur tout le tableau */
	recursion_quick_sort(array, index_start, index_end, size);
}

/**
 * recursion_quick_sort - recursively sorts a sub-array using Quick sort
 * @array: pointer to the array to sort
 * @index_start: starting index of the sub-array
 * @index_end: ending index of the sub-array
 * @size: total size of the original array (used for printing)
 * Return: nothing, void function
 */

void recursion_quick_sort(int *array,int index_start, int index_end, size_t size)
{
	/* index final du pivot après partition */
	int index_pivot;

	/* condition d'arrêt : portion vide ou réduite à un seul élément */
	if (index_start >= index_end)
		return;

	/* partition : place le pivot à sa position finale et réorganise le reste */
	index_pivot = partition(array, index_start, index_end, size);
	/* tri récursif de la partie gauche (éléments < pivot) */
	recursion_quick_sort(array, index_start, index_pivot - 1, size);
	/* tri récursif de la partie droite (éléments > pivot) */
	recursion_quick_sort(array, index_pivot + 1, index_end, size);
}

/**
 * partition - partitions a sub-array using the Lomuto scheme
 * @array: pointer to the array to partition
 * @index_start: starting index of the sub-array
 * @index_end: ending index of the sub-array (pivot position)
 * @size: total size of the array (used for printing)
 * Return: the pivot index after partitioning
 */

int partition(int *array, int index_start, int index_end, size_t size)
{
	/* valeur pivot : dernier élément de la portion */
	int pivot = array[index_end];
	/* i marque la prochaine position où placer un élément < pivot */
	int i = index_start;
	/* j parcourt la portion de gauche à droite */
	int j;

	/* on parcourt tous les éléments sauf le pivot */
	for (j = index_start; j < index_end; j++)
	{
		/* si l'élément courant est strictement inférieur au pivot */
		if (array[j] < pivot)
		{
			/* si j et i sont différents, on échange pour regrouper les < pivot à gauche */
			if (j != i)
			{
				/* swap + print demandé par le projet */
				swap_print(array, j, i, size);
			}
			/* on avance i : la zone < pivot s'agrandit */
			i++;
		}
	}
	/* place le pivot à sa position finale (i), si nécessaire */
	if (index_end != i && array[index_end] != array[i])
		swap_print(array, index_end, i, size);

	/* i est la position finale du pivot */
	return (i);
}

/**
 * swap_print - swaps two elements in an array and prints the result
 * @array: pointer to the array containing the elements to swap
 * @index_low: index of the first element
 * @index_high: index of the second element
 * @size: size of the array to print
 * Return: nothing
 */

void swap_print(int *array, int index_low, int index_high, size_t size)
{
	/* variable temporaire pour faire l'échange */
	int tmp = 0;

	/* sauvegarde de la valeur à index_low */
	tmp = array[index_low];
	/* copie de index_high vers index_low */
	array[index_low] = array[index_high];
	/* restauration de tmp vers index_high */
	array[index_high] = tmp;

	/* affichage du tableau après l'échange *
	print_array(array, size);
}
