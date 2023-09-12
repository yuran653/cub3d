/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 05:42:42 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 00:49:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"

// parse.c
t_data	*parse(int argc, char **argv);
int		check_args(int argc, char **argv);

// ---init.c---
t_file	*init_file(void);
t_data	*init_data(void);
t_map	*init_map(void);
t_color	*init_color(void);
char	**init_array_null(int size);

// read_map.c
int		read_map(char *file_name, t_data *data);
int		open_map(char *file_name, t_data *data);
int		read_line_error(t_data *data);
char	**push_back(char **array, char *line);
int		error_push_back(t_data *data, int errno_malloc);

// parse_map_file.c
void	parse_map_file(t_data *data);
void	define_color_texture(t_data *data, int *i);
int		check_id_color(char *str);
int		check_id_texture(char *str);
int		check_id(char *str, char *id);

// define_texture.c
void	define_texture_value(t_data *data, char *str);
void	assign_texture_value(t_data *data, char **path, char *str);

// define_color.c
void	define_color_value(t_data *data, char *value);
void	parse_color_value(t_data *data, t_color *color, char *value);
void	set_value_end(char *value, int *i);
void	set_rgb_amount(t_data *data, t_color *color, char *value);
void	is_digit_space(t_data *data, char *value);

// assign_color.c
void	assign_color_value(t_data *data, t_color *color, char *value);
void	set_color_value(t_data *data, int *color, char *value);
void	convert_to_hex(t_color *color);

// define_map.c
void	define_map(t_data *data, int *i);
void	skip_empty_line(char **array, int *i);
void	copy_map(t_map *dst, t_file *src, int *i);
void	trim_empty_line(t_data *data, char **array, int size);
void	check_map_empty_line(t_data *data);

// check_map,c
void	check_map_valid_data(t_data *data);
void	chech_map_valid_symbol(t_data *data, int i, int j);
void	check_map_is_closed(t_data *data, int i, int j);
void	check_set_player(t_data *data, int orient, int i, int j);

// check_map_utils.c
void	trim_space_end(char **map_array, int i);
int		check_symbol_inside(t_data *data, int i, int j);

// parser_utils.c
int		check_file_ext(char *file_name, char *file_ext);
int		is_empty_line(char *line);
void	skip_str(char **str, char *skip);
int		close_fd(int fd);

#endif
