/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values_ops_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:32:24 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

int	str_double_check_signs(char *str, size_t *i)
{
	int		dot;
	size_t	j;

	dot = 0;
	if (str[*i] == '+' || str[*i] == '-')
		*i += 1;
	j = *i;
	while (j < ft_strlen(str))
	{
		if (str[j] == '.')
		{
			dot += 1;
			if (dot > 1)
				return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

int	str_isdouble(char *str)
{
	size_t	i;
	int		least_one_digit;

	i = 0;
	least_one_digit = 0;
	if (str_double_check_signs(str, &i) == FALSE)
		return (FALSE);
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '.')
			return (FALSE);
		if (str[i] == '.')
			least_one_digit--;
		least_one_digit++;
		i++;
	}
	if (least_one_digit <= 0)
		return (FALSE);
	return (TRUE);
}

double	get_double(t_element *element, t_parse *parse, int idx, char *err_code)
{
	if (str_isdouble(parse->split[idx]) == FALSE)
		ele_parse_error_exit(err_code, element, parse);
	return (ft_atod(parse->split[idx]));
}

double	get_posd(t_element *element, t_parse *parse, int idx, char *err_code)
{
	double	ret;

	ret = get_double(element, parse, idx, err_code);
	if (ret <= 0)
		ele_parse_error_exit(err_code, element, parse);
	return (ret);
}

double	get_ratio(t_element *element, t_parse *parse, int idx, char *err_code)
{
	double	ret;

	ret = get_double(element, parse, idx, err_code);
	if (ret < 0 || ret > 1)
		ele_parse_error_exit(err_code, element, parse);
	return (ret);
}
