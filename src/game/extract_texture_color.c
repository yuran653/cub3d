/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrylarionov <dmitrylarionov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:18:50 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/22 18:58:13 by dmitrylario      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_texture_color(t_game *game, double y_pos_fixed, int texture)
{
	if (texture == -1)
		return (0X0);

	// int color;
	int img_pixel;
	int x_pos;
	// int r;
	// int g;
	// int b;
	if (texture == 0 || texture == 1)
		x_pos = (int)((game->ray_x - floor(game->ray_x)) * (double)game->map->texture[texture].width); // 0 - 100 позиция в тек квадрате взятая с дабл, сменить в зав от X, Y куда смотрим
	else
		x_pos = (int)((game->ray_y - floor(game->ray_y)) * (double)game->map->texture[texture].width); // 0 - 100 позиция в тек квадрате взятая с дабл, сменить в зав от X, Y куда смотрим
	y_pos_fixed = (double)game->map->texture[texture].width * y_pos_fixed; // коорд Y в текстуре например 155
 	img_pixel = ((int *)game->map->texture[texture].addr)[(int)y_pos_fixed * game->map->texture[texture].width + x_pos ];
	// r = (img_pixel >> 16) & 0xFF;
	// g = (img_pixel >> 8) & 0xFF;
	// b = img_pixel & 0xFF;
	// color = (r << 16) | (g << 8) | b;
	// return color;
	return (img_pixel);
}
