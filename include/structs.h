/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:02:26 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 06:16:14 by jgoldste         ###   ########.fr       */
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

enum e_texture
{
	T_NORTH,
	T_SOUTH,
	T_EAST,
	T_WEST
};

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

typedef struct s_texture
{
	void	*img_ptr;
	void	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_map
{
	int			width; // количество символов в строке карты
	int			height; // количество строк в карте
	int			hex_ceilling;
	int			hex_floor;
	double		player_x; // позиция камеры по X
	double		player_y; // позиция камеры по Y
	double		player_orient; // направление камеры
	char		**map_array;
	char		**texture_path;
	t_texture	*texture;
}	t_map;

typedef struct s_game // теперь все в этой структуре
{
	t_map		*map;
	t_values	*values;
	t_mlx		*mlx_data;
	int			line_num; // норминет требует только маленькие буквы в названиях переменных
	int			x;
	int			y;
	double		ray_x;
	double		ray_y;
	double		ray_cos;
	double		ray_sin;
	double		distance;
	double		ray_angle;
	int			wall_height;
}	t_game;

typedef struct s_file
{
	int		fd;
	int		defined_color;
	int		defined_texture;
	char	*line;
	char	**content;
}	t_file;

typedef struct s_color
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	hex;
}	t_color;

typedef struct s_data
{
	t_color	*ceilling;
	t_color	*floor;
	t_file	*map_file;
	t_map	*map;
}	t_data;

#endif
