/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_ops_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/09 20:32:39 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

static t_disc_cyl	intersect_cyl_disc(t_ray ray)
{
	t_disc_cyl	disc;

	disc.a_zero = 0;
	disc.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (fabs(disc.a) < EPSILON)
	{
		disc.discriminant = 0;
		disc.a_zero = 1;
		return (disc);
	}
	disc.b = 2 * ray.origin.x * ray.direction.x + 2
		* ray.origin.z * ray.direction.z;
	disc.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	disc.discriminant = pow(disc.b, 2) - 4 * disc.a * disc.c;
	return (disc);
}

static t_node_inter	*add_int_cyl(t_node_inter *head,
	t_object *s, t_disc_cyl disc, t_ray ray)
{
	t_node_inter	*node;
	double			tmp;
	double			y;

	node = NULL;
	node = init_node_list(node);
	tmp = (-disc.b - sqrt(disc.discriminant)) / (2 * disc.a);
	y = ray.origin.y + tmp * ray.direction.y;
	if (y < s->cyl.h_height && y > -(s->cyl.h_height))
	{
		node = intersection(node, tmp, s);
		head = list_inter(head, node);
		node = init_node_list(node);
	}
	tmp = (-disc.b + sqrt(disc.discriminant)) / (2 * disc.a);
	y = ray.origin.y + tmp * ray.direction.y;
	if (y < s->cyl.h_height && y > -s->cyl.h_height)
	{
		node = intersection(node, tmp, s);
		head = list_inter(head, node);
	}
	else
		free_intersection_list(node);
	return (head);
}

static int	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= 1);
}

static t_node_inter	*intersect_caps(t_node_inter *head, t_object *s, t_ray ray)
{
	t_node_inter	*node;
	double			t;

	if (fabs(ray.direction.y) < EPSILON)
		return (head);
	node = NULL;
	node = init_node_list(node);
	t = (s->cyl.h_height - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		node = intersection(node, t, s);
		head = list_inter(head, node);
		node = init_node_list(node);
	}
	t = (-s->cyl.h_height - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
	{
		node = intersection(node, t, s);
		head = list_inter(head, node);
	}
	else
		free_intersection_list(node);
	return (head);
}

t_node_inter	*intersect_cyl(t_node_inter *head, t_object *s, t_ray ray)
{
	t_disc_cyl		disc;

	head = intersect_caps(head, s, ray);
	disc = intersect_cyl_disc(ray);
	if (disc.discriminant < 0 || disc.a_zero == 1)
		return (head);
	head = add_int_cyl(head, s, disc, ray);
	return (head);
}
