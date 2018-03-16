/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:46:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/16 12:13:49 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	set_tetri(t_map *map, t_tetris *tetri, t_point *pos, char c)
{
	int	mx;
	int	my;

	mx = 0;
	while (mx < tetri->width)
	{
		my = 0;
		while (my < tetri->height)
		{
			if (tetri->pos[my][mx] == '#')
				map->grid[my + pos->y][mx + pos->x] = c;
			++my;
		}
		++mx;
	}
}

int		try_tetri(t_map *map, t_tetris *tetri, t_point *pos)
{
	int		tx;
	int		ty;

	tx = 0;
	while (tx < tetri->width)
	{
		ty = 0;
		while (ty < tetri->height)
		{
			if (tetri->pos[ty][tx] == '#'
				&& map->grid[pos->y + ty][pos->x + tx] != '.')
				return (0);
			++ty;
		}
		++tx;
	}
	set_tetri(map, tetri, pos, tetri->id);
	return (1);
}

int		try_map(t_map *map, t_list *tetris)
{
	t_point		*pos;
	t_tetris	*tetri;

	if (tetris == NULL)
		return (1);
	pos = ft_memalloc(sizeof(t_point));
	pos->y = 0;
	tetri = (t_tetris *)(tetris->content);
	while (pos->y < map->size - tetri->height + 1)
	{
		pos->x = 0;
		while (pos->x < map->size - tetri->width + 1)
		{
			if (try_tetri(map, tetri, pos))
			{
				if (try_map(map, tetris->next))
					return (1);
				else
					set_tetri(map, tetri, pos, '.');
			}
			++pos->x;
		}
		++pos->y;
	}
	return (0);
}

t_map	*solve_fillit(t_list *tetris)
{
	t_map	*map;
	int		map_size;

	map_size = 2;
	while (map_size * map_size < (int)(ft_lstcount(tetris) * 4))
		++map_size;
	map = buildmap(map_size);
	while (!try_map(map, tetris))
	{
		++map_size;
		destroy_map(map);
		map = buildmap(map_size);
	}
	return (map);
}
