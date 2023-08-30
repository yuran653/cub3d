/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:16 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/30 19:42:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_texture_value(char **data_path, char **str, char *id_ptr)
{
	if (*data_path)
		return (error_msg_return_1(ERROR_TEXTURE_DEF, id_ptr));
	*data_path = ft_strdup(*str);
	if (!*data_path)
		return (error_msg_return_1(strerror(errno), ERROR_TEXTURE));
	return (0);
}

int	define_texture_value(t_data *data, char **str, char *id_ptr)
{
	int	len;

	skip(str, id_ptr);
	len = ft_strlen(id_ptr);
	if (ft_strncmp(NORTH_TEXTURE, id_ptr, len) == 0)
		return (assign_texture_value(&data->north_path, str, id_ptr));
	else if (ft_strncmp(SOUTH_TEXTURE, id_ptr, len) == 0)
		return (assign_texture_value(&data->south_path, str, id_ptr));
	else if (ft_strncmp(EAST_TEXTURE, id_ptr, len) == 0)
		return (assign_texture_value(&data->east_path, str, id_ptr));
	else if (ft_strncmp(WEST_TEXTURE, id_ptr, len) == 0)
		return (assign_texture_value(&data->west_path, str, id_ptr));
	printf("%s->%s->open == [%d]\n", id_ptr, *str, open(*str, O_RDONLY));
	(void)data;
	return (0);
}

int	define_texture_path(t_data *data, int i)
{
	char	*str;
	char	*id_ptr;

	str = data->map_file->content[i];
	skip(&str, NULL);
	// skip_non_print(&str);
	if (check_file_ext(data->map_file->content[i], TEXTURE_EXT))
		return (error_msg_return_1(ERROR_TEXTURE_EXT, str));
	if (check_id(str, NORTH_TEXTURE, &id_ptr) && check_id(str, SOUTH_TEXTURE, &id_ptr)
		&& check_id(str, EAST_TEXTURE, &id_ptr) && check_id (str, WEST_TEXTURE, &id_ptr))
		return (error_msg_return_1(ERROR_TEXTURE_ID, str));
	if (define_texture_value(data, &str, id_ptr));
		return (1);
	return (0);
}

int	define_texture(t_data *data, int *i)
{
	int		defined_amount;

	defined_amount = DEFINED_NONE;
	while (data->map_file->content[*i] && defined_amount < DEFINED_TEXTURE)
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		if (define_texture_path(data, *i))
			return (1);
		defined_amount++;
		*i += 1;
	}
	if (defined_amount != DEFINED_TEXTURE)
		return (error_define_amount(ERROR_TEXTURE_AMOUNT, defined_amount));
	return (0);
}
