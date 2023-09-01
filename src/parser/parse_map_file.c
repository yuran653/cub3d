/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/01 01:30:55 by jgoldste         ###   ########.fr       */
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

int	define_texture_color(t_data *data, int *def_color, int *def_texture, int *i)
{
	char	*str;
	char	*id_ptr;
	int		i;

	str = data->map_file->content[*i];
	skip(&str, NULL);
	i = 0;
	while (data->map_file->content[*i]
		&& (def_color <= DEFINED_COLOR || def_texture <= DEFINED_TEXTURE))
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		if (!check_id(str, NORTH_TEXTURE, &id_ptr)
		|| !check_id(str, SOUTH_TEXTURE, &id_ptr)
		|| !check_id(str, EAST_TEXTURE, &id_ptr)
		|| !check_id (str, WEST_TEXTURE, &id_ptr))
			
		else if 
	}
}

int	parse_map_file(t_data *data)
{
	int	def_color;
	int	def_texture;
	int i;

	i = 0;
	// if (define_texture(data, &i))
	// 	return (1);
	// if (define_color(data, &i))
	// 	return (1);
	def_color = DEFINED_NONE;
	def_texture = DEFINED_NONE;
	if (define_texture_color(data, &def_color, &def_texture, &i))
		return (1);
	if (define_map(data, &i))
		return (1);
	free_data_file(data);
	return (0);
}
