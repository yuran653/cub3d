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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESCAPE)
		close_game_exit(game);
	else if (keycode == RIGHT)
	{
		game->map->player_orient += game->values->inc_angle * TURN_SPEED;
		if (game->map->player_orient > 360)
			game->map->player_orient -= 360;
	}
	else if (keycode == LEFT)
	{
		game->map->player_orient -= game->values->inc_angle * TURN_SPEED;
		if (game->map->player_orient < 0)
			game->map->player_orient += 360;
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
