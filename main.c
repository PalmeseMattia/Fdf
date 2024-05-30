#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fdf.h"

int	key_hook(int keycode, t_mlx_context *context)
{
	printf("KEYCODE: %d\n", keycode);
	if (keycode == R_ARROW)
		context -> settings.x_offset += 1;
	else if (keycode == L_ARROW)
		context -> settings.x_offset -= 1;
	else if (keycode == D_ARROW)
		context -> settings.y_offset += 1;
	else if (keycode == U_ARROW)
		context -> settings.y_offset -= 1;
	else if (keycode == W)
		context -> settings.zoom += 1;
	else if (keycode == S)
		context -> settings.zoom -= 1;
	else if (keycode == ESC)
	{
		mlx_destroy_window(context -> connection, context -> window);
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < (context -> image.bits_per_pixel / 8) * WIDTH * HEIGHT; i++) {
		*((context -> image.pixels) + i) = (char)0;
	}
	mlx_put_image_to_window(context -> connection, context -> window, context -> p_img, 0, 0);
	draw_map(context -> image, context -> map, 0xffffffff, context -> settings);
	return (0);
}

int main()
{
	t_mlx_context	context;
	void		*image;
	t_image_data	image_data;
	int		*map;

	t_settings settings = {20, 10, 20};
	context.settings = settings;
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
	context.image = image_data;
	context.p_img = image;
	//CREATE A SAMPLE MAP
	map = malloc(16 * sizeof(int));
	for (int i = 0; i < 16; i++) {
		*(map + i) = 0;
	}
	context.map = (t_map){map, 16, 4};
	//DRAW PIXELS
	draw_map(context.image, context.map, 0xffffffff, context.settings);
	//DRAW IMAGE
	mlx_put_image_to_window(context.connection, context.window, image, 0, 0);
	
	//ADD KEY HOOK
	mlx_key_hook(context.window, key_hook, &context);
	mlx_loop(context.connection);
	return (0);
}
