/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:51:52 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/17 15:52:05 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_tetris	*test_t0(void)
{
	char		**pos0;
	t_tetris	*t0;

	t0 = ft_memalloc(sizeof(t_tetris));
	t0->width = 1;
	t0->height = 4;
	pos0 = ft_memalloc(t0->height);
	pos0[0] = ft_memalloc(t0->width);
	pos0[0] = "#";
	pos0[1] = ft_memalloc(t0->width);
	pos0[1] = "#";
	pos0[2] = ft_memalloc(t0->width);
	pos0[2] = "#";
	pos0[3] = ft_memalloc(t0->width);
	pos0[3] = "#";
	t0->pos = pos0;
	t0->id = 'A';
	return (t0);
}

t_tetris	*test_t1(void)
{
	char		**pos1;
	t_tetris	*t1;

	t1 = ft_memalloc(sizeof(t_tetris));
	t1->width = 4;
	t1->height = 1;
	pos1 = ft_memalloc(t1->height);
	pos1[0] = ft_memalloc(t1->width);
	pos1[0] = "####";
	t1->pos = pos1;
	t1->id = 'B';
	return (t1);
}

t_tetris	*test_t2(void)
{
	char		**pos2;
	t_tetris	*t2;

	t2 = ft_memalloc(sizeof(t_tetris));
	t2->width = 3;
	t2->height = 2;
	pos2 = ft_memalloc(t2->height);
	pos2[0] = ft_memalloc(t2->width);
	pos2[0] = "###";
	pos2[1] = ft_memalloc(t2->width);
	pos2[1] = "..#";
	t2->pos = pos2;
	t2->id = 'C';
	return (t2);
}

t_tetris	*test_t3(void)
{
	char		**pos3;
	t_tetris	*t3;

	t3 = ft_memalloc(sizeof(t_tetris));
	t3->width = 3;
	t3->height = 2;
	pos3 = ft_memalloc(t3->height);
	pos3[0] = ft_memalloc(t3->width);
	pos3[0] = ".##";
	pos3[1] = ft_memalloc(t3->width);
	pos3[1] = "##.";
	t3->pos = pos3;
	t3->id = 'D';
	return (t3);
}

t_tetris	*test_t4(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 2;
	t->height = 2;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = "##";
	pos[1] = ft_memalloc(t->width);
	pos[1] = "##";
	t->pos = pos;
	t->id = 'E';
	return (t);
}
