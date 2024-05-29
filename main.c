#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fdf.h"

int	key_hook(int keycode, t_mlx_context *context)
{
	printf("KEYCODE: %d\n", keycode);
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
	int		*map;
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
	image_data.pixels = mlx_get_data_addr(image, &image_data.bits_per_pixel, &image_data.size_line, &image_data.endian);

	//CREATE A SAMPLE MAP
	map = malloc(16 * sizeof(int));
	for (int i = 0; i < 16; i++) {
		*(map + i) = 0;
	}
	//DRAW PIXELS
	draw_map(image_data, (t_map){map, 16, 4}, 0xffffffff);
	//DRAW IMAGE
	mlx_put_image_to_window(context.connection, context.window, image, 0, 0);
	
	//ADD KEY HOOK
	mlx_key_hook(context.window, key_hook, &context);
	mlx_loop(context.connection);
	return (0);
}
