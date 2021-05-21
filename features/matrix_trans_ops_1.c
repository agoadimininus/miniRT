/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans_ops_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:58:36 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/16 13:58:39 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

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

t_camera	view_transform(t_camera c, t_pos_w from, t_pos_w to, t_pos_w up)
{
	t_matrix	result;
	t_vtrans	vtrans;
	t_matrix	trans;
	t_matrix	matrix;

	vtrans.forward = norm_pos_w(sub_pos_w(to, from));
	vtrans.left = cross_pos_w(vtrans.forward, norm_pos_w(up));
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
