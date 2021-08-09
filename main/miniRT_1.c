/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:43:40 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:57:08 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

void	run_mlx(t_rt *rt)
{
	int		i;

	i = 0;
	while (i < rt->cam_count)
	{
		printf("Rendering camera\n");
		rt->mlx.img[i] = canvas_to_img(rt->mlx.img[i], rt->canvas[i]);
		i++;
	}
	rt->mlx.win = mlx_new_window(rt->mlx.mlx,
			rt->mlx.width, rt->mlx.height, "miniRT");
	mlx_expose_hook(rt->mlx.win, expose_hook, &rt->mlx);
	printf("Camera view\n");
	mlx_hook(rt->mlx.win, 33, 1L << 17, close_all, rt);
	mlx_hook(rt->mlx.win, 2, 1L << 0, key_pressed, rt);
	mlx_loop(rt->mlx.mlx);
}
