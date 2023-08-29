/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:01:16 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/29 19:44:04 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	define_texture_path(t_data *data, int i)
{
	printf("->%s", data->map_file->content[i]);
	return (0);
}

int	define_texture(t_data *data, int *i)
{
	int		define_status;
	char	*define_amount;

	define_status = DEFINED_NONE;
	while (data->map_file->content[*i] && define_status < DEFINED_TEXTURE)
	{
		while (is_empty_line(data->map_file->content[*i]))
			*i += 1;
		if (define_texture_path(data, *i))
			return (1);
		define_status++;
		*i += 1;
	}
	if (define_status != DEFINED_TEXTURE)
	{
		define_amount = ft_itoa(define_status);
		if (!define_amount)
			return (1); //!!!!
		print_error_msg(ERROR_MSG, ERROR_TEXTURE_AMOUNT, define_amount);
		free(define_amount);
		return (1);
	}
	return(0);
}
