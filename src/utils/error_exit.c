/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:01:43 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:26:49 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	error_game_exit_fail(t_game *game, char *error_msg, char *error_arg)
// {
// 	print_error_msg(error_msg, error_arg);
// 	game = free_game(game);
// 	exit (EXIT_FAILURE);
// }

void	error_data_exit_fail(t_data *data, char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	data = free_data(data);
	exit (EXIT_FAILURE);
}
