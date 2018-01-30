/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:48:00 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/30 14:34:53 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
		++i;
	if (i == size)
		return (i + ft_strlen(src));
	j = i;
	while (i < size - 1 && src[i - j])
	{
		dst[i] = src[i - j];
		++i;
	}
	dst[i] = '\0';
	return (j + ft_strlen(src));
}
