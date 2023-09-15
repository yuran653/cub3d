/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:10:36 by jgoldste          #+#    #+#             */
/*   Updated: 2023/09/16 00:10:55 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**init_array_null(int size)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i <= size)
		array[i++] = NULL;
	return (array);
}
