/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_ops_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:05 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_object	c_square(void)
{
	t_object	square;

	square.shape = SQUARE;
	square.transform = c_id_matrix(4);
	square.material = init_material(square.material);
	return (square);
}

t_node_inter	*intersect_sqr(t_node_inter *head, t_object *s, t_ray ray)
{
	t_node_inter	*node;
	double			t;
	t_pos_w			ray_position;
	t_pos_w			dist;
	double			border;

	if (fabs(ray.direction.y) < EPSILON)
		return (head);
	t = -ray.origin.y / ray.direction.y;
	ray_position = add_pos_w(ray.origin, scal_mul_pos_w(ray.direction, t));
	dist = neg_pos_w(ray_position);
	border = 0.5;
	if ((fabs(dist.x) <= border + EPSILON)
		&& (fabs(dist.y) <= border + EPSILON)
		&& (fabs(dist.z) <= border + EPSILON))
	{
		node = NULL;
		node = init_node_list(node);
		node = intersection(node, t, s);
		head = list_inter(head, node);
	}
	return (head);
}

t_material	*init_material(t_material *material)
{
	material = (t_material *)ft_calloc(1, sizeof(t_material));
	if (material == NULL)
		error_exit(SYSERR);
	material->color = c_color(1, 1, 1);
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	material->ambient = 0.1;
	return (material);
}
