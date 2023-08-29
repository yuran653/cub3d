/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:00:49 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/29 19:04:11 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int define_map(t_data *data, int *i)
{
	while (is_empty_line(data->map_file->content[*i]))
		*i += 1;
	while (data->map_file->content[*i])
	{
		if (is_empty_line(data->map_file->content[*i]))
			return (1);
		printf("->%s", data->map_file->content[*i]);
		*i += 1;
	}
	return(0);
}
