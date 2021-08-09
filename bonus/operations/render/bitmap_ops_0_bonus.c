/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_ops_0_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:57:00 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:31:56 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

static void	write_bmpheader(int fd, t_bmpheader header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &header.dib_header_size, 4);
	write(fd, &header.width_px, 4);
	write(fd, &header.height_px, 4);
	write(fd, &header.num_planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.img_size_bytes, 4);
	write(fd, &header.x_resolution_ppm, 4);
	write(fd, &header.y_resolution_ppm, 4);
	write(fd, &header.num_colors, 4);
	write(fd, &header.important_colors, 4);
}

static void	create_bmpheader(t_canvas canvas, t_bmpheader *header)
{
	header->type = 0x4D42;
	header->size = ((canvas.width + canvas.height) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->dib_header_size = 40;
	header->width_px = canvas.width;
	header->height_px = canvas.height;
	header->num_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_size_bytes = ((canvas.width + canvas.height) * 4);
	header->x_resolution_ppm = 2000;
	header->y_resolution_ppm = 2000;
	header->num_colors = 0;
	header->important_colors = 0;
}

static void	printpx_rgbquad(t_color color, int fd)
{
	char	dst[5];

	*(unsigned int *)dst = color.trgb;
	dst[4] = '\0';
	write(fd, &dst, 4);
}

void	create_bmp(char *str, t_canvas canvas)
{
	int			fd;
	int			h;
	int			w;
	t_bmpheader	header;

	str = ft_strjoin(str, ".bmp");
	fd = open(str, O_RDWR | O_CREAT, 0600);
	free(str);
	ft_bzero(&header, sizeof(t_bmpheader));
	create_bmpheader(canvas, &header);
	write_bmpheader(fd, header);
	h = canvas.height - 1;
	while (h >= 0)
	{
		w = 0;
		while (w < canvas.width)
		{
			printpx_rgbquad(canvas.color[w][h], fd);
			w++;
		}
		h--;
	}
	close(fd);
}
