/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:14:09 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 06:08:58 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			game->map = free_map(game->map);
		if (game->values)
			free(game->values);
		if (game->mlx_data)
		{
			if (game->mlx_data->mlx_ptr && game->mlx_data->img)
				mlx_destroy_image(game->mlx_data->mlx_ptr, game->mlx_data->img);
			if (game->mlx_data->mlx_ptr && game->mlx_data->win_ptr)
				mlx_destroy_window(game->mlx_data->mlx_ptr,
					game->mlx_data->win_ptr);
			else if (game->mlx_data->mlx_ptr)
				free(game->mlx_data->mlx_ptr);
			free(game->mlx_data);
		}
		free(game);
	}
	return (NULL);
}

t_data	*free_data(t_data *data)
{
	if (data)
	{
		data->ceilling = free_color(data->ceilling);
		data->floor = free_color(data->floor);
		data->map_file = free_file(data->map_file);
		data->map = free_map(data->map);
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
