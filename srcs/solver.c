/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/02 18:05:11 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	destroy_roomlist(t_roomlist *list)
{
	if (list->next)
		destroy_roomlist(list->next);
	free(list);
}

int 	ant_in_room(t_room *current, t_lemin *lem)
{
	t_ant *ants;

	ants = lem->ants;
	while (ants)
	{
		if (current == ants->current_room)
			return (1);
		ants = ants->next;
	}
	return (0);
}

void	add_tunnels_to_list(t_roomlist *tunnels, t_roomlist *list,
	t_roomlist *already)
{
	while (tunnels)
	{
		if (!in_roomlist(tunnels->room, already))
		{
			add_roomlist(tunnels->room, list, list);
			add_roomlist(tunnels->room, NULL, already);
		}
		tunnels = tunnels->next;
	}
}

t_roomlist	*tree_paths(t_room *current, t_lemin *lem)
{
	// int					first;
	t_roomlist	*list;
	t_roomlist	*already;
	// first = 1;
	list = init_roomlist(current);
	already = init_roomlist(current);
	while (list && list->room != lem->end_room)
	{
		add_tunnels_to_list(list->room->tunnels, list, already);
		list = list->room != lem->end_room ? list->next : list;
	}
	destroy_roomlist(already);
	if (list->room == lem->end_room)
		return (list);
	else
		destroy_roomlist(list);
	return (NULL);
}

void	solver(t_lemin *lem)
{
	t_roomlist *test;

	init_ants(lem);
	test = tree_paths(lem->start_room, lem);
	while (test->parent)
	{
		ft_putstr(test->room->name);
		ft_putchar('\n');
		test = test->parent;
	}
	ft_putstr(test->room->name);
	ft_putchar('\n');
	destroy_roomlist(test);

}
