#include "fdf.h"

t_pixel	get_pixel(char *p_pixel)
{
	t_pixel	result;

	result.red = p_pixel;
	result.green = p_pixel + 1;
	result.blue = p_pixel + 2;
	result.alpha = p_pixel + 3;
	return (result);
}

t_point	new_point(int x, int y, int z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	draw_pixel(t_image image, int x, int y, int color)
{
	int	byte_per_pixel;
	int	column;
	int	row;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		byte_per_pixel = image.bits_per_pixel / 8;
		column = x * byte_per_pixel;
		row = y * image.size_line;
		t_pixel pixel = get_pixel(image.pixels + row + column);
		*pixel.red = (color & 0xFF);
		*pixel.green = (color >> 8) & 0xFF;
		*pixel.blue = (color >> 16) & 0xFF;
		*pixel.alpha = (color >> 24) & 0xFF;
	}
}

void	draw_line(t_image image, t_point point0, t_point point1, int color)
{
	int dx = abs(point1.x - point0.x);
	int sx = point0.x < point1.x ? 1 : -1;
	int dy = -abs(point1.y - point0.y);
	int sy = point0.y < point1.y ? 1 : -1;
	int error = dx + dy;

	while (1)
	{
		draw_pixel(image, point0.x, point0.y, color);
		if (point0.x == point1.x && point0.y == point1.y)
			break ;
		int e2 = 2 * error;
		if (e2 >= dy)
		{
			if (point0.x == point1.x)
				break ;
			error = error + dy;
			point0.x += sx;
		}
		if (e2 <= dx)
		{
			if (point0.y == point1.y)
				break ;
			error = error + dx;
			point0.y += sy;
		}
	}
}

void project_point(t_point *p, int d) {
	int	z;

	if (p -> z != 0)
	{
		z = p->z;
		p -> x = (p->x / z) * d;
		p -> y = (p->y / z) * d;
	}
}

void	draw_map(t_image image, t_map map, int color)
{
	t_point	**point;
	t_point	*r_point;
	t_point	*d_point;
	int	i;

	i = 0;
	point = map.map;
	while (*point)
	{
		draw_pixel(image, (*point) -> x, (*point) -> y, color);
		i++;
		point++;
	}
}
