/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:09:30 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/14 12:54:31 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_color	color_at(t_world world, t_ray ray)
{
	t_node_inter	*head;
	t_node_inter	*hit_node;
	t_shade_comps	comps;
	t_color			color;

	head = intersect_world(world, ray);
	hit_node = hit(head);
	if (hit_node == NULL)
		color = c_color(0, 0, 0);
	else
	{
		comps = prepare_shade_computations(hit_node, ray);
		color = shade_hit(world, comps);
	}
	free_intersection_list(head);
	return (color);
}

t_world	c_world(t_parse *parse, size_t light_count, size_t objects_count)
{
	t_world		world;

	ft_bzero(&world, sizeof(t_world));
	world.lights = (t_light *)ft_calloc(light_count, sizeof(t_light));
	if (world.lights == NULL)
		error_only_parse_exit("SYSERROR", parse);
	world.light_count = light_count;
	world.objects = (t_object *)ft_calloc(objects_count, sizeof(t_object));
	if (world.objects == NULL)
	{
		free(world.lights);
		error_only_parse_exit("SYSERROR", parse);
	}
	world.objects_count = objects_count;
	return (world);
}
