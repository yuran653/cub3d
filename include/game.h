/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:42:54 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 01:11:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "structs.h"

// init_game.c
t_game	*init_game(t_data *data);
void	init_mlx_data(t_game *game);

// recasting.c
int		recasting(t_game *game);

// draw_utils.c
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);

// key_hook.c
int		key_hook(int keycode, t_game *game);

#endif