#ifndef FDF
# define FDF

# define ESC 65307
# define WIDTH 800
# define HEIGHT 800
# include <math.h>

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
	char	*pixels;
}	t_image_data;

typedef struct s_pixel
{
	char	*red;
	char	*green;
	char	*blue;
	char	*alpha;
}	t_pixel;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int	key_hook(int keycode, t_mlx_context *context);
t_pixel	get_pixel(char *p_pixel);
void	draw_pixel(t_image_data image, int x, int y, int color);

#endif
