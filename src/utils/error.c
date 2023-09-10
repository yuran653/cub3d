/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:36:33 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:00:45 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_arg(char *error_arg)
{
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_arg, STDERR_FILENO);
}

void	print_error_msg(char *error_msg, char *error_arg)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	if (error_arg)
		print_error_arg(error_arg);
	ft_putstr_fd(NEW_LINE, STDERR_FILENO);
}

int	error_msg_return_1(char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	return (1);
}

void	*error_msg_return_null(char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	return (NULL);
}
