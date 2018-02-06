/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/06 18:33:14 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	nb_ant_in_room(t_room *current, t_lemin *lem)
{
	t_ant *ants;
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

void	add_tunnels_to_list(t_roomlist *tunnels, t_roomlist *list,
	t_roomlist *already, t_lemin *lem)
{
	while (tunnels)
	{
		if (!in_roomlist(tunnels->room, already) && !((!list->parent)
			&& (nb_ant_in_room(tunnels->room, lem) && tunnels->room != lem->start_room
				&& tunnels->room != lem->end_room)))
		{
			add_roomlist(tunnels->room, list, list);
			add_roomlist(tunnels->room, NULL, already);
		}
		tunnels = tunnels->next;
	}
}

t_roomlist	*tree_paths(t_room *current, t_lemin *lem)
{
	t_roomlist	*list;
	t_roomlist	*list_start;
	t_roomlist	*already;

	list = init_roomlist(current);
	list_start = list;
	already = init_roomlist(current);
	while (list && list->room != lem->end_room)
	{
		add_tunnels_to_list(list->room->tunnels, list, already, lem);
		list = list->room != lem->end_room ? list->next : list;
	}
	destroy_roomlist(already);
	if (list && list->room == lem->end_room)
		return (list);
	else if (list_start)
		destroy_roomlist(list_start);
	return (NULL);
}

t_room		*path_to_take(t_roomlist *tree_paths)
{
	while (tree_paths->parent && tree_paths->parent->parent)
		tree_paths = tree_paths->parent;
	return (tree_paths->room);
}

void	solver(t_lemin *lem)
{
	t_roomlist	*tmp;
	t_ant				*ants;

	while (nb_ant_in_room(lem->end_room, lem) != lem->ants_nb)
	{
		ants = lem->ants;
		while (ants)
		{
			if ((tmp = tree_paths(ants->current_room, lem))
				&& ants->current_room != lem->end_room)
				move_ant(ants, path_to_take(tmp));
			ants = ants->next;
		}
		ft_putchar('\n');
	}
}
