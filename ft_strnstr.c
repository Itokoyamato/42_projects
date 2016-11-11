/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:21:27 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/11 16:36:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[start] && n > start)
	{
		if (s1[start + i] == s2[i] && start + i < n)
			i++;
		else
		{
			i = 0;
			start++;
		}
		if (!s2[i])
			return ((char *)s1 + start);
	}
	return (0);
}
