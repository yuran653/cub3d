/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:03 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/29 19:01:13 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int define_color(t_data *data, int *i)
{
	int	define_status;

	define_status = DEFINED_NONE;
	while (data->map_file->content[*i] && define_status < DEFINED_COLOR)
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		printf("->%s", data->map_file->content[*i]);
		define_status++;
		*i += 1;
	}
	if (define_status != DEFINED_COLOR)
		return (1);
	return(0);
}
