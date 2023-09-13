/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:42:54 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 19:28:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"

// init_game.c
t_game	*init_game(t_data *data);
void	init_mlx_data(t_game *game);

// recasting.c
int		raycast(t_game *game);
// void 	draw_line(t_game *game);

// draw_utils.c
void	pixel_put(t_mlx *mlx_data, int x, int y, int color);
float	degree_to_radians(float degree);

// key_hook.c
int		key_hook(int keycode, t_game *game);

#endif