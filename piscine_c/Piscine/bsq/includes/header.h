/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 13:10:17 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/25 13:10:18 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_map_info
{
	int		x;
	int		y;
	char	empty;
	char	obs;
	char	full;
}				t_map_info;

typedef struct	s_square
{
	int		x;
	int		y;
	int		length;
}				t_square;

char			**get_map(char *path, t_map_info *map_info);
int				get_file_first_line(int fd);
int				get_file_size(int fd);
char			*get_input(void);
t_square		solve_bsq(char **map, t_map_info map_info);
void			print_result(char **map, t_map_info info, t_square bsq);
int				ft_atoi(const char *str);

#endif
