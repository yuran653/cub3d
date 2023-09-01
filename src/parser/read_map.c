/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:00:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/01 17:34:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_push_back(t_data *data, int errno_malloc)
{
	close_fd(data->map_file->fd);
	free(data->map_file->line);
	data->map_file->line = NULL;
	return (error_msg_return_1(strerror(errno_malloc), NULL));
}

char	**push_back(char **array, char *line)
{
	char	**new_array;
	int		size;
	int		i;

	size = array_size(array);
	new_array = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_array)
		return (free_array(array));
	i = -1;
	if (array)
		while (array[++i])
			new_array[i] = array[i];
	new_array[size] = line;
	new_array[size + 1] = NULL;
	free(array);
	array = NULL;
	return (new_array);
}

int	read_line_error(t_data *data)
{
	close_fd(data->map_file->fd);
	data->map_file->content = free_array(data->map_file->content);
	if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
		return (error_msg_return_1(strerror(errno), NULL));
	return (error_msg_return_1(EMPTY_FILE, NULL));
}

int	open_map(char *file_name, t_data *data)
{
	data->map_file->fd = open(file_name, O_RDONLY);
	if (data->map_file->fd == -1)
		return (1);
	return (0);
}

int	read_map(char *file_name, t_data *data)
{
	errno = 0;
	if (open_map(file_name, data))
		return (error_msg_return_1(strerror(errno), file_name));
	data->map_file->line = get_next_line(data->map_file->fd);
	if (!data->map_file->line)
		return (read_line_error(data));
	while (data->map_file->line)
	{
		data->map_file->content
			= push_back(data->map_file->content, data->map_file->line);
		if (!data->map_file->content)
			return (error_push_back(data, errno));
		data->map_file->line = get_next_line(data->map_file->fd);
		if (!data->map_file->line)
			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
				return (read_line_error(data));
	}
	return (close_fd(data->map_file->fd));
}
