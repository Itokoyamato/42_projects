/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:33:37 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 12:08:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dst_size = i;
	while (src[i - dst_size] && i < size - 1)
	{
		dst[i] = src[i - dst_size];
		i++;
	}
	if (dst_size < size)
		dst[i] = '\0';
	return (dst_size + ft_strlen(src));
}
