/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:03 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/15 22:00:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_digit_space(t_data *data, char *value)
{
	int	j;

	j = 0;
	while (value[j] && ft_isdigit(value[j]))
		j++;
	while (value[j])
		if (value[j++] != SPACE_SIGN)
			error_data_exit_fail(data, ERROR_COLOR_VALUE, value);
}

void	set_rgb_amount(t_data *data, t_color *color, char *value)
{
	color->rgb ++;
	if (color->rgb >= 3)
		error_data_exit_fail(data, ERROR_COLOR_AMOUNT, value);
}

void	set_value_end(char *value, int *i)
{
	*i = 0;
	while (value[*i] && value[*i] != DELIMITER)
		*i += 1;
	if (value[*i + 1])
		value[*i] = '\0';
}

void	parse_color_value(t_data *data, t_color *color, char *value)
{
	int		i;

	if (color->rgb != -1)
		error_data_exit_fail(data, ERROR_COLOR_DEF, value);
	value = &value[COLOR_LEN];
	i = -1;
	while (value[++i])
	{
		while (value[i] && value[i] == SPACE_SIGN)
			i++;
		value = &value[i];
		set_value_end(value, &i);
		set_rgb_amount(data, color, value);
		is_digit_space(data, value);
		assign_color_value(data, color, value);
		if (value [i + 1] && value [i + 1] != DELIMITER)
		{
			value = &value[i + 1];
			i = -1;
		}
	}
	convert_to_hex(color);
}

void	define_color_value(t_data *data, char *str)
{
	if (check_id(str, COLOR_CEILLING))
		parse_color_value(data, data->ceilling, str);
	else if (check_id(str, COLOR_FLOOR))
		parse_color_value(data, data->floor, str);
	data->map_file->defined_color++;
}
