/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_creation_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 12:35:16 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/04/15 18:16:15 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer.h"

void	ppm_header(t_canvas canvas, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(canvas.width, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(canvas.height, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
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

int	ppm_line_len(int *counter, int fd)
{
	if (*counter > 66)
	{
		ft_putchar_fd('\n', fd);
		*counter = 0;
		return (1);
	}
	return (0);
}

void	printpixel_ppm(t_color color, int fd, int *counter)
{
	*counter += ft_putnbr_fd(map_color(color.r), fd);
	if (!ppm_line_len(counter, fd))
	{
		ft_putchar_fd(' ', fd);
		(*counter)++;
	}
	*counter += ft_putnbr_fd(map_color(color.g), fd);
	if (!ppm_line_len(counter, fd))
	{
		ft_putchar_fd(' ', fd);
		(*counter)++;
	}
	*counter += ft_putnbr_fd(map_color(color.b), fd);
	if (!ppm_line_len(counter, fd))
	{
		ft_putchar_fd(' ', fd);
		(*counter)++;
	}
}

void	create_ppm(char *str, t_canvas canvas)
{
	int				fd;
	int				h;
	int				w;
	int				counter;

	str = ft_strjoin(str, ".ppm");
	fd = open(str, O_RDWR | O_CREAT, 0600);
	free(str);
	ppm_header(canvas, fd);
	h = 0;
	while (h < canvas.height)
	{
		counter = 0;
		w = 0;
		while (w < canvas.width)
		{
			printpixel_ppm(canvas.color[w][h], fd, &counter);
			w++;
		}
		ft_putchar_fd('\n', fd);
		h++;
	}
	close(fd);
}
