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

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int		err(char * errmsg)
{
	ft_putstr_fd(errmsg, 2);
	return (0);
}
int		main(int argc, char **argv)
{
	t_list	*list;

	list = creatTetrilist(argv[1]);

/*
**	Testing: printing list containing tetriminos
*/
	ft_putstr("----------------------------\nTetriminos list:\n----------------------------\n");
	t_list *tmp = list;
	while(tmp) {
		t_tetris *tetri =  (t_tetris *)(tmp->content);
		int i = 0;
		while (i <= 3)
		{
			ft_putstr(tetri->pos[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putstr("----------------------------\n");

/*
**	Main
*/

	if (argc != 2 && argv)
	{
		ft_putstr("usage: fillit source_file\n");
		return (1);
	}
	solve_fillit(list);

	return (0);
}
