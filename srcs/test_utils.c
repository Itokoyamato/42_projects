/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:51:58 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/17 15:52:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	display_tetris(t_list *list)
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

t_list	*test_tetris(void)
{
	t_list		*list;

	list = NULL;
	ft_lstadd(&list, ft_lstnew(test_t0(), sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(test_t1(), sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(test_t2(), sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(test_t3(), sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(test_t4(), sizeof(t_tetris)));
	ft_lstrev(&list);
	display_tetris(list);
	return (list);
}

void	test_display_map(t_map *map)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		j = 0;
		while (map->grid[i][j])
		{
			ft_putchar(map->grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		++i;
	}
}