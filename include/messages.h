/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:41:05 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/03 17:33:40 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define ERROR_MSG "\e[1;31mERROR:\e[0m "
# define ERROR_ARGS "wrong number of arguments"
# define ERROR_EXT "wrong file extension"
# define EMPTY_FILE "the file is empty"
# define ERROR_ID "wrong color/texture identifier"
# define ERROR_DEFINED_AMOUNT "wrong amount of color/texture identifiers"
# define ERROR_TEXTURE "failed to initialize the texture"
# define ERROR_TEXTURE_EXT "wrong texture file extension"
# define ERROR_TEXTURE_DEF "failed to initialize the texture. Already defined"
# define ERROR_COLOR "failed to initialize the colors"
# define ERROR_COLOR_DEF "failed to initialize the color. Already defined"
# define ERROR_COLOR_AMOUNT "failed to initialize the color. \
Wrong amount of values"
# define ERROR_COLOR_VALUE "failed to initialize the color. Error color value"
# define ERROR_MAP "failed to initialize the map"
# define ERROR_MAP_SIZE "failed to initialize the map. Map size is too small"
# define ERROR_MAP_EMPTY_LINE "failed to initialize the map. Map has empty line"

#endif
