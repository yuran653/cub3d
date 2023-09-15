/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 06:05:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_texture(t_game *game)
{
	int	i;

	i = -1;
	while (game->map->texture_path[++i])
	{
		game->map->texture[i].img_ptr
			= mlx_xpm_file_to_image(game->mlx_data->mlx_ptr,
				game->map->texture_path[i],
				&game->map->texture[i].width, &game->map->texture[i].height);
		if (!game->map->texture[i].img_ptr)
			error_game_exit_fail(game, strerror(errno), ERROR_TEXTURE); // !!! LEAKS !!!
	}
	i = -1;
	while (++i < TEXTURE_AMOUNT)
	{
		game->map->texture[i].addr
			= mlx_get_data_addr(game->map->texture[i].img_ptr,
				&game->map->texture[i].bits_per_pixel,
				&game->map->texture[i].line_length,
				&game->map->texture[i].endian);
		if (!game->map->texture[i].addr)
			error_game_exit_fail(game, strerror(errno), ERROR_TEXTURE); // !!! LEAKS !!!
	}
	i = -1;
	while (++i < TEXTURE_AMOUNT)
		printf("ADDRESS[%p]->IMG[%p]->WIDTH[%d]->HEIGHT[%d]->BBP[%d]->LINE_LEN[%d]->ENDIAN[%d]\n",
			game->map->texture[i].addr,
			game->map->texture[i].img_ptr,
			game->map->texture[i].width, game->map->texture[i].height,
			game->map->texture[i].bits_per_pixel, game->map->texture[i].line_length,
			game->map->texture[i].endian);
}

// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

// Gets the memory address of the given image. Memory of images is weird.
// It will set the line size in your given pointer. To get or set the value of the
// pixel (5, 100) in an image size of (500, 500), we would need to locate
// the position as follows:

// int pos = (y * size_line + x * (bits_per_pixel / 8));

// Here we multiply size_line by y as we need to skip y lines (and yes, line size is
// not equal to the amount of pixels in a line). We then add the remaining x units
// multiplied by bits_per_pixel / 8 to align with the final location.

// To modify each pixel with the correct color, we need to do some more fancy stuff.
// As we need to align the bits before writing, we need to do the following for
// the best result:

// char *mlx_data_addr = mlx_get_data_addr();
// *(unsigned int *)mlx_data_addr = color;

// The function prototype is as follows:

// /*
// ** Gets the data address of the current image.
// **
// ** @param	void *img_ptr			the image instance;
// ** @param	int  *bits_per_pixel	a pointer to where the bpp is written;
// ** @param	int  *size_line		a pointer to where the line is written;
// ** @param	int  *endian		a pointer to where the endian is written;
// ** @return	char*				the memory address of the image.
// */
// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);


void	init_mlx_data(t_game *game)
{
	game->mlx_data = (t_mlx *)malloc(sizeof(t_mlx));
	if (!game->mlx_data)
		error_game_exit_fail(game, strerror(errno), ERROR_GAME);
	game->mlx_data->mlx_ptr = mlx_init();
	game->mlx_data->win_ptr = mlx_new_window(game->mlx_data->mlx_ptr,
		WIDTH, HEIGHT, NAME);
	game->mlx_data->img = mlx_new_image(game->mlx_data->mlx_ptr, WIDTH, HEIGHT);
	game->mlx_data->addr = mlx_get_data_addr(game->mlx_data->img,
			&game->mlx_data->bits_per_pixel, &game->mlx_data->line_length,
			&game->mlx_data->endian);
}

void	init_values(t_game *game)
{
	game->values = (t_values *)malloc(sizeof(t_values));
	if (!game->values)
		error_game_exit_fail(game, strerror(errno), ERROR_GAME);
	game->values->half_scr_width = WIDTH / 2;
	game->values->half_src_height = HEIGHT / 2;
	game->values->half_fov = FOV / 2;
	game->values->inc_angle = (double)FOV / (double)WIDTH;
	game->values->precision = (double)PRECISION;
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error_map_exit_fail(map, strerror(errno), ERROR_GAME);
	game->map = map;
	game->values = NULL;
	game->mlx_data = NULL;
	init_values(game);
	init_mlx_data(game); // !!! LEAKS AFTER THIS !!!
	open_texture(game);
	return (game);
}
