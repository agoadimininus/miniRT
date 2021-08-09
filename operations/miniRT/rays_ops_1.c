/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_ops_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:21:34 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/06/09 20:33:12 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer.h"

t_node_inter	*pos_node_inter(t_node_inter *head, t_node_inter *node)
{
	t_node_inter	*ptr;

	ptr = head;
	while (ptr->count >= 1)
	{
		ptr->count++;
		if (ptr->next->t > node->t)
			break ;
		ptr = ptr->next;
	}
	if (ptr->count == 0)
		ptr->count++;
	node->next = ptr->next;
	ptr->next = node;
	node->count = ptr->count - 1;
	return (head);
}

t_node_inter	*list_inter(t_node_inter *head, t_node_inter *node)
{
	if (node->next != NULL)
		head = list_inter(head, node->next);
	else if (head->obj == NULL)
	{
		free(head);
		return (node);
	}
	else if (node->obj == NULL)
	{
		free(node);
		return (head);
	}
	if (head->t > node->t)
	{
		node->count = head->count + 1;
		node->next = head;
		return (node);
	}
	head = pos_node_inter(head, node);
	return (head);
}

t_node_inter	*hit(t_node_inter *head)
{
	t_node_inter	*tmp;

	if (head->obj == NULL)
		return (NULL);
	while (head->next != NULL && head->t < 0)
	{
		tmp = head->next;
		head = tmp;
	}
	if (head->t < 0)
		return (NULL);
	return (head);
}

t_ray	transform(t_ray ray, t_matrix matrix)
{
	ray.direction = mult_matrix_pos_w(matrix, ray.direction);
	ray.origin = mult_matrix_pos_w(matrix, ray.origin);
	return (ray);
}

t_object	set_transform(t_object obj, t_matrix trans_matrix)
{
	t_matrix	matrix;

	matrix = mult_matrix(obj.transform, trans_matrix);
	free_matrix(obj.transform);
	obj.transform = matrix;
	return (obj);
}
