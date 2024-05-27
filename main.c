#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

int	key_hook(int keycode, t_mlx_context *context)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(context -> connection, context -> window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main()
{
	t_mlx_context	context;
	void		*image;
	t_image_data	image_data;
	char		*image_pixels;

	//CONNECTION TO GRAPHICAL SERVER
	context.connection = mlx_init();
	if (!context.connection) {
		perror("MLX Error encountered while opening a connection!");
		exit(EXIT_FAILURE);
	}
	//WINDOW CREATION
	context.window = mlx_new_window(context.connection, WIDTH, HEIGHT, "FDF");
	//IMAGE CREATION
	image = mlx_new_image(context.connection, WIDTH, HEIGHT);
	mlx_put_image_to_window(context.connection, context.window, image, 0, 0);
	image_pixels = mlx_get_data_addr(image, &image_data.bits_per_pixel, &image_data.size_line, &image_data.endian);
	printf("%d %d %d\n", image_data.bits_per_pixel, image_data.size_line, image_data.endian);
	//ADD KEY HOOK
	mlx_key_hook(context.window, key_hook, &context);
	mlx_loop(context.connection);
	return (0);
}
