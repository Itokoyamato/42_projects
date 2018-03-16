/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:26:26 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/07 16:48:55 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**** Libs
*/
# include "libft.h"
# include <stdio.h>

/*
**** Struct
*/
typedef struct	s_point
{
	int					x;
	int					y;
}				t_point;

typedef struct s_room	t_room;
typedef struct s_roomlist	t_roomlist;
typedef struct s_ant	t_ant;
typedef struct s_path	t_path;

struct			s_roomlist
{
	t_room		*room;
	t_roomlist	*next;
	t_roomlist	*parent;
};

struct			s_room
{
	int			x;
	int			y;
	char		*name;
	int			id;
	t_room		*next;
	t_roomlist	*tunnels;
	int			nb_tunnels;
	t_roomlist	*tunnels_start;
};

struct			s_ant
{
	int			id;
	t_room		*current_room;
	t_ant		*next;
};

typedef struct	s_lemin
{
	t_room		*start_room;
	t_room		*end_room;
	t_room		*rooms;
	t_room		*rooms_start;
	t_ant		*ants;
	int			ants_nb;
	int			nb_rooms;
	char		*input_str;
}				t_lemin;

/*
**** Functions
*/
void			parse_data(t_lemin *lem);
int				parse_rooms(t_lemin *lem, char *line, int *start_end);
int				is_room_valid(char *line);
int				is_room_position_valid(t_lemin *lem, char *line);
void			new_room(t_lemin *lem, t_room **rooms, char *line);
int				parse_tunnels(t_lemin *lem, char *line);
int				is_tunnel_valid(t_lemin *lem, char *line);
int				new_tunnel(t_room **rooms);
void			parse_debug(t_lemin *lem);
void			save_line(t_lemin *lem, char *l);

void			solver(t_lemin *lem);
void			init_ants(t_lemin *lem);
void			move_ant(t_ant *ant, t_room *target_room);
t_roomlist		*init_roomlist(t_room *toadd);
void			add_roomlist(t_room *toadd,
t_roomlist		*parent, t_roomlist *list);
int				in_roomlist(t_room *current, t_roomlist *list);
void			destroy_roomlist(t_roomlist *list);

void			err(char *err, t_lemin *lem);
void			*s_malloc(size_t size);
void			free_2d(char **table);
void			destroy_ants(t_ant *list);
void			destroy_rooms(t_room *list);

#endif
