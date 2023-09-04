/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:00:29 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 18:25:27 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_symbol_inside(t_data *data, int i, int j)
{
	return (data->map->map_array[i - 1][j] == SPACE_SIGN
		|| data->map->map_array[i][j - 1] == SPACE_SIGN
		|| data->map->map_array[i][j + 1] == SPACE_SIGN
		|| data->map->map_array[i + 1][j] == SPACE_SIGN);
}

int	check_map_borders(t_data *data, int i, int j)
{
	return (i == 0 || j == 0 || data->map->map_array[i + 1] == NULL
		|| data->map->map_array[i][j + 1] == NEW_LINE_SIGN
		|| data->map->map_array[i][j + 1] == END_LINE_SIGN);
}

void	trim_space_end(char **map_array, int i)
{
	int	len;

	len = ft_strlen(map_array[i]);
	while (map_array[i][--len] == SPACE_SIGN)
		map_array[i][len] = END_LINE_SIGN;
}
