/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:30:18 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/07 12:44:34 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if ((*(t_byte *)s1 != *(t_byte *)s2))
			return (*(t_byte *)s1 - *(t_byte *)s2);
		s1++;
		s2++;
	}
	return (0);
}
