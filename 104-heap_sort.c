#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

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
 * siftdown - siftdown
 * @array: array
 * @start: start
 * @end: end
 * @size: size
 *
 */
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, _swap, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_swap = root;
		if (array[_swap] < array[child])
			_swap = child;
		if (child + 1 <= end && array[_swap] < array[child + 1])
			_swap = child + 1;
		if (_swap == root)
			return;
		swap(array, size, &array[root], &array[_swap]);
		root = _swap;
	}
}

/**
 * heapify - heapify
 * @array: array
 * @size: size
 *
 */
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		siftdown(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - heap_sort
 * @array: array
 * @size: size
 *
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		swap(array, size, &array[end], &array[0]);
		end--;
		siftdown(array, 0, end, size);
	}
}
