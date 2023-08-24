/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:10 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/24 17:46:26 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *parse(int argc, char **argv)
{
	t_file	*file;
	t_data	*data;

	if (check_args(argc, argv))
		return (NULL);
	file = read_file(argv[1]);
	if (!file)
		return (NULL);
	data = init_data(file);
	return (data);
}