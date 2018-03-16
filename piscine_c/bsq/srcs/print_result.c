/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 16:00:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/27 16:00:41 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_result(char **map, t_map_info info, t_square bsq)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y >= bsq.y && y <= bsq.y + bsq.length
				&& x >= bsq.x && x <= bsq.x + bsq.length)
				ft_putchar(info.full);
			else
				ft_putchar(map[y][x]);
			x++;
		}
		y++;
	}
	ft_putchar('\n');
}
