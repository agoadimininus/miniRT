/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_ops_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/14 13:17:23 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

int	str_isint(char *str)
{
	size_t	i;
	int		least_one_digit;

	i = 0;
	least_one_digit = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (FALSE);
		least_one_digit++;
		i++;
	}
	if (least_one_digit == 0)
		return (FALSE);
	return (TRUE);
}

int	get_int(t_element *element, t_parse *parse, int idx, char *err_code)
{
	if (str_isint(parse->split[idx]) == FALSE)
		ele_parse_error_exit(err_code, element, parse);
	return (ft_atoi(parse->split[idx]));
}

int	get_posint(t_element *element, t_parse *parse, int idx, char *err_code)
{
	int		ret;

	ret = get_int(element, parse, idx, err_code);
	if (ret <= 0)
		ele_parse_error_exit(err_code, element, parse);
	return (ret);
}

int	get_fov(t_element *element, t_parse *parse, int idx, char *err_code)
{
	int		ret;

	ret = get_int(element, parse, idx, err_code);
	if (ret < 0 || ret > 180)
		ele_parse_error_exit(err_code, element, parse);
	return (ret);
}

t_color	get_rgb(t_element *element, t_parse *parse, int idx, char *err_code)
{
	t_spl_inf	split;
	t_color		color;

	ft_bzero(&color, sizeof(t_color));
	if (ft_strcount(parse->split[idx], ',') != 3)
		ele_parse_error_exit(err_code, element, parse);
	split.split = ft_split(parse->split[idx], ',');
	split.idx = 0;
	color.r = (double)get_int_splitted(element, parse, err_code, split);
	split.idx = 1;
	color.g = (double)get_int_splitted(element, parse, err_code, split);
	split.idx = 2;
	color.b = (double)get_int_splitted(element, parse, err_code, split);
	split.split = free_split(split.split);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
		ele_parse_error_exit(err_code, element, parse);
	return (color);
}
