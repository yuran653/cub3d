/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 05:41:35 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*init_game(t_data *data)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (error_msg_return_null(strerror(errno), ERROR_GAME));
	game->mlx = mlx_init();
	// if (!game->mlx)
	// 	return ();
	game->mlx_win = mlx_new_window(game->mlx, WIDTH, HEIGHT, NAME);
	// if (!game->mlx_win)
	// 	return ();
	game->map = data->map;
	data->map = NULL;
	game->clr_ceilling = data->ceilling->hex;
	game->clr_floor = data->floor->hex;
	return (game);
}
