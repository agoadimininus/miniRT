/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:32:13 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_parse	*get_resolution(t_element *element, t_parse *parse)
{
	element->width = get_posint(element, parse, 1, "013");
	parse->width = element->width;
	element->height = get_posint(element, parse, 2, "014");
	parse->height = element->height;
	parse->check_qty[element->id] += 1;
	return (parse);
}

t_parse	*get_ambient(t_element *element, t_parse *parse)
{
	element->ratio = get_ratio(element, parse, 1, "015");
	element->rgb = get_rgb(element, parse, 2, "016");
	parse->check_qty[element->id] += 1;
	if (equal_color(element->rgb, c_color(0, 0, 0)) == FALSE)
		parse->not_dark = TRUE;
	return (parse);
}

t_parse	*get_camera(t_element *element, t_parse *parse)
{
	element->coord = get_pos_w(element, parse, 1, "017");
	element->norm = get_normv(element, parse, 2, "018");
	element->fov = get_fov(element, parse, 3, "019");
	parse->check_qty[element->id] += 1;
	return (parse);
}

t_parse	*get_light(t_element *element, t_parse *parse)
{
	element->coord = get_pos_w(element, parse, 1, "017");
	element->ratio = get_ratio(element, parse, 2, "015");
	element->rgb = get_rgb(element, parse, 3, "016");
	parse->check_qty[element->id] += 1;
	if (equal_color(element->rgb, c_color(0, 0, 0)) == FALSE)
		parse->not_dark = TRUE;
	return (parse);
}

void	free_and_close(t_parse *parse)
{
	char	*line;

	ft_get_next_line(parse->fd, &line, 1);
	close_fd(parse->fd);
	free_parse(parse);
}
