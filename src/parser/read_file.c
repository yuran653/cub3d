/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:00:06 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/24 17:39:52 by jgoldste         ###   ########.fr       */
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

char	**push_back(char **array, char *str)
{
	char	**new_array;
	int	size;
	int	i;
	
	size = array_size(array);
	new_array = (char **)malloc(sizeof(char *) * (size + 2));
	i = -1;
	if (array)
		while (array[++i])
			new_array[i] = array[i];
	new_array[size] = str;
	new_array[size + 1] = NULL;
	free_null((void*)&array);
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
	int i = 0;
	while (line)
	{
		file_content = push_back(file_content, line);
		line = get_next_line(fd);
		if (i == 2)
		{
			free_null((void*)&line);
			// free(line);
			// line = NULL;
			printf("-------%s", line);
			errno = 35;
			printf("%d\n", errno);
		}
		if (!line)
		{
			if (errno == ENOMEM || errno == EAGAIN || errno == EINVAL)
			{
				printf("read_file->Map check: started\n");
				for (int i = 0; file_content[i]; i++)
					printf("%s", file_content[i]);
				printf("read_file->Map check: finished\n");
				free_array((void**)file_content);
				return (error_msg_null(strerror(errno)));
			}
		}
		i++;
	}
	close_check(fd);
	return (file_content);
}
