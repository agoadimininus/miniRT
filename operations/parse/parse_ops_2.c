/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:20:37 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

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
