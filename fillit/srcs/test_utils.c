/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:51:58 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/24 16:09:57 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		display_tetris(t_list *list)
{
	t_list		*tmp;
	int			i;
	t_tetris	*tetri;

	ft_putstr("---------------\nTetriminos list:\n---------------\n\n");
	tmp = list;
	while (tmp)
	{
		tetri = (t_tetris *)(tmp->content);
		i = 0;
		while (i < tetri->height)
		{
			ft_putstr(tetri->pos[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putstr("---------------\n---------------\n\n");
}

static void	test_display_colored_text(t_map *map, int i, int j)
{
	ft_putstr("\e[");
	if (map->grid[i][j] - 36 > 37)
	{
		ft_putnbr(map->grid[i][j] - 36 + 53);
		ft_putstr(";01m");
	}
	else
	{
		ft_putnbr(map->grid[i][j] - 36);
		ft_putstr(";01m");
	}
	ft_putchar(map->grid[i][j]);
}

void		test_display_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] != '.')
			{
				test_display_colored_text(map, i, j);
			}
			else
				ft_putchar(map->grid[i][j]);
			ft_putstr(" \x1b[0m");
			j++;
		}
		ft_putchar('\n');
		++i;
	}
}
