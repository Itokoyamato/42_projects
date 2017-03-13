/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:16:10 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/08 14:17:34 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	int		size;
	int		j;

	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		size = 0;
		while (s[size + 1])
			size++;
		while (s[size] == ' ' || s[size] == '\n' || s[size] == '\t')
			size--;
		size++;
		result = ft_strnew(size);
		if (result)
		{
			j = -1;
			while (++j < size)
				result[j] = s[j];
			return (result);
		}
	}
	return (0);
}
