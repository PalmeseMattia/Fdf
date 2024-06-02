#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fdf.h"

int	key_hook(int keycode, t_context *context)
{
	printf("KEYCODE: %d\n", keycode);
	if (keycode == R_ARROW)
		translate_map(context -> map.map, 10, 0, 0);
	else if (keycode == L_ARROW)
		translate_map(context -> map.map, -10, 0, 0);
	else if (keycode == D_ARROW)
		translate_map(context -> map.map, 0, 10, 0);
	else if (keycode == U_ARROW)
		translate_map(context -> map.map, 0, -10, 0);
	else if (keycode == W)
	{
		scale_map(context -> map.map, 2.0);
		print_map(context -> map.map);
	}
	else if (keycode == S)
	{
		scale_map(context -> map.map, 0.5);
		print_map(context -> map.map);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_window(context -> mlx, context -> win);
		exit(EXIT_SUCCESS);
	}
	for (int i = 0; i < (context -> image.bits_per_pixel / 8) * WIDTH * HEIGHT; i++) {
		*((context -> image.pixels) + i) = (char)0;
	}
	draw_map(context -> image, context -> map, 0xffffffff);
	mlx_put_image_to_window(context -> mlx, context -> win, context -> image.image, 0, 0);
	return (0);
}

int main()
{
	t_context	context;

	//CONNECTION TO GRAPHICAL SERVER
	context.mlx = mlx_init();
	if (!context.mlx) {
		perror("MLX Error encountered while opening a connection!");
		exit(EXIT_FAILURE);
	}
	
	//WINDOW CREATION
	context.win = mlx_new_window(context.mlx, WIDTH, HEIGHT, "FDF");

	//IMAGE CREATION
	context.image.image = mlx_new_image(context.mlx, WIDTH, HEIGHT);
	context.image.pixels = mlx_get_data_addr(context.image.image, &context.image.bits_per_pixel, &context.image.size_line, &context.image.endian);
	
	//CREATE A SAMPLE MAP
	int *map = (int *)malloc(16 * sizeof(int));
	for (int i = 0; i < 16; i++) {
		*(map + i) = i;
	}
	t_point **mappa = initialize_map(map, 4, 4);
	context.map.map = mappa;
	context.map.size_map = 16;
	context.map.size_line = 4;

	//DRAW MAP
	draw_map(context.image, context.map, 0xffffffff);
	
	//DRAW IMAGE
	mlx_put_image_to_window(context.mlx, context.win, context.image.image, 0, 0);
	
	//ADD KEY HOOK
	mlx_key_hook(context.win, key_hook, &context);
	mlx_loop(context.mlx);
	return (0);
}
