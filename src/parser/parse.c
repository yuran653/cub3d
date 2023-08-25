/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:10 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 19:42:43 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data *parse(int argc, char **argv)
{
	t_file	*file;
	t_data	*data;

	if (check_args(argc, argv))
		return (NULL);
	file = init_file();
	if (!file)
		return (NULL);
	file->fd = open_file(argv[1]);

	read_file(argv[1], file);
	if (!file)
	{

	}
	data = init_data();
	if (!data)
		return (NULL);
	file_content = read_file(argv[1]);
	if (!file_content)
		return (NULL);
	if (file_content)
	{
		printf("Map check: started\n");
		for (int i = 0; file_content[i]; i++)
			printf("%s", file_content[i]);
		printf("Map check: finished\n");
	}
	free_array((void**)file_content);
	file_content = NULL;
	return (data);
}

// t_data *parse(int argc, char **argv)
// {
// 	char	**file_content;
// 	t_data	*data;

// 	if (check_args(argc, argv))
// 		return (NULL);
// 	data = init_data();
// 	if (!data)
// 		return (NULL);
// 	file_content = read_file(argv[1]);
// 	if (!file_content)
// 		return (NULL);
// 	if (file_content)
// 	{
// 		printf("Map check: started\n");
// 		for (int i = 0; file_content[i]; i++)
// 			printf("%s", file_content[i]);
// 		printf("Map check: finished\n");
// 	}
// 	free_array((void**)file_content);
// 	file_content = NULL;
// 	return (data);
// }