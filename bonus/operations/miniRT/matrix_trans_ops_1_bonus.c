/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans_ops_1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:36 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 10:39:44 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

static t_matrix	view_transform_matrix(t_vtrans vtrans)
{
	t_matrix	result;

	result = c_id_matrix(4);
	result.value[0][0] = vtrans.left.x;
	result.value[0][1] = vtrans.left.y;
	result.value[0][2] = vtrans.left.z;
	result.value[1][0] = vtrans.true_up.x;
	result.value[1][1] = vtrans.true_up.y;
	result.value[1][2] = vtrans.true_up.z;
	result.value[2][0] = -vtrans.forward.x;
	result.value[2][1] = -vtrans.forward.y;
	result.value[2][2] = -vtrans.forward.z;
	return (result);
}

t_camera	view_transform_cam(t_camera c, t_pos_w from, t_pos_w norm)
{
	t_matrix	result;
	t_vtrans	vtrans;
	t_matrix	trans;
	t_matrix	matrix;
	t_pos_w		up;

	up = c_vector(0, 1, 0);
	if (norm.y == 1)
		up = c_vector(0, 0, -1);
	else if (norm.y == -1)
		up = c_vector(0, 0, 1);
	vtrans.forward = norm;
	vtrans.left = cross_pos_w(vtrans.forward, up);
	vtrans.true_up = cross_pos_w(vtrans.left, vtrans.forward);
	matrix = view_transform_matrix(vtrans);
	trans = translation(-from.x, -from.y, -from.z);
	result = mult_matrix(matrix, trans);
	free_matrix(matrix);
	free_matrix(trans);
	free_matrix(c.transform);
	c.transform = result;
	return (c);
}

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

t_object	view_transform_obj(t_object o, t_pos_w from, t_pos_w norm)
{
	t_matrix	result;
	t_vtrans	vtrans;
	t_matrix	trans;
	t_matrix	matrix;
	t_pos_w		up;

	up = c_vector(0, 1, 0);
	if (norm.y == 1)
		up = c_vector(0, 0, -1);
	else if (norm.y == -1)
		up = c_vector(0, 0, 1);
	vtrans.forward = norm;
	vtrans.left = cross_pos_w(vtrans.forward, up);
	vtrans.true_up = cross_pos_w(vtrans.left, vtrans.forward);
	matrix = view_transform_matrix(vtrans);
	trans = translation(from.x, from.y, from.z);
	result = mult_matrix(matrix, trans);
	free_matrix(matrix);
	free_matrix(trans);
	o = set_transform(o, result);
	free_matrix(result);
	return (o);
}

t_object	view_transform_cy(t_object o, t_pos_w from, t_pos_w norm)
{
	t_matrix	rot_matrix;
	t_matrix	trans_matrix;

	trans_matrix = translation(from.x, from.y, from.z);
	o = setf_transform(o, trans_matrix);
	rot_matrix = normal_rotation_matrix(norm);
	o = setf_transform(o, rot_matrix);
	return (o);
}
