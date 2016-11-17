/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:04:35 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 16:38:54 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	size_t	j;
	t_byte	*sb1;
	t_byte	*sb2;

	if (!n)
		return (0);
	i = 0;
	j = 1;
	sb1 = (t_byte *)s1;
	sb2 = (t_byte *)s2;
	while (sb1[i] == sb2[i] && j++ < n)
		i++;
	return (sb1[i] - sb2[i]);
}
