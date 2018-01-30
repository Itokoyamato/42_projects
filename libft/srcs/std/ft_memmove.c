/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:27:33 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/10 11:44:09 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ptr;

	ptr = dst;
	if (dst < src)
		while ((size_t)(dst - ptr) < len)
			*(t_byte *)dst++ = *(t_byte *)src++;
	else
		while (len--)
			((t_byte *)dst)[len] = ((t_byte *)src)[len];
	return (ptr);
}
