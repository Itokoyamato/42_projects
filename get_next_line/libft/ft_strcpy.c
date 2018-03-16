/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:42:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 11:01:16 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (dest[i] != '\0')
			{
				dest[i] = '\0';
				i++;
			}
			return (dest);
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
