/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tunnels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:23:44 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/07 17:37:38 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		new_tunnel(t_room **rooms)
{
	t_roomlist	**tunnels;

	tunnels = (t_roomlist **)s_malloc(sizeof(t_roomlist *) * 2);
	tunnels[0] = (t_roomlist *)s_malloc(sizeof(t_roomlist));
	tunnels[0]->room = rooms[1];
	tunnels[0]->next = rooms[0]->tunnels;
	rooms[0]->tunnels = tunnels[0];
	rooms[0]->nb_tunnels++;
	tunnels[1] = (t_roomlist *)s_malloc(sizeof(t_roomlist));
	tunnels[1]->room = rooms[0];
	tunnels[1]->next = rooms[1]->tunnels;
	rooms[1]->tunnels = tunnels[1];
	rooms[1]->nb_tunnels++;
	free(tunnels);
	free(rooms);
	return (1);
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
	lem->rooms = lem->rooms_start;
	if (rooms[0] && rooms[1])
		return (new_tunnel(rooms));
	free(rooms);
	return (0);
}

int		parse_tunnels(t_lemin *lem, char *line)
{
	if (!lem->rooms)
		return (0);
	if (ft_strstr(line, "#") || ft_strstr(line, "##"))
		;
	else if (!ft_strstr(line, "-"))
		err("Error: no tunnels.", lem);
	else if (!is_tunnel_valid(lem, line))
		return (0);
	return (1);
}
