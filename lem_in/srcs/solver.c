/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/07 18:12:37 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			nb_ant_in_room(t_room *current, t_lemin *lem)
{
	t_ant	*ants;
	int		i;

	ants = lem->ants;
	i = 0;
	while (ants)
	{
		if (current == ants->current_room)
			++i;
		ants = ants->next;
	}
	return (i);
}

void		add_tunnels_to_list(t_roomlist *tunnels, t_roomlist *list,
	t_roomlist *already, t_lemin *lem)
{
	while (tunnels)
	{
		if (!in_roomlist(tunnels->room, already) && !((!list->parent)
			&& (nb_ant_in_room(tunnels->room, lem)
			&& tunnels->room != lem->start_room
			&& tunnels->room != lem->end_room)))
		{
			add_roomlist(tunnels->room, list, list);
			add_roomlist(tunnels->room, NULL, already);
		}
		tunnels = tunnels->next;
	}
}

t_room		*path_to_take(t_room *current, t_lemin *lem)
{
	t_roomlist	*list;
	t_roomlist	*list_start;
	t_roomlist	*already;
	t_room		*result;

	result = NULL;
	list_start = init_roomlist(current);
	list = list_start;
	already = init_roomlist(current);
	while (list && list->room != lem->end_room)
	{
		add_tunnels_to_list(list->room->tunnels, list, already, lem);
		if (list->room != lem->end_room)
			list = list->next;
	}
	destroy_roomlist(already);
	if (list && list->room == lem->end_room)
	{
		while (list->parent && list->parent->parent)
			list = list->parent;
		result = list->room;
	}
	if (list_start)
		destroy_roomlist(list_start);
	return (result);
}

void		solver(t_lemin *lem)
{
	t_room		*tmp;
	t_ant		*ants;

	if (!(path_to_take(lem->start_room, lem)))
		err("No paths available to the end.\n", lem);
	while (nb_ant_in_room(lem->end_room, lem) != lem->ants_nb)
	{
		ants = lem->ants;
		while (ants)
		{
			tmp = path_to_take(ants->current_room, lem);
			if (tmp && ants->current_room != lem->end_room)
				move_ant(ants, tmp);
			ants = ants->next;
		}
		ft_putchar('\n');
	}
}
