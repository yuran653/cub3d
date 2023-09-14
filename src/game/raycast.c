/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/14 16:18:11 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_line(t_game *game, int x, int y1, int y2)
// {
// 	if (y1 == 0)
// 		while (y1++ < y2)
// 			pixel_put(game->mlx_data, x, y1, game->data->ceilling->hex);
// 	else if (y1 > HALF_HEIGHT)
// 		while (y1++ < y2)
// 			pixel_put(game->mlx_data, x, y1, game->data->floor->hex);
// 	else
// 		while (y1++ < y2)
// 			pixel_put(game->mlx_data, x, y1, 0XFF99FF);
// }

int	raycast(t_game *game)
{

(void)game;
	// int lineNum;

	// game->rayAngle = 90 - HALF_FOV;
	// lineNum = 0;

	// while(lineNum <= WIDTH)
	// {
	// 	game->rayXd = game->data->map->player_x;
	// 	game->rayYd = game->data->map->player_y;
	// 	game->rayCos = cos(degree_to_radians(game->rayAngle))/100;
	// 	game->raySin = sin(degree_to_radians(game->rayAngle))/100;

	// 	// we send vector x,y to direction x1,y1 to find a wall position ([x,y] = 1) on map
	// 	// in result is we know both positions and can calculate distance, can get sprite color

	// 	while (true)
	// 	{
	// 		game->rayXd += game->rayCos;
	// 		game->rayYd += game->raySin;
	// 		game->rayX = round(game->rayXd);
	// 		game->rayY = round(game->rayYd);
	// 		if (game->data->map->map_array[game->rayY][game->rayX] == '1')
	// 			break;
	// 	}

	// 	// Pythagoras theorem
	// 	game->distance = sqrt(pow(game->data->map->player_x - game->rayX, 2)
	// 		+ pow(game->data->map->player_y - game->rayY, 2));
	// 	// Calculating wall height
	// 	game->wallHeight = floor(HALF_HEIGHT /game->distance);
	// 	// Draw the line...

	// 	draw_line(game, lineNum, 0, (int)(HALF_HEIGHT - game->wallHeight));
	// 	draw_line(game,lineNum,
	// 		(int)(HALF_HEIGHT - game->wallHeight),
	// 		(int)(HALF_HEIGHT + game->wallHeight));
	// 	draw_line(game, lineNum, (int)(HALF_HEIGHT + game->wallHeight), HEIGHT);
	// 	// Increment angle
	// 	game->rayAngle += INC_ANGLE;

	// 	lineNum++;
	// }

	// mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
	// 	game->mlx_data->img, 0, 0);
	return (0);
}
