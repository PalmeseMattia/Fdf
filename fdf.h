#ifndef FDF
# define FDF

# define ESC 65307
# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_mlx_context
{
	void	*connection;
	void	*window;
}	t_mlx_context;

typedef struct s_image_data
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
}	t_image_data;

int	key_hook(int keycode, t_mlx_context *context);

#endif
