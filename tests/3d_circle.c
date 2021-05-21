/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:26:27 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/15 16:07:09 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

int main (void)
{
	t_pos_w			ray_origin;
	double			wall_z;
	double			wall_size;
	int				canvas_pixel;
	double			pixel_size;
	double			half;
	t_canvas		canvas;
	t_color			color;
	t_object		shape;
	int				y;
	double			world_y;
	int				x;
	double			world_x;
	t_pos_w			position;
	t_ray			r;
	t_node_inter	*xs;
	t_node_inter	*hit_node;
	t_matrix		rot;
	t_matrix		scal;
	t_matrix		trans;

	ray_origin = c_point(0, 0, -5);
	wall_z = 10;
	wall_size = 7;
	canvas_pixel = 100;
	pixel_size = wall_size / canvas_pixel;
	half = wall_size / 2;
	canvas = c_canvas(canvas_pixel, canvas_pixel);
	color = c_color(1, 0, 0);
	shape = c_sphere(shape);
	y = 0;
	while (y < canvas_pixel - 1)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < canvas_pixel - 1)
		{
			world_x = -half + pixel_size * x;
			position = c_point(world_x, world_y, wall_z);
			r = c_ray(ray_origin, norm_pos_w(sub_pos_w(position, ray_origin)));
			xs = init_node_list(xs);
			xs = intersect_sph(xs, &shape, r);
			hit_node = hit(xs);
			if (hit_node != NULL)
				canvas = write_pixel(canvas, x, y, color);
			free_intersection_list(xs);
			x++;
		}
		y++;
	}
	free_matrix(shape.transform);
	create_ppm("3d_circle", canvas);
	free_canvas(canvas);
	canvas = c_canvas(canvas_pixel, canvas_pixel);
	shape = c_sphere(shape);
	rot = rotation_z(M_PI / 4);
	scal = scaling(0.5, 1, 1);
	trans = mult_matrix(rot, scal);
	shape = set_transform(shape, scal);
	y = 0;
	while (y < canvas_pixel - 1)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < canvas_pixel - 1)
		{
			world_x = -half + pixel_size * x;
			position = c_point(world_x, world_y, wall_z);
			r = c_ray(ray_origin, norm_pos_w(sub_pos_w(position, ray_origin)));
			xs = init_node_list(xs);
			xs = intersect_sph(xs, &shape, r);
			hit_node = hit(xs);
			if (hit_node != NULL)
				canvas = write_pixel(canvas, x, y, color);
			free_intersection_list(xs);
			x++;
		}
		y++;
	}
	free_matrix(shape.transform);
	create_ppm("3d_circle_trans", canvas);
	free_canvas(canvas);
	free_matrix(scal);
	free_matrix(rot);
	free_matrix(trans);
}
