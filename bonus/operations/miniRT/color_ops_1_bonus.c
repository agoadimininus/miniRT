/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:50:25 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:30:09 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

int	equal_color(t_color a, t_color b)
{
	if (comp_d(a.r, b.r) && comp_d(a.g, b.g) && comp_d(a.b, b.b))
		return (1);
	return (0);
}

t_color	rgbquad(t_color color)
{
	int		r;
	int		g;
	int		b;

	r = map_color(color.r);
	g = map_color(color.g);
	b = map_color(color.b);
	color.trgb = 0 << 24 | r << 16 | g << 8 | b;
	return (color);
}

int	map_color(double color)
{
	if (color <= 0)
		return (0);
	else if (color >= 1)
		return (255);
	else
		return (color * 255);
}
