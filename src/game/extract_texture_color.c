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
	if (game->x > 0 && game->y < round(game->map->player_y)
		&& game->map->map_array[game->y + 1][game->x] == M_SPACE)
		return (0xffffff);
	return (0x0);
}
