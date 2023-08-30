/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:36:33 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/30 15:12:57 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_define_amount(char *error_arg, int defined_amount)
{
	char	*amount_str;

	amount_str = ft_itoa(defined_amount);
	if (!amount_str)
		print_error_msg(strerror(errno), NULL);
	print_error_msg(error_arg, amount_str);
	free(amount_str);
	return (1);
}

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

void	*error_msg_return_null(char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	return (NULL);
}

int	error_msg_return_1(char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	return (1);
}
