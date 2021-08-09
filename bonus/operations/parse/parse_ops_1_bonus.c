/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:32:16 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

static int	valid_info_char(char c)
{
	return ((c >= '0' && c <= '9') || c == '.'
		|| c == ',' || c == '+' || c == '-');
}

static void	check_split_char(t_element *element, t_parse *parse, int *str)
{
	int			j;
	int			info_ctr;

	info_ctr = str[element->id] - 1;
	while (info_ctr > 0)
	{
		j = 0;
		while (parse->split[info_ctr][j] != '\0')
		{
			if (valid_info_char(parse->split[info_ctr][j]) == FALSE)
				ele_parse_error_exit("012", element, parse);
			j++;
		}
		info_ctr--;
	}
}

void	parse_line_split(t_element *element, t_parse *parse)
{
	static int	info_qty[9] = {3, 3, 4, 4, 4, 4, 5, 6, 0};

	if (ft_strcount(parse->line, ' ') != (size_t)info_qty[element->id])
		ele_parse_error_exit("011", element, parse);
	parse->split = ft_split(parse->line, ' ');
	check_split_char(element, parse, info_qty);
}

t_parse	*get_values_hub(t_element *element, t_parse *parse)
{
	if (element->id == RESOLUTION)
		parse = get_resolution(element, parse);
	else if (element->id == AMBIENT)
		parse = get_ambient(element, parse);
	else if (element->id == CAMERA)
		parse = get_camera(element, parse);
	else if (element->id == LIGHT)
		parse = get_light(element, parse);
	else if (element->id == SPHERE)
		parse = get_sphere(element, parse);
	else if (element->id == PLANE)
		parse = get_plane(element, parse);
	else if (element->id == SQUARE)
		parse = get_square(element, parse);
	else if (element->id == CYLINDER)
		parse = get_cylinder(element, parse);
	else if (element->id > 8)
		ele_parse_error_exit("006", element, parse);
	if (element->id >= SPHERE && element->id < 8)
		parse->check_qty[4] += 1;
	return (parse);
}

void	check_parse_elements(t_parse *parse)
{
	if (parse->check_qty[0] == FALSE || parse->check_qty[1] == FALSE
		|| parse->check_qty[2] == FALSE)
	{
		free_and_close(parse);
		if (parse->check_qty[0] == FALSE)
			print_error("023", 0);
		else if (parse->check_qty[1] == FALSE)
			print_error("023", 1);
		else if (parse->check_qty[2] == FALSE)
			print_error("023", 2);
		exit (EXIT_FAILURE);
	}
	if (parse->check_qty[4] == FALSE)
		printf("This will be odd... there are no objects in your .rt file\n");
	if (parse->not_dark == FALSE)
		printf("This will be odd, all light are dark...\n");
}
