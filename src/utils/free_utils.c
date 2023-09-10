/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:14:09 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:21:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_game	*free_game(t_game *game)
// {
// 	if (game)
// 	{
// 		fre
// 	}
// 	return (NULL);
// }

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
		data->ceilling = free_color(data->ceilling);
		data->floor = free_color(data->floor);
		data->map_file = free_file(data->map_file);
		data->map = free_map(data->map);
		// free_data_file(data);
		// free_data_map(data);
		// free_data_color(data);
		free(data);
	}
	return (NULL);
}

char	**free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i++] = NULL;
		}
		free(array);
	}
	return (NULL);
}
