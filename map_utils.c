#include "fdf.h"

t_point **initialize_map(int *points, int rows, int cols)
{
	t_point **map;
	int i;

	i = 0;
	map = (t_point **)malloc(sizeof(t_point *) * rows * cols + 1);
	if (!map)
		return (NULL);
	while (i < (rows * cols))
	{
		(*(map + i)) = malloc(sizeof(t_point));
		(*(map + i)) -> x = i % cols;
		(*(map + i)) -> y = i / rows;
		(*(map + i)) -> z = *(points + i);
		i++;
	}
	*(map + i) = NULL;
	return map;
}

void translate_map(t_point **map, int x, int y, int z)
{
	t_point	**point;

	point = map;
	while(*point)
	{
		(*point) -> x += x;
		(*point) -> y += y;
		(*point) -> z += z;
		point++;
	}
}

void scale_map(t_point **map, float scale)
{
	t_point	**point;

	point = map;
	while(*point)
	{
		(*point) -> x *= scale;
		(*point) -> y *= scale;
		(*point) -> z *= scale;
		point++;
	}
}

void print_map(t_point **map)
{
	t_point **point;

	point = map;
	while (*point)
	{
		printf("X: %f Y: %f Z: %f\n", (*point) -> x, (*point) -> y, (*point) -> z);
		point++;
	}
}
