/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:51:44 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/05/11 18:52:00 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define EPSILON		0.00001
# define TRUE			1
# define FALSE			0

typedef struct s_pos_w
{
	double				x;
	double				y;
	double				z;
	int					w;
}						t_pos_w;

typedef struct s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct s_canvas
{
	t_color				**color;
	int					width;
	int					height;
}						t_canvas;

typedef struct s_material
{
	t_color				color;
	double				diffuse;
	double				specular;
	double				shininess;
	double				ambient;
}						t_material;

typedef struct s_matrix
{
	double				**value;
	int					row;
	int					col;
}						t_matrix;

typedef struct s_ray
{
	t_pos_w				origin;
	t_pos_w				direction;
}						t_ray;

typedef struct s_object
{
	double				size;
	t_pos_w				center;
	t_matrix			transform;
	t_material			*material;
}						t_object;

typedef struct s_disc
{
	double				a;
	double				b;
	double				c;
	double				discriminant;
}						t_disc;

typedef struct s_node_inter
{
	int					count;
	double				t;
	t_object			*obj;
	struct s_node_inter	*next;
}						t_node_inter;

typedef struct s_light
{
	t_color				intensity;
	t_pos_w				position;
}						t_light;

typedef struct s_world
{
	t_light				*lights;
	size_t				light_count;
	t_object			*objects;
	size_t				objects_count;
}						t_world;

typedef struct s_raypx_comps
{
	double				xoffset;
	double				yoffset;
	double				world_x;
	double				world_y;
	t_pos_w				pixel;
	t_pos_w				origin;
	t_pos_w				direction;
}						t_raypx_comps;

typedef struct s_shade_comps
{
	t_object	*object;
	t_pos_w		point;
	t_pos_w		eyev;
	t_pos_w		normalv;
	double		t;
	int			inside;
}						t_shade_comps;

typedef struct s_vtrans
{
	t_pos_w		forward;
	t_pos_w		left;
	t_pos_w		true_up;
}						t_vtrans;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		fov;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
}						t_camera;

/*
** Camera operation.
*/
t_camera		camera_pixel_size_comps(t_camera camera);
t_camera		c_camera(double hsize, double wsize, double fov);
t_ray			ray_for_pixel(t_camera camera, double px, double py);
t_canvas		render(t_camera camera, t_world world);

/*
** Canvas operation.
*/
t_canvas		c_canvas(int width, int height);
void			free_canvas(t_canvas canvas);
t_canvas		write_pixel(t_canvas canvas, int col, int row, t_color color);

/*
** Colors operations 0.
*/
t_color			c_color(double r, double g, double b);
t_color			add_color(t_color a, t_color b);
t_color			sub_color(t_color a, t_color b);
t_color			scal_mul_color(t_color a, double scale);
t_color			mul_color(t_color a, t_color b);

/*
** Colors operations 0.
*/
int				equal_color(t_color a, t_color b);

/*
** OPERATIONS TO DELETE.
** OPERATIONS TO DELETE.
** OPERATIONS TO DELETE.
** OPERATIONS TO DELETE.
*/
t_matrix		assign_values_matrix(t_matrix a, ...);
void			print_matrix(t_matrix a);
void			print_inter_list(t_node_inter *list);

/*
** Materials operations 0.
*/
t_material		*init_material(t_material *material);

/*
** Lights operations 0.
*/
t_light			c_light(t_pos_w	position, t_color color);
t_color			lightning(t_material *material, t_light light, t_pos_w position, t_pos_w eyev, t_pos_w normalv);


/*
** Invert matrix operations.
*/
t_matrix		submatrix(t_matrix a, int row, int col);
double			minor_matrix(t_matrix a, int row, int col);
double			cofactor_matrix(t_matrix a, int row, int col);
double			determ_matrix(t_matrix a);
t_matrix		invert_matrix(t_matrix a);

/*
** Matrix operations 0.
*/
t_matrix		c_matrix(int row, int col);
void			free_matrix(t_matrix matrix);
int				equal_matrix(t_matrix a, t_matrix b);
double			dot_matrix(t_matrix a, t_matrix b, int r, int c);

/*
** Matrix operations 1.
*/
t_matrix		mult_matrix(t_matrix a, t_matrix b);
t_pos_w			mult_matrix_pos_w(t_matrix a, t_pos_w b);
t_matrix		c_id_matrix(int size);
t_matrix		transpose_matrix(t_matrix a);
t_matrix		mult_free(t_matrix a, t_matrix b);

/*
** Matrix transformation operations 0.
*/
t_matrix		translation(double x, double y, double z);
t_matrix		scaling(double x, double y, double z);
t_matrix		rotation_x(double rad);
t_matrix		rotation_y(double rad);
t_matrix		rotation_z(double rad);

/*
** Matrix transformation operations 1.
*/
t_camera		view_transform(t_camera c, t_pos_w from, t_pos_w to, t_pos_w up);

/*
** Objects operations 0.
*/
void			free_object(t_object obj);

/*
** Vector/points operations 0.
*/
t_pos_w			c_point(double x, double y, double z);
t_pos_w			c_vector(double x, double y, double z);
t_pos_w			add_pos_w(t_pos_w a, t_pos_w b);
t_pos_w			sub_pos_w(t_pos_w a, t_pos_w b);
t_pos_w			neg_pos_w(t_pos_w a);

/*
** Vector/points operations 1.
*/
t_pos_w			scal_mul_pos_w(t_pos_w a, double scale);
t_pos_w			scal_div_pos_w(t_pos_w a, double scale);
t_pos_w			cross_pos_w(t_pos_w a, t_pos_w b);
double			dot_pos_w(t_pos_w a, t_pos_w b);
double			mag_pos_w(t_pos_w a);

/*
** Vector/points operations 2.
*/
t_pos_w			norm_pos_w(t_pos_w a);
int				comp_d(double a, double b);
int				equal_pos_w(t_pos_w a, t_pos_w b);
double			deg_to_rad(double deg);
t_pos_w			reflect(t_pos_w vector, t_pos_w normal);

/*
** PPM creation X.
*/
void			ppm_header(t_canvas canvas, int fd);
int				map_color(double color);
int				ppm_line_len(int *counter, int fd);
void			printpixel_ppm(t_color color, int fd, int *counter);
void			create_ppm(char *str, t_canvas canvas);

/*
** Rays operations 0 X.
*/
t_ray			c_ray(t_pos_w origin, t_pos_w direction);
t_pos_w			position(t_ray ray, double time);
t_node_inter	*init_node_list(t_node_inter *node);
t_node_inter	*intersection(t_node_inter *node, double t, t_object *obj);
void			free_intersection_list(t_node_inter *list);

/*
** Rays operations 1 X.
*/
t_node_inter	*pos_node_inter(t_node_inter *head, t_node_inter *node);
t_node_inter	*list_inter(t_node_inter *head, t_node_inter *node);
t_node_inter	*hit(t_node_inter *head);
t_ray			transform(t_ray ray, t_matrix matrix);
t_object		set_transform(t_object obj, t_matrix matrix);

/*
** Rays operations 1 X.
*/
t_object		setf_transform(t_object obj, t_matrix trans_matrix);

/*
** Sphere operations X.
*/
t_object		c_sphere(void);
t_node_inter	*intersect_sph(t_node_inter *head, t_object *s, t_ray ray);
t_pos_w			normal_at(t_object object, t_pos_w world_point);

/*
** World operations 0.
*/
t_world			default_world(t_world world);
void			free_world(t_world world);
t_node_inter	*intersect_world(t_world world, t_ray ray);
t_shade_comps	prepare_shade_computations(t_node_inter *inter, t_ray ray);
t_color			shade_hit(t_world world, t_shade_comps comps);

/*
** World operations 1.
*/
t_color			color_at(t_world world, t_ray ray);
t_world			c_world(size_t light_count, size_t objects_count);

#endif
