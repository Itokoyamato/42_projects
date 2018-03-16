/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:10:32 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/14 13:36:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_a(int n)
{
	if (n < 0)
		return (ft_nbdigit(n * -1) + 1);
	return (ft_nbdigit(n));
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	char			*result;
	int				i;

	i = size_a(n);
	result = (char *)ft_strnew(i);
	if (!result)
		return (0);
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (i--)
	{
		result[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
