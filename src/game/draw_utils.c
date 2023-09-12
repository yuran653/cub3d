/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:45 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/12 19:22:38 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = game->mlx_data->addr
		+ (y * game->mlx_data->line_length
			+ x * (game->mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}
