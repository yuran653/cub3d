/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:16 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 02:51:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_texture_value(t_data *data, char **path, char *str)
{
	int	fd;

	if (*path)
		error_data_exit_fail(data, ERROR_TEXTURE_DEF, str);
	str += TEXTURE_LEN;
	skip_str(&str, NULL);
	*path = ft_strdup(str);
	if (!*path)
		error_data_exit_fail(data, strerror(errno), ERROR_TEXTURE);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_data_exit_fail(data, strerror(errno), str);
	if (close_fd(fd) != 0)
		error_data_exit_fail(data, strerror(errno), str);
}

void	define_texture_value(t_data *data, char *str)
{
	if (check_id(str, TEXTURE_NORTH) == 0)
		assign_texture_value(data, &data->map->texture_path[T_NORTH], str);
	else if (check_id(str, TEXTURE_SOUTH) == 0)
		assign_texture_value(data, &data->map->texture_path[T_SOUTH], str);
	else if (check_id(str, TEXTURE_EAST) == 0)
		assign_texture_value(data, &data->map->texture_path[T_EAST], str);
	else if (check_id(str, TEXTURE_WEST) == 0)
		assign_texture_value(data, &data->map->texture_path[T_WEST], str);
	data->map_file->defined_texture++;
}
