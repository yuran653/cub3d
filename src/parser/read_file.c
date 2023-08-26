/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:00:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/26 18:03:26 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_size(char **array)
{
	int	size;

	size = 0;
	if (array)
		while (array[size])
			size ++;
	return (size);
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

int	open_file(char *file_name, t_data *data)
{
	data->file->fd = open(file_name, O_RDONLY);
	if (data->file->fd == -1)
		return (1);
	return (0);
}

int	read_line_error(t_data *data)
{
	data->file->content = free_array(data->file->content);
	if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
		return (error_msg_1(strerror(errno)));
	return (error_msg_1(EMPTY_FILE));
}

int	read_file(char *file_name, t_data *data)
{
	errno = 0;
	if (open_file(file_name, data))
		return (error_msg_1(strerror(errno)));
	data->file->line = get_next_line(data->file->fd);
	if (!data->file->line)
		return (read_line_error(data));
	while (data->file->line)
	{
		data->file->content = push_back(data->file->content, data->file->line);
		if (!data->file->content)
		{
			free(data->file->line);
			data->file->line = NULL;
			return (error_msg_1(strerror(errno)));
		}
		data->file->line = get_next_line(data->file->fd);
		if (!data->file->line)
			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
				return (read_line_error(data));
	}
	return (close_check(data->file->fd));
}
