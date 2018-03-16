/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:17:17 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 14:27:40 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		index;
	int		index2;
	int		character;

	index = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[index] != '\0')
	{
		index2 = index;
		character = 0;
		while (s1[index2] == s2[character])
		{
			index2++;
			character++;
			if (s2[character] == '\0')
				return ((char *)&s1[index]);
		}
		index++;
	}
	return (0);
}
