/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:00:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/22 16:46:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	array_size(char **array)
{
	size_t size;

	size = 0;
	if (array)
		while(array[size])
			size ++;
	return (size);
}

char	**push_back(char **array, char *str)
{
	char	**new_array;
	int		i;

	new_array = (char**)malloc(sizeof(char*) * (array_size(array) + 2));
	if (!new_array)
	{
		free_null(str);
		free_array((void**)array);
		return (error_msg_null(strerror(errno)));
	}
	i = -1;
	while (array[++i])
		new_array[i] = array[i];
	new_array[i + 1] = str;
	new_array[i + 2] = NULL;
	free_array((void**)array);
	return (new_array);
}

char	**read_file(char *file_name)
{
	int		fd;
	char	*line;
	char	**file_content;

	errno = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_msg_null(strerror(errno)));
	line = get_next_line(fd);
	if (!line)
	{
		if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
				return (error_msg_null(strerror(errno)));
		return (error_msg_null(EMPTY_FILE));
	}
	file_content = NULL;
	while (line)
	{
		file_content = push_back(file_content, line);
		if (!file_content)
			return (NULL);
		// free_null(line);
        line = get_next_line(fd);
		if (!line)
			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
				return (error_msg_null(strerror(errno)));
	}
	return (file_content);
}
