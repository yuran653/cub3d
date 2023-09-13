/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 15:11:57 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				pixel_put(game->mlx_data, x, y, 0xFFFF00);
			else
				pixel_put(game->mlx_data, x, y, 0x994C00);
		}
	}
}

int	recasting(t_game *game)
{
	draw_line(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->mlx_data->img, 0, 0);
	return (0);
}
