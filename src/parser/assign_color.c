/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:28:03 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 14:21:50 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_color_value(t_data *data, int *color, char *value)
{
	*color = ft_atoi(value);
	if (*color < 0 || *color > 255)
		error_msg_exit_fail(data, ERROR_COLOR_VALUE, value);
}

void	assign_color_value(t_data *data, t_color *color, char *value)
{
	if (color->rgb == R)
		set_color_value(data, &color->r, value);
	else if (color->rgb == G)
		set_color_value(data, &color->g, value);
	else if (color->rgb == B)
		set_color_value(data, &color->b, value);
}
