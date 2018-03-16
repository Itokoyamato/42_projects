/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:17:22 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/13 16:19:27 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Borrowed from Thog <3
*/

#include "libft.h"

char			*ft_itoa_base(intmax_t value, int base)
{
	char		*result;
	int			size;
	int			sign;

	if (!value)
		return (ft_strdup("0"));
	sign = value > 0 ? 1 : -1;
	size = ft_nbrlen(value, base) + (sign == -1 && base == 10);
	if (!(result = ft_strnew(sizeof(char) * (size))))
		return (NULL);
	result += size;
	while (value)
	{
		*--result = BASE16[(value % base) * sign];
		value /= base;
	}
	if (sign == -1 && base == 10)
		*--result = '-';
	return (result);
}
