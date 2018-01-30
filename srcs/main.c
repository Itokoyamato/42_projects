/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:24:00 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 13:23:16 by dthuilli         ###   ########.fr       */
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

void	parse_debug(t_lemin *lem)
{
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
	ft_putstr("\n---------------------------------------\nStart room: ");
	ft_putstr(lem->start_room->name);
	ft_putstr("\nEnd room: ");
	ft_putstr(lem->end_room->name);
	ft_putstr("\nAnts count: ");
	ft_putnbr(lem->ants_nb);
}

void	parse_data(t_lemin *lem)
{
	char	*line;
	int		start_end;

	start_end = 0;
	if (get_next_line(0, &line) > 0 && ft_strcmp(line, "")
		&& ft_strcmp(line, "\n") && ft_isstrdigit(line))
		lem->ants_nb = ft_atoi(line);
	else
		err("Error: invalid ants count.");
	free(line);
	while (get_next_line(0, &line) > 0 && ft_strcmp(line, "")
		&& ft_strcmp(line, "\n"))
	{
		ft_putstr("\nLine: ");
		ft_putstr(line);
		if (!ft_strstr(line, "-"))
		{
			if (!parse_rooms(lem, line, &start_end))
				break ;
		}
		else if (!parse_tunnels(lem, line))
			break ;
	}
	if (!lem->start_room || !lem->end_room || !lem->rooms || !lem->rooms->next)
		err("Error: Invalid anthill.");
}

int		main(void)
{
	t_lemin	*lem;

	lem = (t_lemin *)s_malloc(sizeof(t_lemin));
	lem->rooms = NULL;
	parse_data(lem);
	parse_debug(lem);
	return (0);
}
