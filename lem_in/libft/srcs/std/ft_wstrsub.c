/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:49:58 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/24 10:49:41 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t	*result;
	size_t	i;

	i = 0;
	if (s)
	{
		result = (wchar_t *)ft_strnew(len);
		if (result)
		{
			while (i < len)
				result[i++] = s[start++];
			return (result);
		}
	}
	return (0);
}
