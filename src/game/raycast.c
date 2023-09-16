/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 17:44:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_line(t_game *game, int y1, int y2, int color)
{
	while (y1++ < y2)
		pixel_put(game->mlx_data, game->line_num, y1, color);
}

static void	draw_line(t_game *game)
{
	int	wall_top;
	int	wall_bottom;

	wall_top = game->values->half_src_height - game->wall_height;
	wall_bottom = game->values->half_src_height + game->wall_height;
	put_line(game, 0, wall_top, game->map->hex_ceilling);
	put_line(game, wall_top, wall_bottom, extract_texture_color(game));
	put_line(game, wall_bottom, HEIGHT, game->map->hex_floor);
}

static void	define_wall_position(t_game *game)
{
	while (true)
	{
		game->ray_x += game->ray_cos;
		game->ray_y += game->ray_sin;
		game->x = round(game->ray_x);
		game->y = round(game->ray_y);
		if (game->map->map_array[game->y][game->x] == M_WALL
			|| game->x > game->map->width || game->y > game->map->height)
			break ;
	}
}

static void	correct_ray_angle_value(t_game *game)
{
	if (game->ray_angle < 0)
		game->ray_angle += 360;
	else if (game->ray_angle > 360)
		game->ray_angle -= 360;
}

int	raycast(t_game *game)
{
	game->ray_angle = game->map->player_orient - game->values->half_fov;
	correct_ray_angle_value(game);
	game->line_num = 0;
	while (game->line_num < WIDTH)
	{
		game->ray_x = game->map->player_x;
		game->ray_y = game->map->player_y;
		game->ray_cos = cos(degree_to_radians(game->ray_angle))
			/ game->values->precision;
		game->ray_sin = sin(degree_to_radians(game->ray_angle))
			/ game->values->precision;
		define_wall_position(game);
		game->distance = sqrt(pow(game->map->player_x - game->ray_x, 2)
				+ pow(game->map->player_y - game->ray_y, 2));
		game->wall_height = floor(game->values->half_src_height
				/ game->distance);
		draw_line(game);
		game->ray_angle += game->values->inc_angle;
		correct_ray_angle_value(game);
		game->line_num++;
	}
	mlx_clear_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->img, 0, 0);
	return (0);
}
