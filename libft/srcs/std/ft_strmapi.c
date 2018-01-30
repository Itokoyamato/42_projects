/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:30:56 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 17:23:30 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	if (s)
	{
		result = ft_memalloc(ft_strlen(s) + 1);
		if (result)
		{
			while (s[i])
			{
				result[i] = f(i, s[i]);
				++i;
			}
			result[i] = '\0';
			return (result);
		}
	}
	return (0);
}
