/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:21:28 by jgoldste          #+#    #+#             */
/*   Updated: 2021/10/08 18:21:33 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dstsize > 1 && *src != '\0')
	{
		i++;
		dstsize--;
		*dst++ = *src++;
	}
	if (dstsize > 0)
		*dst = '\0';
	while (*src++ != '\0')
		i++;
	return (i);
}
