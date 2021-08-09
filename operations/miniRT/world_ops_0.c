/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_ops_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:09:30 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/08 00:06:50 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

void	free_world(t_world world)
{
	size_t	i;

	i = 0;
	while (i < world.objects_count)
	{
		free_matrix(world.objects[i].transform);
		free(world.objects[i].material);
		i++;
	}
	free(world.objects);
	free(world.lights);
}

t_node_inter	*intersect_world(t_world world, t_ray ray)
{
	t_node_inter	*head;
	size_t			i;

	head = NULL;
	head = init_node_list(head);
	i = 0;
	while (i < world.objects_count)
	{
		head = intersect(head, &world.objects[i], ray);
		i++;
	}
	return (head);
}

t_shade_comps	prepare_shade_computations(t_node_inter *inter, t_ray ray)
{
	t_shade_comps	comps;

	comps.t = inter->t;
	comps.object = inter->obj;
	comps.point = position(ray, comps.t);
	comps.eyev = neg_pos_w(ray.direction);
	comps.normalv = normal_at(*inter->obj, comps.point);
	if (dot_pos_w(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = neg_pos_w(comps.normalv);
	}
	else
		comps.inside = FALSE;
	comps.over_point = scal_mul_pos_w(comps.normalv, EPSILON);
	comps.over_point = add_pos_w(comps.over_point, comps.point);
	return (comps);
}

t_color	shade_hit(t_world world, t_shade_comps comps)
{
	t_color	final_color;
	size_t	i;
	int		shadowed;

	final_color = mul_color(comps.object->material->color,
			world.lights[0].intensity);
	i = 1;
	while (i < world.light_count)
	{
		shadowed = is_shadowed(world, comps.over_point, i);
		final_color = add_color(final_color,
				lightning(comps, world.lights[i], shadowed));
		i++;
	}
	return (final_color);
}
