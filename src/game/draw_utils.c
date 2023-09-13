/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:03:45 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 18:00:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

void	pixel_put(t_mlx *mlx_data, int x, int y, int color)
{
	if (x >= 0 || x < WIDTH || y >= 0 || y < HEIGHT)
		*(unsigned int *)(mlx_data->addr + (y * mlx_data->line_length
					+ x * (mlx_data->bits_per_pixel / 8))) = color;
}
