#ifndef FDF
# define FDF

# define ESC 65307
# define WIDTH 400
# define HEIGHT 400

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

typedef struct s_pixel
{
	char	*red;
	char	*green;
	char	*blue;
	char	*alpha;
}	t_pixel;

int	key_hook(int keycode, t_mlx_context *context);
t_pixel	get_pixel(char *p_pixel);
void	draw_pixel(char *image, t_image_data data, int x, int y, int color);

#endif
