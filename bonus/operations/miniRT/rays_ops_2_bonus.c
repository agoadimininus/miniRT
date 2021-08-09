/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_ops_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:21:34 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:24 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

static t_node_inter	*local_intersect(t_node_inter *head, t_object *s, t_ray ray)
{
	if (s->shape == SPHERE)
		return (intersect_sph(head, s, ray));
	else if (s->shape == PLANE)
		return (intersect_pla(head, s, ray));
	else if (s->shape == SQUARE)
		return (intersect_sqr(head, s, ray));
	else
		return (intersect_cyl(head, s, ray));
}

t_node_inter	*intersect(t_node_inter *head, t_object *s, t_ray ray)
{
	t_matrix		inverse;

	inverse = invert_matrix(s->transform);
	ray = transform(ray, inverse);
	free_matrix(inverse);
	return (local_intersect(head, s, ray));
}

static t_pos_w	cyl_normal_at(t_object object, t_pos_w object_point)
{
	double	dist;

	dist = pow(object_point.x, 2) + pow(object_point.z, 2);
	if (dist < 1 && object_point.y >= object.cyl.h_height - EPSILON)
		return (c_vector(0, 1, 0));
	else if (dist < 1 && object_point.y <= -object.cyl.h_height + EPSILON)
		return (c_vector(0, -1, 0));
	else
		return (c_vector(object_point.x, 0, object_point.z));
}

static t_pos_w	local_normal_at(t_object object, t_pos_w object_point)
{
	if (object.shape == SPHERE)
		return (sub_pos_w(object_point, c_point(0, 0, 0)));
	if (object.shape == PLANE || object.shape == SQUARE)
		return (c_vector(0, 1, 0));
	else
		return (cyl_normal_at(object, object_point));
}

t_pos_w	normal_at(t_object object, t_pos_w world_point)
{
	t_pos_w		object_point;
	t_pos_w		object_normal;
	t_pos_w		world_normal;
	t_matrix	invert;
	t_matrix	transpose;

	invert = invert_matrix(object.transform);
	transpose = transpose_matrix(invert);
	object_point = mult_matrix_pos_w(invert, world_point);
	object_normal = local_normal_at(object, object_point);
	world_normal = mult_matrix_pos_w(transpose, object_normal);
	world_normal.w = 0;
	world_normal = norm_pos_w(world_normal);
	free_matrix(invert);
	free_matrix(transpose);
	return (world_normal);
}
