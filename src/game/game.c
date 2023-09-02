/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/02 23:41:19 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_game_dir(t_data *data)
{
	printf("GAME DIRECTORY: OK\n");
	if (data->map_file)
		printf("MAP FILE IS NOT CLEARED\n");
	else
		printf("MAP FILE IS CORRECTLY CLEARED\n");
	printf("--- DEFINED VALUES ---\n");
	printf("NORTH->fd[%d]->%s\nSOUTH->fd[%d]->%s\nEAST->fd[%d]->%s\nWEST->fd[%d]->%s\n",
		data->north_fd, data->north_path,
		data->south_fd, data->south_path,
		data->east_fd, data->east_path,
		data->west_fd, data->west_path);
	if (data->ceilling && data->floor)
		printf("CEILLING COLOR->[%d,%d,%d]\nFLOOR COLOR->[%d,%d,%d]\n",
				data->ceilling->r, data->ceilling->g, data->ceilling->b,
				data->floor->r, data->floor->g, data->floor->b);
	else
		printf("COLORS VARIABLES ARE NOT ALLOCATED\n");
}
