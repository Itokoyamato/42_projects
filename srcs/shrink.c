/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:08:08 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/21 18:08:31 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		doShrink(t_tetris *tetri)
{
	char		**pos;
	int			x;
	int			y;

	pos = (char **)ft_memalloc(sizeof(char *) * tetri->height);
	pos[0] = (char *)ft_memalloc(sizeof(char) * tetri->width + 1);
	y = 0;
	while (y < 4)
	{
		if (y >= tetri->starty && y <= tetri->endy)
		{
			pos[y - tetri->starty] = (char *)ft_memalloc(sizeof(char) * tetri->width + 1);
			x = 0;
			while (x < 4)
			{
				if (x >= tetri->startx && x <= tetri->endx)
					pos[y - tetri->starty][x - tetri->startx] = tetri->pos[y][x];
				++x;
			}
		}
		++y;
	}
	tetri->pos = pos;
}

void		getTetriSize(t_tetris *tetri)
{
	t_point		*pos;

	pos = ft_memalloc(sizeof(t_point));
	pos->y = 0;
	while (pos->y < 4)
	{
		pos->x = 0;
		while (pos->x < 4)
		{
			if (tetri->pos[pos->y][pos->x] == '#')
			{
				if (pos->x < tetri->startx)
					tetri->startx = pos->x;
				if (pos->x > tetri->endx)
					tetri->endx = pos->x;
				if (pos->y < tetri->starty)
					tetri->starty = pos->y;
				if (pos->y > tetri->endy)
					tetri->endy = pos->y;
			}
			pos->x++;
		}
		pos->y++;
	}
}

t_tetris	*shrink(t_tetris *tetri)
{
	tetri->startx = 4;
	tetri->starty = 4;
	tetri->endx = 0;
	tetri->endy = 0;
	getTetriSize(tetri);
	tetri->width = 1 + tetri->endx - tetri->startx;
	tetri->height = 1 + tetri->endy - tetri->starty;
	doShrink(tetri);
	return (tetri);
}