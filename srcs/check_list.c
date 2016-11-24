/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:30:18 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/24 15:58:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	nb_of_link(int y, int x, t_tetris *tetrist)
{
	int i;

	i = 0;
	if (y + 1 < 4 && tetrist->pos[y + 1][x] == '#')
		++i;
	if (y - 1 >= 0 && tetrist->pos[y - 1][x] == '#')
		++i;
	if (x + 1 <= 4 && tetrist->pos[y][x + 1] == '#')
		++i;
	if (x - 1 >= 0 && tetrist->pos[y][x - 1] == '#')
		++i;
	return (i);
}

void		check_tetri(t_tetris *tetrist)
{
	int			i;
	int			x;
	int			y;
	int			nb_link;

	i = 0;
	x = 0;
	y = 0;
	nb_link = 0;
	while (i < 19)
	{
		if (tetrist->pos[y][x] == '#')
			nb_link = nb_link + nb_of_link(y, x, tetrist);
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			x = -1;
			++y;
		}
		++x;
		++i;
	}
	if (!(nb_link == 6 || nb_link == 8))
		err("Not a valid Tetriminos.\n");
}
