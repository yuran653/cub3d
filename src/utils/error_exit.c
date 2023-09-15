/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:01:43 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 02:38:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game_exit(t_game *game)
{
	game = free_game(game);;
	exit(EXIT_SUCCESS);
	return (0);
}

void	error_game_exit_fail(t_game *game, char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	game = free_game(game);
	exit(EXIT_FAILURE);
}

void	error_map_exit_fail(t_map *map, char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	map = free_map(map);
	exit(EXIT_FAILURE);
}

void	error_data_exit_fail(t_data *data, char *error_msg, char *error_arg)
{
	print_error_msg(error_msg, error_arg);
	data = free_data(data);
	exit (EXIT_FAILURE);
}
