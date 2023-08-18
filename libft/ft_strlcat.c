/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 23:08:55 by jgoldste          #+#    #+#             */
/*   Updated: 2021/10/14 23:09:03 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_s;
	size_t	src_s;
	size_t	count;

	dst_s = 0;
	src_s = 0;
	count = 0;
	while (*dst != '\0' && dst_s < dstsize)
	{
		dst++;
		dst_s++;
	}
	while (src[src_s] != '\0')
		src_s++;
	if (dst_s >= dstsize)
		return (dstsize + src_s);
	else
		while (dst_s + 1 + count++ < dstsize && *src != '\0')
			*dst++ = *src++;
	*dst = '\0';
	return (dst_s + src_s);
}
