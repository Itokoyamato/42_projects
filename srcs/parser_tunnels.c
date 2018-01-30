/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tunnels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:23:44 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 16:50:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	*new_tunnel(t_tunnel **tunnels, t_room *room)
{
	t_tunnel	*tunnel;

	tunnel = (t_tunnel *)s_malloc(sizeof(t_tunnel));
	tunnel->room = room;
	tunnel->next = *tunnels;
	*tunnels = tunnel;
	return (0);
}

int		is_tunnel_valid(t_lemin *lem, char *line)
{
	char	**split;
	t_room	**rooms;

	rooms = (t_room **)malloc(sizeof(t_room *) * 2);
	rooms[0] = NULL;
	rooms[1] = NULL;
	split = ft_strsplit(line, '-');
	if (!split || !split[0] || !split[1] || split[2])
		return (0);
	while (lem->rooms)
	{
		if (ft_strcmp(lem->rooms->name, split[0]) == 0)
			rooms[0] = lem->rooms;
		if (ft_strcmp(lem->rooms->name, split[1]) == 0)
			rooms[1] = lem->rooms;
		lem->rooms = lem->rooms->next;
	}
	free_2d(split);
	if (!rooms[0] || !rooms[1])
		return (0);
	new_tunnel(&rooms[0]->tunnels, rooms[1]);
	new_tunnel(&rooms[1]->tunnels, rooms[0]);
	lem->rooms = lem->rooms_start;
	free(rooms);
	return (1);
}

int		parse_tunnels(t_lemin *lem, char *line)
{
	if (!lem->rooms)
		return (0);
	if (ft_strstr(line, "#") || ft_strstr(line, "##"))
		;
	else if (!ft_strstr(line, "-"))
		err("Error: no tunnels.");
	else if (!is_tunnel_valid(lem, line))
		return (0);
	return (1);
}
