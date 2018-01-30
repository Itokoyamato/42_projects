/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:22:17 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 14:32:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		parse_rooms(t_lemin *lem, char *line, int *start_end)
{
	if (ft_strstr(line, "##start"))
		*start_end = 1;
	else if (ft_strstr(line, "##end"))
		*start_end = 2;
	else if (ft_strstr(line, "#") || ft_strstr(line, "##"))
		;
	else if (is_room_valid(line))
	{
		new_room(&lem->rooms, line);
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
