/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:48:03 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/21 14:36:40 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void		checkChar(char *buf, int i)
{
	if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
	{
		if (buf[i] != '\n')
			err("Tetriminos is not valid, character 5/10/15/20/21 is not \"\\n\".");
	}
	else
		if (buf[i] != '.' && buf[i] != '#')
			err("Tetriminos is not valid, character not \".\" or \"#\".");
}

t_tetris	*tetriAdd(char *buf, char id)
{
	t_tetris	*tetrist;
	int			i;
	int			x;
	int			y;

	if (!(tetrist = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
		err("Can't malloc a t_tetris !");
	i = 0;
	x = 0;
	y = 0;
	tetrist->height = 4;
	tetrist->width = 4;
	tetrist->id = id;
	tetrist->pos = (char **)ft_memalloc(sizeof(char *) * tetrist->height);
	tetrist->pos[0] = (char *)ft_memalloc(sizeof(char) * tetrist->width + 1);
	while (i < 19)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			tetrist->pos[y][x] = '\0';
			x = 0;
			tetrist->pos[++y] = (char *)ft_memalloc(sizeof(char) * tetrist->width + 1);
		}
		else
			tetrist->pos[y][x++] = buf[i];
		++i;
	}
	return (tetrist);
}

t_list		*createTetriList(char *file)
{
	int		fd;
	int		cur;
	char	buf[21];
	char	id;
	t_list	*tetriList;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err("Open failed\nUsage : fillit <source_file>");
	id = 'A';
	tetriList = NULL;
	while((cur = read(fd, buf, 21)) && id <= 'Z')
	{
		ft_putstr("==='");
		ft_putchar(id);
		ft_putstr("'===\n");
		ft_lstadd(&tetriList, ft_lstnew(shrink(tetriAdd(buf, id++)), sizeof(t_tetris)));
	}
	ft_putstr("===EndOfSanitize===\n");
	ft_lstrev(&tetriList);
	display_tetris(tetriList);
	return (tetriList);
}
