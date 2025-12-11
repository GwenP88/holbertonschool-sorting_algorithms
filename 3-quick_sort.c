#include "sort.h"

void recursion_quick_sort(int *array, int index_start,
		int index_end, size_t size);
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
	int index_start, index_end;

	if (array == NULL || size < 2)
		return;

	index_start = 0;
	index_end = size - 1;
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

void recursion_quick_sort(int *array,
	int index_start, int index_end, size_t size)
{
	int index_pivot;

	if (index_start >= index_end)
		return;

	index_pivot = partition(array, index_start, index_end, size);
	recursion_quick_sort(array, index_start, index_pivot - 1, size);
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
	int pivot = array[index_end];
	int i = index_start;
	int j;

	for (j = index_start; j < index_end; j++)
	{
		if (array[j] < pivot)
		{
			if (j != i)
			{
				swap_print(array, j, i, size);
			}
			i++;
		}
	}
	if (index_end != i && array[index_end] != array[i])
		swap_print(array, index_end, i, size);
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
	int tmp = 0;

	tmp = array[index_low];
	array[index_low] = array[index_high];
	array[index_high] = tmp;
	print_array(array, size);
}

