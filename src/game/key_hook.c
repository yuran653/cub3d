/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:44:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 07:11:40 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void move_player(t_game *game, int direction)
{
	double radians;
	double	step_size;

	step_size = 0.2;
	radians = degree_to_radians(game->map->player_orient);
	game->map->player_x += cos(radians) * direction * step_size;
	game->map->player_y += sin(radians) * direction * step_size;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game_exit(game);
	else if (keycode == RIGHT || keycode == 2)
	{
		game->map->player_orient += game->values->inc_angle * TURN_SPEED;
		if (game->map->player_orient > 360)
			game->map->player_orient -= 360;
	}
	else if (keycode == LEFT || keycode == 0)
	{
		game->map->player_orient -= game->values->inc_angle * TURN_SPEED;
		if (game->map->player_orient < 0)
			game->map->player_orient += 360;
	}
	else if (keycode == UP || keycode == 13)
	{
		move_player(game, 1);
	}
	else if (keycode == DOWN || keycode == 1)
	{
		move_player(game, -1);
	}
	// значения направления камеры в градусах я думаю использовать для определения
	// какую текстуру накладывать, поэтому это значение должно быть в диапазоне
	// от 0 до 360
	//
	// предыдущий вариант:
	// else if (keycode == RIGHT)
	// 	game->map->player_orient += game->values->inc_angle * TURN_SPEED;
	// else if (keycode == LEFT)
	// 	game->map->player_orient -= game->values->inc_angle * TURN_SPEED;
	//
	// очистка окна и новое изображение в функции рекаст, которая вызывается
	// функцией лупхук при отлове хука
	// то есть тут нужно только меня значения переменных расположения на карте
	return (0);
}

