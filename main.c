#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx_context
{
	void	*connection;
	void	*window;
} t_mlx_context;

int	key_hook(int keycode, t_mlx_context *context)
{
	printf("%d\n", keycode);
	if (keycode > 0)
		mlx_destroy_window(context -> connection, context -> window);
	return (0);
}

int main()
{
	t_mlx_context	context;

	context.connection = mlx_init();
	if (!context.connection) {
		perror("MLX Error encountered while opening a connection!");
		exit(EXIT_FAILURE);
	}
	context.window = mlx_new_window(context.connection, 800, 800, "FDF");
	mlx_key_hook(context.connection, key_hook, &context);
	mlx_loop(context.connection);
	return (0);
}
