/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:28:02 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:18:58 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	*free_color(t_color *color)
{
	free(color);
	return (NULL);
}

t_map	*free_map(t_map *map)
{
	if (map->map_array)
			map->map_array = free_array(map->map_array);
		free(map);
		return (NULL);
}

t_file *free_file(t_file *file)
{
	free(file->line);
	if (file->content)
		file->content = free_array(file->content);
	free(file);
	return (NULL);
}

// void	free_data_color(t_data *data)
// {
// 	if (data->ceilling)
// 	{
// 		free(data->ceilling);
// 		data->ceilling = NULL;
// 	}
// 	if (data->floor)
// 	{
// 		free(data->floor);
// 		data->floor = NULL;
// 	}
// }

// void	free_data_map(t_data *data)
// {
// 	if (data->map)
// 	{
// 		if (data->map->map_array)
// 			data->map->map_array = free_array(data->map->map_array);
// 		free(data->map);
// 		data->map = NULL;
// 	}
// }

// void	free_data_file(t_data *data)
// {
// 	if (data->map_file)
// 	{
// 		free(data->map_file->line);
// 		data->map_file->content = free_array(data->map_file->content);
// 		free(data->map_file);
// 		data->map_file = NULL;
// 	}
// }
