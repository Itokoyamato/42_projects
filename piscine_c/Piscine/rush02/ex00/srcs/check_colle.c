/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:58:35 by thninh            #+#    #+#             */
/*   Updated: 2016/07/23 18:44:36 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

void	check_colle(char *str, int *l, int *h)
{
	int count;
	int colle[5];
	int i;

	i = 0;
	count = 0;
	colle[0] = (is_colle00(str, l, h) == 1) ? 1 : 0;
	colle[1] = (is_colle01(str, l, h) == 1) ? 1 : 0;
	colle[2] = (is_colle02(str, l, h) == 1) ? 1 : 0;
	colle[3] = (is_colle03(str, l, h) == 1) ? 1 : 0;
	colle[4] = (is_colle04(str, l, h) == 1) ? 1 : 0;
	while (i < 5)
	{
		count += colle[i];
		i++;
	}
	if (count > 0)
		print_colle(colle, l, h, count);
	else
		ft_putstr("aucune");
}
