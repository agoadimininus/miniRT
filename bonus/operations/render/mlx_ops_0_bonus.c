/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops_0_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:25:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:58:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:25:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 13:12:16 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

int	close_all(t_rt *rt)
{
	free_rt(rt);
	exit(0);
	return (0);
}

void	next_cam(t_mlx *vars)
{
	if (vars->img_v + 1 < vars->img_count)
		vars->img_v++;
	else
		vars->img_v = 0;
	printf("Camera #%d view\n", vars->img_v + 1);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img[vars->img_v].img, 0, 0);
}

void	previous_cam(t_mlx *vars)
{
	if (vars->img_v - 1 >= 0)
		vars->img_v--;
	else
		vars->img_v = vars->img_count - 1;
	printf("Camera #%d view\n", vars->img_v + 1);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img[vars->img_v].img, 0, 0);
}

int	key_pressed(int keycode, t_rt *rt)
{
	if (keycode == ESC)
		close_all(rt);
	else if (keycode == RIGHT)
		next_cam(&rt->mlx);
	else if (keycode == LEFT)
		previous_cam(&rt->mlx);
	return (0);
}

int	expose_hook(t_mlx *vars)
{
	return (mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img[vars->img_v].img, 0, 0));
}
