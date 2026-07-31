#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grids sum
 * @grid: 3x3 grid
 *
 */

void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Check if a grid is unstable
 * @grid: 3x3 grid
 * Return: true if unstable, false otherwise
 */

bool is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (true);
			}
		}
	}
	return (false);
}

/**
 * topple - Topple a grid
 * @grid: 3x3 grid
 *
 */

void topple(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {0};

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					temp_grid[i][j] -= 4;
					if (i - 1 >= 0)
						temp_grid[i - 1][j]++;
					if (i + 1 < 3)
						temp_grid[i + 1][j]++;
					if (j - 1 >= 0)
						temp_grid[i][j - 1]++;
					if (j + 1 < 3)
						temp_grid[i][j + 1]++;
				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid[i][j] += temp_grid[i][j];
			}
		}
}
/**
 * sandpiles_sum - Entry point
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: Always 0
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
