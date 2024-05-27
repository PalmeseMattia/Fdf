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

void	draw_pixel(char *image, t_image_data data, int x, int y, int color)
{
	int	byte_per_pixel;
	int	column;
	int	row;

	byte_per_pixel = data.bits_per_pixel / 8;
	column = x * byte_per_pixel;
	row = y * data.size_line;
	t_pixel pixel = get_pixel(image + row + column);
	*pixel.red = (color & 0xFF);
	*pixel.green = (color >> 8) & 0xFF;
	*pixel.blue = (color >> 16) & 0xFF;
	*pixel.alpha = (color >> 24) & 0xFF;
}
