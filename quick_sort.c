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
	quick_sort_rec(array, 0, size - 1, &size);
}
/**
 * quick_sort_rec - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: Array argument
 * @low: Start of array
 * @high: End of array
 *
 * Return: Void
 */
void quick_sort_rec(int *array, int low, int high, size_t *s)
{
	int piv_index;

	if (low < high)
	{
		piv_index = partition(array, low, high);
		print_array(array, *s);
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
 *
 * Return: Index of pivot
 */
int partition(int *array, int low, int high)
{
	int piv_value = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= piv_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	return (i);
}
/**
 * swap - Swaps the elements of an array
 * @a: First Array element
 * @b: Second element
 * @size: Size of the array
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp;

	if (a == NULL || b == NULL)
		return;
	temp = *a;
	*a = *b;
	*b = temp;
}
