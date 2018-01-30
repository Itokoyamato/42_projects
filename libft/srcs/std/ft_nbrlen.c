/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:24:32 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 14:44:28 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Borrowed from Thog <3
*/

#include "libft.h"

int		ft_nbrlen(intmax_t value, int base)
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
