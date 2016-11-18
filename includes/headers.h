/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:34:46 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/16 12:45:37 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "libft.h"
# include <fcntl.h>

typedef struct	s_map
{
	int			size;
	char		**grid;
}				t_map;

typedef struct	s_tetris
{
	char		**pos;
	int			width;
	int			height;
	char		id;
}				t_tetris;

void	solve_fillit(t_list *list);
int		err(char * errmsg);
t_list 	*creatTetrilist(char *file);
#endif
