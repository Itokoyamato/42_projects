/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:20:09 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/08 13:49:13 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (src[len])
		len++;
	if ((str = malloc(len + 1)))
	{
		p = str;
		while (*src)
			*p++ = *src++;
		*p = '\0';
	}
	return (str);
}
