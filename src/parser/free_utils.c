/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:14:09 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/25 12:30:44 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_null(void *var)
{
	if (var)
		free(var);
	var = NULL;
}

void 	free_null_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_array(void **array)
{
	int	i;

	i = 0;
	if (array)
		while (array[i])
			free_null_ptr((void*)&array[i++]);
	free_null_ptr((void*)&array);
}
