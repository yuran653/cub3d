/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:23:11 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/27 17:55:05 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_fd(int fd)
{
	if (close(fd) == -1)
	{
		print_error_msg(strerror(errno), NULL);
		return (1);
	}
	return (0);
}

int	array_size(char **array)
{
	int	size;

	size = 0;
	if (array)
		while (array[size])
			size ++;
	return (size);
}

int	check_file_ext(char *file_name, char *file_ext)
{
	int	ext_len;
	int	index;

	ext_len = ft_strlen(file_ext);
	index = ft_strlen(file_name) - ext_len;
	if (index < 0 || ft_strncmp(file_ext, &file_name[index], ext_len + 1))
		return (error_msg_1(ERROR_EXT, file_name));
	return (0);
}
