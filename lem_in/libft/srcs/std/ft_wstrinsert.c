/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 16:12:58 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/27 15:01:50 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrinsert(wchar_t const *s1, wchar_t const *s2, int where)
{
	wchar_t	*result;
	int		i;
	int		j;
	int		k;

	if (!(result = (wchar_t *)ft_strnew(ft_wstrlen(s1) + ft_wstrlen(s2))))
		return (0);
	i = 0;
	j = 0;
	while (s1[j] && i != where)
		result[i++] = s1[j++];
	k = 0;
	while (s2[k])
		result[i++] = s2[k++];
	while (s1[j])
		result[i++] = s1[j++];
	return (result);
}
