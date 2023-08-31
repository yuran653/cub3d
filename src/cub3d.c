/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/31 19:15:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	// ---easy_map---
	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");
	// argv[1] = ft_strdup("maps/subject_map_no_empty_lines.cub");
	// argv[1] = ft_strdup("maps/subject_map_map_empty_line.cub");
	// --!easy_map---
	// ---parser---
	data = parse(argc, argv);
	if (!data)
		return (1);
	// --!parser---
	// ---game---
	check_game_dir(data);
	// --!game---
	// --free_easy_map---
	free(argv[1]);
	argv[1] = NULL;
	// --!free_easy_map---
	data = free_data(data);
	return (0);
}
