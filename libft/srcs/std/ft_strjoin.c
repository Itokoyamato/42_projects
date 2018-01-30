/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:39:16 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/10 14:53:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		sz1;
	int		sz2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		sz1 = ft_strlen(s1);
		sz2 = ft_strlen(s2);
		if (!(result = (char *)ft_strnew(sz1 + sz2)))
			return (0);
		while (j < sz1)
			result[i++] = s1[j++];
		j = 0;
		while (j < sz2)
			result[i++] = s2[j++];
		return (result);
	}
	return (0);
}
