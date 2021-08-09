/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_ops_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 15:50:29 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_object	c_plane(void)
{
	t_object	plane;

	plane.shape = PLANE;
	plane.transform = c_id_matrix(4);
	plane.material = init_material(plane.material);
	return (plane);
}

t_node_inter	*intersect_pla(t_node_inter *head, t_object *s, t_ray ray)
{
	t_node_inter	*node;
	double			t;

	if (fabs(ray.direction.y) < EPSILON)
		return (head);
	node = NULL;
	node = init_node_list(node);
	t = -ray.origin.y / ray.direction.y;
	node = intersection(node, t, s);
	head = list_inter(head, node);
	return (head);
}

t_object	c_cylinder(double height)
{
	t_object	cylinder;

	cylinder.shape = CYLINDER;
	cylinder.transform = c_id_matrix(4);
	cylinder.material = init_material(cylinder.material);
	cylinder.cyl.height = height;
	cylinder.cyl.h_height = height / 2;
	return (cylinder);
}
