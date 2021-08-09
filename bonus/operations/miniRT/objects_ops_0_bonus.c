/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_ops_0_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:18:04 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:30:55 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

void	free_object(t_object obj)
{
	free(obj.material);
	free_matrix(obj.transform);
}

t_object	c_sphere(void)
{
	t_object	s;

	s.shape = SPHERE;
	s.sph.center = c_point(0, 0, 0);
	s.sph.size = 1;
	s.transform = c_id_matrix(4);
	s.material = init_material(s.material);
	return (s);
}

static t_disc_sph	intersect_sph_disc(t_object *s, t_ray ray)
{
	t_pos_w			sphere_to_ray;
	t_disc_sph		disc;

	sphere_to_ray = sub_pos_w(ray.origin, s->sph.center);
	disc.a = dot_pos_w(ray.direction, ray.direction);
	disc.b = 2 * dot_pos_w(ray.direction, sphere_to_ray);
	disc.c = dot_pos_w(sphere_to_ray, sphere_to_ray) - 1;
	disc.discriminant = pow(disc.b, 2) - (4 * disc.a * disc.c);
	return (disc);
}

static t_node_inter	*add_int_sph(t_node_inter *head,
	t_object *s, t_disc_sph disc)
{
	t_node_inter	*node;
	double			tmp;

	node = NULL;
	node = init_node_list(node);
	tmp = (-disc.b - sqrt(disc.discriminant)) / (2 * disc.a);
	node = intersection(node, tmp, s);
	head = list_inter(head, node);
	node = init_node_list(node);
	tmp = (-disc.b + sqrt(disc.discriminant)) / (2 * disc.a);
	node = intersection(node, tmp, s);
	head = list_inter(head, node);
	return (head);
}

t_node_inter	*intersect_sph(t_node_inter *head, t_object *s, t_ray ray)
{
	t_disc_sph		disc;

	disc = intersect_sph_disc(s, ray);
	if (disc.discriminant < 0)
		return (head);
	head = add_int_sph(head, s, disc);
	return (head);
}
