
#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int y, x, i, axis;
	char c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	axis = (size.y > size.x) ? size.y : size.x;
	for (i = 0; i < axis * axis * axis; i++)
	{
		for (y = 0; y < size.y; y++)
		{
			for (x = 0; x < size.x; x++)
			{
				if (tab[y][x] == 'F')
				{
					if (y > 0 && tab[y - 1][x] == c)
						tab[y - 1][x] = 'F';
					if (x > 0 && tab[y][x - 1] == c)
						tab[y][x - 1] = 'F';
					if (x < size.x - 1 && tab[y][x + 1] == c)
						tab[y][x + 1] = 'F';
					if (y < size.y - 1 && tab[y + 1][x] == c)
						tab[y + 1][x] = 'F';
				}
			}
		}
	}
}
