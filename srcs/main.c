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
	return (1);
}
int		main(int argc, char **argv)
{
	t_list	*list;

/*
**	Testing: building tetriminos
*/
	char	*pos0[21];
	t_tetris	*t0;
	char	*pos1[21];
	t_tetris	*t1;
	char	*pos2[21];
	t_tetris	*t2;
	char	*pos3[21];
	t_tetris	*t3;

	list = NULL;

	t0 = ft_memalloc(sizeof(t_tetris));
	t0->width = 1;
	t0->height = 4;
	pos0[0] = "#";
	pos0[1] = "#";
	pos0[2] = "#";
	pos0[3] = "#";
	t0->pos = pos0;
	t0->id = 'A';

	t1 = ft_memalloc(sizeof(t_tetris));
	t1->width = 4;
	t1->height = 1;
	pos1[0] = "####";
	t1->pos = pos1;
	t1->id = 'B';

	t2 = ft_memalloc(sizeof(t_tetris));
	t2->width = 3;
	t2->height = 2;
	pos2[0] = "###";
	pos2[1] = "..#";
	t2->pos = pos2;
	t2->id = 'C';

	t3 = ft_memalloc(sizeof(t_tetris));
	t3->width = 3;
	t3->height = 2;
	pos3[0] = ".##";
	pos3[1] = "##.";
	t3->pos = pos3;
	t3->id = 'D';

	ft_lstadd(&list, ft_lstnew(t0, sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(t1, sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(t2, sizeof(t_tetris)));
	ft_lstadd(&list, ft_lstnew(t3, sizeof(t_tetris)));

	ft_lstrev(&list);

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
