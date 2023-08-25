/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:02:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 17:36:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_file
// {
// 	char	*line;
// 	char	**file_content;
// }	t_file;

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_orient;
	char	**map_array;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int b;
}	t_color;

typedef struct s_data
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	t_map	*map;
	t_color	*color;
}	t_data;

#endif
