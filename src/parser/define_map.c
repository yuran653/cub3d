/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:00:49 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:03:31 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_empty_line(t_data *data)
{
	int	i;

	i = -1;
	while (data->map->map_array[++i])
		if (is_empty_line(data->map->map_array[i]))
			error_data_exit_fail(data, ERROR_MAP, ERROR_MAP_EMPTY_LINE);
}

void	trim_empty_line(t_data *data, char **array, int size)
{
	while (size > 0 && is_empty_line(array[--size]))
	{
		free(array[size]);
		array[size] = NULL;
	}
	if (size < MAP_MIN_SIZE)
		error_data_exit_fail(data, ERROR_MAP, ERROR_MAP_SIZE);
}

void	copy_map(t_map *dst, t_file *src, int *i)
{
	int	size;

	size = 0;
	while (src->content[*i])
	{
		dst->map_array[size] = src->content[*i];
		src->content[*i] = NULL;
		*i += 1;
		size++;
	}
}

void	skip_empty_line(char **array, int *i)
{
	while (array[*i] && is_empty_line(array[*i]))
		*i += 1;
}

void	define_map(t_data *data, int *i)
{
	int	size;

	skip_empty_line(data->map_file->content, i);
	if (!data->map_file->content[*i])
		error_data_exit_fail(data, ERROR_MAP, ERROR_MAP_NONE);
	size = array_size(&data->map_file->content[*i]);
	if (size < MAP_MIN_SIZE)
		error_data_exit_fail(data, ERROR_MAP, ERROR_MAP_SIZE);
	data->map->map_array = init_array_null(size);
	if (!data->map->map_array)
		error_data_exit_fail(data, strerror(errno), ERROR_MAP);
	copy_map(data->map, data->map_file, i);
	trim_empty_line(data, data->map->map_array, size);
	check_map_empty_line(data);
	check_map_valid_data(data);
}
