/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ops_0_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfico-vi <cfico-vi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:44:00 by cfico-vi          #+#    #+#             */
/*   Updated: 2021/08/09 12:14:28 by cfico-vi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raytracer_bonus.h"

int	open_fd(char *file, t_parse *parse)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(parse);
		error_exit(SYSERR);
	}
	return (fd);
}

void	close_fd(int fd)
{
	if (close(fd) < 0)
		error_exit(SYSERR);
}

void	print_error(char *code, int id)
{
	int		fd;
	char	*error;

	fd = open("bonus/operations/error/errors.txt", O_RDONLY);
	if (fd == -1)
		error_exit(SYSERR);
	while (ft_get_next_line(fd, &error, 0) == 1)
	{
		if (ft_strncmp(code, error, 3) == 0)
		{
			ft_putstr_fd("Error/n", STDERR_FILENO);
			if (code[1] == '1' || code[1] == '2')
				print_element_error(id);
			ft_putstr_fd(error, STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
			break ;
		}
		free(error);
	}
	free(error);
	ft_get_next_line(fd, &error, 1);
	close_fd(fd);
}

void	parse_error_exit(char *err_str, t_element *element, t_parse *parse)
{
	free(element);
	free_and_close(parse);
	print_error(err_str, 0);
	exit (EXIT_FAILURE);
}

void	error_exit(char *err_str)
{
	if (errno && ft_strcmp(err_str, SYSERR) == 0)
		perror("Error\nSystem error");
	else if (ft_strcmp(err_str, MISSEDERR) == 0)
	{
		ft_putstr_fd("CRASHED - Oops, that was unexpected.", STDERR_FILENO);
		ft_putstr_fd("Please get in contact if you can\n", STDERR_FILENO);
	}
	else if (ft_strcmp(err_str, SYSERR))
		print_error(err_str, 0);
	else
		ft_putstr_fd("Crazy error\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
