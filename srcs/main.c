/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:24:00 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/29 19:00:51 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		err(char *err)
{
	ft_putendl(err);
	exit(1);
	return (1);
}

void	*s_malloc(size_t size)
{
	void	*var;

	if ((var = ft_memalloc(size)) == NULL)
		exit(0);
	return (var);
}

void	*new_tunnel(t_tunnel **tunnels, t_room *room)
{
	t_tunnel	*tunnel;

	tunnel = (t_tunnel *)s_malloc(sizeof(t_tunnel));
	tunnel->room = room;
	tunnel->next = *tunnels;
	*tunnels = tunnel;
	return (0);
}

void	is_tunnel_valid(t_lemin *lem, char *line)
{
	char	**split;
	t_room	*room1;
	t_room	*room2;

	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1] || split[2])
		err("Invalid tunnel");
	while (lem->rooms)
	{
		if (ft_strcmp(lem->rooms->name, split[0]) == 0)
			room1 = lem->rooms;
		if (ft_strcmp(lem->rooms->name, split[1]) == 0)
			room2 = lem->rooms;
		lem->rooms = lem->rooms->next;
	}
	if (!room1 || !room2)
		err("Invalid tunnel");
	new_tunnel(&room1->tunnels, room2);
	new_tunnel(&room2->tunnels, room1);
	lem->rooms = lem->rooms_start;
	free(split[0]);
	free(split[1]);
	free(split);
}

int		is_room_valid(char *line)
{
	char	**split;
	int		i;

	split = ft_strsplit(line, ' ');
	i = -1;
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		while (split[++i])
			free(split[i]);
		free(split);
		return (0);
	}
	if (!ft_isstrdigit(split[1]) || !ft_isstrdigit(split[2]))
	{
		while (split[++i])
			free(split[i]);
		free(split);
		return (0);
	}
	while (split[++i])
		free(split[i]);
	free(split);
	return (1);
}

void	*new_room(t_room **rooms, char *line)
{
	t_room	*room;
	char	**split;

	split = ft_strsplit(line, ' ');
	room = (t_room *)s_malloc(sizeof(t_room));
	room->name = split[0];
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->tunnels = NULL;
	room->next = *rooms;
	*rooms = room;
	free(split[1]);
	free(split[2]);
	free(split);
	return (0);
}

int		main(void)
{
	char	*line;
	t_lemin	*lem;
	int		start_end;

	start_end = 0;
	lem = (t_lemin *)s_malloc(sizeof(t_lemin));
	lem->rooms = NULL;
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, ""))
	{
		if (!ft_strstr(line, "-"))
		{
			if (ft_strstr(line, "##start"))
				start_end = 1;
			else if (ft_strstr(line, "##end"))
				start_end = 2;
			else if (ft_strstr(line, "#"))
			{
				ft_putstr(line);
			}
			else
			{
				if (is_room_valid(line))
				{
					new_room(&lem->rooms, line);
					if (start_end == 1)
						lem->start_room = lem->rooms;
					else if (start_end == 2)
						lem->end_room = lem->rooms;
					start_end = 0;
				}
			}
		}
		else
		{
			if (!lem->rooms_start)
				lem->rooms_start = lem->rooms;
			if (ft_strstr(line, "#"))
				ft_putstr(line);
			else
				is_tunnel_valid(lem, line);
		}
		free(line);
	}
	// Debug data, display all rooms and tunnels
	while (lem->rooms)
	{
		ft_putstr("\n-------------------------------------------\nRoom: ");
		ft_putstr(lem->rooms->name);
		ft_putstr("\nTunnels with rooms:\n");
		lem->rooms->tunnels_start = lem->rooms->tunnels;
		while (lem->rooms->tunnels)
		{
			ft_putstr(lem->rooms->tunnels->room->name);
			ft_putstr("\n");
			lem->rooms->tunnels = lem->rooms->tunnels->next;
		}
		lem->rooms->tunnels = lem->rooms->tunnels_start;
		lem->rooms = lem->rooms->next;
	}
	lem->rooms = lem->rooms_start;
	ft_putstr("\n---------------------------------------\nStart room:\n");
	ft_putstr(lem->start_room->name);
	ft_putstr("\nEnd room:\n");
	ft_putstr(lem->end_room->name);
	return (0);
}
