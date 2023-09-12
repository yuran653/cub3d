/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recasting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 01:36:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	draw_line(t_game *game, int x)
// {
// 	int	y;

// 	y = -1;
// 	while (++y < HEIGHT)
// 	{
// 		if (y < HEIGHT / 2)
// 			my_mlx_pixel_put(game, x, y, game->data->ceilling->hex);
// 		else
// 			my_mlx_pixel_put(game, x, y, game->data->floor->hex);
// 	}
// }

int	recasting(t_game *game)
{
	int	x;
	
	x = -1;
	while(++x < WIDTH)
	{
		// draw_line(game, x);
		my_mlx_pixel_put(game, x, 200, game->data->ceilling->hex);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->mlx_data->img, 0, 0);
	return (0);
}
