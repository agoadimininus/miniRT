/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:44:00 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:49:32 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

void	print_element_error(int id)
{
	if (id == AMBIENT)
		ft_putstr_fd("AMBIENT LIGHT ", STDERR_FILENO);
	else if (id == LIGHT)
		ft_putstr_fd("LIGHT ", STDERR_FILENO);
	else if (id == CAMERA)
		ft_putstr_fd("CAMERA ", STDERR_FILENO);
	else if (id == SPHERE)
		ft_putstr_fd("SPHERE ", STDERR_FILENO);
	else if (id == PLANE)
		ft_putstr_fd("PLANE ", STDERR_FILENO);
	else if (id == CYLINDER)
		ft_putstr_fd("CYLINDER ", STDERR_FILENO);
	else
		ft_putstr_fd("ID NOT KNOWN ", STDERR_FILENO);
}

void	ele_parse_error_exit(char *err_str, t_element *element, t_parse *parse)
{
	int		id;

	id = element->id;
	free(element);
	free_and_close(parse);
	print_error(err_str, id);
	exit (EXIT_FAILURE);
}

void	split_parse_error_exit(char *err_code,
			t_element *element, t_parse *parse, char **split)
{
	free_split(split);
	ele_parse_error_exit(err_code, element, parse);
}

void	error_only_parse_exit(char *err_str, t_parse *parse)
{
	free_and_close(parse);
	print_error(err_str, 0);
	exit (EXIT_FAILURE);
}

void	exit_scene_creation(char *err_str, t_rt *rt, t_parse *parse)
{
	int		i;

	i = 0;
	while (i < rt->cam_count)
	{
		mlx_destroy_image(rt->mlx.mlx, rt->mlx.img[i].img);
		i++;
	}
	free_and_close(parse);
	print_error(err_str, 0);
	exit (EXIT_FAILURE);
}
