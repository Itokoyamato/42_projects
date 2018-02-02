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

t_room	*get_first(t_roomlist *list)
{
	t_room		*result;

	result = list->room;
	return (result);
}

void	destroy_roomlist(t_roomlist *list)
{
	if (list->next)
		destroy_roomlist(list->next);
	free(list);
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
	t_roomlist	*list;
	t_roomlist	*list_start;
	t_roomlist	*already;
	t_room		*current_room;
	t_roomlist	*current_room_tunnels;

	list = init_roomlist(current);
	list_start = list;
	already = init_roomlist(current);
	while (list && current_room != lem->end_room)
	{
		current_room = get_first(list);
		current_room_tunnels = current_room->tunnels;
		add_tunnels_to_list(current_room_tunnels, list, already);
		list = current_room != lem->end_room ? list->next : list;
	}
	destroy_roomlist(already);
	if (current_room == lem->end_room)
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
