/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:32:15 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:28:43 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

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
	int					trgb;
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

typedef struct s_sphere
{
	double				size;
	t_pos_w				center;
}						t_sphere;

typedef struct s_square
{
	double				vazio;
}						t_square;

typedef struct s_cylinder
{
	double				height;
	double				h_height;
}						t_cylinder;

typedef struct s_object
{
	int					shape;
	t_sphere			sph;
	t_cylinder			cyl;
	t_square			sqr;
	t_matrix			transform;
	t_material			*material;
}						t_object;

typedef struct s_disc_sph
{
	double				a;
	double				b;
	double				c;
	double				discriminant;
}						t_disc_sph;

typedef struct s_disc_cyl
{
	double				a;
	double				b;
	double				c;
	double				discriminant;
	int					a_zero;
}						t_disc_cyl;

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

typedef struct s_light_comps
{
	t_color				effective_color;
	t_color				ambient;
	t_pos_w				lightv;
	t_color				diffuse;
	t_color				specular;
	double				light_dot_normal;
	t_pos_w				reflectv;
	double				reflect_dot_eye;
	double				factor;
}						t_light_comps;

typedef struct s_world
{
	t_light				ambient;
	t_light				*lights;
	size_t				light_count;
	t_object			*objects;
	size_t				objects_count;
	t_pos_w				vec;
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
	t_object			*object;
	t_pos_w				point;
	t_pos_w				eyev;
	t_pos_w				normalv;
	double				t;
	int					inside;
	t_pos_w				over_point;
}						t_shade_comps;

typedef struct s_vtrans
{
	t_pos_w				forward;
	t_pos_w				left;
	t_pos_w				true_up;
}						t_vtrans;

typedef struct s_camera
{
	double				hsize;
	double				vsize;
	double				fov;
	double				pixel_size;
	double				half_width;
	double				half_height;
	t_matrix			transform;
}						t_camera;

typedef struct s_bmpheader
{
	uint16_t			type;
	uint32_t			size;
	uint16_t			reserved;
	uint32_t			offset;
	uint32_t			dib_header_size;
	int32_t				width_px;
	int32_t				height_px;
	uint16_t			num_planes;
	uint16_t			bpp;
	uint32_t			compression;
	uint32_t			img_size_bytes;
	int32_t				x_resolution_ppm;
	int32_t				y_resolution_ppm;
	uint32_t			num_colors;
	uint32_t			important_colors;
}						t_bmpheader;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	t_data				*img;
	int					img_v;
	int					img_count;
	int					height;
	int					width;
}						t_mlx;

typedef struct s_rt
{
	t_mlx				mlx;
	int					save;
	t_world				world;
	int					cam_count;
	t_camera			*cameras;
	t_canvas			*canvas;
}						t_rt;

typedef struct s_element
{
	int					id;
	int					width;
	int					height;
	double				ratio;
	t_color				rgb;
	t_pos_w				coord;
	t_pos_w				norm;
	int					fov;
	double				element_d_1;
	double				element_d_2;
	struct s_element	*next;
}						t_element;

typedef struct s_spl_inf
{
	char				**split;
	int					idx;
}						t_spl_inf;

typedef struct s_parse
{
	int					check_qty[5];
	char				*line;
	char				**split;
	t_element			*ele_list;
	int					fd;
	int					width;
	int					height;
	int					not_dark;
}						t_parse;

#endif
