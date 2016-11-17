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

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

int				err(char *errmsg);

void			display_map(t_map *map);
t_map			*buildmap(int size);
void			destroy_map(t_map *map);

void			solve_fillit(t_list *list);
int				try_map(t_map *map, t_list *tetris);
int				try_tetri(t_map *map, t_tetris *tetri, t_point *pos);
void			set_tetri(t_map *map, t_tetris *tetri, t_point *pos, char c);
#endif
