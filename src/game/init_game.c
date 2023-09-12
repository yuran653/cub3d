/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/12 17:22:16 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_data(t_game *game)
{
	game->mlx_ptr = mlx_init();	
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, NAME);
	game->mlx_data->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	game->mlx_data->addr = mlx_get_data_addr(game->mlx_data->img,
			&game->mlx_data->bits_per_pixel, &game->mlx_data->line_length,
			&game->mlx_data->endian);
}

t_game	*init_game(t_data *data)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_data_exit_fail(data, strerror(errno), ERROR_GAME);
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->mlx_data = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game->mlx_data)
		error_game_exit_fail(game, strerror(errno), ERROR_GAME);
	game->mlx_data->img = NULL;
	game->mlx_data->addr = NULL;
	init_mlx_data(game);
	return (game);
}
