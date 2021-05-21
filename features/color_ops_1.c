/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:50:25 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 20:36:15 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

int	equal_color(t_color a, t_color b)
{
	if (comp_d(a.r, b.r) && comp_d(a.g, b.g) && comp_d(a.b, b.b))
		return (1);
	return (0);
}
