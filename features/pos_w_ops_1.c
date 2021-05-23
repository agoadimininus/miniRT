/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_w_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/22 17:33:34 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_pos_w	scal_mul_pos_w(t_pos_w a, double scale)
{
	t_pos_w		tmp;

	tmp.x = a.x * scale;
	tmp.y = a.y * scale;
	tmp.z = a.z * scale;
	tmp.w = a.w * scale;
	return (tmp);
}

t_pos_w	scal_div_pos_w(t_pos_w a, double scale)
{
	t_pos_w		tmp;

	tmp.x = a.x / scale;
	tmp.y = a.y / scale;
	tmp.z = a.z / scale;
	tmp.w = a.w / scale;
	return (tmp);
}

t_pos_w	cross_pos_w(t_pos_w a, t_pos_w b)
{
	t_pos_w		tmp;

	tmp.x = a.y * b.z - a.z * b.y;
	tmp.y = a.z * b.x - a.x * b.z;
	tmp.z = a.x * b.y - a.y * b.x;
	tmp.w = 0;
	return (tmp);
}

double	dot_pos_w(t_pos_w a, t_pos_w b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
}

double	mag_pos_w(t_pos_w a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}
