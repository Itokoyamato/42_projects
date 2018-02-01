/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:29:30 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/01 16:24:53 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_2d(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

void	parse_debug(t_lemin *lem)
{
	ft_putstr("\n");
	while (lem->rooms)
	{
		ft_putstr("-------------------------------------------\nRoom: ");
		ft_putstr(lem->rooms->name);
		ft_putstr(" (id: ");
		ft_putnbr(lem->rooms->id);
		ft_putstr(" | nb_tunnels: ");
		ft_putnbr(lem->rooms->nb_tunnels);
		ft_putstr(")\n");
		ft_putstr("\nConnected to rooms:\n");
		lem->rooms->tunnels_start = lem->rooms->tunnels;
		while (lem->rooms->tunnels)
		{
			ft_putstr(lem->rooms->tunnels->room->name);
			ft_putstr(" (id: ");
			ft_putnbr(lem->rooms->tunnels->room->id);
			ft_putstr(")\n");
			lem->rooms->tunnels = lem->rooms->tunnels->next;
		}
		lem->rooms->tunnels = lem->rooms->tunnels_start;
		lem->rooms = lem->rooms->next;
	}
	lem->rooms = lem->rooms_start;
	ft_putstr("---------------------------------------\nStart room: ");
	ft_putstr(lem->start_room->name);
	ft_putstr("\nEnd room: ");
	ft_putstr(lem->end_room->name);
	ft_putstr("\nRooms count: ");
	ft_putnbr(lem->nb_rooms);
	ft_putstr("\nAnts count: ");
	ft_putnbr(lem->ants_nb);
	ft_putstr("\n");
}

void	save_line(t_lemin *lem, char *l)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(l, "\n");
	tmp2 = ft_strdup(lem->input_str);
	if (lem->input_str[0])
		free(lem->input_str);
	lem->input_str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void	parse_ants(t_lemin *lem, char *l)
{
	char	*tofree;

	if ((lem->ants_nb = ft_atoi(l)) <= 0)
		err("Error: invalid ants count.");
	if ((ft_strcmp(tofree = ft_itoa(lem->ants_nb), l)))
	{
		free(tofree);
		err("Error: invalid ants count. (overflow)");
	}
	free(tofree);
}

void	parse_data(t_lemin *lem)
{
	char	*l;
	int		start_end;

	start_end = 0;
	while (ft_gnl(0, &l) > 0 && ft_strcmp(l, ""))
	{
		save_line(lem, l);
		if (!lem->ants_nb && ft_isstrdigit(l))
			parse_ants(lem, l);
		else if (!ft_strstr(l, "-"))
		{
			if (!parse_rooms(lem, l, &start_end))
				break ;
		}
		else if (!parse_tunnels(lem, l))
			break ;
		free(l);
	}
	if (!lem->start_room || !lem->end_room || !lem->rooms || !lem->rooms->next)
		err("Error: Invalid anthill.");
}
