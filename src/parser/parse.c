/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:10 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/03 14:05:30 by jgoldste         ###   ########.fr       */
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

t_data	*parse(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv))
		return (NULL);
	data = init_data();
	if (!data)
		return (error_msg_return_null(strerror(errno), NULL));
	if (read_map(argv[1], data))
		return (free_data(data));
	parse_map_file(data);
	return (data);
}
