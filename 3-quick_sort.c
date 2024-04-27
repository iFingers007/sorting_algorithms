#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Array argument
 * @size: Size of the array
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}
/**
 * quick_sort_rec - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Array argument
 * @low: Start of array
 * @high: End of array
 * @s: size of array
 *
 * Return: Void
 */
void quick_sort_rec(int *array, int low, int high, size_t s)
{
	int piv_index;

	if (low < high)
	{
		piv_index = partition(array, low, high, s);
		quick_sort_rec(array, low, piv_index - 1, s);
		quick_sort_rec(array, piv_index + 1, high, s);
	}
}
/**
 * partition - Uses the lomuto partion
 *
 * @array: Array argument
 * @low: Start of array
 * @high: End of array
 * @size: Size of the array
 *
 * Return: Index of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j < high; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (high != i + 1)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}
/**
 * swap - Swaps the elements of an array
 * @a: First Array element
 * @b: Second element
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
