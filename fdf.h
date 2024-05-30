#ifndef FDF
# define FDF

# define ESC 65307
# define R_ARROW 65363
# define L_ARROW 65361
# define D_ARROW 65364
# define U_ARROW 65362
# define W 119
# define S 115
# define WIDTH 1600
# define HEIGHT 1600
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_image_data
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char	*pixels;
}	t_image_data;

typedef struct s_settings
{
	int x_offset;
	int y_offset;
	int zoom;
}	t_settings;

typedef struct s_map
{
	int	*map;
	int	size_map;
	int	size_line;
}	t_map;

typedef struct s_mlx_context
{
	void		*connection;
	void		*window;
	void		*p_img;
	t_image_data	image;
	t_settings	settings;
	t_map		map;
}	t_mlx_context;

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
	int	z;
}	t_point;

int	key_hook(int keycode, t_mlx_context *context);
t_pixel	get_pixel(char *p_pixel);
void	draw_pixel(t_image_data image, int x, int y, int color);
void	draw_line(t_image_data image, t_point point1, t_point point2, int color);
void	draw_map(t_image_data image, t_map map, int color, t_settings settings);

#endif
