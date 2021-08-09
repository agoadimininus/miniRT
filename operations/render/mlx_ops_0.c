/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ops_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:25:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:59:06 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

int	close_all(t_rt *rt)
{
	free_rt(rt);
	exit(0);
	return (0);
}

int	key_pressed(int keycode, t_rt *rt)
{
	if (keycode == ESC)
		close_all(rt);
	return (0);
}

int	expose_hook(t_mlx *vars)
{
	return (mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img[vars->img_v].img, 0, 0));
}
