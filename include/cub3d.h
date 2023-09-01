/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:57 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/02 01:02:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "constants.h"
# include "messages.h"
# include "structs.h"
# include "../libft/libft.h"
# include "../mini_libx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// --- Parser ---
// parse.c
t_data	*parse(int argc, char **argv);
int		check_args(int argc, char **argv);

// ---init.c---
t_file	*init_file(void);
t_data	*init_data(void);
t_map	*init_map(void);
t_color	*init_color(void);
void	close_data_fd(t_data *data);

// read_map.c
int		read_map(char *file_name, t_data *data);
int		open_map(char *file_name, t_data *data);
int		read_line_error(t_data *data);
char	**push_back(char **array, char *line);
int		error_push_back(t_data *data, int errno_malloc);

// parse_map_file.c
void	parse_map_file(t_data *data);
void	define_texture_color(t_data *data, int *i);
int		check_id_color(char *str);
int		check_id_texture(char *str);
int		check_id(char *str, char *id);

// define_texture.c
void	define_texture_value(t_data *data, char **str);
void	assign_texture_value(t_data *data, int *fd, char **path, char **str);

// define_color.c
void	define_color_value(t_data *data, char **str);
// int		define_color(t_data *data, int *i);
// int		define_color_value(t_data *data, char **str, char *id_ptr, int *def_clr);

// define_map.c
// int		define_map(t_data *data, int *i);

// utils.c
int		check_file_ext(char *file_name, char *file_ext);
int		array_size(char **array);
int		close_fd(int fd);
int		is_empty_line(char *line);
void	skip_str(char **str, char *skip);

// free_utils.c
char	**free_array(char **array);
t_data	*free_data(t_data *data);
void	free_data_file(t_data *data);
void	free_data_map(t_data *data);
void	free_data_color(t_data *data);

// error.c
void	*error_msg_return_null(char *error_msg, char *error_arg);
int		error_msg_return_1(char *error_msg, char *error_arg);
void	error_msg_exit_fail(t_data *data, char *error_msg, char *error_arg);
void	print_error_msg(char *error_msg, char *error_arg);
void	print_error_arg(char *error_arg);

// --- Game ---
// game.c
void	check_game_dir(t_data *data);

#endif
