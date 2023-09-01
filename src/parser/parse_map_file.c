/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/02 00:38:26 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_id(char *str, char *id)
{
	if (ft_strncmp(str, id, ft_strlen(id)))
		return (1);
	return (0);
}

int	check_id_color(char *str)
{
	return (check_id(str, CEILLING_COLOR) == 0
		|| check_id(str, FLOOR_COLOR) == 0);
}

int	check_id_texture(char *str)
{
	return (check_id(str, NORTH_TEXTURE) == 0
		|| check_id(str, SOUTH_TEXTURE) == 0
		|| check_id(str, EAST_TEXTURE) == 0
		|| check_id (str, WEST_TEXTURE) == 0);
}

void	define_texture_color(t_data *data, int *i)
{
	char	*str;

	while (data->map_file->content[*i]
		&& (data->map_file->defined_color < DEFINED_COLOR
			|| data->map_file->defined_texture < DEFINED_TEXTURE))
	{
		while (data->map_file->content[*i]
			&& is_empty_line(data->map_file->content[*i]))
				*i += 1;
		if (!data->map_file->content[*i])
			break;
		str = data->map_file->content[*i];
		skip_str(&str, NULL);
		if (check_id_color(str))
			define_color_value(data, &str);
		else if (check_id_texture(str))
			define_texture_value(data, &str);
		else
			error_msg_exit_fail(data, ERROR_ID, str);
		*i += 1;
	}
	if (data->map_file->defined_color < DEFINED_COLOR
		|| data->map_file->defined_texture < DEFINED_TEXTURE)
		error_msg_exit_fail(data, ERROR_DEFINED_AMOUNT, NULL);
}

void	parse_map_file(t_data *data)
{
	int	i;

	i = 0;
	define_texture_color(data, &i);
	// define_map(data, &i);
	free_data_file(data);
}
