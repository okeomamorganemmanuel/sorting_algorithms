#include "sort.h"

/**
* bubble_sort - bubble sort algorith
* @array: the array to be sorted
* @size: the size of the array
*
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp, swap;

	swap = 0;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; swap == 0; i++)
	{
		swap = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 0;
				print_array(array, size);
			}
		}
	}
}
