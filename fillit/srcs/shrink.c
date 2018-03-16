/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:08:08 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/24 16:09:35 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	do_shrink(t_tetris *t)
{
	char		**p;
	int			x;
	int			y;

	p = (char **)ft_memalloc(sizeof(char *) * t->height);
	p[0] = (char *)ft_memalloc(sizeof(char) * t->width + 1);
	y = 0;
	while (y < 4)
	{
		if (y >= t->starty && y <= t->endy)
		{
			p[y - t->starty] = (char *)ft_memalloc(sizeof(char) * t->width + 1);
			x = 0;
			while (x < 4)
			{
				if (x >= t->startx && x <= t->endx)
					p[y - t->starty][x - t->startx] = t->pos[y][x];
				++x;
			}
		}
		++y;
	}
	t->pos = p;
}

static void	get_tetri_size(t_tetris *tetri)
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
	get_tetri_size(tetri);
	tetri->width = 1 + tetri->endx - tetri->startx;
	tetri->height = 1 + tetri->endy - tetri->starty;
	do_shrink(tetri);
	return (tetri);
}
