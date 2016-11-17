/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:18:34 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 14:49:07 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbdigit(int n)
{
	unsigned int nb;

	nb = n;
	if (nb < 10)
		return (1);
	if (nb < 100)
		return (2);
	if (nb < 1000)
		return (3);
	if (nb < 10000)
		return (4);
	if (nb < 100000)
		return (5);
	if (nb < 1000000)
		return (6);
	if (nb < 10000000)
		return (7);
	if (nb < 100000000)
		return (8);
	if (nb < 1000000000)
		return (9);
	return (10);
}
