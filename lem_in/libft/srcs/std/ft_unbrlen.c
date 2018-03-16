/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:24:32 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 17:41:01 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unbrlen(uintmax_t value, int base)
{
	int	i;

	i = 0;
	if (!value)
		return (1);
	while (value)
	{
		i++;
		value /= base;
	}
	return (i);
}
