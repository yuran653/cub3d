/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture_side.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:58:56 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/22 18:47:57 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	north_south(int prev_y, int y)
{
	if (prev_y <= y)
		return (T_SOUTH);
	if (prev_y >= y)
		return (T_NORTH);
	return (-1);
}

static int	east_west(int prev_x, int x)
{
	if (prev_x <= x)
			return (T_WEST);
	if (prev_x >= x)
		return (T_EAST);
	return (-1);
}

int	define_texture_side(t_game *game)
{
	if (game->prev_y == game->y)
		return (east_west(game->prev_x, game->x));
	else
		return (north_south(game->prev_y, game->y));
	return (-1);
}
