/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:33:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/28 19:37:44 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	parse_map_file(t_data *data)
// {
// 	char	**content;
	
// 	content = data->map_file->content;
// 	while (*content)
// 		printf("->%s", *content++);
// 	return (1);
// }

// int	define_texture(t_data *data)
// {

// }

int is_empty_line(char *line)
{
	while (*line)
	{
		// if (ft_isprint(*line))
		// {
			printf("char[%c]->return_value[%d]\n", *line, ft_isprint(*line));
		// }
		line++;
	}
	return (0);
}


int	parse_map(t_data *data)
{
	char	**content;
	int i;

	content = data->map_file->content;
	i = 0;
	while (content[i])
	{
		content = &content[i];
		i = 0;
		while (content[i])
		{
			is_empty_line(content[i]);
			// printf("-->%s", content[i]);
			i++;
		}
	}
	// if (data)// !for test
	// {
	// 	if (data->map_file)
	// 	{
	// 		if (data->map_file->content)
	// 		{
	// 			printf("Map check: started\n");
	// 			for (int i = 0; data->map_file->content[i]; i++)
	// 				printf("%s", data->map_file->content[i]);
	// 			printf("Map check: finished\n");
	// 		}
	// 	}
	// }// !for test
	free_data_file(data);
	return (0);
}
