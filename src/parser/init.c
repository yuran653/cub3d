/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:10:58 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**init_array_null(int size)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i <= size)
		array[i++] = NULL;
	return (array);
}

t_color	*init_color(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (error_msg_return_null(strerror(errno), NULL));
	color->rgb = -1;
	color->r = -1;
	color->g = -1;
	color->b = -1;
	return (color);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (error_msg_return_null(strerror(errno), NULL));
	map->width = -1;
	map->height = -1;
	map->player_x = -1;
	map->player_y = -1;
	map->player_orient = -1;
	map->map_array = NULL;
	return (map);
}

t_file	*init_file(void)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (error_msg_return_null(strerror(errno), NULL));
	file->fd = -1;
	file->defined_color = DEFINED_NONE;
	file->defined_texture = DEFINED_NONE;
	file->line = NULL;
	file->content = NULL;
	return (file);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (error_msg_return_null(strerror(errno), NULL));
	data->north_path = NULL;
	data->south_path = NULL;
	data->east_path = NULL;
	data->west_path = NULL;
	data->ceilling = init_color();
	data->floor = init_color();
	data->map_file = init_file();
	data->map = init_map();
	if (data->ceilling == NULL || data->floor == NULL
		|| data->map == NULL || data->map_file == NULL)
		return (free_data(data));
	return (data);
}
