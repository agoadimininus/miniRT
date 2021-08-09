/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans_ops_0_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:36 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:30:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	t;

	t = c_id_matrix(4);
	t.value[0][3] = x;
	t.value[1][3] = y;
	t.value[2][3] = z;
	return (t);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	t;

	t = c_id_matrix(4);
	t.value[0][0] = x;
	t.value[1][1] = y;
	t.value[2][2] = z;
	return (t);
}

t_matrix	rotation_x(double rad)
{
	t_matrix	t;

	t = c_id_matrix(4);
	t.value[1][1] = cos(rad);
	t.value[2][1] = sin(rad);
	t.value[1][2] = -(sin(rad));
	t.value[2][2] = cos(rad);
	return (t);
}

t_matrix	rotation_y(double rad)
{
	t_matrix	t;

	t = c_id_matrix(4);
	t.value[0][0] = cos(rad);
	t.value[0][2] = sin(rad);
	t.value[2][0] = -(sin(rad));
	t.value[2][2] = cos(rad);
	return (t);
}

t_matrix	rotation_z(double rad)
{
	t_matrix	t;

	t = c_id_matrix(4);
	t.value[0][0] = cos(rad);
	t.value[1][0] = sin(rad);
	t.value[0][1] = -(sin(rad));
	t.value[1][1] = cos(rad);
	return (t);
}
