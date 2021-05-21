/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_ops_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:09:30 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/11 18:52:51 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_world	default_world(t_world world)
{
	t_matrix	transform;

	world.lights = (t_light *)malloc(sizeof(t_light));
	if (world.lights == NULL)
		exit(0);
	world.light_count = 1;
	world.lights[0] = c_light(c_point(-10, 10, -10), c_color(1, 1, 1));
	world.objects = (t_object *)malloc(sizeof(t_object) * 2);
	if (world.objects == NULL)
	{
		free(world.lights);
		exit(0);
	}
	world.objects_count = 2;
	world.objects[0] = c_sphere();
	world.objects[0].material->color = c_color(0.8, 1, 0.6);
	world.objects[0].material->diffuse = 0.7;
	world.objects[0].material->specular = 0.2;
	world.objects[1] = c_sphere();
	transform = scaling(0.5, 0.5, 0.5);
	world.objects[1] = set_transform(world.objects[1], transform);
	free_matrix(transform);
	return (world);
}

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
		head = intersect_sph(head, &world.objects[i], ray);
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
	return (comps);
}

t_color	shade_hit(t_world world, t_shade_comps comps)
{
	t_color	final_color;
	size_t	i;

	final_color = lightning(comps.object->material, world.lights[0], comps.point, comps.eyev, comps.normalv);
 	i = 2;
	while (i <= world.light_count)
	{
		final_color = add_color(final_color, lightning(comps.object->material, world.lights[i], comps.point, comps.eyev, comps.normalv));
		i++;
	}
	return (final_color);
}
