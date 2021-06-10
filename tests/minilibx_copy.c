#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_data	img;
	int		height;
	int		width;
}				t_mlx;

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char*)(s + i++) = '\0';
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(t_mlx *vars)
{
	if (vars->win)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	free(vars->mlx);
	vars->mlx = NULL;
	exit(0);
	return (0);
}


t_data	c_print_image(t_data img, int color, int win_w, int win_h)
{
	int		x;
	int		y;

	x = 0;
	while (x < win_w)
	{
		y = 0;
		while (y < win_h)
		{
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	return (img);
}

int			expose_hook(t_mlx *vars)
{
	return (mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.img, 0, 0));
}

int	main(void)
{
	t_mlx	vars;

	ft_bzero(&vars, sizeof(t_mlx));
	vars.mlx = mlx_init();
	vars.height = 500;
	vars.width = 500;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "minilibX_test!");
	vars.img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
		vars.img.addr = mlx_get_data_addr(vars.img.img,
				&vars.img.bits_per_pixel, &vars.img.line_length,
				&vars.img.endian);
	vars.img = c_print_image(vars.img, 0x00FFFFFF, vars.width, vars.height);
	mlx_expose_hook(vars.win, expose_hook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, close, &vars);
	mlx_loop(vars.mlx);
}

