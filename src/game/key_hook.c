/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/23 02:46:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_game *game, double axis, int direction)
{
	double	radians;
	double	new_x;
	double	new_y;

	if (axis == 0)
	{
		radians = degree_to_radians(game->map->player_orient);
		new_x = game->map->player_x + cos(radians) * direction * STEP_SIZE;
		new_y = game->map->player_y + sin(radians) * direction * STEP_SIZE;
	}
	else
	{
		radians = degree_to_radians(game->map->player_orient - 90);
		new_x = game->map->player_x + cos(radians) * direction * STEP_SIZE / 2;
		new_y = game->map->player_y + sin(radians) * direction * STEP_SIZE / 2;
	}
	if (!is_wall(game, (int)round(new_x), (int)round(new_y)))
	{
		game->map->player_x = new_x;
		game->map->player_y = new_y;
	}
}

static void	rotate_move(int dir, t_game *game)
{
	if (dir)
		game->map->player_orient += game->values->inc_angle * TURN_SPEED;
	else
		game->map->player_orient -= game->values->inc_angle * TURN_SPEED;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game_exit(game);
	else if (keycode == TURN_RIGHT)
		rotate_move(1, game);
	else if (keycode == TURN_LEFT)
		rotate_move(0, game);
	else if (keycode == MOVE_UP)
		move_player(game, 0, 1);
	else if (keycode == MOVE_DOWN)
		move_player(game, 0, -1);
	else if (keycode == MOVE_RIGHT)
		move_player(game, 1, -1);
	else if (keycode == MOVE_LEFT)
		move_player(game, 1, 1);
	return (0);
}

int	mouse_hook(int x, int y, t_game *game)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (game->values->mouse_x < x)
			rotate_move(1, game);
		else
			rotate_move(0, game);
		game->values->mouse_x = x;
	}
	return (0);
}
