/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:48:03 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/24 17:11:30 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void		check_char(char *buf, int i)
{
	if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
	{
		if (buf[i] != '\n')
			err("Tetriminos is not valid, character is not \"\\n\".\n");
	}
	else if (buf[i] != '.' && buf[i] != '#')
		err("Tetriminos is not valid, character not \".\" or \"#\".\n");
}

static void		tadd2(char *buf, t_tetris *tt)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	tt->pos[0] = (char *)ft_memalloc(sizeof(char) * tt->width + 1);
	while (i < 19)
	{
		check_char(buf, i);
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			tt->pos[y][x] = '\0';
			x = 0;
			tt->pos[++y] = (char *)ft_memalloc(sizeof(char) * tt->width + 1);
		}
		else
			tt->pos[y][x++] = buf[i];
		++i;
	}
}

static t_tetris	*tadd(char *buf, char id)
{
	t_tetris	*tetrist;

	if (!(tetrist = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
		err("Can't malloc a t_tetris !\n");
	tetrist->height = 4;
	tetrist->width = 4;
	tetrist->id = id;
	tetrist->pos = (char **)ft_memalloc(sizeof(char *) * tetrist->height);
	tadd2(buf, tetrist);
	check_tetri(tetrist);
	return (tetrist);
}

t_list			*create_tetri_list(char *file)
{
	int		fd;
	int		cur;
	char	buf[22];
	char	id;
	t_list	*tlst;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err("Open failed\nUsage : fillit <source_file>\n");
	id = 'A';
	tlst = NULL;
	while ((cur = read(fd, buf, 21)))
	{
		buf[cur] = '\0';
		if (id > 'Z')
			err("There is too much Tetriminos, must be between 1 and 26\n");
		ft_lstadd(&tlst, ft_lstnew(shrink(tadd(buf, id++)), sizeof(t_tetris)));
	}
	if (ft_strlen(buf) != 20)
		err("Rolfina");
	ft_lstrev(&tlst);
	return (tlst);
}
