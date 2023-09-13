/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 19:42:33 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_line(t_game *game, int x, int y1, int y2)
// {
// 	// int	x;
// 	// int	y;

// 	// x = -1;
// 	// while (++x < WIDTH)
// 	// {
// 	// 	y = -1;
// 	// 	while (++y < HEIGHT)
// 	// 	{
// 	// 		if (y < HEIGHT / 2)
// 	// 			pixel_put(game->mlx_data, x, y, 0xFFFF00);
// 	// 		else
// 	// 			pixel_put(game->mlx_data, x, y, 0x994C00);
// 	// 	}
// 	// }

// 	while (y1 < y2 && y1 < HEIGHT)
// 	{
// 		if (y1 < HEIGHT / 2)
// 			pixel_put(game->mlx_data, x, y1, 0xFFFF00);
// 		else
// 			pixel_put(game->mlx_data, x, y1, 0x994C00);
// 	}
// }

int	raycast(t_game *game)
{
	int lineNum;

	game->rayAngle = ANGLE - HALF_FOV;
	lineNum = 0;

	while(lineNum <= WIDTH)
	{
		game->rayXd = game->data->map->player_x;
		game->rayYd = game->data->map->player_y;
		game->rayCos = cos(degree_to_radians(game->rayAngle))/PRECISION;
		game->raySin = sin(degree_to_radians(game->rayAngle))/PRECISION;
		// printf("sin(degRad(rayAngle)) is %f \n", raySin);

		// printf("worldMap[2][2] is %d\n",worldMap[0][0]);

		// we send vector x,y to direction x1,y1 to find a wall position ([x,y] = 1) on map
		// in result is we know both positions and can calculate distance, can get sprite color
		
		while (true)
		{
			game->rayXd += game->rayCos;
			game->rayYd += game->raySin;
			game->rayX = round(game->rayXd);
			game->rayY = round(game->rayYd);
			if (game->data->map->map_array[game->rayY][game->rayX] == '1')
				break;
			// printf("current rayX = %f, rayY is %f\n", rayXd, rayYd);
		}

		// Pythagoras theorem
		game->distance = sqrt(pow(game->data->map->player_x - game->rayX, 2)
			+ pow(game->data->map->player_y - game->rayY, 2));
		// Calculating wall height
		game->wallHeight = floor(HALF_HEIGHT /game->distance);
		// Draw the line...

		// draw_line(game, lineNum, 0, (int)(HALF_HEIGHT - game->wallHeight));
		// // drawLine(lineNum, (int)(halfHeight - wallHeight), lineNum, (int)(halfHeight + wallHeight));
		// draw_line(game, lineNum, (int)(HALF_HEIGHT + game->wallHeight), HEIGHT);
		printf("WALL HEIGHT [%lf]\n", game->wallHeight);
		// Increment angle
		game->rayAngle += INC_ANGLE;

		lineNum++;
	}

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->mlx_data->img, 0, 0);
	close_game_exit(game);
	return (0);
}
