/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_ops_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:00:20 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/08 00:03:22 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_material	*init_material(t_material *material)
{
	material = (t_material *)ft_calloc(1, sizeof(t_material));
	if (material == NULL)
		error_exit(SYSERR);
	material->color = c_color(1, 1, 1);
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200;
	material->ambient = 0.1;
	return (material);
}
