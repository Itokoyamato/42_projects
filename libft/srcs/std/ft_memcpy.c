/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:14:59 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/10 11:43:56 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;
	t_byte *ptr;

	i = 0;
	ptr = dst;
	while (i++ < n)
		*(t_byte *)dst++ = *(t_byte *)src++;
	return (ptr);
}
