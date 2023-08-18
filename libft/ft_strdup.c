/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:32:13 by jgoldste          #+#    #+#             */
/*   Updated: 2021/10/17 03:32:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
