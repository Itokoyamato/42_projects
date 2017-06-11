/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:43:37 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/11 11:36:44 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
**** Libs
*/
# include "libft.h"

/*
**** Struct
*/
typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_data
{
	char	**map;
	t_point	map_size;
	char	local_p_char;
	char	p_char;
	t_point	play_pos;
	int		play_move;
	int		play_dir;
	t_point	player_pos;
	t_point	local_pos;
	char	**piece;
	t_point	piece_size;
	int		gamestate;
	int		stuck;
}				t_data;

/*
**** Functions
*/
int				do_solve(t_data *env);
void			do_play(t_data *env);

#endif
