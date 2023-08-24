/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:14:09 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/24 17:14:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_null(void *var)
{
	if (var)
		free(var);
	var = NULL;
}

void	free_array(void **array)
{
	int	i;

	i = 0;
	if (array)
		while (array[i])
			free_null(array[i++]);
	free_null(array);
}

void	free_map(t_map *map)
{
	if (map)
	{
		free_array(map->map_array);
		free_null(map);
	}
}


void	free_data(t_data *data)
{
	if (data)
	{
		free_null(data->north_path);
		free_null(data->south_path);
		free_null(data->east_path);
		free_null(data->west_path);
		free_null(data->color);
		free_map(data->map);
		free_null(data);
	}
}
