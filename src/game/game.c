/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 19:13:08 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_data *data)
{
	if (data->map_file)
		printf("MAP FILE IS NOT CLEARED\n");
	else
		printf("MAP FILE IS CORRECTLY CLEARED\n");
	printf("--- DEFINED VALUES ---\n");
	printf("NORTH->fd[%d]->%s\nSOUTH->fd[%d]->%s\n EAST->fd[%d]->%s\n WEST->fd[%d]->%s\n",
		data->north_fd, data->north_path,
		data->south_fd, data->south_path,
		data->east_fd, data->east_path,
		data->west_fd, data->west_path);
	if (data->ceilling && data->floor)
	{
		printf("- CEILLING COLOR ->[%0.3d,%0.3d,%0.3d]\n",
			data->ceilling->r, data->ceilling->g, data->ceilling->b);
		printf("--- FLOOR COLOR -->[%0.3d,%0.3d,%0.3d]\n",
			data->floor->r, data->floor->g, data->floor->b);
	}
	else
		printf("COLORS VARIABLES ARE NOT ALLOCATED\n");
	if (data->map && data->map->map_array && data->map->map_array[0])
	{
		printf("--------- MAP ---------\n");
		for (int i = 0; data->map->map_array[i]; i++)
			printf("[%s]\n", data->map->map_array[i]);
		printf("--- MAP WIDTH ---> [%d]\n", data->map->width);
		printf("--- MAP HEIGHT --> [%d]\n", data->map->height);
		printf("--- PLAYER X ----> [%d]\n", data->map->player_x);
		printf("--- PLAYER Y ----> [%d]\n", data->map->player_y);
		printf("- PLAYER ORIENT -> [%d]\n", data->map->player_orient);
	}
	else
		printf("-- MAP IS NOT DEFINED --\n");
}
