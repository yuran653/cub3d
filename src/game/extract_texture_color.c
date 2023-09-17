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
	int north = 0x9999ff;
	int south = 0xff9999;
	int east = 0xffff99;
	int west = 0x99ffff;
	int angle;

	angle = game->ray_angle + game->values->half_fov;
	if (angle > 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	if (angle >= 0 && angle <= 90)
		return (north);	
	else if (angle > 90 && angle < 180)
		return(east);
	else if (angle >= 180 && angle <= 270)
		return (south);
	else if (angle > 270 && angle < 360)
		return (west);
	return (0x0);
}
