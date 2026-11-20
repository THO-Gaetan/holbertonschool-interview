#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the largest value in an array of integers
 * @array: The array to scan
 * @size: Number of elements in @array
 *
 * Return: The largest value found
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Stable counting sort on one digit of each number
 * @array: The array to sort
 * @size: Number of elements in @array
 * @exp: Current significant digit (1, 10, 100, ...)
 * @buffer: Temporary array of @size elements
 */
static void counting_sort_digit(int *array, size_t size, long exp,
				int *buffer)
{
	size_t count[10] = {0};
	size_t i;
	int digit;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		buffer[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, *buffer;
	long exp;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp, buffer);
		print_array(array, size);
	}

	free(buffer);
}
