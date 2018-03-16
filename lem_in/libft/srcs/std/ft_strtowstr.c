/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtowstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:16:38 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/27 15:00:41 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strtowstr(char *str)
{
	wchar_t		*wstr;
	int			i;

	if (!(wstr = (wchar_t *)ft_strnew(ft_strlen(str) * sizeof(wchar_t))))
		return (0);
	i = 0;
	if (str)
		while (str[i])
		{
			wstr[i] = ft_ctowc(str[i]);
			++i;
		}
	return (wstr);
}
