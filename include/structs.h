/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:02:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 05:32:35 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_rgb
{
	R,
	G,
	B
};

enum e_define_status
{
	DEFINED_NONE = 0,
	DEFINED_COLOR = 2,
	DEFINED_TEXTURE = 4
};

enum e_player_orient
{
	E_NORTH = 1,
	E_SOUTH = 2,
	E_EAST = 3,
	E_WEST = 4
};

typedef struct s_color
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	hex;
}	t_color;

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_orient;
	char	**map_array;
}	t_map;

typedef struct s_file
{
	int		fd;
	int		defined_color;
	int		defined_texture;
	char	*line;
	char	**content;
}	t_file;

typedef struct s_data
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	t_color	*ceilling;
	t_color	*floor;
	t_file	*map_file;
	t_map	*map;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	int		clr_ceilling;
	int		clr_floor;
}	t_game;

#endif
