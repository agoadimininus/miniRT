/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_w_ops_0_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:09 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_pos_w	c_point(double x, double y, double z)
{
	t_pos_w		tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	tmp.w = 1.0;
	return (tmp);
}

t_pos_w	c_vector(double x, double y, double z)
{
	t_pos_w		tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	tmp.w = 0.0;
	return (tmp);
}

t_pos_w	add_pos_w(t_pos_w a, t_pos_w b)
{
	t_pos_w		tmp;

	tmp.x = a.x + b.x;
	tmp.y = a.y + b.y;
	tmp.z = a.z + b.z;
	tmp.w = a.w + b.w;
	return (tmp);
}

t_pos_w	sub_pos_w(t_pos_w a, t_pos_w b)
{
	t_pos_w		tmp;

	tmp.x = a.x - b.x;
	tmp.y = a.y - b.y;
	tmp.z = a.z - b.z;
	tmp.w = a.w - b.w;
	return (tmp);
}

t_pos_w	neg_pos_w(t_pos_w a)
{
	t_pos_w		tmp;

	tmp.x = -a.x;
	tmp.y = -a.y;
	tmp.z = -a.z;
	tmp.w = a.w;
	return (tmp);
}
