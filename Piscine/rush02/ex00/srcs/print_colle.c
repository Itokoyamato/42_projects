/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 18:40:58 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/24 09:57:46 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

void	print_colle(int colle[5], int *l, int *h, int count)
{
	int i;

	i = 0;
	if (count && l && h)
	{
		while (i < 5)
		{
			if (colle[i] == 1)
			{
				ft_putstr("[colle-0");
				ft_putnbr(i);
				ft_putstr("] [");
				ft_putnbr(*l);
				ft_putstr("] [");
				ft_putnbr(*h);
				ft_putstr("]");
				if (count > 1)
				{
					ft_putstr(" || ");
					count--;
				}
			}
			i++;
		}
	}
}
