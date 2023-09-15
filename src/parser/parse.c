/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:10 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 02:46:43 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg_return_1(ERROR_ARGS, NULL));
	if (check_file_ext(argv[1], MAP_EXT))
		return (error_msg_return_1(ERROR_EXT, argv[1]));
	return (0);
}

t_map	*parse(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	if (check_args(argc, argv))
		return (NULL);
	data = init_data();
	if (!data)
		return (error_msg_return_null(strerror(errno), NULL));
	if (read_map(argv[1], data))
		return ((void *)free_data(data));
	parse_map_file(data);
	map = data->map;
	data->map = NULL;
	data = free_data(data);
	return (map);
}
