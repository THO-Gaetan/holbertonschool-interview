#include <stdio.h>
#include "menger.h"

/**
 * is_hole - checks if a coordinate falls on a removed (hole) cell
 * of a 2D Menger Sponge
 *
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 1 if the cell is a hole, 0 otherwise
 */
int is_hole(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}

	return (0);
}

/**
 * menger - draws a 2D Menger Sponge of a given level
 *
 * @level: the level of the Menger Sponge
 *
 * Return: void
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = 1;
	while (level-- > 0)
		size *= 3;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
			putchar(is_hole(x, y) ? ' ' : '#');
		putchar('\n');
	}
}