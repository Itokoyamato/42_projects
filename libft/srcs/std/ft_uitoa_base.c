/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:46:24 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/13 17:46:21 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(uintmax_t value, int base)
{
	char		*result;
	char		*ptr;
	int			size;

	if (!value)
		return (ft_strdup("0"));
	size = ft_unbrlen(value, base);
	if (!(result = ft_strnew(sizeof(char) * (size))))
		return (NULL);
	ptr = result;
	result += size;
	while (value)
	{
		*--result = BASE16[(value % base)];
		value /= base;
	}
	return (ptr);
}
