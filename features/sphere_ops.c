/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:28:49 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/23 14:39:04 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_object	c_sphere(void)
{
	t_object	s;

	s.sphere.center = c_point(0, 0, 0);
	s.sphere.size = 1;
	s.transform = c_id_matrix(4);
	s.material = init_material(s.material);
	return (s);
}

static t_disc	intersect_sph_disc(t_object *s, t_ray ray)
{
	t_pos_w		sphere_to_ray;
	t_disc		disc;

	sphere_to_ray = sub_pos_w(ray.origin, s->sphere.center);
	disc.a = dot_pos_w(ray.direction, ray.direction);
	disc.b = 2 * dot_pos_w(ray.direction, sphere_to_ray);
	disc.c = dot_pos_w(sphere_to_ray, sphere_to_ray) - 1;
	disc.discriminant = pow(disc.b, 2) - (4 * disc.a * disc.c);
	return (disc);
}

static t_node_inter	*add_int_sph(t_node_inter *head, t_object *s, t_disc disc)
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
	t_disc			disc;
	t_matrix		inverse;

	inverse = invert_matrix(s->transform);
	ray = transform(ray, inverse);
	free_matrix(inverse);
	disc = intersect_sph_disc(s, ray);
	if (disc.discriminant < 0)
		return (head);
	head = add_int_sph(head, s, disc);
	return (head);
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
	object_normal = sub_pos_w(object_point, c_point(0, 0, 0));
	world_normal = mult_matrix_pos_w(transpose, object_normal);
	world_normal.w = 0;
	world_normal = norm_pos_w(world_normal);
	free_matrix(invert);
	free_matrix(transpose);
	return (world_normal);
}
