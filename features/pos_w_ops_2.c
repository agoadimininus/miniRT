/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_w_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/16 13:38:56 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_pos_w	norm_pos_w(t_pos_w a)
{
	double		magnitude;
	t_pos_w		tmp;

	magnitude = mag_pos_w(a);
	if (magnitude == 0)
	{
		tmp.x = 0;
		tmp.y = 0;
		tmp.z = 0;
		tmp.w = 0;
	}
	else
	{
		tmp.x = a.x / magnitude;
		tmp.y = a.y / magnitude;
		tmp.z = a.z / magnitude;
		tmp.w = a.w / magnitude;
	}
	return (tmp);
}

int	comp_d(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}

int	equal_pos_w(t_pos_w a, t_pos_w b)
{
	if ((comp_d(a.x, b.x)) && (comp_d(a.y, b.y))
		&& (comp_d(a.z, b.z)) && a.w == b.w)
		return (1);
	else
		return (0);
}

double	deg_to_rad(double deg)
{
	return ((deg / 180) * M_PI);
}

t_pos_w	reflect(t_pos_w vector, t_pos_w normal)
{
	return (sub_pos_w(vector,
			scal_mul_pos_w(normal, 2 * dot_pos_w(vector, normal))));
}
