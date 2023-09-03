/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_close_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:55:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/03 17:57:04 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_fd(int fd)
{
	if (close(fd) == -1)
		return (error_msg_return_1(strerror(errno), NULL));
	return (0);
}

void	close_data_fd(t_data *data)
{
	if (data->north_fd != -1)
		close_fd(data->north_fd);
	if (data->south_fd != -1)
		close_fd(data->south_fd);
	if (data->east_fd != -1)
		close_fd(data->east_fd);
	if (data->west_fd != -1)
		close_fd(data->west_fd);
}
