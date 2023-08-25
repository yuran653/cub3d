/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 17:40:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	// argc = 2;
	// argv[1] = ft_strdup("maps/subject_map.cub");

	data = parse(argc, argv);
	if (!data)
		return (1);

	check_game_dir();
	free_data(data);
	data = NULL;

	// free(argv[1]);
	// argv[1] = NULL;

	return (0);
}
