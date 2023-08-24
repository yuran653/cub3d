/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/24 17:13:18 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(int argc, char **argv)
// {
// 	t_data	*data;

// 	argc = 2;
// 	argv[1] = ft_strdup("maps/subject_map.cub");

// 	if (check_args(argc, argv))
// 		return (1);
// 	data = parse(argc, argv, data);
// 	if (!data)
// 		return (1);
// 	check_game_dir();
// 	printf("Map check: started\n");
// 	for (int i = 0; data->map->map_array[i]; i++)
// 		printf("%s", data->map->map_array[i]);
// 	printf("Map check: finished\n");
// 	free_data(data);

// 	free_null(argv[1]);

// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data	*data;

	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");

	data = parse(argc, argv);
	if (!data)
		return (1);
	check_game_dir();
	printf("Map check: started\n");
	for (int i = 0; data->map->map_array[i]; i++)
		printf("%s", data->map->map_array[i]);
	printf("Map check: finished\n");
	free_data(data);

	free_null(argv[1]);

	return (0);
}
