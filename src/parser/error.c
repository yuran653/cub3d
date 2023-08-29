/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:36:33 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/29 19:33:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error_arg(char *error_arg)
{
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_arg, STDERR_FILENO);
}

void	print_error_msg(char *error_msg, char *error_arg1, char *error_arg2)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	if (error_arg1)
		print_error_arg(error_arg1);
	if (error_arg2)
		print_error_arg(error_arg2);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	*error_msg_null(char *error_msg, char *error_arg1, char *error_arg2)
{
	print_error_msg(error_msg, error_arg1, error_arg2);
	return (NULL);
}

int	error_msg_1(char *error_msg, char *error_arg1, char *error_arg2)
{
	print_error_msg(error_msg, error_arg1, error_arg2);
	return (1);
}
