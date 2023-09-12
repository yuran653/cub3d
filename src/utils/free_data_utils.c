/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:28:02 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/12 15:09:02 by jgoldste         ###   ########.fr       */
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
	if (map)
	{
		if (map->map_array)
			map->map_array = free_array(map->map_array);
		free(map);
	}
	return (NULL);
}

t_file *free_file(t_file *file)
{
	if (file)
	{
		free(file->line);
		if (file->content)
			file->content = free_array(file->content);
		free(file);
	}
	return (NULL);
}
