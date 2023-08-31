/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:03 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/31 19:30:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_color_value(t_color *color, char **str, char *id_ptr)
{
	char	**values;
	
	if (color->r > -1)
		return (error_msg_return_1(ERROR_COLOR_DEF, id_ptr));
	values = ft_split(*str, ',');
	if (!values)
		return (error_msg_return_1(strerror(errno), ERROR_COLOR));
	printf("--->[%s]values to define:", id_ptr);
	for (int j = 0; values[j]; j++)
		printf("[%s]", values[j]);
	printf("\n");
	values = free_array(values);
	return (0);
}

int	define_color_value(t_data *data, char **str, char *id_ptr)
{
	int	len;

	skip(str, id_ptr);
	len = ft_strlen(id_ptr);
	if (ft_strncmp(CEILLING_COLOR, id_ptr, len) == 0)
		return (assign_color_value(data->ceilling, str, id_ptr));
	else if (ft_strncmp(FLOOR_COLOR, id_ptr, len) == 0)
		return (assign_color_value(data->ceilling, str, id_ptr));
	return (0);
}

int	define_color_values(t_data *data, int i)
{
	char	*str;
	char	*id_ptr;

	str = data->map_file->content[i];
	skip(&str, NULL);
	if (check_id(str, CEILLING_COLOR, &id_ptr)
		&& check_id(str, FLOOR_COLOR, &id_ptr))
		return (error_msg_return_1(ERROR_COLOR_ID, str));
	if (define_color_value(data, &str, id_ptr))
		return (1);
	return (0);
}

int define_color(t_data *data, int *i)
{
	int	defined_amount;

	defined_amount = DEFINED_NONE;
	while (data->map_file->content[*i] && defined_amount < DEFINED_COLOR)
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		if (define_color_values(data, *i))
			return (1);
		defined_amount++;
		*i += 1;
	}
	if (defined_amount != DEFINED_COLOR)
		return (error_define_amount(ERROR_COLOR_AMOUNT, defined_amount));
	return(0);
}
