/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:14:54 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/14 10:48:35 by llaporte         ###   ########.fr       */
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
	--i;
	while (s[i] && s[i] != (char)c)
		--i;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
