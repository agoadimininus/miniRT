/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:43:40 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 10:31:03 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

static t_rt	*push_camera(t_rt *rt, t_parse *parse);
static t_rt	*push_ambient(t_rt *rt, t_parse *parse);
static t_rt	*push_elements_hub(t_rt *rt, t_parse *parse);
static t_rt	*push_elements_rt(t_rt *rt, t_parse *parse);

t_rt	create_scene_and_render(t_rt *rt, t_parse *parse)
{
	int	i;

	i = 0;
	rt->world = c_world(parse, parse->check_qty[LIGHT] + 1,
			parse->check_qty[SPHERE]);
	rt->cam_count = parse->check_qty[1];
	rt->cameras = (t_camera *)ft_calloc(rt->cam_count, sizeof(t_camera));
	if (rt->cameras == NULL)
		exit_scene_creation(SYSERR, rt, parse);
	rt->canvas = (t_canvas *)ft_calloc(rt->cam_count, sizeof(t_canvas));
	if (rt->canvas == NULL)
	{
		free(rt->cameras);
		exit_scene_creation(SYSERR, rt, parse);
	}
	rt = push_elements_rt(rt, parse);
	free_and_close(parse);
	while (i < rt->cam_count)
	{
		printf("Rendering image\n");
		rt->canvas[i] = render(rt->cameras[i], rt->world);
		i++;
	}
	return (*rt);
}

static t_rt	*push_elements_rt(t_rt *rt, t_parse *parse)
{
	t_element	*next_ptr;

	if (parse->ele_list != NULL)
	{
		while (parse->ele_list->next != NULL)
		{
			rt = push_elements_hub(rt, parse);
			next_ptr = parse->ele_list->next;
			free(parse->ele_list);
			parse->ele_list = NULL;
			parse->ele_list = next_ptr;
		}
		rt = push_elements_hub(rt, parse);
		free(parse->ele_list);
		parse->ele_list = NULL;
	}
	return (rt);
}

static t_rt	*push_elements_hub(t_rt *rt, t_parse *parse)
{
	if (parse->ele_list->id == AMBIENT)
		rt = push_ambient(rt, parse);
	else if (parse->ele_list->id == CAMERA)
		rt = push_camera(rt, parse);
	else if (parse->ele_list->id == LIGHT)
		rt = push_light(rt, parse);
	else if (parse->ele_list->id == SPHERE)
		rt = push_sphere(rt, parse);
	else if (parse->ele_list->id == PLANE)
		rt = push_plane(rt, parse);
	else if (parse->ele_list->id == CYLINDER)
		rt = push_cylinder(rt, parse);
	return (rt);
}

static t_rt	*push_ambient(t_rt *rt, t_parse *parse)
{
	t_color		color;

	ft_bzero(&color, sizeof(t_color));
	color.r = (parse->ele_list->rgb.r * parse->ele_list->ratio) / 255;
	color.g = (parse->ele_list->rgb.g * parse->ele_list->ratio) / 255;
	color.b = (parse->ele_list->rgb.b * parse->ele_list->ratio) / 255;
	rt->world.lights[AMBIENT].intensity = color;
	return (rt);
}

static t_rt	*push_camera(t_rt *rt, t_parse *parse)
{
	double	fov;

	fov = (M_PI * parse->ele_list->fov) / 180;
	parse->check_qty[CAMERA] -= 1;
	rt->cameras[parse->check_qty[CAMERA]] = c_camera(rt->mlx.width,
			rt->mlx.height, fov);
	rt->cameras[parse->check_qty[CAMERA]] = view_transform_cam
		(rt->cameras[parse->check_qty[CAMERA]], parse->ele_list->coord,
			parse->ele_list->norm);
	return (rt);
}
