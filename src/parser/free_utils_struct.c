/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:02:19 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/26 17:43:27 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	*free_color(t_color *color)
{
	if (color)
		free(color);
	return (NULL);
}

t_map	*free_map(t_map *map)
{
	if (map)
	{
		map->map_array = free_array(map->map_array);
		free(map);
	}
	return (NULL);
}

t_file	*free_file(t_file *file)
{
	if (file)
	{
		free(file->line);
		file->content = free_array(file->content);
		free(file);
	}
	return (NULL);
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
		data->file = free_file(data->file);
		data->map = free_map(data->map);
		data->color = free_color(data->color);
		free(data);
	}
	return (NULL);
}
