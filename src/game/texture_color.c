/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:18:50 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/23 02:37:34 by jgoldste         ###   ########.fr       */
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
			return (T_EAST);
	if (prev_x >= x)
		return (T_WEST);
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

int	extract_texture_color(t_game *game, double y_pos_fixed, int texture)
{
	int img_pixel;
	int x_pos;

	if (texture == -1)
		return (0X0);
	if (texture == 0 || texture == 1)
		x_pos = (int)((game->ray_x - floor(game->ray_x))
			* (double)game->map->texture[texture].width
			- (double)game->map->texture[texture].width / 2);
	else
		x_pos = (int)((game->ray_y - floor(game->ray_y))
			* (double)game->map->texture[texture].width
			- (double)game->map->texture[texture].width / 2);
	y_pos_fixed = (double)game->map->texture[texture].width * y_pos_fixed;
 	img_pixel = ((int *)game->map->texture[texture].addr)
		[(int)y_pos_fixed * game->map->texture[texture].width + x_pos];
	return (img_pixel);
}
