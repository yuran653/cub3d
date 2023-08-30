/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:40:15 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/30 18:43:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_id(char *str, char *id, char **id_ptr)
{
	int	len;

	*id_ptr = id;
	len = ft_strlen(id);
	if (ft_strncmp(str, id, len))
		return (1);
	return (0);
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
