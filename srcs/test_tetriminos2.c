/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:11:39 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/18 11:14:00 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_tetris	*test_t5(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 2;
	t->height = 3;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = "##";
	pos[1] = ft_memalloc(t->width);
	pos[1] = ".#";
	pos[2] = ft_memalloc(t->width);
	pos[2] = ".#";
	t->pos = pos;
	t->id = 'F';
	return (t);
}

t_tetris	*test_t6(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 3;
	t->height = 2;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = ".#.";
	pos[1] = ft_memalloc(t->width);
	pos[1] = "###";
	t->pos = pos;
	t->id = 'G';
	return (t);
}

t_tetris	*test_t7(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 2;
	t->height = 3;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = "#..";
	pos[1] = ft_memalloc(t->width);
	pos[1] = "##.";
	pos[2] = ft_memalloc(t->width);
	pos[2] = "#..";
	t->pos = pos;
	t->id = 'H';
	return (t);
}

t_tetris	*test_t8(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 3;
	t->height = 2;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = "##.";
	pos[1] = ft_memalloc(t->width);
	pos[1] = ".##";
	t->pos = pos;
	t->id = 'I';
	return (t);
}

t_tetris	*test_t9(void)
{
	char		**pos;
	t_tetris	*t;

	t = ft_memalloc(sizeof(t_tetris));
	t->width = 3;
	t->height = 2;
	pos = ft_memalloc(t->height);
	pos[0] = ft_memalloc(t->width);
	pos[0] = "###";
	pos[1] = ft_memalloc(t->width);
	pos[1] = "..#";
	t->pos = pos;
	t->id = 'J';
	return (t);
}
