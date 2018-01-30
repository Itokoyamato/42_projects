/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:02:44 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/10 11:48:46 by llaporte         ###   ########.fr       */
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
			++size;
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
