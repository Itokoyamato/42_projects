/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tunnels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:23:44 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 14:58:01 by dthuilli         ###   ########.fr       */
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
	t_room	*room1;
	t_room	*room2;

	split = ft_strsplit(line, '-');
	if (!split || !split[0] || !split[1] || split[2])
		return (0);
	while (lem->rooms)
	{
		if (ft_strcmp(lem->rooms->name, split[0]) == 0)
			room1 = lem->rooms;
		if (ft_strcmp(lem->rooms->name, split[1]) == 0)
			room2 = lem->rooms;
		lem->rooms = lem->rooms->next;
	}
	if (!room1 || !room2)
		return (0);
	new_tunnel(&room1->tunnels, room2);
	new_tunnel(&room2->tunnels, room1);
	lem->rooms = lem->rooms_start;
	free(split[0]);
	free(split[1]);
	free(split);
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
	else
	{
		if (!lem->rooms_start)
			lem->rooms_start = lem->rooms;
		if (!is_tunnel_valid(lem, line))
			return (0);
	}
	return (1);
}
