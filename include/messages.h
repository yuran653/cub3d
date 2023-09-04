/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:41:05 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/04 18:52:16 by jgoldste         ###   ########.fr       */
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
# define ERROR_TEXTURE_DEF "failed to initialize the texture: already defined"
# define ERROR_COLOR "failed to initialize the colors"
# define ERROR_COLOR_DEF "failed to initialize the color: already defined"
# define ERROR_COLOR_AMOUNT "failed to initialize the color: \
wrong amount of values"
# define ERROR_COLOR_VALUE "failed to initialize the color: error color value"
# define ERROR_MAP "failed to initialize the map"
# define ERROR_MAP_SIZE "map size is too small"
# define ERROR_MAP_EMPTY_LINE "map has empty line"
# define ERROR_MAP_SYMBOL "failed to initialize the map: undefined map symbol"
# define ERROR_MAP_NOT_CLOSED "failed to initialize the map: map is not closed"
# define ERROR_MAP_NO_PLAYER "no player on the map"
# define ERROR_PLAYER_AMOUNT "failed to initialize the map:\
more than one player"
# define ERROR_PLAYER_INSIDE "failed to initialize the map:\
player should be inside the map"

#endif
