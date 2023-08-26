/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:37:17 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/26 17:45:45 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_ext(char *file_name)
{
	int	ext_len;
	int	index;

	ext_len = ft_strlen(FILE_EXT);
	index = ft_strlen(file_name) - ext_len;
	if (index < 0 || ft_strncmp(FILE_EXT, &file_name[index], ext_len + 1))
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg_1(ERROR_ARGS));
	if (check_file_ext(argv[1]))
		return (error_msg_1(ERROR_EXT));
	return (0);
}
