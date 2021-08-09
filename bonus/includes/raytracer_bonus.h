/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:16:28 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/08 00:16:30 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_BONUS_H
# define RAYTRACER_BONUS_H

/*
** ~*~*~*~*~*~*~*~ HEADERS ~*~*~*~*~*~*~*~
*/

# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include "../../libraries/libft/libft.h"
# include "../../libraries/minilibx-linux/mlx.h"
# include "../../libraries/minilibx-linux/mlx_int.h"
# include "structs_bonus.h"

/*
** ~*~*~*~*~*~*~*~ MACROS ~*~*~*~*~*~*~*~
*/

# define SYSERR			"000"
# define MISSEDERR		"---"

# define EPSILON		0.00001
# define TRUE			1
# define FALSE			0

# define RESOLUTION		0
# define AMBIENT		1
# define CAMERA			2
# define LIGHT			3
# define SPHERE			4
# define PLANE			5
# define SQUARE			6
# define CYLINDER		7

# define ESC			0xff1b
# define LEFT			0xff51
# define RIGHT			0xff53

/*
** ~*~*~*~*~*~*~*~ FUNCTION PROTOTYPES ~*~*~*~*~*~*~*~
*/
/*
** ~*~*~*~ MAIN ~*~*~*~
*/
/*
** MiniRT_1.c
*/
void			run_mlx(t_rt *rt);
void			save_bmp(t_rt *rt);

/*
** ~*~*~*~ OPERATIONS ~*~*~*~
*/
/*
** /\/\ ERROR /\/\
*/
/*
** Error operations 0
*/
int				open_fd(char *file, t_parse *parse);
void			close_fd(int fd);
void			print_error(char *code, int id);
void			parse_error_exit(char *err_str,
					t_element *element, t_parse *parse);
void			error_exit(char *err_str);

/*
** Error operations 1
*/
void			print_element_error(int id);
void			ele_parse_error_exit(char *err_str,
					t_element *element, t_parse *parse);
void			split_parse_error_exit(char *err_code,
					t_element *element, t_parse *parse, char **split);
void			error_only_parse_exit(char *err_str, t_parse *parse);
void			exit_scene_creation(char *err_str, t_rt *rt, t_parse *parse);

/*
** /\/\ MINIRT /\/\
*/
/*
** Camera operation.
*/
t_camera		camera_pixel_size_comps(t_camera camera);
t_camera		c_camera(double hsize, double vsize, double fov);
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
** Colors operations 1.
*/
int				equal_color(t_color a, t_color b);
t_color			rgbquad(t_color color);
int				map_color(double color);

/*
** Lights operations 0.
*/
t_light			c_light(t_pos_w	position, t_color color);
t_color			lightning(t_shade_comps comps, t_light light, int in_shadow);
int				is_shadowed(t_world world, t_pos_w point, size_t i);

/*
** Lights operations 1.
*/
t_color			ambient_lightning(t_material *material, t_light light);

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
t_camera		view_transform_cam(t_camera c, t_pos_w from, t_pos_w norm);
t_object		view_transform_obj(t_object o, t_pos_w from, t_pos_w norm);
t_object		view_transform_cy(t_object o, t_pos_w from, t_pos_w norm);

/*
** Objects operations 0.
*/
void			free_object(t_object obj);
t_object		c_sphere(void);
t_node_inter	*intersect_sph(t_node_inter *head, t_object *s, t_ray ray);

/*
** Objects operations 1.
*/
t_node_inter	*intersect_cyl(t_node_inter *head, t_object *s, t_ray ray);

/*
** Objects operations 2.
*/
t_object		c_plane(void);
t_node_inter	*intersect_pla(t_node_inter *head, t_object *s, t_ray ray);
t_object		c_cylinder(double height);

/*
** Objects operations 3.
*/
t_node_inter	*intersect_sqr(t_node_inter *head, t_object *s, t_ray ray);
t_object		c_square(void);
t_material		*init_material(t_material *material);

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
** Rays operations 2 X.
*/
t_node_inter	*intersect(t_node_inter *head, t_object *s, t_ray ray);
t_pos_w			normal_at(t_object object, t_pos_w world_point);

/*
** Rays operations 3 X.
*/
t_object		setf_transform(t_object obj, t_matrix trans_matrix);

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
t_world			c_world(t_parse *parse, size_t light_count,
					size_t objects_count);

/*
** /\/\ PARSE /\/\
*/
/*
** Parse_ops_0.c
*/
t_parse			*parse_line(t_element *element, t_parse *parse);
void			free_line_split(t_parse *parse);
void			free_parse(t_parse *parse);
t_element		*init_element_list(t_element *list);
t_parse			*init_parse_struct(t_parse *parse);

/*
** Parse_ops_1.c
*/
void			parse_line_split(t_element *element, t_parse *parse);
t_parse			*get_values_hub(t_element *element, t_parse *parse);
void			check_parse_elements(t_parse *parse);

/*
** Parse_ops_2.c
*/
t_parse			*get_resolution(t_element *element, t_parse *parse);
t_parse			*get_ambient(t_element *element, t_parse *parse);
t_parse			*get_camera(t_element *element, t_parse *parse);
t_parse			*get_light(t_element *element, t_parse *parse);
void			free_and_close(t_parse *parse);

/*
** Parse_ops_3.c
*/
t_parse			*get_sphere(t_element *element, t_parse *parse);
t_parse			*get_plane(t_element *element, t_parse *parse);
t_parse			*get_square(t_element *element, t_parse *parse);
t_parse			*get_cylinder(t_element *element, t_parse *parse);

/*
** Parse_ops_4.c
*/
char			**free_split(char **split);
void			check_id(t_element *element, t_parse *parse);
t_element		*next_element_list(t_element *list);

/*
** get_values_ops_0.c
*/
int				str_isint(char *str);
int				get_int(t_element *element, t_parse *parse,
					int idx, char *err_code);
int				get_posint(t_element *element, t_parse *parse,
					int idx, char *err_code);
int				get_fov(t_element *element, t_parse *parse,
					int idx, char *err_code);
t_color			get_rgb(t_element *element, t_parse *parse,
					int idx, char *err_code);

/*
** get_values_ops_1.c
*/
int				str_double_check_signs(char *str, size_t *i);
int				str_isdouble(char *str);
double			get_double(t_element *element,
					t_parse *parse, int idx, char *err_code);
double			get_posd(t_element *element,
					t_parse *parse, int idx, char *err_code);
double			get_ratio(t_element *element,
					t_parse *parse, int idx, char *err_code);

/*
** get_values_ops_2.c
*/
int				get_int_splitted(t_element *element,
					t_parse *parse, char *err_code, t_spl_inf split);
double			get_double_splitted(t_element *element,
					t_parse *parse, char *err_code, t_spl_inf split);
t_pos_w			get_pos_w(t_element *element,
					t_parse *parse, int idx, char *err_code);
t_pos_w			get_normv(t_element *element,
					t_parse *parse, int idx, char *err_code);

/*
** /\/\ RENDER /\/\
*/
/*
** Bitmaps operation.
*/
void			create_bmp(char *str, t_canvas canvas);

/*
** MLX operations 0.
*/
int				close_all(t_rt *rt);
void			next_cam(t_mlx *vars);
void			previous_cam(t_mlx *vars);
int				key_pressed(int keycode, t_rt *rt);
int				expose_hook(t_mlx *vars);

/*
** MLX operations 1.
*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_mlx			c_images(t_mlx vars, int img_count, int win_w, int win_h);
t_mlx			screen_resolution(t_mlx vars);
t_data			canvas_to_img(t_data img, t_canvas canvas);

/*
** MLX operations 2.
*/
t_rt			*free_rt(t_rt *rt);
t_rt			*free_scene(t_rt *rt);

/*
** /\/\ SCENE /\/\
*/
/*
** init_scene_0.c.
*/
t_rt			create_scene_and_render(t_rt *rt, t_parse *parse);

/*
** init_scene_1.c.
*/
t_rt			*push_light(t_rt *rt, t_parse *parse);
t_rt			*push_sphere(t_rt *rt, t_parse *parse);
t_rt			*push_plane(t_rt *rt, t_parse *parse);
t_rt			*push_square(t_rt *rt, t_parse *parse);
t_rt			*push_cylinder(t_rt *rt, t_parse *parse);

#endif
