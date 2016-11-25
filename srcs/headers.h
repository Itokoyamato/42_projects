/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:34:46 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/25 17:17:48 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

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
	int			startx;
	int			starty;
	int			endx;
	int			endy;
}				t_tetris;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void			err(void);

t_list			*create_tetri_list(char *file);
void			check_tetri(t_tetris *tetrist);

void			display_map(t_map *map);
t_map			*buildmap(int size);
void			destroy_map(t_map *map);

t_map			*solve_fillit(t_list *list);
int				try_map(t_map *map, t_list *tetris);
int				try_tetri(t_map *map, t_tetris *tetri, t_point *pos);
void			set_tetri(t_map *map, t_tetris *tetri, t_point *pos, char c);
t_tetris		*shrink(t_tetris *tetri);

t_list			*test_tetris(void);
void			test_display_map(t_map *map);
void			display_tetris(t_list *list);
#endif
