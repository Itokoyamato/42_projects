/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:34:36 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/16 12:44:05 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		err(char *errmsg)
{
	ft_putstr_fd(errmsg, 2);
	return (1);
}

void	display_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->grid[i]);
		ft_putchar('\n');
		++i;
	}
}

int		main(int argc, char **argv)
{
	t_list		*list;
	t_map		*map;

	if (argc != 2 && argv)
	{
		ft_putstr("usage: fillit source_file\n");
		return (1);
	}
	if ((list = test_tetris()))
	{
		if ((map = solve_fillit(list)))
			test_display_map(map);
	}
	else
		err("Failed to retrieve tetriminos list");
	return (0);
}
