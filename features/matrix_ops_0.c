/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:59:54 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/09 14:40:59 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_matrix	c_matrix(int row, int col)
{
	t_matrix	matrix;
	int			r;
	int			c;

	matrix.row = row;
	matrix.col = col;
	matrix.value = (double **)malloc(sizeof(double *) * row);
	if (matrix.value == NULL)
		exit(0);
	r = -1;
	while (++r < row)
	{
		c = -1;
		matrix.value[r] = (double *)malloc(sizeof(double) * col);
		if (matrix.value[r] == NULL)
		{
			while (--r >= 0)
				free(matrix.value[r]);
			free(matrix.value);
			exit(0);
		}
		while (++c < col)
			matrix.value[r][c] = 0;
	}
	return (matrix);
}

void	free_matrix(t_matrix matrix)
{
	int			r;

	r = 0;
	while (r < matrix.row)
		free(matrix.value[r++]);
	free(matrix.value);
}

int	equal_matrix(t_matrix a, t_matrix b)
{
	int			r;
	int			c;

	if (a.col != b.col || a.row != b.row)
		return (0);
	r = -1;
	while (++r < a.row)
	{
		c = -1;
		while (++c < a.col)
			if (!(comp_d(a.value[r][c], b.value[r][c])))
				return (0);
	}
	return (1);
}

double	dot_matrix(t_matrix a, t_matrix b, int r, int c)
{
	double		ret;
	int			i;

	ret = 0;
	i = -1;
	while (++i < a.col)
		ret += a.value[r][i] * b.value[i][c];
	return (ret);
}
