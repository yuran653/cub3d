/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:42:47 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/13 19:43:45 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define NAME "Cub3D"
# define WIDTH 1280
# define HALF_WIDTH 640 // (WIDTH / 2)
# define HEIGHT 720
# define HALF_HEIGHT 360 // (HEIGHT / 2)
# define ANGLE 0 // !!! to be changed to 'player_orientation' !!!
# define FOV 66
# define HALF_FOV 33 // (FOV / 2)
# define INC_ANGLE 0.0515625 // (FOV / WIDTH)
# define PRECISION 64

# define SPACE_SIGN 32
# define DELIMITER 44
# define NEW_LINE "\n"
# define NEW_LINE_SIGN 10
# define END_LINE_SIGN 0
# define MAP_EXT ".cub"
# define MAP_MIN_SIZE 3
# define COLOR_LEN 2
# define COLOR_AMOUNT 2
# define COLOR_CEILLING "C "
# define COLOR_FLOOR "F "
# define TEXTURE_EXT ".xpm"
# define TEXTURE_LEN 3
# define TEXTURE_AMOUNT 4
# define TEXTURE_NORTH "NO "
# define TEXTURE_SOUTH "SO "
# define TEXTURE_EAST "EA "
# define TEXTURE_WEST "WE "
# define P_NORTH 78
# define P_SOUTH 83
# define P_EAST 69
# define P_WEST 87
# define M_WALL 49
# define M_SPACE 48

#endif
