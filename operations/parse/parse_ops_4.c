/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 23:18:28 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

char	**free_split(char **split)
{
	int		i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free(split);
		split = NULL;
	}
	return (split);
}

void	check_id(t_element *element, t_parse *parse)
{
	if (element->id < 3)
	{
		if (parse->check_qty[element->id] == TRUE)
			ele_parse_error_exit("010", element, parse);
	}
	else if (element->id > 2 && element->id < 6)
	{
		if (parse->line[2] != ' ')
			parse_error_exit("005", element, parse);
	}
	else if (element->id >= 7)
		parse_error_exit("005", element, parse);
}

t_element	*next_element_list(t_element *list)
{
	if (list != NULL)
		return (list->next);
	return (NULL);
}
