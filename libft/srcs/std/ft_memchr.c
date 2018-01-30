/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:48:32 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/09 16:56:17 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*ptr;
	size_t	i;

	ptr = (t_byte *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (t_byte)c)
			return (ptr + i);
		i++;
	}
	return (0);
}
