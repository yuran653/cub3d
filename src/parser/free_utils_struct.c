/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:02:19 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/27 18:14:58 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data_color(t_data *data)
{
	if (data->ceilling)
	{
		free(data->ceilling);
		data->ceilling = NULL;
	}
	if (data->floor)
	{
		free(data->floor);
		data->floor = NULL;
	}
}

void	free_data_map(t_data *data)
{
	if (data->map)
	{
		data->map->map_array = free_array(data->map->map_array);
		free(data->map);
		data->map = NULL;
	}
}

void	free_data_file(t_data *data)
{
	if (data->map_file)
	{
		free(data->map_file->line);
		data->map_file->content = free_array(data->map_file->content);
		free(data->map_file);
		data->map_file = NULL;
	}
}

t_data	*free_data(t_data *data)
{
	if (data)
	{
		free(data->north_path);
		data->north_path = NULL;
		free(data->south_path);
		data->south_path = NULL;
		free(data->east_path);
		data->north_path = NULL;
		free(data->west_path);
		data->west_path = NULL;
		free_data_file(data);
		free_data_map(data);
		free_data_color(data);
		free(data);
	}
	return (NULL);
}