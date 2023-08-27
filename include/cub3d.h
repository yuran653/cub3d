/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:57 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/27 18:00:46 by jgoldste         ###   ########.fr       */
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

// parse_map.c
int		parse_map(t_data *data);
// int		define_texture(t_data *data);

// utils.c
int		check_file_ext(char *file_name, char *file_ext);
int		array_size(char **array);
int		close_fd(int fd);

// free_utils.c
char	**free_array(char **array);

// free_utils_struct.c
t_data	*free_data(t_data *data);
void	free_data_file(t_data *data);
void	free_data_map(t_data *data);
void	free_data_color(t_data *data);

// error.c
int		error_msg_1(char *error_msg, char *error_arg);
void	*error_msg_null(char *error_msg, char *error_arg);
void	print_error_msg(char *error_msg, char *error_arg);

// --- Game ---
// game.c
void	check_game_dir(void);

#endif
