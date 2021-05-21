/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ops_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:09:13 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/15 15:49:30 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_camera	camera_pixel_size_comps(t_camera camera)
{
	double	half_view;
	double	aspect;

	half_view = tan(camera.fov / 2);
	aspect = camera.hsize / camera.vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}

t_camera	c_camera(double hsize, double vsize, double fov)
{
	t_camera	result;

	result.fov = fov;
	result.hsize = hsize;
	result.vsize = vsize;
	result.transform = c_id_matrix(4);
	result = camera_pixel_size_comps(result);
	return (result);
}

t_ray	ray_for_pixel(t_camera camera, double px, double py)
{
	t_raypx_comps	c;
	t_matrix		inv;

	c.xoffset = (px + 0.5) * camera.pixel_size;
	c.yoffset = (py + 0.5) * camera.pixel_size;
	c.world_x = camera.half_width - c.xoffset;
	c.world_y = camera.half_height - c.yoffset;
	inv = invert_matrix(camera.transform);
	c.pixel = mult_matrix_pos_w(inv, c_point(c.world_x, c.world_y, -1));
	c.origin = mult_matrix_pos_w(inv, c_point(0, 0, 0));
	c.direction = norm_pos_w(sub_pos_w(c.pixel, c.origin));
	free_matrix(inv);
	return (c_ray(c.origin, c.direction));
}

t_canvas	render(t_camera camera, t_world world)
{
	t_canvas	image;
	size_t		y;
	size_t		x;
	t_ray		ray;
	t_color		color;

	image = c_canvas(camera.hsize, camera.vsize);
	y = 0;
	while (y < camera.vsize)
	{
		x = 0;
		while (x < camera.hsize)
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			image = write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
