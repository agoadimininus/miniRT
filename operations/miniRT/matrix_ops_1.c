/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:59:54 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 10:13:47 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_matrix	mult_matrix(t_matrix a, t_matrix b)
{
	t_matrix	mul;
	int			r;
	int			c;

	if (a.col != b.row)
	{
		mul.col = 0;
		return (mul);
	}
	mul = c_matrix(a.row, b.col);
	r = -1;
	while (++r < mul.row)
	{
		c = -1;
		while (++c < mul.col)
			mul.value[r][c] = dot_matrix(a, b, r, c);
	}
	return (mul);
}

t_pos_w	mult_matrix_pos_w(t_matrix a, t_pos_w b)
{
	t_matrix		matrix;
	t_matrix		matrix_a;
	t_pos_w			tmp;

	matrix = c_matrix(4, 1);
	matrix.value[0][0] = b.x;
	matrix.value[1][0] = b.y;
	matrix.value[2][0] = b.z;
	matrix.value[3][0] = b.w;
	matrix_a = mult_matrix(a, matrix);
	tmp.x = matrix_a.value[0][0];
	tmp.y = matrix_a.value[1][0];
	tmp.z = matrix_a.value[2][0];
	tmp.w = matrix_a.value[3][0];
	free_matrix(matrix);
	free_matrix(matrix_a);
	return (tmp);
}

t_matrix	c_id_matrix(int size)
{
	t_matrix	result;
	int			i;

	result = c_matrix(size, size);
	i = -1;
	while (++i < size)
		result.value[i][i] = 1;
	return (result);
}

t_matrix	transpose_matrix(t_matrix a)
{
	t_matrix	tmp;
	int			r;
	int			c;

	tmp = c_matrix(a.col, a.row);
	r = -1;
	while (++r < a.row)
	{
		c = -1;
		while (++c < a.col)
			tmp.value[c][r] = a.value[r][c];
	}
	return (tmp);
}

t_matrix	mult_free(t_matrix a, t_matrix b)
{
	t_matrix	result;

	result = mult_matrix(a, b);
	free_matrix(a);
	free_matrix(b);
	return (result);
}
