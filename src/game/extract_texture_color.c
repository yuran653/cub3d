// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   extract_texture_color.c                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/16 15:18:50 by jgoldste          #+#    #+#             */
// /*   Updated: 2023/09/16 16:51:46 by jgoldste         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

int	extract_texture_color(t_game *game)
{
	if (game->ray_angle < 0 || game->ray_angle > 360)
		error_game_exit_fail(game, strerror(EOVERFLOW),
			ft_itoa(round(game->ray_angle)));
	return (0x0);
}
