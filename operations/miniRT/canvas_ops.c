/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:59:54 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/13 22:54:33 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_canvas	c_canvas(int width, int height)
{
	t_canvas	canvas;
	int			w;
	int			h;

	canvas.height = height;
	canvas.width = width;
	canvas.color = (t_color **)ft_calloc(width, sizeof(t_color *));
	if (canvas.color == NULL)
		error_exit(SYSERR);
	w = -1;
	while (++w < width)
	{
		h = -1;
		canvas.color[w] = (t_color *)ft_calloc(height, sizeof(t_color));
		if (canvas.color[w] == NULL)
		{
			while (--w >= 0)
				free(canvas.color[w]);
			free(canvas.color);
			error_exit(SYSERR);
		}
		while (++h < height)
			canvas.color[w][h] = c_color(0, 0, 0);
	}
	return (canvas);
}

void	free_canvas(t_canvas canvas)
{
	int			w;

	w = -1;
	while (++w < canvas.width)
	{
		free(canvas.color[w]);
		canvas.color[w] = NULL;
	}
	free(canvas.color);
	canvas.color = NULL;
}

t_canvas	write_pixel(t_canvas canvas, int col, int row, t_color color)
{
	canvas.color[col][row] = c_color(color.r, color.g, color.b);
	canvas.color[col][row] = rgbquad(color);
	return (canvas);
}
