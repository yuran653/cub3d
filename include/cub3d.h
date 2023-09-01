/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:57 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/01 01:22:27 by jgoldste         ###   ########.fr       */
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

// read_map.c
int		read_map(char *file_name, t_data *data);
int		open_map(char *file_name, t_data *data);
int		read_line_error(t_data *data);
char	**push_back(char **array, char *line);

// parse_map_file.c
int		parse_map_file(t_data *data);

int		check_id(char *str, char *id, char **id_ptr);

// define_texture.c
int		define_texture(t_data *data, int *i);
int		define_texture_path(t_data *data, int i);
int		define_texture_value(t_data *data, char **str, char *id_ptr);
int		assign_texture_value(char **data_path, char **str, char *id_ptr);

// define_color.c
int		define_color(t_data *data, int *i);

// define_map.c
int		define_map(t_data *data, int *i);

// utils.c
int		array_size(char **array);
int		close_fd(int fd);
int		is_empty_line(char *line);
void	skip(char **str, char *skip);

// utils_file.c
int		check_file_ext(char *file_name, char *file_ext);

// free_utils.c
char	**free_array(char **array);

// free_utils_struct.c
t_data	*free_data(t_data *data);
void	free_data_file(t_data *data);
void	free_data_map(t_data *data);
void	free_data_color(t_data *data);

// error.c
int		error_msg_return_1(char *error_msg, char *error_arg);
void	*error_msg_return_null(char *error_msg, char *error_arg);
void	print_error_msg(char *error_msg, char *error_arg);
void	print_error_arg(char *error_arg);
int		error_define_amount(char *error_arg, int defined_amount);

// --- Game ---
// game.c
void	check_game_dir(t_data *data);

#endif
