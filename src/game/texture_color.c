/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:18:50 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/23 22:48:23 by jgoldste         ###   ########.fr       */
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

int	extract_texture_color(t_game *game, double y_pos_fixed, int side)
{
	int x_pos;
	int	img_pxl_idx;
	int	*img_pxl_ptr;

	if (side == -1)
		return (0X0);
	if (side == 0 || side == 1)
		x_pos = (int)((game->ray_x - floor(game->ray_x))
			* (double)game->map->texture[side].width
			- (double)game->map->texture[side].width / 2);
	else
		x_pos = (int)((game->ray_y - floor(game->ray_y))
			* (double)game->map->texture[side].width
			- (double)game->map->texture[side].width / 2);
	y_pos_fixed = (double)game->map->texture[side].width * y_pos_fixed;
	img_pxl_ptr = (int *)game->map->texture[side].addr;
	img_pxl_idx = (int)y_pos_fixed * game->map->texture[side].width + x_pos;
	if (img_pxl_idx >= 0 && img_pxl_idx < game->map->texture[side].width
		* game->map->texture[side].width)
		return (img_pxl_ptr[img_pxl_idx]);
	return (-1);
}
