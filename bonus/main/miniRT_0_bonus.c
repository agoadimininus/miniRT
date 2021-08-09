/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_0_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:43:40 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:36:11 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raytracer_bonus.h"

static void	check_args(int argc, char **argv)
{
	if (argc < 2)
		error_exit("001");
	if (argc > 3)
		error_exit("002");
	if (ft_strncmp_rev(argv[1], ".rt", 3))
		error_exit("003");
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		error_exit("004");
}

static t_parse	*init_parse(char *rt_file)
{
	static char	*s[9] = {"R ", "A ", "c ", "l ", "sp", "pl", "sq", "cy", ""};
	int			gnl_ret;
	t_element	*element;
	t_parse		*parse;

	parse = NULL;
	parse = init_parse_struct(parse);
	parse->fd = open_fd(rt_file, parse);
	gnl_ret = ft_get_next_line(parse->fd, &parse->line, 0);
	while (gnl_ret >= 0)
	{
		element = init_element_list(element);
		while (element->id < 9 && ft_strncmp(parse->line, s[element->id], 2))
			element->id++;
		check_id(element, parse);
		parse = parse_line(element, parse);
		if (gnl_ret == 0)
			break ;
		gnl_ret = ft_get_next_line(parse->fd, &parse->line, 0);
	}
	check_parse_elements(parse);
	return (parse);
}

static t_rt	init_mlx_rt(t_rt *rt, t_parse *parse)
{
	rt->mlx.mlx = mlx_init();
	rt->mlx.height = parse->height;
	rt->mlx.width = parse->width;
	if (rt->save == FALSE)
		rt->mlx = screen_resolution(rt->mlx);
	rt->mlx = c_images(rt->mlx, parse->check_qty[2],
			rt->mlx.width, rt->mlx.height);
	return (*rt);
}

static t_rt	init_rt(t_rt *rt)
{
	ft_bzero(rt, sizeof(t_rt));
	rt->cameras = NULL;
	rt->canvas = NULL;
	return (*rt);
}

int	main(int argc, char *argv[])
{
	t_rt	rt;
	t_parse	*parse;

	check_args(argc, argv);
	parse = NULL;
	rt = init_rt(&rt);
	rt.save = (argc == 3);
	parse = init_parse(argv[1]);
	rt = init_mlx_rt(&rt, parse);
	rt = create_scene_and_render(&rt, parse);
	if (rt.save)
		save_bmp(&rt);
	else
		run_mlx(&rt);
}
