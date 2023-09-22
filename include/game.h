/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:42:54 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/22 18:16:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"

// init_game.c
t_game	*init_game(t_map *map);
void	init_values(t_game *game);
void	init_mlx_data(t_game *game);
void	open_texture(t_game *game);

// raycast.c
int		raycast(t_game *game);

// extract_texture_color.c
int		extract_texture_color(t_game *game, double y_pos_fixed, int texture);

// define_texture_side.c
int		define_texture_side(t_game *game);

// draw_utils.c
void	pixel_put(t_mlx *mlx_data, int x, int y, int color);
float	degree_to_radians(float degree);
int		is_wall(t_game *game, int x, int y);

// key_hook.c
int		key_hook(int keycode, t_game *game);
int		mouse_hook(int x, int y, t_game *game);

#endif