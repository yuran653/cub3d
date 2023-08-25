/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:14:09 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 19:25:13 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_array(void **array)
{
	int	i;

	i = 0;
	if (array)
		while (array[i])
		{
			free(array[i++]);
			array[i] = NULL;
		}
	free(array);
}

void	free_file(t_file *file)
{
	if (file)
	{
		free(file->line);
		file->line = NULL;
		free_array((void**)file->file_content);
		file->file_content = NULL;
		free(file);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		free_array((void**)map->map_array);
		map->map_array = NULL;
		free(map);
	}
}

void	free_data(t_data *data)
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
		free_map(data->map);
		data->map = NULL;
		free(data->color);
		data->color = NULL;
		free(data);
	}
}