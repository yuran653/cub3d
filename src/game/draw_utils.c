/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:45 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/23 14:42:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_game *game, int x, int y)
{
	return (x == 0 || y == 0 || game->map->map_array[y][x] == M_WALL
		|| game->map->map_array[y][x] == SPACE_SIGN
		|| game->map->map_array[y][x] == NEW_LINE_SIGN
		|| game->map->map_array[y][x] == END_LINE_SIGN);
}

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

void	pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx_data->addr
		+ (y * mlx_data->line_length + x * (mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
