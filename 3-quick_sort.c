#include "sort.h"

/**
 * swap - swap 2 int
 * @array: array
 * @size: size
 * @a: first value
 * @b: second
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 * @array: array
 * @size: size
 * @lo: low index
 * @hi: high index
 *
 * Return: size_t
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}

/**
 * quicksort - via lumuto
 * @array: array
 * @size: size
 * @lo: low
 * @hi: high
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - quick_sort
 * @array: array
 * @size: size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
