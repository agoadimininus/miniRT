/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_ops_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 10:45:20 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

int	get_int_splitted(t_element *element, t_parse *parse,
		char *err_code, t_spl_inf split)
{
	if (str_isint(split.split[split.idx]) == FALSE)
		split_parse_error_exit(err_code, element, parse, split.split);
	return (ft_atoi(split.split[split.idx]));
}

double	get_double_splitted(t_element *element, t_parse *parse,
		char *err_code, t_spl_inf split)
{
	if (str_isdouble(split.split[split.idx]) == FALSE)
		split_parse_error_exit(err_code, element, parse, split.split);
	return (ft_atod(split.split[split.idx]));
}

t_pos_w	get_pos_w(t_element *element, t_parse *parse, int idx, char *err_code)
{
	t_pos_w		coord;
	t_spl_inf	split;

	if (ft_strcount(parse->split[idx], ',') != 3)
		ele_parse_error_exit(err_code, element, parse);
	split.split = ft_split(parse->split[idx], ',');
	split.idx = 0;
	coord.x = get_double_splitted(element, parse, err_code, split);
	split.idx = 1;
	coord.y = get_double_splitted(element, parse, err_code, split);
	split.idx = 2;
	coord.z = get_double_splitted(element, parse, err_code, split);
	coord.w = 1;
	split.split = free_split(split.split);
	return (coord);
}

t_pos_w	get_normv(t_element *element, t_parse *parse, int idx, char *err_code)
{
	t_pos_w		coord;
	t_spl_inf	split;

	if (ft_strcount(parse->split[idx], ',') != 3)
		ele_parse_error_exit(err_code, element, parse);
	split.split = ft_split(parse->split[idx], ',');
	split.idx = 0;
	coord.x = get_double_splitted(element, parse, err_code, split);
	split.idx = 1;
	coord.y = get_double_splitted(element, parse, err_code, split);
	split.idx = 2;
	coord.z = get_double_splitted(element, parse, err_code, split);
	coord.w = 0;
	split.split = free_split(split.split);
	if (equal_pos_w(coord, norm_pos_w(coord)) == 0)
		ele_parse_error_exit(err_code, element, parse);
	return (coord);
}
