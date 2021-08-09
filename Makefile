# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 12:58:34 by cfico-vi          #+#    #+#              #
#    Updated: 2021/08/09 13:47:51 by cfico-vi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
NAME_B		= miniRT_bonus
LIBFT		= libft.a
MLX			= libmlx.a

LIBFT_PATH	= ./libraries/libft/
MLX_PATH	= ./libraries/minilibx-linux/

MAIN		= ./main/
OPS			= ./operations/
ERROR		= ${OPS}error/
MINI		= ${OPS}miniRT/
PARSE		= ${OPS}parse/
RENDER		= ${OPS}render/
SCENE		= ${OPS}scene/

MAIN_F		= ${MAIN}miniRT_0.c ${MAIN}miniRT_1.c
MAIN_OBJ	= miniRT_0.o miniRT_1.o
ERROR_F		= ${ERROR}error_ops_0.c ${ERROR}error_ops_1.c
ERROR_OBJ	= error_ops_0.o error_ops_1.o
MINI_F		= ${MINI}matrix_ops_1.c ${MINI}objects_ops_0.c ${MINI}pos_w_ops_1.c ${MINI}rays_ops_2.c ${MINI}camera_ops_0.c ${MINI}lights_ops_0.c ${MINI}matrix_trans_ops_0.c ${MINI}objects_ops_1.c ${MINI}pos_w_ops_2.c ${MINI}rays_ops_3.c ${MINI}canvas_ops.c ${MINI}lights_ops_1.c ${MINI}matrix_trans_ops_1.c ${MINI}objects_ops_2.c  ${MINI}world_ops_0.c ${MINI}color_ops_0.c ${MINI}matrix_invert_ops.c ${MINI}objects_ops_3.c ${MINI}rays_ops_0.c ${MINI}world_ops_1.c ${MINI}color_ops_1.c ${MINI}matrix_ops_0.c ${MINI}pos_w_ops_0.c ${MINI}rays_ops_1.c
MINI_OBJ	= matrix_ops_1.o objects_ops_0.o pos_w_ops_1.o rays_ops_2.o camera_ops_0.o lights_ops_0.o matrix_trans_ops_0.o objects_ops_1.o pos_w_ops_2.o rays_ops_3.o canvas_ops.o lights_ops_1.o matrix_trans_ops_1.o objects_ops_2.o world_ops_0.o color_ops_0.o matrix_invert_ops.o objects_ops_3.o rays_ops_0.o world_ops_1.o color_ops_1.o matrix_ops_0.o pos_w_ops_0.o rays_ops_1.o
PARSE_F		= ${PARSE}parse_ops_4.c ${PARSE}get_values_ops_2.c ${PARSE}get_values_ops_1.c ${PARSE}parse_ops_3.c ${PARSE}parse_ops_0.c ${PARSE}parse_ops_1.c ${PARSE}parse_ops_2.c ${PARSE}get_values_ops_0.c
PARSE_OBJ	= parse_ops_4.o get_values_ops_2.o get_values_ops_1.o parse_ops_3.o parse_ops_0.o parse_ops_1.o parse_ops_2.o get_values_ops_0.o
RENDER_F	= ${RENDER}mlx_ops_0.c ${RENDER}mlx_ops_1.c ${RENDER}mlx_ops_2.c
RENDER_OBJ	= mlx_ops_0.o mlx_ops_1.o mlx_ops_2.o
SCENE_F		= ${SCENE}init_scene_1.c ${SCENE}init_scene_0.c
SCENE_OBJ	= init_scene_1.o init_scene_0.o

BON			= ./bonus/

MAIN_B		= ${BON}/main/
OPS_B		= ${BON}/operations/
ERROR_B		= ${BON}${OPS}error/
MINI_B		= ${BON}${OPS}miniRT/
PARSE_B		= ${BON}${OPS}parse/
RENDER_B	= ${BON}${OPS}render/
SCENE_B		= ${BON}${OPS}scene/

MAIN_F_B	= ${MAIN_B}miniRT_0_bonus.c ${MAIN_B}miniRT_1_bonus.c
MAIN_OBJ_B	= miniRT_0_bonus.o miniRT_1_bonus.o
ERROR_F_B	= ${ERROR_B}error_ops_0_bonus.c ${ERROR_B}error_ops_1_bonus.c
ERROR_OBJ_B	= error_ops_0_bonus.o error_ops_1_bonus.o
MINI_F_B	= ${MINI_B}matrix_ops_1_bonus.c ${MINI_B}objects_ops_0_bonus.c ${MINI_B}pos_w_ops_1_bonus.c ${MINI_B}rays_ops_2_bonus.c ${MINI_B}camera_ops_0_bonus.c ${MINI_B}lights_ops_0_bonus.c ${MINI_B}matrix_trans_ops_0_bonus.c ${MINI_B}objects_ops_1_bonus.c ${MINI_B}pos_w_ops_2_bonus.c ${MINI_B}rays_ops_3_bonus.c ${MINI_B}canvas_ops_bonus.c ${MINI_B}lights_ops_1_bonus.c ${MINI_B}matrix_trans_ops_1_bonus.c ${MINI_B}objects_ops_2_bonus.c  ${MINI_B}world_ops_0_bonus.c ${MINI_B}color_ops_0_bonus.c ${MINI_B}matrix_invert_ops_bonus.c ${MINI_B}objects_ops_3_bonus.c ${MINI_B}rays_ops_0_bonus.c ${MINI_B}world_ops_1_bonus.c ${MINI_B}color_ops_1_bonus.c ${MINI_B}matrix_ops_0_bonus.c ${MINI_B}pos_w_ops_0_bonus.c ${MINI_B}rays_ops_1_bonus.c
MINI_OBJ_B	= matrix_ops_1_bonus.o objects_ops_0_bonus.o pos_w_ops_1_bonus.o rays_ops_2_bonus.o camera_ops_0_bonus.o lights_ops_0_bonus.o matrix_trans_ops_0_bonus.o objects_ops_1_bonus.o pos_w_ops_2_bonus.o rays_ops_3_bonus.o canvas_ops_bonus.o lights_ops_1_bonus.o matrix_trans_ops_1_bonus.o objects_ops_2_bonus.o world_ops_0_bonus.o color_ops_0_bonus.o matrix_invert_ops_bonus.o objects_ops_3_bonus.o rays_ops_0_bonus.o world_ops_1_bonus.o color_ops_1_bonus.o matrix_ops_0_bonus.o pos_w_ops_0_bonus.o rays_ops_1_bonus.o
PARSE_F_B	= ${PARSE_B}parse_ops_4_bonus.c ${PARSE_B}get_values_ops_2_bonus.c ${PARSE_B}get_values_ops_1_bonus.c ${PARSE_B}parse_ops_3_bonus.c ${PARSE_B}parse_ops_0_bonus.c ${PARSE_B}parse_ops_1_bonus.c ${PARSE_B}parse_ops_2_bonus.c ${PARSE_B}get_values_ops_0_bonus.c
PARSE_OBJ_B	= parse_ops_4_bonus.o get_values_ops_2_bonus.o get_values_ops_1_bonus.o parse_ops_3_bonus.o parse_ops_0_bonus.o parse_ops_1_bonus.o parse_ops_2_bonus.o get_values_ops_0_bonus.o
RENDER_F_B	= ${RENDER_B}bitmap_ops_0_bonus.c ${RENDER_B}mlx_ops_0_bonus.c ${RENDER_B}mlx_ops_1_bonus.c ${RENDER_B}mlx_ops_2_bonus.c
RENDER_OBJ_B= bitmap_ops_0_bonus.o mlx_ops_0_bonus.o mlx_ops_1_bonus.o mlx_ops_2_bonus.o
SCENE_F_B	= ${SCENE_B}init_scene_1_bonus.c ${SCENE_B}init_scene_0_bonus.c
SCENE_OBJ_B	= init_scene_1_bonus.o init_scene_0_bonus.o

CC			= clang
CFLAGS		= -Wall -Werror -Wextra
LIB_FLAGS	= -lft -lbsd -lmlx -lXext -lX11 -lm
RM			= rm -f

all:		${NAME}

${NAME}: 	${MAIN_OBJ} ${ERROR_OBJ} ${SCENE_OBJ} ${MINI_OBJ} ${PARSE_OBJ} ${RENDER_OBJ} $(LIBFT) $(MLX)
			@echo making miniRT...
			@${CC} ${CFLAGS} -o ${NAME} ${MAIN_OBJ} ${ERROR_OBJ} ${SCENE_OBJ} ${MINI_OBJ} ${PARSE_OBJ} ${RENDER_OBJ} -L ${LIBFT_PATH} -L ${MLX_PATH} ${LIB_FLAGS}
			@echo all done!
			@echo run 'miniRT' with a well formatted '.rt' file.
			@echo hope you like it!

${MLX}:
			@echo making minilibx....
			@echo ...................
			@make --no-print-directory -C ${MLX_PATH}
			@echo done!

${LIBFT}:
			@echo making libft.......
			@echo ...................
			@make --no-print-directory -C ${LIBFT_PATH}
			@echo done!

${MAIN_OBJ}: ${MAIN_F}
			@${CC} ${CFLAGS} -g -c ${MAIN_F}

${ERROR_OBJ}: ${ERROR_F}
			@${CC} ${CFLAGS} -g -c ${ERROR_F}

${MINI_OBJ}: ${MINI_F}
			@${CC} ${CFLAGS} -g -c ${MINI_F}

${PARSE_OBJ}: ${PARSE_F}
			@${CC} ${CFLAGS} -g -c ${PARSE_F}

${RENDER_OBJ}: ${RENDER_F}
			@${CC} ${CFLAGS} -g -c ${RENDER_F}

${SCENE_OBJ}:	${SCENE_F}
			@${CC} ${CFLAGS} -g -c ${SCENE_F}

clean:
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			@make --no-print-directory -C ${MLX_PATH} clean
			${RM} ${MAIN_OBJ} ${ERROR_OBJ} ${MINI_OBJ} ${PARSE_OBJ} ${RENDER_OBJ} ${SCENE_OBJ}

fclean:		clean
			@echo cleaning!
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			${RM} ${NAME}
			@echo cleaned!

re:			fclean all

bonus:		${NAME_B}

${NAME_B}: 	${MAIN_OBJ_B} ${ERROR_OBJ_B} ${SCENE_OBJ_B} ${MINI_OBJ_B} ${PARSE_OBJ_B} ${RENDER_OBJ_B} $(LIBFT) $(MLX)
			@echo making miniRT...
			@${CC} ${CFLAGS} -o ${NAME_B} ${MAIN_OBJ_B} ${ERROR_OBJ_B} ${SCENE_OBJ_B} ${MINI_OBJ_B} ${PARSE_OBJ_B} ${RENDER_OBJ_B} -L ${LIBFT_PATH} -L ${MLX_PATH} ${LIB_FLAGS}
			@echo all done!
			@echo run 'miniRT_bonus' with a well formatted '.rt' file. '--save' flag will render images as bitmap.
			@echo if executing through window, press LEFT or RIGHT to change between cameras and ESC to exit.
			@echo hope you like it!

${MAIN_OBJ_B}: ${MAIN_F_B}
			@${CC} ${CFLAGS} -g -c ${MAIN_F_B}

${ERROR_OBJ_B}: ${ERROR_F_B}
			@${CC} ${CFLAGS} -g -c ${ERROR_F_B}

${MINI_OBJ_B}: ${MINI_F_B}
			@${CC} ${CFLAGS} -g -c ${MINI_F_B}

${PARSE_OBJ_B}: ${PARSE_F_B}
			@${CC} ${CFLAGS} -g -c ${PARSE_F_B}

${RENDER_OBJ_B}: ${RENDER_F_B}
			@${CC} ${CFLAGS} -g -c ${RENDER_F_B}

${SCENE_OBJ_B}:	${SCENE_F_B}
			@${CC} ${CFLAGS} -g -c ${SCENE_F_B}

clean_b:
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			@make --no-print-directory -C ${MLX_PATH} clean
			${RM} ${MAIN_OBJ_B} ${ERROR_OBJ_B} ${MINI_OBJ_B} ${PARSE_OBJ_B} ${RENDER_OBJ_B} ${SCENE_OBJ_B}

fclean_b:	clean_b
			@echo cleaning!
			@make --no-print-directory -C ${LIBFT_PATH} fclean
			${RM} ${NAME_B}
			@echo cleaned!

re_b:		fclean_b bonus

fclean_all:	fclean_b fclean

git:
			git add .
			git commit -m "$m"
			git push

norminette:
			norminette ./includes ./libraries/libft ./main ./operations ./bonus/includes ./bonus

test:
			@echo "\033[92mTests that should work for mandatory\033[0m"
			@echo "\033[92mTest 1 - Sphere and camera along z axis (0,0,1)\033[0m"
			cat tests/test7.rt
			./miniRT tests/test7.rt
			@echo "\033[92mTest 2 - Plane and camera along x axis (1,0,0)\033[0m"
			cat tests/test8.rt
			./miniRT tests/test8.rt
			@echo "\033[92mTest 3 - Cylinder and camera along z axis (0,0,-1)\033[0m"
			cat tests/test9.rt
			./miniRT tests/test9.rt
			@echo "\033[92mTest 4 - Two spheres and than translate one of than, note light shading changes, camera along y axis (0,1,0)\033[0m"
			cat tests/test10.rt
			./miniRT tests/test10.rt
			cat tests/test11.rt
			./miniRT tests/test11.rt
			@echo "\033[92mTest 5 - Cylinder along y axis and than rotate 90º along z axis, note light shading changes, camera along x axis (-1,0,0)\033[0m"
			cat tests/test12.rt
			./miniRT tests/test12.rt
			cat tests/test13.rt
			./miniRT tests/test13.rt
			@echo "\033[92mTest 6 - Many intersecting objects (with repetited kinds), camera along y axis (-0,-1,0)\033[0m"
			cat tests/test14.rt
			./miniRT tests/test14.rt
			@echo "\033[92mTest 7 - Many intersecting objects (with repetited kinds), camera at a random position and normal vector\033[0m"
			cat tests/test15.rt
			./miniRT tests/test15.rt
			@echo "\033[92mTest 8 - Light, over a sphere, over a plane, camera along z axis (0,0,1)\033[0m"
			cat tests/test16.rt
			./miniRT tests/test16.rt

.PHONY:		all clean fclean re
