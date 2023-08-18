/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:40:39 by jgoldste          #+#    #+#             */
/*   Updated: 2021/10/08 14:40:42 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_r;

	dst_r = (void *)dst;
	if (!dst && !src)
		return (dst_r);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (dst_r);
}
