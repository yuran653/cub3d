/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:58:56 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/22 18:15:54 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	define_texture_side(t_game *game)
{
	if (game->prev_y == game->y)
	{
		if (game->prev_x < game->x)
			return (T_WEST);
		if (game->prev_x > game->x)
			return (T_EAST);
	}
	else if (game->prev_x == game->x)
	{
		if (game->prev_y < game->y)
			return (T_SOUTH);
		if (game->prev_y > game->y)
			return (T_NORTH);

	}
	return (-1);
}

// int	define_texture_side(t_game *game)
// {
// 	int north = 0x9999ff;
// 	int south = 0xff9999;
// 	int east = 0xffff99;
// 	int west = 0x99ff99;

// 	if (game->prev_y == game->y)
// 	{
// 		if (game->prev_x < game->x)
// 			return (west);
// 		if (game->prev_x > game->x)
// 			return (east);
// 	}
// 	else if (game->prev_x == game->x)
// 	{
// 		if (game->prev_y < game->y)
// 			return (south);
// 		if (game->prev_y > game->y)
// 			return (north);

// 	}
// 	return (0X0);
// }
