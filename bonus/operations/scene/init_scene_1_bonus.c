/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:43:40 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 10:35:24 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_rt	*push_light(t_rt *rt, t_parse *parse)
{
	t_color		color;

	ft_bzero(&color, sizeof(t_color));
	color.r = (parse->ele_list->rgb.r * parse->ele_list->ratio) / 255;
	color.g = (parse->ele_list->rgb.g * parse->ele_list->ratio) / 255;
	color.b = (parse->ele_list->rgb.b * parse->ele_list->ratio) / 255;
	rt->world.lights[parse->check_qty[LIGHT]] = c_light(parse->ele_list->coord,
			color);
	parse->check_qty[LIGHT] -= 1;
	return (rt);
}

t_rt	*push_sphere(t_rt *rt, t_parse *parse)
{
	t_color		color;
	t_matrix	scal_matrix;

	ft_bzero(&color, sizeof(t_color));
	parse->check_qty[SPHERE] -= 1;
	rt->world.objects[parse->check_qty[SPHERE]] = c_sphere();
	color.r = parse->ele_list->rgb.r / 255;
	color.g = parse->ele_list->rgb.g / 255;
	color.b = parse->ele_list->rgb.b / 255;
	rt->world.objects[parse->check_qty[SPHERE]].material->color = color;
	rt->world.objects[parse->check_qty[SPHERE]] = view_transform_obj
		(rt->world.objects[parse->check_qty[SPHERE]], parse->ele_list->coord,
			c_vector(0, 0, -1));
	scal_matrix = scaling(parse->ele_list->element_d_1 / 2,
			parse->ele_list->element_d_1 / 2, parse->ele_list->element_d_1 / 2);
	rt->world.objects[parse->check_qty[SPHERE]] = setf_transform
		(rt->world.objects[parse->check_qty[SPHERE]], scal_matrix);
	return (rt);
}

t_rt	*push_plane(t_rt *rt, t_parse *parse)
{
	t_color		color;

	ft_bzero(&color, sizeof(t_color));
	parse->check_qty[SPHERE] -= 1;
	rt->world.objects[parse->check_qty[SPHERE]] = c_plane();
	color.r = parse->ele_list->rgb.r / 255;
	color.g = parse->ele_list->rgb.g / 255;
	color.b = parse->ele_list->rgb.b / 255;
	rt->world.objects[parse->check_qty[SPHERE]].material->color = color;
	rt->world.objects[parse->check_qty[SPHERE]] = view_transform_obj
		(rt->world.objects[parse->check_qty[SPHERE]], parse->ele_list->coord,
			parse->ele_list->norm);
	return (rt);
}

t_rt	*push_square(t_rt *rt, t_parse *parse)
{
	t_color		color;
	t_matrix	scal_matrix;

	ft_bzero(&color, sizeof(t_color));
	parse->check_qty[SPHERE] -= 1;
	rt->world.objects[parse->check_qty[SPHERE]] = c_square();
	color.r = parse->ele_list->rgb.r / 255;
	color.g = parse->ele_list->rgb.g / 255;
	color.b = parse->ele_list->rgb.b / 255;
	rt->world.objects[parse->check_qty[SPHERE]].material->color = color;
	rt->world.objects[parse->check_qty[SPHERE]] = view_transform_obj
		(rt->world.objects[parse->check_qty[SPHERE]], parse->ele_list->coord,
			parse->ele_list->norm);
	scal_matrix = scaling(parse->ele_list->element_d_1, 1,
			parse->ele_list->element_d_1);
	rt->world.objects[parse->check_qty[SPHERE]] = setf_transform
		(rt->world.objects[parse->check_qty[SPHERE]], scal_matrix);
	return (rt);
}

t_rt	*push_cylinder(t_rt *rt, t_parse *parse)
{
	t_color		color;
	t_matrix	scal_matrix;

	ft_bzero(&color, sizeof(t_color));
	parse->check_qty[SPHERE] -= 1;
	if (parse->ele_list->norm.y == 1)
		parse->ele_list->norm = c_vector(0, 0.99999999, 0);
	else if (parse->ele_list->norm.y == -1)
		parse->ele_list->norm = c_vector(0, 0.99999999, 0);
	rt->world.objects[parse->check_qty[SPHERE]] = c_cylinder
		(parse->ele_list->element_d_2);
	color.r = parse->ele_list->rgb.r / 255;
	color.g = parse->ele_list->rgb.g / 255;
	color.b = parse->ele_list->rgb.b / 255;
	rt->world.objects[parse->check_qty[SPHERE]].material->color = color;
	rt->world.objects[parse->check_qty[SPHERE]] = view_transform_cy
		(rt->world.objects[parse->check_qty[SPHERE]], parse->ele_list->coord,
			parse->ele_list->norm);
	scal_matrix = scaling(parse->ele_list->element_d_1 / 2, 1,
			parse->ele_list->element_d_1 / 2);
	rt->world.objects[parse->check_qty[SPHERE]] = setf_transform
		(rt->world.objects[parse->check_qty[SPHERE]], scal_matrix);
	return (rt);
}
