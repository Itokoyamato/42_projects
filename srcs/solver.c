/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/01 19:52:40 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_roomlist	*init_roomlist(t_room *toadd)
{
	t_roomlist	*list;
	list = (t_roomlist *)s_malloc(sizeof(t_roomlist));
	list->room = toadd;
	return (list);
}

// void	add_roomlist(t_room *toadd, t_roomlist *list)
// {
// 	// printf("\n%p->%p\n", list, list->next);
// 	// while (list->next)
// 	// {
// 	// 	list = list->next;
// 	// 	printf("%p->%p\n", list, list->next);
// 	// }
// 	// list->next = (t_roomlist *)s_malloc(sizeof(t_roomlist));
// 	// printf("%p->%p\n", list, list->next);
// 	// list->next->room = toadd;
// }

int		in_roomlist(t_room *current, t_roomlist *list)
{
	while (list)
	{
		if (list->room == current)
			return (1);
		list = list->next;
	}
	return (0);
}

t_room	*get_and_remove_first(t_roomlist *list)
{
	t_roomlist	*to_free;
	t_room		*result;

	if (list)
	{
		result = list->room;
		to_free = list;
		if (list->next)
			list = list->next;
		free(to_free);
		return (result);
	}
	return (NULL);
}

void	destroy_roomlist(t_roomlist *list)
{
	if (list->next)
		destroy_roomlist(list->next);
	free(list);
}

char	*shortest_direction (t_room *current)
{
	t_roomlist	*list;
	t_roomlist	*already;
	t_room		*current_room;
	t_roomlist	*current_room_tunnels;

	list = init_roomlist(current);
	already = init_roomlist(current);
	while (list)
	{
		current_room = get_and_remove_first(list);
		ft_putstr(current_room->name);
		current_room_tunnels = current_room->tunnels;
		while (current_room_tunnels)
		{
			if (!in_roomlist(current_room_tunnels->room, list))
			{
				// add_roomlist(current_room_tunnels->room, list);
				while (list)
				{
					printf("%p->%p\n", list, list->next);
					list = list->next;
				}
				// add_roomlist(current_room_tunnels->room, already);
			}
			current_room_tunnels = current_room_tunnels->next;
		}
		list = list->next;
	}
	return (NULL);
}

void	solver(t_lemin *lem)
{
	init_ants(lem);
	ft_putstr(shortest_direction(lem->start_room));
}
