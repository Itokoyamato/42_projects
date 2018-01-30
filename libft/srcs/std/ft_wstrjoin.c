/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 18:16:43 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/27 15:01:47 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*result;
	int		sz1;
	int		sz2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		sz1 = ft_wstrlen(s1);
		sz2 = ft_wstrlen(s2);
		if (!(result = (wchar_t *)ft_strnew(sz1 + sz2)))
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
