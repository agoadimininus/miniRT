/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ops_0_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 00:07:07 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/07 22:32:19 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

t_parse	*parse_line(t_element *element, t_parse *parse)
{
	parse_line_split(element, parse);
	parse = get_values_hub(element, parse);
	if (parse->ele_list != NULL)
		element->next = parse->ele_list;
	parse->ele_list = element;
	element = NULL;
	free_line_split(parse);
	return (parse);
}

void	free_line_split(t_parse *parse)
{
	if (parse->line != NULL)
	{
		free(parse->line);
		parse->line = NULL;
	}
	parse->split = free_split(parse->split);
}

void	free_parse(t_parse *parse)
{
	t_element	*next_ele;

	next_ele = NULL;
	if (parse == NULL)
		return ;
	free_line_split(parse);
	if (parse->ele_list != NULL)
	{
		next_ele = next_element_list(parse->ele_list);
		while (next_ele != NULL)
		{
			free(parse->ele_list);
			parse->ele_list = next_ele;
			next_ele = next_element_list(parse->ele_list);
		}
		free (parse->ele_list);
	}
	free(parse);
}

t_element	*init_element_list(t_element *list)
{
	list = (t_element *)ft_calloc(1, sizeof(t_element));
	list->next = NULL;
	list->id = 0;
	return (list);
}

t_parse	*init_parse_struct(t_parse *parse)
{
	parse = (t_parse *)ft_calloc(1, sizeof(t_parse));
	parse->split = NULL;
	parse->line = NULL;
	parse->ele_list = NULL;
	return (parse);
}
