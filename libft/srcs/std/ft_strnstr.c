/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:06:23 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/10 11:48:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[0])
			while (big[i + j] && little[j] && big[i + j] == little[j]
					&& (i + j) < len)
				++j;
		if (little[j] == '\0')
			return ((char *)(big + i));
		++i;
	}
	return (0);
}
