/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:26:26 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/29 19:00:27 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**** Libs
*/
# include "libft.h"

/*
**** Struct
*/
typedef struct	room	t_room;
typedef struct	tunnel	t_tunnel;

typedef struct	tunnel
{
	t_room		*room;
	t_tunnel	*next;
}				t_tunnel;

typedef struct	room
{
	int			x;
	int			y;
	char		*name;
	t_room		*next;
	t_tunnel	*tunnels;
	t_tunnel	*tunnels_start;
}				t_room;

typedef struct	lemin
{
	t_room		*start_room;
	t_room		*end_room;
	t_room		*rooms;
	t_room		*rooms_start;
}				t_lemin;

#endif
