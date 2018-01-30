/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:14:54 by llaporte          #+#    #+#             */
/*   Updated: 2017/01/09 14:33:38 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	if (s[i] == (char)c)
		return ((char *)s + i);
	if (!s[i - 1])
		return (0);
	--i;
	while (i && s[i] && s[i] != (char)c)
		--i;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
