#include "sort.h"

/**
 *  bubble_sort - sorts an array of integers in ascending order
 *  using the Bubble sort algorithm
 * @array: Array argument passed
 * @size: Size of the array passed
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, i;
	int tmp, flag;


	if (size < 2)
		return;

	for (k = 1; k <= size - 1; k++)
	{
		flag = 0;
		for (i = 0; i <= size - k - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				flag += 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
