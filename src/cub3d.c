/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/30 18:58:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");
	// argv[1] = ft_strdup("maps/subject_map_no_empty_lines.cub");
	// argv[1] = ft_strdup("maps/subject_map_map_empty_line.cub");

	data = parse(argc, argv);
	if (!data)
		return (1);

	if (data)// !for test
	{
		if (data->map_file)
			printf("data->map_file->content: \e[1;31mIS NOT EMPTY\e[0m\n");
		// {
		// 	if (data->map_file->content)
		// 	{
		// 		printf("Map check: started\n");
		// 		for (int i = 0; data->map_file->content[i]; i++)
		// 			printf("<-%s", data->map_file->content[i]);
		// 		printf("Map check: finished\n");
		// 	}
		// }
		else
			printf("data->map_file->content: IS EMPTY\n");
	} // for test!

	check_game_dir();

	free(argv[1]);
	argv[1] = NULL;

	data = free_data(data);
	return (0);
}
