#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j,  inter = 1;
	int tmp;

	if (array == NULL || size < 2)
		return;
	while (inter < size / 3)
		inter = inter * 3 + 1;
	for (; inter > 0; inter /= 3)
	{
		for (i = inter; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= inter; j -= inter)

/*
 *			for (j = i; j >= inter &&
 *			array[j- inter] > tmp; j -= inter)
*/
			{
				if (tmp < array[j - inter])
					array[j] = array[j - inter];
				else
					break;
			}
			/*	array[j] = array[j - inter]; */
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
