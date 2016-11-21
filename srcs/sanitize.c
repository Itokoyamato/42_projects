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

char		**tetriAdd2(char *buf)
{
	char	**pos;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	pos = (char **)ft_memalloc(3);
	pos[j] = (char *)ft_memalloc(4);
	while (i < 21)
	{
		checkChar(buf, i);
		pos[j][k] = buf[i];
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			pos[j][k] = '\0';
			ft_putstr(pos[j]);
			ft_putchar('\n');
			pos[++j] = (char *)ft_memalloc(4);
			k = -1;
		}
		++k;
		++i;
	}
	return (pos);
}

t_tetris	*tetriAdd(char *buf, char id)
{
	t_tetris	*tetrist;

	if (!(tetrist = (t_tetris *)ft_memalloc(sizeof(tetrist))))
		err("Can't malloc a t_tetris !");
	tetrist->height = 3;
	tetrist->width = 3;
	tetrist->pos = tetriAdd2(buf);
	ft_putstr(tetrist->pos[0]);
	tetrist->id = id;
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
		ft_lstadd(&tetriList, ft_lstnew(tetriAdd(buf, id++), sizeof(t_tetris)));
	}
	ft_putstr("===EndOfSanitize===\n");
	ft_lstrev(&tetriList);
	display_ttlist(tetriList);
	return (tetriList);
}
