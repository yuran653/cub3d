/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:16 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/02 00:40:37 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_texture_value(t_data *data, char **data_path, char **str)
{
	if (*data_path)
		error_msg_exit_fail(data, ERROR_TEXTURE_DEF, *str);
	*str += TEXTURE_LEN;
	skip_str(str, NULL);
	*data_path = ft_strdup(*str);
	if (!*data_path)
		error_msg_exit_fail(data, strerror(errno), ERROR_TEXTURE);
}

void	define_texture_value(t_data *data, char **str)
{
	if (check_file_ext(*str, TEXTURE_EXT))
		error_msg_exit_fail(data, ERROR_TEXTURE_EXT, *str);
	if (check_id(*str, NORTH_TEXTURE) == 0)
		assign_texture_value(data, &data->north_path, str);
	else if (check_id(*str, SOUTH_TEXTURE) == 0)
		assign_texture_value(data, &data->south_path, str);
	else if (check_id(*str, EAST_TEXTURE) == 0)
		assign_texture_value(data, &data->east_path, str);
	else if (check_id(*str, WEST_TEXTURE) == 0)
		assign_texture_value(data, &data->west_path, str);
	data->map_file->defined_texture++;
}
