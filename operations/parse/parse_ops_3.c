/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:21:02 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_parse	*get_sphere(t_element *element, t_parse *parse)
{
	element->coord = get_pos_w(element, parse, 1, "017");
	element->element_d_1 = get_posd(element, parse, 2, "020");
	element->rgb = get_rgb(element, parse, 3, "016");
	return (parse);
}

t_parse	*get_plane(t_element *element, t_parse *parse)
{
	element->coord = get_pos_w(element, parse, 1, "017");
	element->norm = get_normv(element, parse, 2, "018");
	element->rgb = get_rgb(element, parse, 3, "016");
	return (parse);
}

t_parse	*get_cylinder(t_element *element, t_parse *parse)
{
	element->coord = get_pos_w(element, parse, 1, "017");
	element->norm = get_normv(element, parse, 2, "018");
	element->element_d_1 = get_posd(element, parse, 3, "020");
	element->element_d_2 = get_posd(element, parse, 4, "022");
	element->rgb = get_rgb(element, parse, 5, "016");
	return (parse);
}
