/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:58 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/24 17:40:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// t_map	*init_map(char **file_content)
// {

// }

t_data	*init_data(t_file *file)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (error_msg_null(strerror(errno)));
	
	data->north_path = NULL;
	data->south_path = NULL;
	data->east_path = NULL;
	data->west_path = NULL;
	data->color = NULL;
	data->map = (t_map*)malloc(sizeof(t_map));
	if (!data->map)
	{
		free_null((void*)&data);
		return (error_msg_null(strerror(errno)));
	}
	data->map->width = 0;
	data->map->height = 0;
	data->map->player_x = 0;
	data->map->player_y = 0;
	data->map->player_orient = 0;
	data->map->map_array = file->file_content;
	return (data);
}
