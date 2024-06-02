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

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_image
{
	void	*image;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char	*pixels;
}	t_image;

typedef struct s_settings
{
	int x_offset;
	int y_offset;
	int zoom;
}	t_settings;

typedef struct s_map
{
	t_point	**map;
	int	size_map;
	int	size_line;
}	t_map;

typedef struct s_context
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_settings	settings;
	t_map		map;
}	t_context;

typedef struct s_pixel
{
	char	*red;
	char	*green;
	char	*blue;
	char	*alpha;
}	t_pixel;

int	key_hook(int keycode, t_context *context);
t_pixel	get_pixel(char *p_pixel);
void	draw_pixel(t_image image, int x, int y, int color);
void	draw_line(t_image image, t_point point1, t_point point2, int color);
void	draw_map(t_image image, t_map map, int color);
t_point **initialize_map(int *points, int rows, int cols);
void shift_map(t_point **map, int x, int y);
void print_map(t_point **map);
void translate_map(t_point **map, int x, int y, int z);
void scale_map(t_point **map, float scale);

#endif
