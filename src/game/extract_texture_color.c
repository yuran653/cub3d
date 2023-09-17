// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   extract_texture_color.c                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/16 15:18:50 by jgoldste          #+#    #+#             */
// /*   Updated: 2023/09/16 16:51:46 by jgoldste         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

int	extract_texture_color(t_game *game)
{
	int north = 0x9999ff;
	// int south = 0xff9999;
	// int east = 0xffff99;
	// int west = 0x99ffff;
	
	if (game->y < game->map->player_y
		&& game->map->map_array[game->y - 1][game->x] == M_SPACE)
		return (north);
	// else if (game->y > game->map->player_y)
	// 	return (south);
	return (0x0);
}
