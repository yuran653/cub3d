/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/01 19:45:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_id(char *str, char *id)
{
	if (ft_strncmp(str, id, ft_strlen(id)))
		return (1);
	return (0);
}

void	define_texture_color(t_data *data, int *i)
{
	char	*str;

	while (data->map_file->content[*i]
		&& (data->map_file->defined_color < DEFINED_COLOR
			|| data->map_file->defined_texture < DEFINED_TEXTURE))
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		str = data->map_file->content[*i];
		skip_str(&str, NULL);
		printf("-[%d]>[%s]\n", *i, str);
		if (check_id(str, NORTH_TEXTURE) == 0
			|| check_id(str, SOUTH_TEXTURE) == 0
			|| check_id(str, EAST_TEXTURE) == 0
			|| check_id (str, WEST_TEXTURE) == 0)
			define_texture_value(data, &str);
		else if (check_id(str, CEILLING_COLOR) == 0
			|| check_id(str, FLOOR_COLOR) == 0)
			define_color_value(data, &str);
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

// ----------------------------------------------------------------

// int	check_id(char *str, char *id, char **id_ptr)
// {
// 	int	len;

// 	*id_ptr = id;
// 	len = ft_strlen(id);
// 	if (ft_strncmp(str, id, len))
// 		return (1);
// 	return (0);
// }

// int	define_texture_color(t_data *data, int *def_clr, int *def_txt, int *i)
// {
// 	char	*str;
// 	char	*id_ptr;
// 	int		i;

// 	str = data->map_file->content[*i];
// 	skip(&str, NULL);
// 	i = 0;
// 	while (data->map_file->content[*i]
// 		&& (def_clr <= DEFINED_COLOR || def_txt <= DEFINED_TEXTURE))
// 	{
// 		while (is_empty_line(data->map_file->content[*i]))
// 			*i += 1;
// 		if (check_id(str, NORTH_TEXTURE, &id_ptr) == 0
// 		|| check_id(str, SOUTH_TEXTURE, &id_ptr) == 0
// 		|| check_id(str, EAST_TEXTURE, &id_ptr) == 0
// 		|| check_id (str, WEST_TEXTURE, &id_ptr) == 0)
// 			return (define_texture_value(data, &str, id_ptr, def_txt));
// 		else if (check_id(str, CEILLING_COLOR, &id_ptr) == 0
// 			|| check_id(str, FLOOR_COLOR, &id_ptr) == 0)
// 			return (define_color_value(data, &str, id_ptr, def_clr));
// 		else
// 			return (error_msg_return_1(ERROR_ID, str));
// 	}
// }

// int	parse_map_file(t_data *data)
// {
// 	int	def_clr;
// 	int	def_txt;
// 	int i;

// 	i = 0;
// 	// if (define_texture(data, &i))
// 	// 	return (1);
// 	// if (define_color(data, &i))
// 	// 	return (1);
// 	def_clr = DEFINED_NONE;
// 	def_txt = DEFINED_NONE;
// 	if (define_texture_color(data, &def_clr, &def_txt, &i))
// 		return (1);
// 	if (define_map(data, &i))
// 		return (1);
// 	free_data_file(data);
// 	return (0);
// }
