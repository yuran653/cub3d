/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/29 19:11:57 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	parse_map_file(t_data *data)
{
	int	i;

	i = 0;
	if (define_texture(data, &i))
		return (1);
	if (define_color(data, &i))
		return (1);
	if (define_map(data, &i))
		return (1);
	free_data_file(data);
	return (0);
}
