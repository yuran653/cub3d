/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:03 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/03 00:48:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_color_value(t_data *data, t_color *color, char *value)
{
	if (color->rgb == R)
	{
		color->r = ft_atoi(value);
		if (color->r < 0 || color->r > 255)
			error_msg_exit_fail(data, ERROR_COLOR_VALUE, value);
	}
	else if (color->rgb == G)
	{
		color->g = ft_atoi(value);
		if (color->g < 0 || color->g > 255)
			error_msg_exit_fail(data, ERROR_COLOR_VALUE, value);
	}
	else if (color->rgb == B)
	{
		color->b = ft_atoi(value);
		if (color->b < 0 || color->b > 255)
			error_msg_exit_fail(data, ERROR_COLOR_VALUE, value);
	}
}

static void	is_digit_space(t_data *data, char *value)
{
	int	j;
	
	j = 0;
	while (value[j] && ft_isdigit(value[j]))
		j++;
	while (value[j])
		if (value[j++] != SPACE_SIGN)
			error_msg_exit_fail(data, ERROR_COLOR_VALUE, value);
}

static void set_value_end_plus_rgb(t_color *color, char *value, int *i)
{
	*i = 0;
	while (value[*i] && value[*i] != DELIMITER)
		*i += 1;
	if (value[*i + 1])
		value[*i] = '\0';
	color->rgb ++;
}

void	parse_color_value(t_data *data, t_color *color, char *value)
{		
	char	*id;
	int		i;
	
	if (color->rgb != -1)
		error_msg_exit_fail(data, ERROR_COLOR_DEF, value);
	id = value;
	id[COLOR_LEN] = '\0';
	value = &value[COLOR_LEN + 1];
	i = -1;
	while (value[++i])
	{
		while (value[i] && value[i] == SPACE_SIGN)
			i++;
		value = &value[i];
		set_value_end_plus_rgb(color, value, &i);
		if (color->rgb  >= 3)
			error_msg_exit_fail(data, ERROR_COLOR_AMOUNT, id);
		is_digit_space(data, value);
		assign_color_value(data, color, value);
		if (value [i + 1] && value [i + 1] != DELIMITER)
		{
			value = &value[i + 1];
			i = -1;
		}
	}
}

void	define_color_value(t_data *data, char *str)
{
	if (check_id(str, COLOR_CEILLING))
		parse_color_value(data, data->ceilling, str);
	else if (check_id(str, COLOR_FLOOR))
		parse_color_value(data, data->floor, str);
	data->map_file->defined_color++;
}

// void	parse_color_value(t_data *data, t_color *color, char *str)
// {		
// 	char	*values;
// 	int		i;
// 	int		j;
	
// 	if (color->rgb != -1)
// 		error_msg_exit_fail(data, ERROR_COLOR_DEF, *str);
// 	values = *str + (COLOR_LEN - 1);
// 	*values = '\0';
// 	values++;
// 	i = -1;
// 	while (values[++i])
// 	{
// 		while (values[i] && values[i] == SPACE_SIGN)
// 			i++;
// 		values = &values[i];
// 		i = 0;
// 		while (values[i] && values[i] != DELIMITER)
// 			i++;
// 		if (values[i + 1])
// 			values[i] = '\0';
// 		color->rgb ++;
// 		if (color->rgb  >= 3)
// 			error_msg_exit_fail(data, ERROR_COLOR_AMOUNT, *str);
// 		j = 0;
// 		while (values[j] && ft_isdigit(values[j]))
// 			j++;
// 		while (values[j])
// 			if (values[j++] != SPACE_SIGN)
// 				error_msg_exit_fail(data, ERROR_COLOR_VALUE, values);
// 		assign_color_value(data, color, values);
// 		if (values [i + 1] && values [i + 1] != DELIMITER)
// 		{
// 			values = &values[i + 1];
// 			i = -1;
// 		}
// 	}
// }