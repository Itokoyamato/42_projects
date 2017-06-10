/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:43:37 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/10 13:29:55 by dthuilli         ###   ########.fr       */
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
typedef struct	s_data
{
	char	**map;
	int		map_size_x;
	int		map_size_y;
	char	local_playerchar;
	char	playerchar;
	int		play_x;
	int		play_y;
	int		play_move;
	int		play_dir;
	int		player_pos_x;
	int		player_pos_y;
	int		local_pos_x;
	int		local_pos_y;
	char	**piece;
	int		piece_size_x;
	int		piece_size_y;
	int		gamestate;
	int		stuck;
}				t_data;

int				do_solve(t_data *env);
void			do_play(t_data *env);

#endif
