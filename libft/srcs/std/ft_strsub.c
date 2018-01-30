/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: technowix <technowix@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:49:58 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/30 11:42:55 by technowix        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(result = (char *)ft_strnew(len)))
			return (0);
		while (i < len)
			result[i++] = s[start++];
		return (result);
	}
	return (0);
}
