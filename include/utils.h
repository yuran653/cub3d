/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:22:25 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/10 18:26:23 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

// utils.c
int		array_size(char **array);

// free_utils.c
char	**free_array(char **array);
t_data	*free_data(t_data *data);
// t_game	*free_game(t_game *game);

// free_data_utils.c
t_file	*free_file(t_file *file);
t_map	*free_map(t_map *map);
t_color	*free_color(t_color *color);
// void	free_data_file(t_data *data);
// void	free_data_map(t_data *data);
// void	free_data_color(t_data *data);

// error.c
void	*error_msg_return_null(char *error_msg, char *error_arg);
int		error_msg_return_1(char *error_msg, char *error_arg);
void	print_error_msg(char *error_msg, char *error_arg);
void	print_error_arg(char *error_arg);

// error_exit.c
void	error_data_exit_fail(t_data *data, char *error_msg, char *error_arg);

#endif
