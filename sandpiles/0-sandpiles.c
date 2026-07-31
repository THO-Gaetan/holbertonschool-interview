#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - Entry point
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: Always 0
 */
int sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	while (1)
	{
		print_grid_sum(grid1, grid2);
		if (sandpiles_stable(grid1, grid2))
			break;
		sandpiles_toppling(grid1, grid2);
	}
}