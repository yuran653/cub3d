/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 19:15:00 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	// ---easy_map---
	argc = 2;
	argv[1] = ft_strdup("maps/subject_map.cub");
	// --!easy_map---
	// ---parser---
	data = parse(argc, argv);
	if (!data)
		return (EXIT_FAILURE);
	// --!parser---
	// ---game---
	game(data);
	// --!game---
	// --free_easy_map---
	free(argv[1]);
	argv[1] = NULL;
	// --!free_easy_map---
	data = free_data(data);
	return (EXIT_SUCCESS);
}
