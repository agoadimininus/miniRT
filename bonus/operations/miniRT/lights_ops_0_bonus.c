/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_ops_0_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:09:30 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:30:34 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_light	c_light(t_pos_w	position, t_color color)
{
	t_light	new_light;

	new_light.position = position;
	new_light.intensity = color;
	return (new_light);
}

static t_light_comps	lightning_else_dot(t_shade_comps comps, t_light light,
	t_light_comps l)
{
	l.diffuse = scal_mul_color(l.effective_color,
			(comps.object->material->diffuse * l.light_dot_normal));
	l.reflectv = reflect(neg_pos_w(l.lightv), comps.normalv);
	l.reflect_dot_eye = dot_pos_w(l.reflectv, comps.eyev);
	if (l.reflect_dot_eye <= 0)
		l.specular = c_color(0, 0, 0);
	else
	{
		l.factor = pow(l.reflect_dot_eye, comps.object->material->shininess);
		l.specular = scal_mul_color(light.intensity,
				comps.object->material->specular * l.factor);
	}
	return (l);
}

/*
** modificações na função lightning que produzem glitches interessantes:
** lightv = norm_pos_w(sub_pos_w(comps.over_point, light.position));
** light_dot_normal = sqrt(dot_pos_w(lightv, comps.normalv));
*/

t_color	lightning(t_shade_comps comps, t_light light, int in_shadow)
{
	t_light_comps	l;

	l.effective_color = mul_color(comps.object->material->color,
			light.intensity);
	l.ambient = scal_mul_color(l.effective_color,
			comps.object->material->ambient);
	if (in_shadow == TRUE)
		return (l.ambient);
	l.lightv = norm_pos_w(sub_pos_w(light.position, comps.over_point));
	l.light_dot_normal = dot_pos_w(l.lightv, comps.normalv);
	if (l.light_dot_normal < 0)
	{
		l.diffuse = c_color(0, 0, 0);
		l.specular = c_color(0, 0, 0);
	}
	else
		l = lightning_else_dot(comps, light, l);
	return (add_color(l.ambient, add_color(l.diffuse, l.specular)));
}

static int	inter_shadow(t_world world, t_pos_w point,
	t_pos_w direction, double distance)
{
	t_ray			r;
	t_node_inter	*intersections;
	t_node_inter	*h;

	r = c_ray(point, direction);
	intersections = intersect_world(world, r);
	h = hit(intersections);
	if (h != NULL && h->t < distance)
	{
		free_intersection_list(intersections);
		return (TRUE);
	}
	else
	{
		free_intersection_list(intersections);
		return (FALSE);
	}
}

int	is_shadowed(t_world world, t_pos_w point, size_t i)
{
	t_pos_w			v;
	double			distance;
	t_pos_w			direction;

	v = sub_pos_w(world.lights[i].position, point);
	distance = mag_pos_w(v);
	direction = norm_pos_w(v);
	return (inter_shadow(world, point, direction, distance));
}
