/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans_ops_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:36 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/08 00:14:37 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

static t_matrix	normal_rotation_matrix(t_pos_w normal)
{
	double		angle;
	double		vals[3];
	t_pos_w		axis;
	t_matrix	rotation;

	rotation = c_matrix(4, 4);
	angle = acos(dot_pos_w(normal, c_vector(0, 1, 0)));
	axis = cross_pos_w(normal, c_vector(0, 1, 0));
	vals[0] = cos(angle);
	vals[1] = sin(angle);
	vals[2] = 1.0 - vals[0];
	rotation.value[0][0] = vals[0] + (pow(axis.x, 2) * vals[2]);
	rotation.value[0][1] = (axis.x * axis.y * vals[2]) - (axis.z * vals[1]);
	rotation.value[0][2] = (axis.x * axis.z * vals[2]) + (axis.y * vals[1]);
	rotation.value[1][0] = (axis.y * axis.z * vals[2]) + (axis.z * vals[1]);
	rotation.value[1][1] = vals[0] + (pow(axis.y, 2) * vals[2]);
	rotation.value[1][2] = (axis.y * axis.z * vals[2]) - (axis.x * vals[1]);
	rotation.value[2][0] = (axis.z * axis.x * vals[2]) - (axis.y * vals[1]);
	rotation.value[2][1] = (axis.z * axis.y * vals[2]) + (axis.x * vals[1]);
	rotation.value[2][2] = vals[0] + (pow(axis.z, 2) * vals[2]);
	rotation.value[3][3] = 1;
	return (rotation);
}

t_object	view_transform_cyl(t_object o, t_pos_w from, t_pos_w norm)
{
	t_matrix	rot_matrix;
	t_matrix	trans_matrix;

	trans_matrix = translation(from.x, from.y, from.z);
	o = setf_transform(o, trans_matrix);
	rot_matrix = normal_rotation_matrix(norm);
	o = setf_transform(o, rot_matrix);
	return (o);
}
