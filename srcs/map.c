/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:07:51 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/17 14:08:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	destroy_map(t_map *map)
{
	while (map->size--)
		ft_memdel((void **)&map->grid[map->size]);
	ft_memdel((void **)&map->grid);
	ft_memdel((void **)&map);
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
			++x;
		}
		++y;
	}
	return (map);
}
