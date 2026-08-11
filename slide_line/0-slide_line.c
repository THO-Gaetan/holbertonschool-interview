#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;
    int tmp[2048];

    if (!line || size == 0)
        return (0);

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    for (i = 0; i < size; i++)
        tmp[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = j = 0; i < size; i++)
            if (line[i] != 0)
                tmp[j++] = line[i];

        for (i = 0; i + 1 < size; i++)
        {
            if (tmp[i] != 0 && tmp[i] == tmp[i + 1])
            {
                tmp[i] *= 2;
                tmp[i + 1] = 0;
            }
        }

        for (i = j = 0; i < size; i++)
            if (tmp[i] != 0)
                line[j++] = tmp[i];
        while (j < size)
            line[j++] = 0;
    }
    else
    {
        for (i = size, j = size; i > 0; i--)
            if (line[i - 1] != 0)
                tmp[--j] = line[i - 1];

        for (k = size; k > 1; k--)
        {
            i = k - 1;
            if (tmp[i] != 0 && tmp[i] == tmp[i - 1])
            {
                tmp[i] *= 2;
                tmp[i - 1] = 0;
            }
        }

        for (i = size, j = size; i > 0; i--)
            if (tmp[i - 1] != 0)
                line[--j] = tmp[i - 1];

        while (j > 0)
            line[--j] = 0;
    }

    return (1);
}