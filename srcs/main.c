/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:34:36 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/25 17:17:36 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	err(void)
{
	ft_putstr_fd("error\n", 1);
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
		err();
	if ((list = create_tetri_list(argv[1])))
	{
		if ((map = solve_fillit(list)))
			display_map(map);
		else
			err();
	}
	else
		err();
	return (0);
}
