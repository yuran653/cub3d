/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/15 20:07:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_line(t_game *game, int y1, int y2, int color)
{
	while (y1++ < y2)
		pixel_put(game->mlx_data, game->lineNum, y1, color);
}

static void	draw_line(t_game *game)
{
	put_line(game, 0, game->values->half_src_height - game->wallHeight,
		game->data->ceilling->hex);
	put_line(game, game->values->half_src_height - game->wallHeight,
		game->values->half_src_height + game->wallHeight, 0XFF99FF);
	put_line(game, game->values->half_src_height + game->wallHeight,
		HEIGHT, game->data->floor->hex);
}

static void	define_wall_position(t_game *game)
{
	while (true)
	{
		game->rayXd += game->rayCos;
		game->rayYd += game->raySin;
		game->x = round(game->rayXd);
		game->y = round(game->rayYd);
		if (game->data->map->map_array[game->y][game->x] == '1'
			|| game->x > game->data->map->width
				|| game->y > game->data->map->height)
			break ;
	}
}

int	raycast(t_game *game)
{
	game->rayAngle = game->data->map->player_orient - game->values->half_fov;
	game->lineNum = 0;
	while (game->lineNum < WIDTH)
	{
		game->rayXd = game->data->map->player_x;
		game->rayYd = game->data->map->player_y;
		game->rayCos = cos(degree_to_radians(game->rayAngle))
			/ game->values->precision;
		game->raySin = sin(degree_to_radians(game->rayAngle))
			/ game->values->precision;
		define_wall_position(game);
		game->distance = sqrt(pow(game->data->map->player_x - game->rayXd, 2)
				+ pow(game->data->map->player_y - game->rayYd, 2));
		game->wallHeight = floor(game->values->half_src_height
				/ game->distance);
		draw_line(game);
		game->rayAngle += game->values->inc_angle;
		game->lineNum++;
	}
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->img, 0, 0);
	return (0);
}
