/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:42:10 by jgoldste          #+#    #+#             */
/*   Updated: 2021/10/08 14:42:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dst_r;

	dst_r = (void *)dst;
	if (!dst && !src)
		return (dst_r);
	else if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
		while (len--)
			*(char *)dst++ = *(char *)src++;
	return (dst_r);
}
