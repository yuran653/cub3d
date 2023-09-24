/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:42:07 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/24 11:12:25 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_texture_line(t_game *game, int wall_top, int wall_bottom)
{
	int color;
	int	side;
	int temp_y;
	int wall_size;
	double y_pos_fixed;

	temp_y = 0;
	wall_size = 0;
	if (wall_top < 0)
			wall_size = wall_bottom + abs(wall_top);
		else
			wall_size = wall_bottom - wall_top;
	while (wall_top++ < wall_bottom)
	{
		temp_y++;
		y_pos_fixed = (double)temp_y/(double)wall_size;
		side = define_texture_side(game);
		color = extract_texture_color(game, y_pos_fixed, side);
		if (color != -1)
			pixel_put(game->mlx_data, game->line_num, wall_top, color);
	}
}

static void	put_line(t_game *game, int wall_top, int wall_bottom, int color)
{
	while (wall_top < wall_bottom)
	{
		pixel_put(game->mlx_data, game->line_num, wall_top, color);
		wall_top++;
	}
}

static void	draw_line(t_game *game)
{
	int	wall_top;
	int	wall_bottom;

	wall_top = game->values->half_src_height - game->wall_height;
	wall_bottom = game->values->half_src_height + game->wall_height;
	put_line(game, 0, wall_top, game->map->hex_ceilling);
	put_texture_line(game, wall_top, wall_bottom);
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
		if (game->x < 0)
			game->x = 0;
		else if (game->x >= game->map->width)
			game->x = game->map->width - 1;
		if (game->y < 0)
			game->y = 0;
		else if (game->y >= game->map->height)
			game->y = game->map->height - 1;
		if (is_wall(game, game->x, game->y))
			break ;
		game->prev_x = game->x;
		game->prev_y = game->y;
	}
}

int	raycast(t_game *game)
{
	game->ray_angle = game->map->player_orient - game->values->half_fov;
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
		game->distance = game->distance
			* cos(degree_to_radians(game->ray_angle - game->map->player_orient));
		game->wall_height = floor(game->values->half_src_height
				/ game->distance);
		draw_line(game);
		game->ray_angle += game->values->inc_angle;
		game->line_num++;
	}
	mlx_clear_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr);
	mlx_put_image_to_window(game->mlx_data->mlx_ptr, game->mlx_data->win_ptr,
		game->mlx_data->img, 0, 0);
	return (0);
}
