/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:47:35 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/07 12:11:41 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*result;

	result = dst;
	if (dst < src)
		while ((size_t)(dst - result) < len)
			*(t_byte *)dst++ = *(t_byte *)src++;
	else
		while (len--)
			((t_byte *)dst)[len] = ((t_byte *)src)[len];
	return (result);
}
