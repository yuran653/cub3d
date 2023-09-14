/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:02:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/14 19:07:24 by jgoldste         ###   ########.fr       */
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
	E_NORTH = 270,
	E_SOUTH = 90,
	E_EAST = 0,
	E_WEST = 180
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
	double	player_x;
	double	player_y;
	double	player_orient;
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

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_values
{
	int		half_scr_width;
	int		half_src_height;
	int		half_fov;
	double	inc_angle;
	double	precision;
}	t_values;

typedef struct s_game
{
	t_data		*data;
	t_values	*values;
	t_mlx		*mlx_data;
	int			lineNum;
	int			x;
	int			y;
	double		rayXd;
	double		rayYd;
	double		rayCos;
	double		raySin;
	double		distance;
	double		rayAngle;
	int			wallHeight;
}	t_game;

#endif
