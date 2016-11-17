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

void	display_map(t_map *map)
{
	int i;

	i = 0;
	ft_putstr("\n----------------------------\nTesting map size: ");
	ft_putnbr(map->size);
	ft_putstr("\n----------------------------\n");
	while (i < map->size)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		i++;
	}
}

t_map	*buildmap(int size)
{
	t_map	*map;
	int		y;
	int		x;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->grid = (char **)ft_memalloc(sizeof(char *) * size);
	y = 0;
	while (y < size)
	{
		map->grid[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			map->grid[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

void	set_tetri(t_map *map, t_tetris *tetri, int x, int y, char c)
{
	int	mx;
	int	my;

	mx = 0;
	ft_putstr("Tetri set in map.\n");
	while(mx < tetri->height)
	{
		my = 0;
		while (my < tetri->width)
		{
			if (tetri->pos[my][mx] == '#')
				map->grid[my + y][mx + x] = c;
			my++;
		}
		mx++;
	}
}

int		test_tetri(t_map *map, t_tetris *tetri, int x, int y)
{
	int		tx;
	int		ty;

	tx = 0;
	while (tx < tetri->width)
	{
		ty = 0;
		while (ty < tetri->height)
		{
			if (tetri->pos[ty][tx] == '#' && map->grid[y + ty][x + tx] != '.')
				return (0);
			ty++;
		}
		tx++;
	}
	set_tetri(map, tetri, x, y, tetri->id);
	return (1);
}

int		test_map(t_map *map, t_list *tetris)
{
	int			x;
	int			y;
	t_tetris	*tetri;

	if (tetris == NULL)
		return (1);
	y = 0;
	tetri = (t_tetris *)(tetris->content);
	ft_putstr("Testing tetri: ");
	ft_putchar(tetri->id);
	ft_putchar('\n');
	while (y < map->size - tetri->height + 1)
	{
		x = 0;
		while (x < map->size - tetri->width + 1)
		{
			if (test_tetri(map, tetri, y, x))
			{
				if (test_map(map, tetris->next))
					return (1);
				else
					set_tetri(map, tetri, x, y, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	solve_fillit(t_list *tetris)
{
	t_map	*map;
	int		size;

	size = 4;
	map = buildmap(size);
	ft_putstr("\n----------------------------\nTesting map size:  ");
	ft_putnbr(size);
	ft_putstr("\n----------------------------\n");
	while (!test_map(map, tetris))
	{
		size++;
		map = buildmap(size);
		ft_putstr("\n----------------------------\nTesting map size: ");
		ft_putnbr(size);
		ft_putstr("\n----------------------------\n");
		display_map(map);
	}
}
