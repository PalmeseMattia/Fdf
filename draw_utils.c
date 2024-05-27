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

t_point	new_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

void	draw_pixel(t_image_data image, int x, int y, int color)
{
	int	byte_per_pixel;
	int	column;
	int	row;

	byte_per_pixel = image.bits_per_pixel / 8;
	column = x * byte_per_pixel;
	row = y * image.size_line;
	t_pixel pixel = get_pixel(image.pixels + row + column);
	*pixel.red = (color & 0xFF);
	*pixel.green = (color >> 8) & 0xFF;
	*pixel.blue = (color >> 16) & 0xFF;
	*pixel.alpha = (color >> 24) & 0xFF;
}

void	draw_line(t_image_data image, t_point point1, t_point point2, int color)
{
	int dx = point2.x - point1.x;
	int dy = point2.y - point1.y;
    	int D = 2 * (dy - dx);
    	int y = point1.y;
	int x = point1.x;

	while (x != point2.x) {
		draw_pixel(image, x, y, color);
		if (D > 0) {
			y = y + 1;
			D = D - (2 * dx);
		}
		D = D + (2 *dy);
		if (x > point2.x)
			x--;
		else
			x++;
	}
}
