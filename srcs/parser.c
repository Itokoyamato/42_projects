/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:29:30 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 15:09:38 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	parse_data(t_lemin *lem)
{
	char	*l;
	int		start_end;

	start_end = 0;
	if (ft_gnl(0, &l) <= 0 || !ft_strcmp(l, "") || !ft_isstrdigit(l))
		err("Error: invalid ants count.");
	lem->ants_nb = ft_atoi(l);
	save_line(lem, l);
	free(l);
	while (ft_gnl(0, &l) > 0 && ft_strcmp(l, ""))
	{
		save_line(lem, l);
		if (!ft_strstr(l, "-"))
		{
			if (!parse_rooms(lem, l, &start_end))
				break ;
		}
		else if (!parse_tunnels(lem, l))
			break ;
		free(l);
	}
	if (l[0])
		free(l);
	if (!lem->start_room || !lem->end_room || !lem->rooms || !lem->rooms->next)
		err("Error: Invalid anthill.");
}
