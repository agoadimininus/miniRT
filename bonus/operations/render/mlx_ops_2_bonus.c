/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:25:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_rt	*free_rt(t_rt *rt)
{
	int		i;

	if (rt->mlx.win != NULL)
	{
		mlx_clear_window(rt->mlx.mlx, rt->mlx.win);
		mlx_destroy_window(rt->mlx.mlx, rt->mlx.win);
		i = 0;
		while (i < rt->cam_count)
		{
			mlx_destroy_image(rt->mlx.mlx, rt->mlx.img[i].img);
			i++;
		}
		mlx_destroy_display(rt->mlx.mlx);
		rt->mlx.win = NULL;
	}
	free(rt->mlx.img);
	rt->mlx.img = NULL;
	free(rt->mlx.mlx);
	rt->mlx.mlx = NULL;
	rt = free_scene(rt);
	return (rt);
}

t_rt	*free_scene(t_rt *rt)
{
	int		i;

	i = 0;
	while (i < rt->cam_count)
	{
		free_matrix(rt->cameras[i].transform);
		free_canvas(rt->canvas[i]);
		i++;
	}
	free(rt->cameras);
	rt->cameras = NULL;
	free(rt->canvas);
	rt->canvas = NULL;
	free_world(rt->world);
	return (rt);
}
