/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 02:45:57 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

// 	// ---easy_map---
	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");
// 	// --!easy_map---
// 	// ---parser---
	map = parse(argc, argv);
	if (!map)
		return (EXIT_FAILURE);
// 	// --!parser---
// 	// ---game---
	game = init_game(map);
	if (!game)
		return (EXIT_FAILURE);
	mlx_loop_hook(game->mlx_data->mlx_ptr, raycast, game);
	mlx_hook(game->mlx_data->win_ptr, 17, 0L, close_game_exit, game);
	mlx_hook(game->mlx_data->win_ptr, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx_data->mlx_ptr);
// 	// --!game---
// 	// --free_easy_map---
	free(argv[1]);
	argv[1] = NULL;
// 	// --!free_easy_map---
	game = free_game(game);
	return (EXIT_SUCCESS);
}
