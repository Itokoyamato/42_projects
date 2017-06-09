/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:43:37 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/09 18:40:07 by dthuilli         ###   ########.fr       */
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
	int		mapx;
	int		mapy;
	char	local_playerchar;
	char	playerchar;
	int		x;
	int		y;
	int		player_pos_x;
	int		player_pos_y;
	int		local_pos_x;
	int		local_pos_y;
	char	**piece;
	int		piece_x;
	int		piece_y;
	int		gamestate;
	int		spaceav;
	int		move;
}				t_data;

#endif
