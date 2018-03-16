/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomlist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:31:11 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/07 17:48:01 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		destroy_roomlist(t_roomlist *list)
{
	if (list)
	{
		if (list->next)
			destroy_roomlist(list->next);
		free(list);
	}
}

t_roomlist	*init_roomlist(t_room *toadd)
{
	t_roomlist	*list;

	list = (t_roomlist *)s_malloc(sizeof(t_roomlist));
	list->room = toadd;
	list->next = NULL;
	return (list);
}

void		add_roomlist(t_room *toadd, t_roomlist *parent,
	t_roomlist *list)
{
	while (list->next)
		list = list->next;
	list->next = (t_roomlist *)s_malloc(sizeof(t_roomlist));
	list->next->room = toadd;
	list->next->parent = parent;
	list->next->next = NULL;
}

int			in_roomlist(t_room *current, t_roomlist *list)
{
	while (list)
	{
		if (list->room == current)
			return (1);
		list = list->next;
	}
	return (0);
}
