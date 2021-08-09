/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_ops_0_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:21:34 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:18 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_ray	c_ray(t_pos_w origin, t_pos_w direction)
{
	t_ray		ret;

	ret.origin = c_point(origin.x, origin.y, origin.z);
	ret.direction = c_vector(direction.x, direction.y, direction.z);
	return (ret);
}

t_pos_w	position(t_ray ray, double time)
{
	t_pos_w		ret;

	ret = scal_mul_pos_w(ray.direction, time);
	ret = add_pos_w(ray.origin, ret);
	return (ret);
}

t_node_inter	*init_node_list(t_node_inter *node)
{
	node = (t_node_inter *)malloc(sizeof(t_node_inter));
	node->obj = NULL;
	node->next = NULL;
	node->count = 0;
	return (node);
}

t_node_inter	*intersection(t_node_inter *node, double t, t_object *obj)
{
	node->obj = obj;
	node->t = t;
	return (node);
}

void	free_intersection_list(t_node_inter *list)
{
	t_node_inter	*tmp;

	while (list->next != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	free(list);
}
