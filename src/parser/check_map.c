/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:20:37 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 18:52:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_set_player(t_data *data, int orient, int i, int j)
{
	if (data->map->player_orient != -1)
		error_msg_exit_fail(data, ERROR_PLAYER_AMOUNT, data->map->map_array[i]);
	if (check_symbol_inside(data, i, j))
		error_msg_exit_fail(data, ERROR_PLAYER_INSIDE, data->map->map_array[i]);
	data->map->player_orient = orient;
	data->map->player_x = j;
	data->map->player_y = i;
}

void	check_map_is_closed(t_data *data, int i, int j)
{
	if (check_symbol_inside(data, i, j))
		error_msg_exit_fail
			(data, ERROR_MAP_NOT_CLOSED, data->map->map_array[i]);
}

void	chech_map_valid_symbol(t_data *data, int i, int j)
{
	if (data->map->map_array[i][j] == SPACE_SIGN)
		;
	else if (data->map->map_array[i][j] == M_WALL)
		;
	else if (data->map->map_array[i][j] == M_SPACE)
		check_map_is_closed(data, i, j);
	else if (data->map->map_array[i][j] == P_NORTH)
		check_set_player(data, E_NORTH, i, j);
	else if (data->map->map_array[i][j] == P_SOUTH)
		check_set_player(data, E_SOUTH, i, j);
	else if (data->map->map_array[i][j] == P_EAST)
		check_set_player(data, E_EAST, i, j);
	else if (data->map->map_array[i][j] == P_WEST)
		check_set_player(data, E_WEST, i, j);
	else
		error_msg_exit_fail(data, ERROR_MAP_SYMBOL, data->map->map_array[i]);
}

void	check_map_valid_data(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map->map_array[++i])
	{
		trim_space_end(data->map->map_array, i);
		j = -1;
		while (data->map->map_array[i][++j])
			chech_map_valid_symbol(data, i, j);
		if (j > data->map->width)
			data->map->width = j;
		if (data->map->width < MAP_MIN_SIZE)
			error_msg_exit_fail(data, ERROR_MAP, ERROR_MAP_SIZE);
	}
	data->map->height = i;
	if (data->map->player_orient == -1)
		error_msg_exit_fail(data, ERROR_MAP, ERROR_MAP_NO_PLAYER);
}
