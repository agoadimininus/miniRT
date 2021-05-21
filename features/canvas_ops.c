/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:59:54 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/08 22:07:51 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

t_canvas	c_canvas(int width, int height)
{
	t_canvas	canvas;
	int			w;
	int			h;

	canvas.height = height;
	canvas.width = width;
	canvas.color = (t_color **)malloc(sizeof(t_color *) * width);
	if (canvas.color == NULL)
		exit(0);
	w = -1;
	while (++w < width)
	{
		h = -1;
		canvas.color[w] = (t_color *)malloc(sizeof(t_color) * height);
		if (canvas.color[w] == NULL)
		{
			while (--w >= 0)
				free(canvas.color[w]);
			free(canvas.color);
			exit(0);
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
		free(canvas.color[w]);
	free(canvas.color);
}

t_canvas	write_pixel(t_canvas canvas, int col, int row, t_color color)
{
	canvas.color[col][row] = c_color(color.r, color.g, color.b);
	return (canvas);
}
