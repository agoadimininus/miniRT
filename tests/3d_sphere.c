/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 21:26:27 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/11 18:51:18 by cfico-vi         ###   ########.fr       */
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
	t_canvas		canvas1;
	t_canvas		canvas2;
	t_object		shape;
	int				y;
	double			world_y;
	int				x;
	double			world_x;
	t_pos_w			pos;
	t_ray			r;
	t_node_inter	*xs;
	t_node_inter	*hit_node;
	t_light			light1;
	t_light			light2;
	t_light			light3;
	t_pos_w			point;
	t_pos_w			normal;
	t_pos_w			eye;
	t_color			color1;
	t_color			color2;

	ray_origin = c_point(-3, 0, -5);
	wall_z = 10;
	wall_size = 14;
	canvas_pixel = 500;
	pixel_size = wall_size / canvas_pixel;
	half = wall_size / 2;
	canvas1 = c_canvas(canvas_pixel, canvas_pixel);
	canvas2 = c_canvas(canvas_pixel, canvas_pixel);
	shape = c_sphere();
	shape = setf_transform(shape, translation(-1.5 , 0.5, -0.5));
//	shape.transform = mult_free(shape.transform, scaling(1, 2, 1));
	shape.material->color = c_color(1, 1, 1);
	light2 = c_light(c_point(10, 10, -10), c_color(1, 0.2, 0.2));
	light1 = c_light(c_point(-10, 10, -10), c_color(0.2, 0.2, 1));
	light3 = c_light(c_point(0, 0, -10), c_color(0.2, 1, 0.2));
	y = 0;
	while (y < canvas_pixel - 1)
	{
		world_y = half - pixel_size * y;
		x = 0;
		while (x < canvas_pixel - 1)
		{
			world_x = -half + pixel_size * x;
			pos = c_point(world_x, world_y, wall_z);
			r = c_ray(ray_origin, norm_pos_w(sub_pos_w(pos, ray_origin)));
			xs = init_node_list(xs);
			xs = intersect_sph(xs, &shape, r);
			hit_node = hit(xs);
/* 			if (hit_node != NULL)
			{
				printf("BEFORE %f, %f, %f || ", hit_node->obj->material->ambient, hit_node->obj->material->diffuse, hit_node->obj->material->specular);
				printf("%f, %f, %f\n", shape.material->ambient, shape.material->diffuse, shape.material->specular);
			} */
 			if (hit_node != NULL)
			{
				point = position(r, hit_node->t);
				normal = normal_at(shape, point);
				eye = neg_pos_w(r.direction);
				color1 = lightning(hit_node->obj->material, light1, point, eye, normal);
			//	color1 = add_color(color1, lightning(hit_node->obj->material, light2, point, eye, normal));
			//	color1 = add_color(color1, lightning(hit_node->obj->material, light3, point, eye, normal));
				canvas1 = write_pixel(canvas1, x, y, color1);
				color2 = lightning(hit_node->obj->material, light1, point, eye, normal);
				color2 = add_color(color2, lightning(hit_node->obj->material, light2, point, eye, normal));
				color2 = add_color(color2, lightning(hit_node->obj->material, light3, point, eye, normal));
				canvas2 = write_pixel(canvas2, x, y, color2);
			}
			free_intersection_list(xs);
			x++;
		}
		y++;
	}
	free_matrix(shape.transform);
	//create_ppm("3d_sphere_test_color1_trans", canvas1);
	free_canvas(canvas1);
	create_ppm("3d_sphere_test_color2_trans", canvas2);
	free_canvas(canvas2);
}
