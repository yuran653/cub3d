/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/14 17:51:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_data(t_game *game)
{
	game->mlx_data = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game->mlx_data)
		error_game_exit_fail(game, strerror(errno), ERROR_GAME);
	game->mlx_data->mlx_ptr = mlx_init();
	game->mlx_data->win_ptr = mlx_new_window(game->mlx_data->mlx_ptr,
		WIDTH, HEIGHT, NAME);
	game->mlx_data->img = mlx_new_image(game->mlx_data->mlx_ptr, WIDTH, HEIGHT);
	game->mlx_data->addr = mlx_get_data_addr(game->mlx_data->img,
			&game->mlx_data->bits_per_pixel, &game->mlx_data->line_length,
			&game->mlx_data->endian);
}

void	init_values(t_game *game)
{
	game->values = (t_values *)malloc(sizeof(t_values));
	if (!game->values)
		error_game_exit_fail(game, strerror(errno), ERROR_GAME);
	game->values->half_scr_width = WIDTH / 2;
	game->values->half_src_height = HEIGHT / 2;
	game->values->half_fov = FOV / 2;
	game->values->inc_angle = (double)FOV / (double)WIDTH;
	game->values->precision = (double)PRECISION;
}

t_game	*init_game(t_data *data)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_data_exit_fail(data, strerror(errno), ERROR_GAME);
	game->data = data;
	game->values = NULL;
	game->mlx_data = NULL;
	init_values(game);
	init_mlx_data(game);
	return (game);
}
