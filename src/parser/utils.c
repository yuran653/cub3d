/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:23:11 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/01 19:27:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_str(char **str, char *skip)
{
	int	len;

	if (skip)
	{
		len = ft_strlen(skip);
		if (ft_strncmp (*str, skip, len) == 0)
			*str += len;
	}
	while (ft_isprint(**str) == false || **str == SPACE_SIGN)
			*str += 1;
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (ft_isprint(*line) == true && *line != SPACE_SIGN)
			return (false);
		line++;
	}
	return (true);
}

int	close_fd(int fd)
{
	if (close(fd) == -1)
		return (error_msg_return_1(strerror(errno), NULL));
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
		return (1);
	return (0);
}
