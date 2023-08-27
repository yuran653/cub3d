/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:10 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/27 14:22:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*parse(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (NULL);
	data = init_data();
	if (!data)
		return (NULL);
	if (read_file(argv[1], data))
		return (free_data(data));
	return (data);
}
