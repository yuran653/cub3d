/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:37:17 by jgoldste          #+#    #+#             */
/*   Updated: 2023/08/18 23:12:13 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (invalid_argc());
	for (int i = 1; i < argc; i++)
		printf("%s", argv[i]);
	return (0);
}
