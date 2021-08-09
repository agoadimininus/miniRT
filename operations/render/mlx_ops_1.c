/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:25:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:53:57 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_mlx	c_images(t_mlx vars, int img_count, int win_w, int win_h)
{
	int		x;

	vars.img_count = img_count;
	vars.img_v = 0;
	vars.img = (t_data *)ft_calloc(img_count, sizeof(t_data));
	x = 0;
	while (x < img_count)
	{
		vars.img[x].img = mlx_new_image(vars.mlx, win_w, win_h);
		vars.img[x].addr = mlx_get_data_addr(vars.img[x].img,
				&vars.img[x].bits_per_pixel, &vars.img[x].line_length,
				&vars.img[x].endian);
		x++;
	}
	return (vars);
}

t_data	canvas_to_img(t_data img, t_canvas canvas)
{
	int		x;
	int		y;

	x = 0;
	while (x < canvas.width)
	{
		y = 0;
		while (y < canvas.height)
		{
			my_mlx_pixel_put(&img, x, y, canvas.color[x][y].trgb);
			y++;
		}
		x++;
	}
	return (img);
}
