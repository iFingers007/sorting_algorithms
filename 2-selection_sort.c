#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array passed
 * @size: Size of the array
 *
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, min_i, j;
	int tmp;

	for (i = 0; i <= size - 2; i++)
	{
		min_i = i;
		for (j = i + 1; j <= size - 1; j++)
		{
			if (array[j] < array[min_i])
				min_i = j;
			tmp = array[i];
			array[i] = array[min_i];
			array[min_i] = tmp;
		}
		print_array(array, size);
	}
}
