/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_ops_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:09:30 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/22 19:02:53 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_light	c_light(t_pos_w	position, t_color color)
{
	t_light	new_light;

	new_light.position = position;
	new_light.intensity = color;
	return (new_light);
}

t_color	lightning(t_material *material, t_light light, t_pos_w point, t_pos_w eyev, t_pos_w normalv, int in_shadow)
{
	t_color	effective_color;
	t_pos_w	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	double	light_dot_normal;
	t_pos_w	reflectv;
	double	reflect_dot_eye;
	double	factor;

	effective_color = mul_color(material->color, light.intensity);
	ambient = scal_mul_color(effective_color, material->ambient);
	if (in_shadow == TRUE)
		return (ambient);
	lightv = norm_pos_w(sub_pos_w(light.position, point));
	//?lightv = norm_pos_w(sub_pos_w(point, light.position));
	light_dot_normal = dot_pos_w(lightv, normalv);
	//?light_dot_normal = sqrt(dot_pos_w(lightv, normalv));
	if (light_dot_normal < 0)
	{
		diffuse = c_color(0, 0, 0);
		specular = c_color(0, 0, 0);
	}
	else
	{
		diffuse = scal_mul_color(effective_color, (material->diffuse * light_dot_normal));
		reflectv = reflect(neg_pos_w(lightv), normalv);
		reflect_dot_eye = dot_pos_w(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = c_color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, material->shininess);
			specular = scal_mul_color(light.intensity, material->specular * factor);
		}
	}
	return (add_color(ambient, add_color(diffuse, specular)));
}

t_node_inter	*inter_shadow(t_world world, t_pos_w point, t_pos_w direction)
{
	t_ray			r;
	t_node_inter	*intersections;
	t_node_inter	*h;

	r = c_ray(point, direction);
	intersections = intersect_world(world, r);
	return (hit(intersections));
}

int	is_shadowed(t_world world, t_pos_w point, size_t i)
{
	t_pos_w			v;
	double			distance;
	t_pos_w			direction;
	t_node_inter	*h;

	v = sub_pos_w(world.lights[i].position, point);
	distance = mag_pos_w(v);
	direction = norm_pos_w(v);
	h = inter_shadow(world, point, direction);
	if (h != NULL && h->t < distance)
		return (TRUE);
	else
		return (FALSE);
}
