#include "sort.h"

/**
 * quick_sort - a sorting function based on the quick
 *              sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int max_idx;

	if (array == NULL || size < 2)
		return;

	max_idx = size - 1;
	lomuto_partition(array, 0, max_idx, size);

}


/**
 * lomuto_partition - a quick sort algorithm based on lomuto partition
 *
 * @array: the array to be sorted
 * @min_idx: the first index in the sub-array
 * @max_idx: the last index in the sub array
 * @size: the size of the array
 */
void lomuto_partition(int *array, int min_idx, int max_idx, size_t size)
{
	int pivot;

	if (min_idx >= max_idx || min_idx < 0)
		return;

	pivot = partition(array, min_idx, max_idx, size);

	lomuto_partition(array, min_idx, pivot - 1, size);
	lomuto_partition(array, pivot + 1, max_idx, size);
}



/**
 * partition - a function that divides an array into two sub arrays
 * @array: the array to partition
 * @min_idx: the first index of the array
 * @max_idx: the last index of the array
 * @size: the size of the array
 *
 * Return: the pivot index of the partition
 */
int partition(int *array, int min_idx, int max_idx, size_t size)
{
	int j, temp, pivot_idx, pivot_element;

	pivot_element = array[max_idx];

	pivot_idx = min_idx;


	for (j = min_idx; j < max_idx; j++)
	{
		if (array[j] < pivot_element)
		{
			if (pivot_idx < j)
			{
				temp = array[pivot_idx];
				array[pivot_idx] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			pivot_idx++;
		}
	}

	if (array[pivot_idx] > pivot_element)
	{
		temp = array[pivot_idx];
		array[pivot_idx] = array[max_idx];
		array[max_idx] = temp;
		print_array(array, size);
	}

	return (pivot_idx);
}
