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

void	err(char *errmsg)
{
	ft_putstr_fd(errmsg, 2);
	exit(1);
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
		err("Wrong number of argument\nUsage : fillit <source_file>");
	if ((list = createTetriList(argv[1])))
	{
		if ((map = solve_fillit(list)))
			display_map(map);
		else
			err("Failed to solve tetriminos");
	}
	else
		err("\nFailed to retrieve tetriminos list");
	return (0);
}
