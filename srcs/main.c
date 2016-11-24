/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:34:36 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/24 16:21:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	err(char *errmsg)
{
	ft_putstr_fd("error\n", 1);
	ft_putstr_fd(errmsg, 2);
	exit(-1);
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
		err("Wrong number of argument\nUsage : fillit <source_file>\n");
	if ((list = create_tetri_list(argv[1])))
	{
		if ((map = solve_fillit(list)))
			display_map(map);
		else
			err("Failed to solve tetriminos\n");
	}
	else
		err("Failed to retrieve tetriminos list\n");
	return (0);
}
