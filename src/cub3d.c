/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/12 17:06:47 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map_data(t_data *data)
{
	if (data->map_file)
		printf("MAP FILE IS NOT CLEARED\n");
	else
		printf("MAP FILE IS CORRECTLY CLEARED\n");
	printf("--- DEFINED VALUES ---\n");
	printf("--NORTH->%s\n--SOUTH->%s\n---EAST->%s\n---WEST->%s\n",
		data->north_path, data->south_path, data->east_path, data->west_path);
	if (data->ceilling && data->floor)
	{
		printf("- CEILLING COLOR ->[%0.3d,%0.3d,%0.3d]->[%#X]\n",
			data->ceilling->r, data->ceilling->g, data->ceilling->b, data->ceilling->hex);
		printf("--- FLOOR COLOR -->[%0.3d,%0.3d,%0.3d]->[%#X]\n",
			data->floor->r, data->floor->g, data->floor->b, data->floor->hex);
	}
	else
		printf("COLORS VARIABLES ARE NOT ALLOCATED\n");
	if (data->map && data->map->map_array && data->map->map_array[0])
	{
		printf("--------- MAP ---------\n");
		for (int i = 0; data->map->map_array[i]; i++)
			printf("[%s]\n", data->map->map_array[i]);
		printf("--- MAP WIDTH ---> [%d]\n", data->map->width);
		printf("--- MAP HEIGHT --> [%d]\n", data->map->height);
		printf("--- PLAYER X ----> [%d]\n", data->map->player_x);
		printf("--- PLAYER Y ----> [%d]\n", data->map->player_y);
		printf("- PLAYER ORIENT -> [%d]\n", data->map->player_orient);
	}
	else
		printf("-- MAP IS NOT DEFINED --\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;

	// ---easy_map---
	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");
	// --!easy_map---
	// ---parser---
	data = parse(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	// --!parser---
	print_map_data(data);
	// ---game---
	game = init_game(data);
	if (!game)
		return (EXIT_FAILURE);
	mlx_loop_hook(game->mlx_ptr, recasting, game);
	mlx_hook(game->win_ptr, 17, 0L, close_game_exit, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx_ptr);
	// --!game---
	// --free_easy_map---
	free(argv[1]);
	argv[1] = NULL;
	// --!free_easy_map---
	game = free_game(game);
	return (EXIT_SUCCESS);
}
