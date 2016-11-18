/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:48:03 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/16 12:47:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "headers.h"

t_tetris	*formatTetri(char **str, int id)
{
	t_tetris	*tetri;

	tetri = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	if (tetri)
	{
		tetri->pos = str;
		tetri->width = 5;
		tetri->width = 5;
		tetri->id = id;
	}
	return(tetri);
}

t_tetris	*newTetri(char *str, char id)
{
	int		i;
	int		j;
	int		k;
	char	**ttemp;

	i = 0;
	k = 0;
	ttemp = (char **)ft_memalloc(5);
	while (i <= 4)
	{
		j = 0;
		ttemp[i] = (char *)ft_memalloc(5);
		while (j <= 3 && str[k] && (str[k] == '.' || str[k] == '#' || str[k] == '\n'))
		{
			ft_putchar(str[k]);
			ttemp[i][j++] = str[k++];
		}
		++i;
	}
	return (formatTetri(ttemp, id));
}

t_list 		*creatTetrilist(char *file)
{
	t_list	*lst;
	char 	buff[21];
	int 	fd;
	int 	st;
	char	id;

	id = 'A';
	fd = open(file, O_RDONLY);
	while((st = read(fd, buff, 21)) && id <= 'Z')
	{		
		ft_lstaddend(&lst, ft_lstnew(newTetri(buff, id), sizeof(t_tetris)));
		++id;
	}
	return (lst);
}
