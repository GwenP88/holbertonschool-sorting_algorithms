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
	size_t i, j;
	int temp;
	int swapped = 0;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			swapped = 1;
			print_array(array, size);
			}
		}
		if (swapped == 0)
		break;
	}
}

