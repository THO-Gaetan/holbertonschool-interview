#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_parts - Merges two sorted halves of an array
 * @array: The array containing both halves
 * @tmp: Buffer used to build the merged result
 * @mid: Size of the left half (right half starts at array + mid)
 * @size: Total number of elements to merge
 */
void merge_parts(int *array, int *tmp, size_t mid, size_t size)
{
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);

	while (i < mid && j < size)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i < mid)
		tmp[k++] = array[i++];
	while (j < size)
		tmp[k++] = array[j++];

	for (k = 0; k < size; k++)
		array[k] = tmp[k];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort_rec - Recursively sorts an array (top-down merge sort)
 * @array: The array to sort
 * @tmp: Buffer shared by every merge
 * @size: Number of elements in @array
 */
void merge_sort_rec(int *array, int *tmp, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;
	merge_sort_rec(array, tmp, mid);
	merge_sort_rec(array + mid, tmp, size - mid);
	merge_parts(array, tmp, mid, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the top-down Merge Sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	merge_sort_rec(array, tmp, size);
	free(tmp);
}
