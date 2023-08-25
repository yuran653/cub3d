/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:00:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 19:38:50 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_size(char **array)
{
	int size;

	size = 0;
	if (array)
		while(array[size])
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
		return (NULL);
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

char	**read_file(char *file_name)
{
	int		fd;
	char	*line;
	char	**file_content;

	errno = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_msg_null(strerror(errno)));
	file_content = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
				return (error_msg_null(strerror(errno)));
		return (error_msg_null(EMPTY_FILE));
	}
	while (line)
	{
		file_content = push_back(file_content, line);
		if (!file_content)
		{
			free_array((void**)file_content);
			file_content = NULL;
			free(line);
			line = NULL;
			return (error_msg_null(strerror(errno)));
		}
		line = get_next_line(fd);
		if (!line)
		{
			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
			{
				free_array((void**)file_content);
				file_content = NULL;
				return (error_msg_null(strerror(errno)));
			}
		}
	}
	close_check(fd);
	return (file_content);
}



// char	**read_file(char *file_name)
// {
// 	int		fd;
// 	char	*line;
// 	char	**file_content;

// 	errno = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return (error_msg_null(strerror(errno)));
// 	file_content = NULL;
// 	line = get_next_line(fd);
// 	if (!line)
// 	{
// 		if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
// 				return (error_msg_null(strerror(errno)));
// 		return (error_msg_null(EMPTY_FILE));
// 	}
// 	while (line)
// 	{
// 		file_content = push_back(file_content, line);
// 		if (!file_content)
// 		{
// 			free_array((void**)file_content);
// 			file_content = NULL;
// 			free(line);
// 			line = NULL;
// 			return (error_msg_null(strerror(errno)));
// 		}
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
// 			{
// 				free_array((void**)file_content);
// 				file_content = NULL;
// 				return (error_msg_null(strerror(errno)));
// 			}
// 		}
// 	}
// 	close_check(fd);
// 	return (file_content);
// }
