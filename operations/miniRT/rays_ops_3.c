/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_ops_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:21:34 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/09 20:33:20 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_object	setf_transform(t_object obj, t_matrix trans_matrix)
{
	t_matrix	matrix;

	matrix = mult_matrix(obj.transform, trans_matrix);
	free_matrix(obj.transform);
	free_matrix(trans_matrix);
	obj.transform = matrix;
	return (obj);
}
