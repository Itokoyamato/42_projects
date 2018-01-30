/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:26:26 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 15:14:55 by dthuilli         ###   ########.fr       */
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
typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct s_room	t_room;
typedef struct s_tunnel	t_tunnel;

struct			s_tunnel
{
	t_room		*room;
	t_tunnel	*next;
};

struct			s_room
{
	int			x;
	int			y;
	char		*name;
	t_room		*next;
	t_tunnel	*tunnels;
	t_tunnel	*tunnels_start;
};

typedef struct	s_lemin
{
	t_room		*start_room;
	t_room		*end_room;
	t_room		*rooms;
	t_room		*rooms_start;
	int			ants_nb;
	char		*input_str;
}				t_lemin;

/*
**** Functions
*/
void			parse_data(t_lemin *lem);
int				parse_rooms(t_lemin *lem, char *line, int *start_end);
int				is_room_valid(char *line);
void			*new_room(t_room **rooms, char *line);
int				parse_tunnels(t_lemin *lem, char *line);
int				is_tunnel_valid(t_lemin *lem, char *line);
void			*new_tunnel(t_tunnel **tunnels, t_room *room);
void			parse_debug(t_lemin *lem);
void			save_line(t_lemin *lem, char *l);

int				err(char *err);
void			*s_malloc(size_t size);

#endif
