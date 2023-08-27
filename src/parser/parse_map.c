/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/27 18:21:22 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int		define_texture(t_data *data)
// {

// }


int	parse_map(t_data *data)
{
	if (data)
	{
		if (data->map_file)
		{
			if (data->map_file->content)
			{
				printf("Map check: started\n");
				for (int i = 0; data->map_file->content[i]; i++)
					printf("%s", data->map_file->content[i]);
				printf("Map check: finished\n");
			}
		}
	}
	free_data_file(data);
	return (0);
}
