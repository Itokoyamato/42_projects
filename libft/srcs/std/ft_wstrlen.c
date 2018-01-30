/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:29:45 by technowix         #+#    #+#             */
/*   Updated: 2017/05/09 17:17:15 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t const *str)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			size++;
		else if (str[i] <= 0x7FF)
			size += 2;
		else if (str[i] <= 0xFFFF)
			size += 3;
		else if (str[i] <= 0x10FFFF)
			size += 4;
		i++;
	}
	return (size);
}
