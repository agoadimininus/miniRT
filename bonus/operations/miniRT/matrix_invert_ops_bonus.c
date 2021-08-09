/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert_ops_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:50:03 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:30:39 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_matrix	submatrix(t_matrix a, int row, int col)
{
	t_matrix	sub;
	int			r;
	int			c;
	int			r_sub;
	int			c_sub;

	sub = c_matrix(a.row - 1, a.col - 1);
	r = -1;
	r_sub = -1;
	while (++r < a.row && r_sub < sub.row)
	{
		c = -1;
		c_sub = -1;
		if (r != row)
		{
			r_sub++;
			while (++c < a.col && c_sub < sub.col)
				if (c != col)
					sub.value[r_sub][++c_sub] = a.value[r][c];
		}
	}
	return (sub);
}

double	minor_matrix(t_matrix a, int row, int col)
{
	t_matrix	tmp;
	double		ret;

	tmp = submatrix(a, row, col);
	ret = determ_matrix(tmp);
	free_matrix(tmp);
	return (ret);
}

double	cofactor_matrix(t_matrix a, int row, int col)
{
	double		ret;

	ret = minor_matrix(a, row, col);
	if ((row + col) % 2 == 0)
		return (ret);
	return (-ret);
}

double	determ_matrix(t_matrix a)
{
	double		ret;
	int			c;

	ret = 0;
	if (a.col == 2)
		return (a.value[0][0] * a.value[1][1] - a.value[0][1] * a.value[1][0]);
	else
	{
		c = -1;
		while (++c < a.col)
			ret += a.value[0][c] * cofactor_matrix(a, 0, c);
	}
	return (ret);
}

t_matrix	invert_matrix(t_matrix a)
{
	t_matrix	inverse;
	int			r;
	int			c;
	double		co;
	double		determ;

	determ = determ_matrix(a);
	if (determ == 0)
	{
		inverse.col = 0;
		return (inverse);
	}
	inverse = c_matrix(a.row, a.col);
	r = -1;
	while (++r < a.row)
	{
		c = -1;
		while (++c < a.col)
		{
			co = cofactor_matrix(a, c, r);
			inverse.value[r][c] = co / determ;
		}
	}
	return (inverse);
}
