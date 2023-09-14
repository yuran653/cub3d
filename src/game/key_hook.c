/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 14:31:23 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game_exit(game);
	if (keycode == 13)
	{
		// change angle
		printf("W pressed");
		game->rayAngle++;
		mlx_clear_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr);
		raycast(game);
		// clear ??
		// raycast
		// if (game->map[game->y - 1][game->x] != '1')
		// 	game->y -= 1;

	}
	return (0);
}
