/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:22:17 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/07 16:12:22 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	new_room(t_lemin *lem, t_room **rooms, char *line)
{
	t_room	*room;
	char	**split;

	split = ft_strsplit(line, ' ');
	room = (t_room *)s_malloc(sizeof(t_room));
	room->name = ft_strdup(split[0]);
	if (!lem->rooms)
		room->id = 0;
	else
		room->id = lem->rooms->id + 1;
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->nb_tunnels = 0;
	room->tunnels = NULL;
	room->next = *rooms;
	*rooms = room;
	lem->nb_rooms++;
	free_2d(split);
}

int		is_room_position_name_valid(t_lemin *lem, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	while (lem->rooms)
	{
		if (ft_strcmp(lem->rooms->name, split[0]) == 0)
		{
			free_2d(split);
			return (0);
		}
		if (ft_atoi(split[1]) == lem->rooms->x
			&& ft_atoi(split[2]) == lem->rooms->y)
		{
			free_2d(split);
			lem->rooms = lem->rooms_start;
			return (0);
		}
		lem->rooms = lem->rooms->next;
	}
	lem->rooms = lem->rooms_start;
	free_2d(split);
	return (1);
}

int		is_room_valid(char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (!split[0] || !split[1] || !split[2] || split[3])
	{
		free_2d(split);
		return (0);
	}
	if (!ft_isstrdigit(split[1]) || !ft_isstrdigit(split[2]))
	{
		free_2d(split);
		return (0);
	}
	free_2d(split);
	return (1);
}

int		parse_rooms(t_lemin *lem, char *line, int *start_end)
{
	if (ft_strstr(line, "##start"))
		*start_end = 1;
	else if (ft_strstr(line, "##end"))
		*start_end = 2;
	else if (ft_strstr(line, "#") || ft_strstr(line, "##"))
		;
	else if (is_room_valid(line) && is_room_position_name_valid(lem, line))
	{
		new_room(lem, &lem->rooms, line);
		lem->rooms_start = lem->rooms;
		if (*start_end == 1)
			lem->start_room = lem->rooms;
		else if (*start_end == 2)
			lem->end_room = lem->rooms;
		*start_end = 0;
	}
	else
		return (0);
	return (1);
}
