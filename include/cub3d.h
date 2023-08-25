/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:17:57 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 12:32:55 by jgoldste         ###   ########.fr       */
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

// --- Parcer ---
// parse.c
t_data	*parse(int argc, char **argv);
// t_data	*parse(int argc, char **argv, t_data *t_data);
t_data	*init_data(char **file_content);
// t_data	*init_data(void);

// check_args.c
int		check_args(int argc, char **argv);
int		check_file_ext(char* file_name);

// read_file.c
char	**read_file(char *file_name);
char	**push_back(char **array, char *str);
int		array_size(char **array);

// free_utils.c
void	free_null(void **str);
void 	free_null_ptr(void **ptr);
void	free_array(void **array);

// free_struct_utils.c
void	free_map(t_map *map);
void	free_data(t_data *data);

// error.c
int		error_msg_1(char *error_msg);
void	*error_msg_null(void *error_msg);
void	close_check(int fd);

// --- Game ---
// game.c
void	check_game_dir(void);

#endif
